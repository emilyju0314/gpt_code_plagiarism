bool ValidateGrapheme::IsBadlyFormed(char32 prev_ch, char32 ch) {
  // Reject badly formed Indic vowels.
  if (IsBadlyFormedIndicVowel(prev_ch, ch)) {
    if (report_errors_) {
      tprintf("Badly formed Indic vowel sequence:0x%x 0x%x\n", prev_ch, ch);
    }
    return true;
  }
  if (IsBadlyFormedThai(prev_ch, ch)) {
    if (report_errors_) {
      tprintf("Badly formed Thai:0x%x 0x%x\n", prev_ch, ch);
    }
    return true;
  }
  return false;
}