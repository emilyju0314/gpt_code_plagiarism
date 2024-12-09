void Fl_Text_Editor::maybe_do_callback() {
//  printf("Fl_Text_Editor::maybe_do_callback()\n");
//  printf("changed()=%d, when()=%x\n", changed(), when());
  if (changed() || (when()&FL_WHEN_NOT_CHANGED)) do_callback();
}