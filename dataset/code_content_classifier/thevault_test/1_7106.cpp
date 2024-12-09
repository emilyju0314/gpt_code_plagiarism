Fl_Text_Editor::Key_Func Fl_Text_Editor::bound_key_function(int key, int state, Key_Binding* list) {
  Key_Binding* cur;
  for (cur = list; cur; cur = cur->next)
    if (cur->key == key)
      if (cur->state == FL_TEXT_EDITOR_ANY_STATE || cur->state == state)
        break;
  if (!cur) return 0;
  return cur->function;
}