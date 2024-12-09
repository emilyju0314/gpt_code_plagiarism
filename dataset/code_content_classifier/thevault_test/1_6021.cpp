void YARPColorLocator::AddExpectancy (YARPImageOf<YarpPixelBGR>& img)
{
	double x, y, quality;

	YARPImageOf<YarpPixelBGR> out;
	out.Resize (m_backprojected.GetWidth(), m_backprojected.GetHeight());
	BackProject (img, out);

	double ex, ey;
	GetExtent (ex, ey);
	
	Find (ex, ey, x, y, quality);

	m_count++;
	m_acc_thr += quality;
	m_acc_std += (quality*quality);
}