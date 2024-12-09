static void build_image_window(int width, int height) {
  delete image_win;
  image_win = new ScrollView(editor_image_win_name.c_str(), editor_image_xpos, editor_image_ypos,
                             width + 1, height + editor_image_menuheight + 1, width, height, true);
}