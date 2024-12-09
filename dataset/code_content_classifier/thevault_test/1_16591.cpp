CString DumpRenderTreeSupportGtk::pageSizeAndMarginsInPixels(WebKitWebFrame* frame, int pageNumber, int width, int height, int marginTop, int marginRight, int marginBottom, int marginLeft)
{
    g_return_val_if_fail(WEBKIT_IS_WEB_FRAME(frame), CString());

    Frame* coreFrame = core(frame);
    if (!coreFrame)
        return CString();

    return PrintContext::pageSizeAndMarginsInPixels(coreFrame, pageNumber, width, height, marginTop, marginRight, marginBottom, marginLeft).utf8();
}