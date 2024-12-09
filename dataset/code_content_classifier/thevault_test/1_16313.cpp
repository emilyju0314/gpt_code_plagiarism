Any MkFromSuffixedHexPtr(const HexPtr hex) {
  Any result;

  const unsigned length = hex.str->length();
  if ((length == 2*kDigestSizes[kMd5]) || (length == 2*kDigestSizes[kMd5] + 1))
  {
    Suffix suffix = (length == 2*kDigestSizes[kMd5] + 1) ?
      *(hex.str->rbegin()) : kSuffixNone;
    result = Any(kMd5, hex, suffix);
  }
  if ((length == 2*kDigestSizes[kSha1]) ||
      (length == 2*kDigestSizes[kSha1] + 1))
  {
    Suffix suffix = (length == 2*kDigestSizes[kSha1] + 1) ?
      *(hex.str->rbegin()) : kSuffixNone;
    result = Any(kSha1, hex, suffix);
  }
  if ((length == 2*kDigestSizes[kRmd160] + kAlgorithmIdSizes[kRmd160]) ||
      (length == 2*kDigestSizes[kRmd160] + kAlgorithmIdSizes[kRmd160] + 1))
  {
    Suffix suffix =
      (length == 2*kDigestSizes[kRmd160] + kAlgorithmIdSizes[kRmd160] + 1)
        ? *(hex.str->rbegin())
        : kSuffixNone;
    result = Any(kRmd160, hex, suffix);
  }
  if ((length == 2*kDigestSizes[kShake128] + kAlgorithmIdSizes[kShake128]) ||
      (length == 2*kDigestSizes[kShake128] + kAlgorithmIdSizes[kShake128] + 1))
  {
    Suffix suffix =
      (length == 2*kDigestSizes[kShake128] + kAlgorithmIdSizes[kShake128] + 1)
        ? *(hex.str->rbegin())
        : kSuffixNone;
    result = Any(kShake128, hex, suffix);
  }

  return result;
}