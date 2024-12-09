String *CFFI::lispy_name(char *name) {
  bool helper = false;
  String *new_name = NewString("");
  for (unsigned int i = 0; i < strlen(name); i++) {
    if (name[i] == '_' || name[i] == '-') {
      Printf(new_name, "%c", '-');
      helper = false;
    } else if (name[i] >= 'A' && name[i] <= 'Z') {
      if (helper)
  Printf(new_name, "%c", '-');
      Printf(new_name, "%c", ('a' + (name[i] - 'A')));
      helper = false;
    } else {
      helper = true;
      Printf(new_name, "%c", name[i]);
    }
  }
  return new_name;
}