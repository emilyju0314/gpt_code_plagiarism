static void destroyFramebuffers(Frame& frame)
{
	if (frame.fb)
		frame.fb = nullptr;
	if (frame.ssfb.id)
		frame.ssfb.destroy();
	if (frame.msfb.id)
		frame.msfb.destroy();
	if (frame.color.id)
		frame.color.destroy();
	if (frame.depthStencil.id)
		frame.depthStencil.destroy();
	if (frame.colorMS.id)
		frame.colorMS.destroy();
	if (frame.depthStencilMS.id)
		frame.depthStencilMS.destroy();
}