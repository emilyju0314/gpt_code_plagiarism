void 
BoxAgent::draw(View* nv, double time) {
  double corner_x, corner_y, partner_corner_x, partner_corner_y;
  double label_width, label_height, label_x, label_y;
  char full_label[128];

  // Draw line connecting this to its partner
  if (AgentPartner_) {
    if (draw_link_) {
      AgentPartner_->findClosestCornertoPoint(x(), y(), 
                                        partner_corner_x, partner_corner_y);

      findClosestCornertoPoint(partner_corner_x, partner_corner_y,
                               corner_x, corner_y);
      nv->line(corner_x, corner_y, 
               partner_corner_x, partner_corner_y,
               paint_);
    }
  }
    
        
  // Draw the label if it exists
  if (label_ != 0) {
    // Exapnd label to show partner id if connected
    if (AgentPartner_) {
      if (AgentRole_ == SOURCE) {
        sprintf(full_label, "%s - %d", label_, number_);
      } else {
        sprintf(full_label, "%s - %d", label_, AgentPartner_->number());
      }

    } else {
      sprintf(full_label, "%s", label_);
    }

    // We have to keep calculting the label width and height because
    // we have no way of knowing if the user has zoomed in or out 
    // on the current network view.
    label_height = 0.9 * height_;
    label_width = nv->getStringWidth(full_label, label_height);

    // Add 10% of padding to width for the box
    setWidth(1.1 * label_width);

    place(x_,y_);
    
    // Center label in box
    label_x = x0_ + (width_ - label_width);
    label_y = y0_ + (height_ - label_height);

    nv->string(full_label, label_x , label_y, label_height, NULL);
    
    update_bb();
  }
  
  // Draw the rectangle 
  nv->rect(x0_, y0_, x0_ + width_, y0_ + height_, paint_);

  if (monitor_ != NULL) {
    monitor_->draw(nv, (x0_ + x0_ + width_)/2, y0_ - height_);
  }
}