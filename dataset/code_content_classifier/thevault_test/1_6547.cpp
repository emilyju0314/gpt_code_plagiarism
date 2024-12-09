void Trace::addHandler(TraceHandler* th)
{
  TraceHandlerList* p = new TraceHandlerList;
  p->th = th;
  p->next = handlers_;
  handlers_ = p;
}