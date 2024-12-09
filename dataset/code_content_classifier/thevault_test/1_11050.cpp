bool ValidateGrapheme::IsBadlyFormedIndicVowel(char32 prev_ch, char32 ch) {
  return ((prev_ch == 0x905 && (ch == 0x946 || ch == 0x93E)) || (prev_ch == 0x909 && ch == 0x941) ||
          (prev_ch == 0x90F && (ch >= 0x945 && ch <= 0x947)) ||
          (prev_ch == 0x905 && (ch >= 0x949 && ch <= 0x94C)) ||
          (prev_ch == 0x906 && (ch >= 0x949 && ch <= 0x94C)) ||
          // Illegal combinations of two dependent Devanagari vowels.
          (prev_ch == 0x93E && (ch >= 0x945 && ch <= 0x948)) ||
          // Dependent Devanagari vowels following a virama.
          (prev_ch == 0x94D && (ch >= 0x93E && ch <= 0x94C)) ||
          // Bengali vowels (Table 9-5, pg 313)
          (prev_ch == 0x985 && ch == 0x9BE) ||
          // Telugu vowels (Table 9-19, pg 331)
          (prev_ch == 0xC12 && (ch == 0xC55 || ch == 0xC4C)) ||
          // Kannada vowels (Table 9-20, pg 332)
          (prev_ch == 0xC92 && ch == 0xCCC));
}