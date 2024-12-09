ScrollView::ScrollView(const char *name, int x_pos, int y_pos, int x_size, int y_size,
                       int x_canvas_size, int y_canvas_size, bool y_axis_reversed,
                       const char *server_name) {
  Initialize(name, x_pos, y_pos, x_size, y_size, x_canvas_size, y_canvas_size, y_axis_reversed,
             server_name);
}