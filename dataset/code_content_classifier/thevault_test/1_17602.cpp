CvRect offsetRect(const CvRect rectA, const CvRect rectB)
{
	CvRect rectC;
	rectC.x = rectA.x + rectB.x;
	rectC.y = rectA.y + rectB.y;
	rectC.width = rectA.width;
	rectC.height = rectA.height;
	return rectC;
}