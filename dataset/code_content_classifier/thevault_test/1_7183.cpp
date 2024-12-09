void Fl_Text_Display::draw(void) {
  // don't even try if there is no associated text buffer!
  if (!buffer()) { draw_box(); return; }
  
  fl_push_clip(x(),y(),w(),h());	// prevent drawing outside widget area
  
  // draw the non-text, non-scrollbar areas.
  if (damage() & FL_DAMAGE_ALL) {
    //    printf("drawing all (box = %d)\n", box());
    // draw the box()
    int W = w(), H = h();
    draw_box(box(), x(), y(), W, H, color());
    
    if (mHScrollBar->visible())
      W -= scrollbar_width();
    if (mVScrollBar->visible())
      H -= scrollbar_width();
    
    // left margin
    fl_rectf(text_area.x-LEFT_MARGIN, text_area.y-TOP_MARGIN,
             LEFT_MARGIN, text_area.h+TOP_MARGIN+BOTTOM_MARGIN,
             color());
    
    // right margin
    fl_rectf(text_area.x+text_area.w, text_area.y-TOP_MARGIN,
             RIGHT_MARGIN, text_area.h+TOP_MARGIN+BOTTOM_MARGIN,
             color());
    
    // top margin
    fl_rectf(text_area.x, text_area.y-TOP_MARGIN,
             text_area.w, TOP_MARGIN, color());
    
    // bottom margin
    fl_rectf(text_area.x, text_area.y+text_area.h,
             text_area.w, BOTTOM_MARGIN, color());
    
    // draw that little box in the corner of the scrollbars
    if (mVScrollBar->visible() && mHScrollBar->visible())
      fl_rectf(mVScrollBar->x(), mHScrollBar->y(),
               mVScrollBar->w(), mHScrollBar->h(),
               FL_GRAY);
    
    // blank the previous cursor protrusions
  }
  else if (damage() & (FL_DAMAGE_SCROLL | FL_DAMAGE_EXPOSE)) {
    //    printf("blanking previous cursor extrusions at Y: %d\n", mCursorOldY);
    // CET - FIXME - save old cursor position instead and just draw side needed?
    fl_push_clip(text_area.x-LEFT_MARGIN,
                 text_area.y,
                 text_area.w+LEFT_MARGIN+RIGHT_MARGIN,
                 text_area.h);
    fl_rectf(text_area.x-LEFT_MARGIN, mCursorOldY,
             LEFT_MARGIN, mMaxsize, color());
    fl_rectf(text_area.x+text_area.w, mCursorOldY,
             RIGHT_MARGIN, mMaxsize, color());
    fl_pop_clip();
  }
  
  // draw the scrollbars
  if (damage() & (FL_DAMAGE_ALL | FL_DAMAGE_CHILD)) {
    mVScrollBar->damage(FL_DAMAGE_ALL);
    mHScrollBar->damage(FL_DAMAGE_ALL);
  }
  update_child(*mVScrollBar);
  update_child(*mHScrollBar);
  
  // draw all of the text
  if (damage() & (FL_DAMAGE_ALL | FL_DAMAGE_EXPOSE)) {
    //printf("drawing all text\n");
    int X, Y, W, H;
    if (fl_clip_box(text_area.x, text_area.y, text_area.w, text_area.h,
                    X, Y, W, H)) {
      // Draw text using the intersected clipping box...
      // (this sets the clipping internally)
      draw_text(X, Y, W, H);
    } else {
      // Draw the whole area...
      draw_text(text_area.x, text_area.y, text_area.w, text_area.h);
    }
  }
  else if (damage() & FL_DAMAGE_SCROLL) {
    // draw some lines of text
    fl_push_clip(text_area.x, text_area.y,
                 text_area.w, text_area.h);
    //printf("drawing text from %d to %d\n", damage_range1_start, damage_range1_end);
    draw_range(damage_range1_start, damage_range1_end);
    if (damage_range2_end != -1) {
      //printf("drawing text from %d to %d\n", damage_range2_start, damage_range2_end);
      draw_range(damage_range2_start, damage_range2_end);
    }
    damage_range1_start = damage_range1_end = -1;
    damage_range2_start = damage_range2_end = -1;
    fl_pop_clip();
  }
  
  // draw the text cursor
  if (damage() & (FL_DAMAGE_ALL | FL_DAMAGE_SCROLL | FL_DAMAGE_EXPOSE)
      && !buffer()->primary_selection()->selected() &&
      mCursorOn && Fl::focus() == this ) {
    fl_push_clip(text_area.x-LEFT_MARGIN,
                 text_area.y,
                 text_area.w+LEFT_MARGIN+RIGHT_MARGIN,
                 text_area.h);
    
    int X, Y;
    if (position_to_xy(mCursorPos, &X, &Y)) draw_cursor(X, Y);
    //    else puts("position_to_xy() failed - unable to draw cursor!");
    //printf("drew cursor at pos: %d (%d,%d)\n", mCursorPos, X, Y);
    mCursorOldY = Y;
    fl_pop_clip();
  }
  fl_pop_clip();
}