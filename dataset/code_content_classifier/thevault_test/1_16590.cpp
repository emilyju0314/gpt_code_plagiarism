int DumpRenderTreeSupportGtk::pageNumberForElementById(WebKitWebFrame* frame, const char* id, float pageWidth, float pageHeight)
{
    g_return_val_if_fail(WEBKIT_IS_WEB_FRAME(frame), 0);

    Frame* coreFrame = core(frame);
    if (!coreFrame)
        return -1;

    Element* coreElement = coreFrame->document()->getElementById(AtomicString(id));
    if (!coreElement)
        return -1;
    return PrintContext::pageNumberForElement(coreElement, FloatSize(pageWidth, pageHeight));
}