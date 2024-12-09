CheckRender::CheckRender(unsigned int width, unsigned int height, unsigned int Bpp,
                         bool bQAReadback, bool bUseFBO, bool bUsePBO) 
                         :
    m_Width(width), m_Height(height), m_Bpp(Bpp), m_bQAReadback(bQAReadback),
    m_bUseFBO(bUseFBO), m_bUsePBO(bUsePBO), m_PixelFormat(GL_BGRA), m_fThresholdCompare(0.0f)
{
    allocateMemory(width, height, Bpp, bQAReadback, bUseFBO, bUsePBO);
}