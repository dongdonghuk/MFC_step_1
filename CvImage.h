
class CvImage
{

public:
	Mat matImg;
	shared_ptr<Bitmap> bitImg;
	CPoint pt;
	double dZoomRate;

public:
	CvImage();
	~CvImage();

public:
	void imread(CString imgPath);
	void ImgAlignment(CRect& rect);
	void DrawImage(Graphics& g, CWnd* cwnd);
	void resize(CPoint& pt, short& zDelta);
};
