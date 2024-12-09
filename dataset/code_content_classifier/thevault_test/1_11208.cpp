void UNICHARSET::UNICHAR_PROPERTIES::Init() {
  isalpha = false;
  islower = false;
  isupper = false;
  isdigit = false;
  ispunctuation = false;
  isngram = false;
  enabled = false;
  SetRangesOpen();
  script_id = 0;
  other_case = 0;
  mirror = 0;
  normed = "";
  direction = UNICHARSET::U_LEFT_TO_RIGHT;
  fragment = nullptr;
}