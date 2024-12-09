bool has_ieee_float_representation() {
  // start by assume IEEE platform (i.e.: not a Cray machine).
  bool i_am_ieee(true);

  // Create a double precision value that will be used to test bit representations.
  double d_two(2.0);
  size_t constexpr size(sizeof(double));
  // Generate a bit-by-bit view of the double precision value:
  std::array<char, size> char_two;
  std::memcpy(&char_two, &d_two, size);

  // IEEE reference value:
  std::array<char, size> ieee64_two = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40};
  if (is_big_endian())
    char_byte_swap(&ieee64_two[0], size);

  // Cray reference value:
  // Note The 5th value of the actual Cray representation causes overflow warnings on IEEE machines:
  // char cray64_two[size] = {0x00,0x00,0x00,0x00,0x00,0x80,0x02,0x40};

  for (size_t i = 0; i < size; ++i)
    if (char_two[i] != ieee64_two[i]) {
      i_am_ieee = false;
      break;
    }

  return i_am_ieee;
}