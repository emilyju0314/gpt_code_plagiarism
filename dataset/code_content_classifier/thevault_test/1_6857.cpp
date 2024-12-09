void 
TrafficSource::placeNextTo(TrafficSource * neighbor)  {
  if (neighbor) {
    x_ = neighbor->x() + neighbor->width(); 
    y_ = neighbor->y(); 
    update_bb();
  }
}