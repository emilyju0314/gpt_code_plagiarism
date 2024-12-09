base::StringPiece MakeNotNullTerminatedInput(const char* input,
                                             std::unique_ptr<char[]>* owner) {
  size_t str_len = strlen(input);
  owner->reset(new char[str_len]);
  memcpy(owner->get(), input, str_len);
  return base::StringPiece(owner->get(), str_len);
}