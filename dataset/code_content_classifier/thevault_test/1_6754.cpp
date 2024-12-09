int EditView::cmdMoveTo(float cx, float cy) {
  // cx and cy should be in screen (canvas) coordinates
  cx_ = cx;
  cy_ = cy;

  switch (editing_stage_) {
    case START_RUBBERBAND:
    case MOVE_RUBBERBAND:
      oldx_ = rb_.xmax;
      oldy_ = rb_.ymax;
      rb_.xmax = cx_;
      rb_.ymax = cy_;
      editing_stage_ = MOVE_RUBBERBAND;
      clip_ = rb_;
      clip_.adjust();

      if (clip_.xmin > oldx_) 
        clip_.xmin = oldx_;

      if (clip_.xmax < oldx_) 
        clip_.xmax = oldx_;

      if (clip_.ymin > oldy_) 
        clip_.ymin = oldy_;

      if (clip_.ymax < oldy_) 
        clip_.ymax = oldy_;

      break;

    case START_OBJECT:
    case MOVE_OBJECT: {
      oldx_ = rb_.xmax;
      oldy_ = rb_.ymax;
      rb_.xmax = cx_;
      rb_.ymax = cy_;
      editing_stage_ = MOVE_OBJECT;
      clip_.clear();
      defTag_->merge(clip_);
      matrix_.map(clip_.xmin, clip_.ymin);
      matrix_.map(clip_.xmax, clip_.ymax);
      clip_.adjust();
      // Actual move and final bbox computation is done in render
      break;

      case START_LINK:
      case MOVE_LINK:
        // I believe this is never reached and should be removed
        // maybe it is changed in the future
        oldx_ = rb_.xmax;
        oldy_ = rb_.ymax;
        rb_.xmax = cx_;
        rb_.ymax = cy_;
        editing_stage_ = MOVE_LINK;
        clip_ = rb_;
        clip_.adjust();
        if (clip_.xmin > oldx_)
          clip_.xmin = oldx_;
        if (clip_.xmax < oldx_)
          clip_.xmax = oldx_;
        if (clip_.ymin > oldy_)
          clip_.ymin = oldy_;
        if (clip_.ymax < oldy_)
          clip_.ymax = oldy_;
        break;
      }
    default:
      // to avoid segmentation fault from click-n-dragging
      return (TCL_OK);
  }
  draw();
  return (TCL_OK);
}