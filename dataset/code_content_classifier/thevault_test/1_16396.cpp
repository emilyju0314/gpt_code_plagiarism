static WebURL urlFromFrame(Frame* frame)
{
    if (frame) {
        DocumentLoader* dl = frame->loader()->documentLoader();
        if (dl) {
            WebDataSource* ds = WebDataSourceImpl::fromDocumentLoader(dl);
            if (ds)
                return ds->hasUnreachableURL() ? ds->unreachableURL() : ds->request().url();
        }
    }
    return WebURL();
}