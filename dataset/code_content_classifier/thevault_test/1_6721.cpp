void 
QueueItem::draw(View* nv, double time ) {
  BBox bb;
  nv->BoundingBox(bb);

  if (bb.inside(bb_)) {
    nv->fill(px_, py_, 4, paint_);
    if (monitor_ != NULL)
        monitor_->draw(nv, px_[0],py_[0]);
  }
}