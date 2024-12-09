void GraphicsContext::drawLine(const IntPoint& po1, const IntPoint& po2)
{
    if (paintingDisabled())
        return;	

    IntPoint point1 = m_data->matrix.mapPoint(po1);
    IntPoint point2 = m_data->matrix.mapPoint(po2);

	HDC hdc = m_data->context;

    StrokeStyle penStyle = strokeStyle();
    if (penStyle == NoStroke)
        return;

    SaveDC(hdc);   

    float width = strokeThickness();
    if (width < 1)
        width = 1;

    FloatPoint p1 = point1;
    FloatPoint p2 = point2;
    bool isVerticalLine = (p1.x() == p2.x());
    
    adjustLineToPixelBoundaries(p1, p2, width, penStyle);
    SetPenWidth (hdc, static_cast<int>(width));

    int patWidth = 0;
    switch (penStyle) {
    case NoStroke:
    case SolidStroke:
        SetPenType( hdc, PT_SOLID); 
        break;
    case DottedStroke:
        patWidth = static_cast<int>(width);
        SetPenType( hdc, PT_ON_OFF_DASH); 
        break;
    case DashedStroke:
        patWidth = 3*static_cast<int>(width);
        SetPenType( hdc, PT_ON_OFF_DASH); 
        break;
    }

    setPenColor (hdc, strokeColor());
//to set antialias to false

    if (patWidth) {
        // Do a rect fill of our endpoints.  This ensures we always have the
        // appearance of being a border.  We then draw the actual dotted/dashed line.
        if (isVerticalLine) {
            fillRectSourceOver(hdc, FloatRect(p1.x()-width/2, p1.y()-width, width, width), strokeColor());
            fillRectSourceOver(hdc, FloatRect(p2.x()-width/2, p2.y(), width, width), strokeColor());
        } else {
            fillRectSourceOver(hdc, FloatRect(p1.x()-width, p1.y()-width/2, width, width), strokeColor());
            fillRectSourceOver(hdc, FloatRect(p2.x(), p2.y()-width/2, width, width), strokeColor());
        }
        
        // Example: 80 pixels with a width of 30 pixels.
        // Remainder is 20.  The maximum pixels of line we could paint
        // will be 50 pixels.
        int distance = (isVerticalLine ? (point2.y() - point1.y()) : (point2.x() - point1.x())) - 2*static_cast<int>(width);
        int remainder = distance%patWidth;
        int coverage = distance-remainder;
        int numSegments = coverage/patWidth;

        float patternOffset = 0;
        // Special case 1px dotted borders for speed.
        if (patWidth == 1)
            patternOffset = 1.0;
        else {
            bool evenNumberOfSegments = numSegments%2 == 0;
            if (remainder)
                evenNumberOfSegments = !evenNumberOfSegments;
            if (evenNumberOfSegments) {
                if (remainder) {
                    patternOffset += patWidth - remainder;
                    patternOffset += remainder/2;
                }
                else
                    patternOffset = patWidth/2;
            }
            else if (!evenNumberOfSegments) {
                if (remainder)
                    patternOffset = (patWidth - remainder)/2;
            }
        }

       unsigned char pattern[2] = {(unsigned char)patWidth, (unsigned char)patWidth};
       SetPenDashes( hdc, (int)patternOffset, pattern, 2);
    }

	LineEx(hdc, (int)p1.x(), (int)p1.y(), (int)p2.x(), (int)p2.y());
    RestoreDC(hdc, -1);
}