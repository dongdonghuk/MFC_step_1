
class CvImage
{

public:
	Mat matImg;
	CPoint pt;
	REAL dZoomRate;


public:
	void imread(CString imgPath);
	void DrawImage(Graphics& g, CWnd* cwnd);
	void resize(CPoint& pt, short& zDelta);
};
