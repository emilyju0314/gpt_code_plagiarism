bool ValidateGrapheme::IsBadlyFormedThai(char32 prev_ch, char32 ch) {
  // Tone marks must follow consonants or specific vowels.
  if (IsThaiToneMark(ch) && !(IsThaiConsonant(prev_ch) || IsThaiTonableVowel(prev_ch))) {
    return true;
  }
  // Tonable vowels must follow consonants.
  if ((IsThaiTonableVowel(ch) || ch == 0xe47) && !IsThaiConsonant(prev_ch)) {
    return true;
  }
  // Thanthakhat must follow consonant or specific vowels.
  if (ch == 0xe4c && !(IsThaiConsonant(prev_ch) || prev_ch == 0xe38 || prev_ch == 0xe34)) {
    return true;
  }
  // Nikkhahit must follow a consonant ?or certain markers?.
  // TODO(rays) confirm this, but there were so many in the ground truth of the
  // validation set that it seems reasonable to assume it is valid.
  if (ch == 0xe4d && !(IsThaiConsonant(prev_ch) || prev_ch == 0xe48 || prev_ch == 0xe49)) {
    return true;
  }
  // The vowels e30, e32, e33 can be used more liberally.
  if ((ch == 0xe30 || ch == 0xe32 || ch == 0xe33) &&
      !(IsThaiConsonant(prev_ch) || IsThaiToneMark(prev_ch)) &&
      !(prev_ch == 0xe32 && ch == 0xe30) && !(prev_ch == 0xe4d && ch == 0xe32)) {
    return true;
  }
  // Some vowels come before consonants, and therefore cannot follow things
  // that cannot end a syllable.
  if (IsThaiBeforeConsonantVowel(ch) &&
      (IsThaiBeforeConsonantVowel(prev_ch) || prev_ch == 0xe31 || prev_ch == 0xe37)) {
    return true;
  }
  // Don't allow the standalone vowel U+0e24 to be followed by other vowels.
  if ((0xe30 <= ch && ch <= 0xe4D) && prev_ch == 0xe24) {
    return true;
  }
  return false;
}