
#include "pch.h"
#include "CvImage.h"


void CvImage::imread(CString imgPath) {
	matImg = cv::imread(std::string(CT2CA(imgPath)));
}


void CvImage::DrawImage(Graphics& g, CWnd* cwnd) {

	if (!(matImg.empty())) {

		CRect rect;
		cwnd->GetClientRect(rect);

		float width = rect.Width(), height = rect.Height();
		float rectRate = width / height;
		float imgRate = (float)matImg.size().width / (float)matImg.size().height;

		int priority_range = ((imgRate > rectRate && imgRate < 1) || (imgRate < rectRate&& imgRate >= 1)) ? 1 : 0;
		if (imgRate < 1) priority_range = 1 - priority_range;

		if (priority_range) width = height * imgRate;
		else height = width / imgRate;

		int interval_x = (rect.right - (int)width) / 2, interval_y = (rect.bottom - (int)height) / 2;

		if (priority_range) {
			rect.left = interval_x; rect.right = (int)width; rect.top = 0; rect.bottom = (int)height;
		}
		else {
			rect.left = 0; rect.right = (int)width; rect.top = interval_y; rect.bottom = (int)height;
		}


		cvtColor(matImg, matImg, COLOR_BGR2BGRA);

		Bitmap bitmap((INT)matImg.size().width, (INT)matImg.size().height, matImg.step,
			PixelFormat32bppARGB, matImg.data);

		//g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());
		g.DrawImage(&bitmap, rect.left, rect.top, (int)width, (int)height);


	}
}