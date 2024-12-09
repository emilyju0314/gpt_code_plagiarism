int fl_wait( double time ) 
{
  do_queued_events( time );
  return (got_events);
}