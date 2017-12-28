#include "stdafx.h"
/*
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/videoio/videoio.hpp"

#include <Windows.h>

using namespace std;
using namespace cv;

int screenCounter = 0;
BOOL CALLBACK MonitorEnumProcCallback(_In_  HMONITOR hMonitor, _In_  HDC DevC, _In_  LPRECT lprcMonitor, _In_  LPARAM dwData) {
	screenCounter++;

	//char*BmpName;

	if (screenCounter == 1) {
	//BmpName = "1 screen.bmp";
	
		MONITORINFO  info;
		info.cbSize = sizeof(MONITORINFO);

		BOOL monitorInfo = GetMonitorInfo(hMonitor, &info);

		if (monitorInfo) {

			DWORD Width = info.rcMonitor.right - info.rcMonitor.left;
			DWORD Height = info.rcMonitor.bottom - info.rcMonitor.top;

			BITMAPINFOHEADER  bi;
			bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
			bi.biWidth = Width;
			bi.biHeight = Height;  //this is the line that makes it draw upside down or not
			bi.biPlanes = 1;
			bi.biBitCount = 32;
			bi.biCompression = BI_RGB;
			bi.biSizeImage = 0;
			bi.biXPelsPerMeter = 0;
			bi.biYPelsPerMeter = 0;
			bi.biClrUsed = 0;
			bi.biClrImportant = 0;

			VideoWriter oVideoWriter("C:\\Users\\kait\\Desktop\\a\\MyVideo.wmv", CV_FOURCC('W', 'M', 'V', '2'), 10, Size(Width, Height), true); //initialize the VideoWriter object 

			namedWindow("HueieCam", 1);
			cout << "1" << endl;
			while (1) {
				Mat curframe;
				curframe.create(Height, Width, CV_8UC4);

				HDC CaptureDC = CreateCompatibleDC(DevC);
				HBITMAP CaptureBitmap = CreateCompatibleBitmap(DevC, Width, Height);
				SelectObject(CaptureDC, CaptureBitmap);
				BitBlt(CaptureDC, 0, 0, Width, Height, DevC, info.rcMonitor.left, info.rcMonitor.top, SRCCOPY | CAPTUREBLT);
				GetDIBits(CaptureDC, CaptureBitmap, 0, Height, curframe.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);
			
				oVideoWriter.write(curframe);
				imshow("HueieCam", curframe);
			}
		

		}
	}
	else {
		cout << "2" << endl;
		//BmpName = "2 screen.bmp";
	}
	return TRUE;
}

int main() {

	HDC DevC = GetDC(NULL);
	BOOL b = EnumDisplayMonitors(DevC, NULL, MonitorEnumProcCallback, 0);

	return 0;
}

*/