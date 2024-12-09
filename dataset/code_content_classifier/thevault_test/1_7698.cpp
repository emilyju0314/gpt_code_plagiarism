bool CodepageToWide(const std::string& encoded,
                    const char* codepage_name,
                    OnStringUtilConversionError::Type on_error,
                    std::wstring* wide) {
  wide->clear();

  UErrorCode status = U_ZERO_ERROR;
  UConverter* converter = ucnv_open(codepage_name, &status);
  if (!U_SUCCESS(status))
    return false;

  // The worst case is all the input characters are non-BMP (32-bit) ones.
  size_t uchar_max_length = encoded.length() * 2 + 1;

  UChar* uchar_dst;
#if defined(WCHAR_T_IS_UTF16)
  uchar_dst = WriteInto(wide, uchar_max_length);
#elif defined(WCHAR_T_IS_UTF32)
  // When wchar_t is wider than UChar (16 bits), convert into a temporary
  // UChar* buffer.
  std::vector<UChar> wide_uchar(uchar_max_length);
  uchar_dst = &wide_uchar[0];
#endif  // defined(WCHAR_T_IS_UTF32)

  // Setup our error handler.
  switch (on_error) {
    case OnStringUtilConversionError::FAIL:
      ucnv_setToUCallBack(converter, UCNV_TO_U_CALLBACK_STOP, 0,
                          NULL, NULL, &status);
      break;
    case OnStringUtilConversionError::SKIP:
      ucnv_setToUCallBack(converter, UCNV_TO_U_CALLBACK_SKIP, 0,
                          NULL, NULL, &status);
      break;
    default:
      NOTREACHED();
  }

  int actual_size = ucnv_toUChars(converter,
                                  uchar_dst,
                                  static_cast<int>(uchar_max_length),
                                  encoded.data(),
                                  static_cast<int>(encoded.length()),
                                  &status);
  ucnv_close(converter);
  if (!U_SUCCESS(status)) {
    wide->clear();  // Make sure the output is empty on error.
    return false;
  }

#ifdef WCHAR_T_IS_UTF32
  // When wchar_t is wider than UChar (16 bits), it's not possible to wind up
  // with any more wchar_t elements than UChar elements.  ucnv_toUChars
  // returns the number of UChar elements not including the NUL terminator, so
  // leave extra room for that.
  u_strToWCS(WriteInto(wide, actual_size + 1), actual_size + 1, &actual_size,
             uchar_dst, actual_size, &status);
  DCHECK(U_SUCCESS(status)) << "failed to convert UChar* to wstring";
#endif  // WCHAR_T_IS_UTF32

  wide->resize(actual_size);
  return true;
}