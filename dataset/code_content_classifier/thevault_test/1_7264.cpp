void Fl_X::flush()
{
  w->flush();
  if (fl_gc) 
    CGContextFlush(fl_gc);
  SetOrigin( 0, 0 );
}