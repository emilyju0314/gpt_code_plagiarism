void ScrollView::Draw(Image image, int x_pos, int y_pos) {
  l_uint8 *data;
  size_t size;
  pixWriteMem(&data, &size, image, IFF_PNG);
  int base64_len = (size + 2) / 3 * 4;
  y_pos = TranslateYCoordinate(y_pos);
  SendMsg("readImage(%d,%d,%d)", x_pos, y_pos, base64_len);
  // Base64 encode the data.
  const char kBase64Table[64] = {
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
      'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/',
  };
  char *base64 = new char[base64_len + 1];
  memset(base64, '=', base64_len);
  base64[base64_len] = '\0';
  int remainder = 0;
  int bits_left = 0;
  int code_len = 0;
  for (size_t i = 0; i < size; ++i) {
    int code = (data[i] >> (bits_left + 2)) | remainder;
    base64[code_len++] = kBase64Table[code & 63];
    bits_left += 2;
    remainder = data[i] << (6 - bits_left);
    if (bits_left == 6) {
      base64[code_len++] = kBase64Table[remainder & 63];
      bits_left = 0;
      remainder = 0;
    }
  }
  if (bits_left > 0) {
    base64[code_len++] = kBase64Table[remainder & 63];
  }
  SendRawMessage(base64);
  delete[] base64;
  lept_free(data);
}