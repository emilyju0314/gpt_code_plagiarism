Frame* core(const MDWebFrame* webFrame)
{
    if (!webFrame)
        return 0;
    return const_cast<MDWebFrame*>(webFrame)->impl();
}