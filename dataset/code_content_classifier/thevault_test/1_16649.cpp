void GraphicsContext::drawRect(const IntRect& r)
{
	if (paintingDisabled())
		return;	

    IntRect rect = m_data->matrix.mapRect(r);

	HDC hdc = m_data->context;
    if (fillColor().alpha())
        fillRectSourceOver(hdc, rect, fillColor());

    if (strokeStyle() != NoStroke) {
        setPenColor(hdc, strokeColor());
        FloatRect r(rect);
        r.inflate(-.5f);
        SetPenWidth (hdc, static_cast<int>(strokeThickness()));
	    Rectangle(hdc, (int)r.x(), (int)r.y(), (int)(r.x()+r.width()), (int)(r.y()+r.height()));
    }
}