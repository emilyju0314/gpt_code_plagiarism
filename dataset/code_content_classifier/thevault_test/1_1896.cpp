CheckFBO::CheckFBO(unsigned int width, unsigned int height, unsigned int Bpp) :
			CheckRender(width, height, Bpp, false, false, true),
			m_pFrameBufferObject(NULL)
{
}