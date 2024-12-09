void Fl_Window::make_current() 
{
  OSStatus err;
  Fl_X::q_release_context();
  if ( !fl_window_region )
    fl_window_region = NewRgn();
  fl_window = i->xid;
  current_ = this;

  SetPort( GetWindowPort(i->xid) ); // \todo check for the handling of doublebuffered windows

  int xp = 0, yp = 0;
  Fl_Window *win = this;
  while ( win ) 
  {
    if ( !win->window() )
      break;
    xp += win->x();
    yp += win->y();
    win = (Fl_Window*)win->window();
  }
  SetOrigin( -xp, -yp );
  
  SetRectRgn( fl_window_region, 0, 0, w(), h() );
  
  // \todo for performance reasons: we don't have to create this unless the child windows moved
  for ( Fl_X *cx = i->xidChildren; cx; cx = cx->xidNext )
  {
    Fl_Window *cw = cx->w;
    if (!cw->visible_r()) continue;
    Fl_Region r = NewRgn();
    SetRectRgn( r, cw->x() - xp, cw->y() - yp, 
                   cw->x() + cw->w() - xp, cw->y() + cw->h() - yp );
    DiffRgn( fl_window_region, r, fl_window_region );
    DisposeRgn( r );
  }
 
  err = QDBeginCGContext(GetWindowPort(i->xid), &i->gc);
  if (err!=noErr) 
    fprintf(stderr, "Error %d in QDBeginCGContext\n", (int)err);
  fl_gc = i->gc;
  CGContextSaveGState(fl_gc);
  Fl_X::q_fill_context();
#if defined(USE_CAIRO)
   if (Fl::cairo_autolink_context()) Fl::cairo_make_current(this); // capture gc changes automatically to update the cairo context adequately
#endif

  fl_clip_region( 0 );
  SetPortClipRegion( GetWindowPort(i->xid), fl_window_region );

#if defined(USE_CAIRO)
  // update the cairo_t context
  if (Fl::cairo_autolink_context()) Fl::cairo_make_current(this);
#endif
}