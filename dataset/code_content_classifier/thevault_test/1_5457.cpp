static void createFramebuffers(Frame& frame, uvec2 const size, Samples const _aa)
{
	ASSERT(_aa != Samples::None);

	frame.ssfb.create("Frame::ssfb");
	frame.color.create("Frame::color", size);
	frame.depthStencil.create("Frame::depthStencil", size);
	frame.ssfb.attach(frame.color, Attachment::Color0);
	frame.ssfb.attach(frame.depthStencil, Attachment::DepthStencil);

	if (_aa != Samples::_1) {
		frame.msfb.create("Frame::msfb");
		frame.colorMS.create("Frame::colorMS", size, _aa);
		frame.depthStencilMS.create("Frame::depthStencilMS", size, _aa);
		frame.msfb.attach(frame.colorMS, Attachment::Color0);
		frame.msfb.attach(frame.depthStencilMS, Attachment::DepthStencil);
	}
}