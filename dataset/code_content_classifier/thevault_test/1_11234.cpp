void SVPaint::PopupHandler(const SVEvent *sv_event) {
  // Since we only have the RGB values as popup items,
  // we take a shortcut to not bloat up code:
  rgb[sv_event->command_id - 1] = atoi(sv_event->parameter);
  window_->Pen(rgb[0], rgb[1], rgb[2]);
}