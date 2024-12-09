CanvasSurface::CanvasSurface(float pageScaleFactor)
    : m_size(DefaultWidth, DefaultHeight)
    , m_pageScaleFactor(pageScaleFactor)
    , m_originClean(true)
    , m_hasCreatedImageBuffer(false)
{
}