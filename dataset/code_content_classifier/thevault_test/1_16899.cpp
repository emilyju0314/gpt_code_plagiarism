void OpenGLContext::FlushContext()
{
	if(flush_pending())
	{
		// A flush is pending so do nothing; just drop this flush on the floor.
		return;
	}
	set_flush_pending(true);
	context_.SwapBuffers(pp::CompletionCallback(&FlushCallback, this));
}