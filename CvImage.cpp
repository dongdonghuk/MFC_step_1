
#include "pch.h"
#include "CvImage.h"


void CvImage::imread(CString imgPath) {
	matImg = cv::imread(std::string(CT2CA(imgPath)));
}


void CvImage::DrawImage(Graphics& g) {

	if (!(matImg.empty())) {
		cvtColor(matImg, matImg, COLOR_BGR2BGRA);

		Bitmap bitmap((INT)matImg.size().width, (INT)matImg.size().height, matImg.step,
			PixelFormat32bppARGB, matImg.data);

		g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	}
}