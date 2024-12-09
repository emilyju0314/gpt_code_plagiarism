void ScrollView::SendPolygon() {
  if (!points_->empty) {
    points_->empty = true; // Allows us to use SendMsg.
    int length = points_->xcoords.size();
    // length == 1 corresponds to 2 SetCursors in a row and only the
    // last setCursor has any effect.
    if (length == 2) {
      // An isolated line!
      SendMsg("drawLine(%d,%d,%d,%d)", points_->xcoords[0], points_->ycoords[0],
              points_->xcoords[1], points_->ycoords[1]);
    } else if (length > 2) {
      // A polyline.
      SendMsg("createPolyline(%d)", length);
      char coordpair[kMaxIntPairSize];
      std::string decimal_coords;
      for (int i = 0; i < length; ++i) {
        snprintf(coordpair, kMaxIntPairSize, "%d,%d,", points_->xcoords[i], points_->ycoords[i]);
        decimal_coords += coordpair;
      }
      decimal_coords += '\n';
      SendRawMessage(decimal_coords.c_str());
      SendMsg("drawPolyline()");
    }
    points_->xcoords.clear();
    points_->ycoords.clear();
  }
}