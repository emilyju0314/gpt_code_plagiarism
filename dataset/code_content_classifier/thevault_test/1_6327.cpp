void View::port(int win_width, int win_height)
{
  width = ceil(w * win_width);
  height = ceil(h * win_height);

  xpos = ceil(x * win_width);
  ypos = ceil((1.0 - y - h) * win_height); //Flip y-coord for gl

  //Ensure full window area filled
  if (abs(win_width - (xpos + width)) < 5)
    width = win_width - xpos;
  if (abs(win_height - (ypos + height)) < 5)
    height = win_height - ypos;

  glViewport(xpos, ypos, width, height);
  glScissor(xpos, ypos, width, height);
  //debug_print("-------Viewport (%f,%f %fx%f) set at %d,%d %d x %d\n", x,y,w,h, xpos, ypos, width, height);

  //Save unscaled initial height
  if (base_height == 0) base_height = height / session.context.scale2d;
}