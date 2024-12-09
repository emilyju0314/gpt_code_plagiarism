bool ReadUnicodeCharacter(const wchar_t* src, int32 src_len,
                        int32* char_index, uint32* code_point) {
  // Conversion is easy since the source is 32-bit.
  *code_point = src[*char_index];

  // Validate the value.
  return U_IS_UNICODE_CHAR(*code_point);
}