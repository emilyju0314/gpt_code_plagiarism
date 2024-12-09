HBITMAP cImageCapturingModuleId3d11Impl::getCurrentFrameAsBitmap()
{
	HBITMAP  hbitmapCurrentFrame = NULL;

	getBitmapFromTextureId3d11(m_CurrentFrameTexture, &hbitmapCurrentFrame);

	return hbitmapCurrentFrame;
}