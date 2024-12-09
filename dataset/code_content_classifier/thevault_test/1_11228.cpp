bool UNICHARSET::major_right_to_left() const {
  int ltr_count = 0;
  int rtl_count = 0;
  for (unsigned id = 0; id < unichars.size(); ++id) {
    int dir = get_direction(id);
    if (dir == UNICHARSET::U_LEFT_TO_RIGHT) {
      ltr_count++;
    }
    if (dir == UNICHARSET::U_RIGHT_TO_LEFT ||
        dir == UNICHARSET::U_RIGHT_TO_LEFT_ARABIC ||
        dir == UNICHARSET::U_ARABIC_NUMBER) {
      rtl_count++;
    }
  }
  return rtl_count > ltr_count;
}