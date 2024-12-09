bool TextlineProjection::PadBlobBox(BLOBNBOX *blob, TBOX *bbox) {
  // Determine which direction to spread.
  // If text is well spaced out, it can be useful to pad perpendicular to
  // the textline direction, so as to ensure diacritics get absorbed
  // correctly, but if the text is tightly spaced, this will destroy the
  // blank space between textlines in the projection map, and that would
  // be very bad.
  int pad_limit = scale_factor_ * kMinLineSpacingFactor;
  int xpad = 0;
  int ypad = 0;
  bool padding_horizontally = false;
  if (blob->UniquelyHorizontal()) {
    xpad = bbox->height() * kOrientedPadFactor;
    padding_horizontally = true;
    // If the text appears to be very well spaced, pad the other direction by a
    // single pixel in the projection profile space to help join diacritics to
    // the textline.
    if ((blob->neighbour(BND_ABOVE) == nullptr ||
         bbox->y_gap(blob->neighbour(BND_ABOVE)->bounding_box()) > pad_limit) &&
        (blob->neighbour(BND_BELOW) == nullptr ||
         bbox->y_gap(blob->neighbour(BND_BELOW)->bounding_box()) > pad_limit)) {
      ypad = scale_factor_;
    }
  } else if (blob->UniquelyVertical()) {
    ypad = bbox->width() * kOrientedPadFactor;
    if ((blob->neighbour(BND_LEFT) == nullptr ||
         bbox->x_gap(blob->neighbour(BND_LEFT)->bounding_box()) > pad_limit) &&
        (blob->neighbour(BND_RIGHT) == nullptr ||
         bbox->x_gap(blob->neighbour(BND_RIGHT)->bounding_box()) > pad_limit)) {
      xpad = scale_factor_;
    }
  } else {
    if ((blob->neighbour(BND_ABOVE) != nullptr &&
         blob->neighbour(BND_ABOVE)->neighbour(BND_BELOW) == blob) ||
        (blob->neighbour(BND_BELOW) != nullptr &&
         blob->neighbour(BND_BELOW)->neighbour(BND_ABOVE) == blob)) {
      ypad = bbox->width() * kDefaultPadFactor;
    }
    if ((blob->neighbour(BND_RIGHT) != nullptr &&
         blob->neighbour(BND_RIGHT)->neighbour(BND_LEFT) == blob) ||
        (blob->neighbour(BND_LEFT) != nullptr &&
         blob->neighbour(BND_LEFT)->neighbour(BND_RIGHT) == blob)) {
      xpad = bbox->height() * kDefaultPadFactor;
      padding_horizontally = true;
    }
  }
  bbox->pad(xpad, ypad);
  pad_limit = scale_factor_ * kMaxTabStopOverrun;
  // Now shrink horizontally to avoid stepping more than pad_limit over a
  // tab-stop.
  if (bbox->left() < blob->left_rule() - pad_limit) {
    bbox->set_left(blob->left_rule() - pad_limit);
  }
  if (bbox->right() > blob->right_rule() + pad_limit) {
    bbox->set_right(blob->right_rule() + pad_limit);
  }
  return padding_horizontally;
}