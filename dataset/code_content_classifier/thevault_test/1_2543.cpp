void Console_Token_Stream::fill_character_buffer_() {
  char c = static_cast<char>(cin.get());
  if (cin.fail()) {
    character_push_back_('\0');
  } else {
    if (c == '\n') {
      c = ';';
    }
    character_push_back_(c);
  }

  Ensure(check_class_invariants());
}