void RenderPath::addFocusRingRects(Vector<IntRect>& rects, int, int) 
{
    IntRect rect = enclosingIntRect(repaintRectInLocalCoordinates());
    if (!rect.isEmpty())
        rects.append(rect);
}