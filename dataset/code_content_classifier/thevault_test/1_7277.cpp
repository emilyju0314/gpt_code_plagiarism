void Fl_Sys_Menu_Bar::remove(int rank)
{
  Fl_Menu_::remove(rank);
  convertToMenuBar(Fl_Menu_::menu());
}