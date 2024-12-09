void Fl::get_mouse(int &x, int &y) 
{
  fl_open_display();
  Point loc; 
  GetMouse( &loc );
  LocalToGlobal( &loc );
  x = loc.h;
  y = loc.v;
}