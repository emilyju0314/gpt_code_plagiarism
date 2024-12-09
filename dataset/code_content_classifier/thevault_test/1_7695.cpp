bool ReadUnicodeCharacter(const char16* src, int32 src_len,
                          int32* char_index, uint32* code_point) {
  if (U16_IS_SURROGATE(src[*char_index])) {
    if (!U16_IS_SURROGATE_LEAD(src[*char_index]) ||
        *char_index + 1 >= src_len ||
        !U16_IS_TRAIL(src[*char_index + 1])) {
      // Invalid surrogate pair.
      return false;
    }

    // Valid surrogate pair.
    *code_point = U16_GET_SUPPLEMENTARY(src[*char_index],
                                        src[*char_index + 1]);
    (*char_index)++;
  } else {
    // Not a surrogate, just one 16-bit word.
    *code_point = src[*char_index];
  }

  return U_IS_UNICODE_CHAR(*code_point);
}