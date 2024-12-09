Handle<String> Parser::ParseIdentifierOrGetOrSet(bool* is_get,
                                                 bool* is_set,
                                                 bool* ok) {
  Expect(Token::IDENTIFIER, ok);
  if (!*ok) return Handle<String>();
  if (scanner_.literal_length() == 3) {
    const char* token = scanner_.literal_string();
    *is_get = strcmp(token, "get") == 0;
    *is_set = !*is_get && strcmp(token, "set") == 0;
  }
  return GetSymbol(ok);
}