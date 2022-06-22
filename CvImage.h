
class CvImage
{

public:
	Mat matImg;
	CPoint pt;
	double dZoomRate;


public:
	void imread(CString imgPath);
	void DrawImage(Graphics& g, CWnd* cwnd);
	void resize(CPoint& pt);
};
