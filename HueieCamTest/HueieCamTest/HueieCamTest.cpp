// HueieCamTest.cpp : Defines the entry point for the console application.
//

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


int main()
{
	// get the height and width of the screen
	int height = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	int width = GetSystemMetrics(SM_CXVIRTUALSCREEN);

	BITMAPINFOHEADER  bi;
	bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
	bi.biWidth = width;
	bi.biHeight = -height;  //this is the line that makes it draw upside down or not
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	
	Size resize_ratio(width / 2, height / 2);
	namedWindow("HueieCam", 1);
	
	VideoWriter oVideoWriter("C:\\Users\\kait\\Desktop\\a\\MyVideo.wmv", CV_FOURCC('W', 'M', 'V', '2'), 10, resize_ratio, true); //initialize the VideoWriter object 

	if (!oVideoWriter.isOpened()) //if not initialize the VideoWriter successfully, exit the program
	{
		int i;
		cout << "ERROR: Failed to write the video" << endl;
		cin >> i;
		return -1;
	}
	
	while(1){
		Mat curframe, resized_frame;
		curframe.create(height, width, CV_8UC4);

		HDC hdc = GetDC(NULL); // get the desktop device context
		HDC hDest = CreateCompatibleDC(hdc); // create a device context to use yourself
		
		RECT windowsize;    // get the height and width of the screen
		GetClientRect(NULL, &windowsize);
		int srcheight = windowsize.bottom;
		int srcwidth = windowsize.right;

		// create a bitmap
		HBITMAP hbDesktop = CreateCompatibleBitmap(hdc, width, height);
		// use the previously created device context with the bitmap
		SelectObject(hDest, hbDesktop);
		
		// copy from the desktop device context to the bitmap device context
		// call this once per 'frame'
		BitBlt(hDest, 0, 0, width, height, hdc, 0, 0, SRCCOPY);
		// create a bitmap
		if (0 == GetDIBits(hDest, hbDesktop, 0, height, curframe.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS)) {
			//copy from hwindowCompatibleDC to hbwindow
			cout << "error2" << endl;
		}
		StretchBlt(hDest, 0, 0, width, height, hdc, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
		GetDIBits(hDest, hbDesktop, 0, height, curframe.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow


		resize(curframe, resized_frame, resize_ratio);//resize image
		if (resized_frame.empty()) {
			break;
		}
		Mat newmat = resized_frame.clone();
		oVideoWriter.write(newmat);
		imshow("HueieCam", newmat);
		
		DeleteObject(hbDesktop);
		// after the recording is done, release the desktop context you got..
		ReleaseDC(NULL, hdc);
		// ..and delete the context you created
		DeleteDC(hDest);

		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	oVideoWriter.release();
	destroyAllWindows();

    return 0;
}

*/