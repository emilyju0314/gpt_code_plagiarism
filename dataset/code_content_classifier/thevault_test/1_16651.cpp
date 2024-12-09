void GraphicsContext::drawEllipse(const IntRect& r)
{
    if (paintingDisabled())
        return;	

    IntRect rect = m_data->matrix.mapRect(r);

	HDC hdc = m_data->context;
    SaveDC(hdc);

    if (fillColor().alpha()) {
        setBrushColor(hdc, fillColor()); //FIXME: should be alpha blend
        FillEllipse (hdc, rect.x()+rect.width()/2, rect.y()+rect.height()/2, rect.width()/2, rect.height()/2);
    }

    if (strokeStyle() != NoStroke) {
        setPenColor(hdc, strokeColor());
        SetPenWidth (hdc, strokeThickness());
	    Ellipse(hdc, rect.x()+rect.width()/2, rect.y()+rect.height()/2, rect.width()/2, rect.height()/2);
    }
    RestoreDC(hdc, -1);
}