void
EditView::render() {
  // Here we can compute the clipping box for render
  Paint *paint = Paint::instance();
  GC gc = paint->paint_to_gc(paint->Xor());

  switch (editing_stage_) {
    case START_RUBBERBAND:
      // draw rubber band
      xrect(rb_.xmin, rb_.ymin, rb_.xmax, rb_.ymax, gc);
      break;

    case MOVE_RUBBERBAND: 
      // erase previous rubberband
      xrect(rb_.xmin, rb_.ymin, oldx_, oldy_, gc);
      // draw new rubberband
      xrect(rb_.xmin, rb_.ymin, rb_.xmax, rb_.ymax, gc);
      break;

    case END_RUBBERBAND: 
      // erase previous rubber band
      xrect(rb_.xmin, rb_.ymin, oldx_, oldy_, gc);
      // XXX Should draw the tag?
      model_->render(this);
      editing_stage_ = NONE;
      break;

    case START_OBJECT:
      xrect(rb_.xmin, rb_.ymin, rb_.xmax, rb_.ymax, gc);
      // xor-draw all relevant objects
      defTag_->draw(this, model_->now());
      break;

    case MOVE_OBJECT: 
      // erase old positions first.
      if ((oldx_ == rb_.xmax) && (oldy_ == rb_.ymax)) 
        return;
      defTag_->draw(this, model_->now());
      // move these objects
      defTag_->move(this, rb_.xmax - oldx_, rb_.ymax - oldy_);
      BBox bb;
      bb.clear();
      defTag_->merge(bb);
      matrix_.imap(bb.xmin, bb.ymin);
      matrix_.imap(bb.xmax, bb.ymax);
      bb.adjust();
      clip_.merge(bb);
      defTag_->draw(this, model_->now());
      break;

    case END_OBJECT:
      // Erase old positions
      defTag_->draw(this, model_->now());
      // At least we should redo scale estimation and 
      // place everything
      defTag_->move(this, rb_.xmax - oldx_, rb_.ymax - oldy_);
      model_->recalc();
      model_->render(this);
      editing_stage_ = NONE;
      break;

    case START_LINK:
      line(link_start_x_, link_start_y_, link_end_x_, link_end_y_, 3);
      defTag_->draw(this, model_->now());
      break;

    case MOVE_LINK:
      // erase previous link
      xline(rb_.xmin, rb_.ymin, oldx_, oldy_, gc);
      // draw new rubberband
      xline(rb_.xmin, rb_.ymin, rb_.xmax, rb_.ymax, gc);
      break;

    case END_LINK:
      // erase previous link
      xline(rb_.xmin, rb_.ymin, oldx_, oldy_, gc);
      // XXX Should draw the tag?
      model_->render(this);
      editing_stage_ = NONE;
      break;

    default:
      // redraw model
      model_->render(this);
      break;
  }
  return;
}