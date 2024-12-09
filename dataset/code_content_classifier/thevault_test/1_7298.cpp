void Fl::get_system_colors()
{
  fl_open_display();

  if (!fl_bg2_set) background2(0xff, 0xff, 0xff);
  if (!fl_fg_set) foreground(0, 0, 0);
  if (!fl_bg_set) background(0xd8, 0xd8, 0xd8);
  
#if 0 
  // this would be the correct code, but it does not run on all versions
  // of OS X. Also, setting a bright selection color would require 
  // some updates in Fl_Adjuster and Fl_Help_Browser
  OSStatus err;
  RGBColor c;
  err = GetThemeBrushAsColor(kThemeBrushPrimaryHighlightColor, 24, true, &c);
  if (err)
    set_selection_color(0x00, 0x00, 0x80);
  else
    set_selection_color(c.red, c.green, c.blue);
#else
  set_selection_color(0x00, 0x00, 0x80);
#endif
}