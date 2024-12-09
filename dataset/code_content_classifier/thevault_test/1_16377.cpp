void DumpRenderTreeSupportQt::suspendActiveDOMObjects(QWebFrame* frame)
{
    Frame* coreFrame = QWebFramePrivate::core(frame);
    if (coreFrame->document())
        // FIXME: This function should be changed take a ReasonForSuspension parameter 
        // https://bugs.webkit.org/show_bug.cgi?id=45732
        coreFrame->document()->suspendActiveDOMObjects(ActiveDOMObject::JavaScriptDebuggerPaused);
}