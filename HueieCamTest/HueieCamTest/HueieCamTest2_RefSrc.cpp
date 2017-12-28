#include "stdafx.h"
#include <windows.h>

#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/videoio/videoio.hpp"
using namespace cv;

int screenCounter = 0;
int screent; int screenb; int screenl; int screenr;

void setPosition(int t, int b, int l, int r) {
	screent = t;
	screenb = b;
	screenl = l;
	screenr = r;
}

BOOL CALLBACK MonitorEnumProcCallback(_In_  HMONITOR hMonitor, _In_  HDC DevC, _In_  LPRECT lprcMonitor, _In_  LPARAM dwData) {
	screenCounter++;

	char*BmpName;

	if (screenCounter == 1) {
		BmpName = "D:/1_screen.bmp";
	}
	else {
		BmpName = "D:/2_screen.bmp";
	}

	MONITORINFO  info;
	info.cbSize = sizeof(MONITORINFO);

	BOOL monitorInfo = GetMonitorInfo(hMonitor, &info);

	if (monitorInfo && screenCounter == 1) {
		//DWORD Width = info.rcMonitor.right - info.rcMonitor.left;
		//DWORD Height = info.rcMonitor.bottom - info.rcMonitor.top;

		DWORD Width = screenr - screenl;;
		DWORD Height = screenb - screent;


		DWORD FileSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBTRIPLE) + 1 * (Width*Height * 4));
		char *BmpFileData = (char*)GlobalAlloc(0x0040, FileSize);

		PBITMAPFILEHEADER BFileHeader = (PBITMAPFILEHEADER)BmpFileData;
		PBITMAPINFOHEADER  BInfoHeader = (PBITMAPINFOHEADER)&BmpFileData[sizeof(BITMAPFILEHEADER)];

		BFileHeader->bfType = 0x4D42; // BM
		BFileHeader->bfSize = sizeof(BITMAPFILEHEADER);
		BFileHeader->bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

		BInfoHeader->biSize = sizeof(BITMAPINFOHEADER);
		BInfoHeader->biPlanes = 1;
		BInfoHeader->biBitCount = 24;
		BInfoHeader->biCompression = BI_RGB;
		BInfoHeader->biHeight = Height;
		BInfoHeader->biWidth = Width;

		RGBTRIPLE *Image = (RGBTRIPLE*)&BmpFileData[sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)];
		RGBTRIPLE color;

		VideoWriter oVideoWriter("C:\\Users\\kait\\Desktop\\a\\MyVideo.wmv", CV_FOURCC('W', 'M', 'V', '2'), 10, Size(Width, Height), true); //initialize the VideoWriter object 
		namedWindow("HueieCam", 1);
		
		HDC CaptureDC = CreateCompatibleDC(DevC);
		HBITMAP CaptureBitmap = CreateCompatibleBitmap(DevC, Width, Height);
		HANDLE FH;
		while (1) {
			SelectObject(CaptureDC, CaptureBitmap);
			//BitBlt(CaptureDC, 0, 0, Width, Height, DevC, info.rcMonitor.left, info.rcMonitor.top, SRCCOPY | CAPTUREBLT);
			BitBlt(CaptureDC, 0, 0, Width, Height, DevC, screenl, screent, SRCCOPY | CAPTUREBLT);
			GetDIBits(CaptureDC, CaptureBitmap, 0, Height, Image, (LPBITMAPINFO)BInfoHeader, DIB_RGB_COLORS);

			DWORD Junk;
			FH = CreateFileA(BmpName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, 0, 0);
			WriteFile(FH, BmpFileData, FileSize, &Junk, 0);
			CloseHandle(FH);

			Mat curframe = imread(BmpName);
			oVideoWriter.write(curframe);
			imshow("HueieCam", curframe);

			char c = (char)waitKey(1);
			if (c == 27)
				break;
		}
		oVideoWriter.release();
		
		GlobalFree(BmpFileData);

	}

	return TRUE;
}


void run() {
	HDC DevC = GetDC(NULL);
	BOOL b = EnumDisplayMonitors(DevC, NULL, MonitorEnumProcCallback, 0);
}

int main() {

	setPosition(100, 200, 100, 300);
	run();

	return 0;
}


