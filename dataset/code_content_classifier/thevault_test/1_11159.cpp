bool UnicharCompress::DecomposeHangul(int unicode, int *leading, int *vowel, int *trailing) {
  if (unicode < kFirstHangul) {
    return false;
  }
  int offset = unicode - kFirstHangul;
  if (offset >= kNumHangul) {
    return false;
  }
  const int kNCount = kVCount * kTCount;
  *leading = offset / kNCount;
  *vowel = (offset % kNCount) / kTCount;
  *trailing = offset % kTCount;
  return true;
}