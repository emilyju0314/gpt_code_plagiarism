int Fl_Text_Editor::kf_copy(int, Fl_Text_Editor* e) {
  if (!e->buffer()->selected()) return 1;
  const char *copy = e->buffer()->selection_text();
  if (*copy) Fl::copy(copy, strlen(copy), 1);
  free((void*)copy);
  e->show_insert_position();
  return 1;
}