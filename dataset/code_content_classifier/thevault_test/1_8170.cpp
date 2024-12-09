inline strings_internal::AlphaNumBuffer<numbers_internal::kSixDigitsToBufferSize> SixDigits(double d) {
  strings_internal::AlphaNumBuffer<numbers_internal::kSixDigitsToBufferSize> result{0};
  result.size = numbers_internal::SixDigitsToBuffer(d, &result.data[0]);
  return result;
}