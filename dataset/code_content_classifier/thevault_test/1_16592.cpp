void DumpRenderTreeSupportGtk::addUserStyleSheet(WebKitWebFrame* frame, const char* sourceCode, bool allFrames)
{
    g_return_if_fail(WEBKIT_IS_WEB_FRAME(frame));

    Frame* coreFrame = core(frame);
    if (!coreFrame)
        return;

    WebKitWebView* webView = getViewFromFrame(frame);
    Page* page = core(webView);
    page->group().addUserStyleSheetToWorld(mainThreadNormalWorld(), sourceCode, KURL(), 0, 0, allFrames ? InjectInAllFrames : InjectInTopFrameOnly); 
}