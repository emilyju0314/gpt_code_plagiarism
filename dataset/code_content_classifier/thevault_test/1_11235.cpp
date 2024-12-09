void SVPaint::SelectionHandler(const SVEvent *sv_event) {
  switch (drag_mode_) {
      // FIXME inversed x_size, y_size
    case 4: // Line
      window_->Line(sv_event->x, sv_event->y, sv_event->x - sv_event->x_size,
                    sv_event->y - sv_event->y_size);
      break;
    case 5: // Rectangle
      window_->Rectangle(sv_event->x, sv_event->y, sv_event->x - sv_event->x_size,
                         sv_event->y - sv_event->y_size);
      break;
    case 6: // Ellipse
      window_->Ellipse(sv_event->x - sv_event->x_size, sv_event->y - sv_event->y_size,
                       sv_event->x_size, sv_event->y_size);
      break;
  }
}