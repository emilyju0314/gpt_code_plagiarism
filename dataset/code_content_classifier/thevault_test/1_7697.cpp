bool WideToCodepage(const std::wstring& wide,
                    const char* codepage_name,
                    OnStringUtilConversionError::Type on_error,
                    std::string* encoded) {
  encoded->clear();

  UErrorCode status = U_ZERO_ERROR;
  UConverter* converter = ucnv_open(codepage_name, &status);
  if (!U_SUCCESS(status))
    return false;

  const UChar* uchar_src;
  int uchar_len;
#if defined(WCHAR_T_IS_UTF16)
  uchar_src = wide.c_str();
  uchar_len = static_cast<int>(wide.length());
#elif defined(WCHAR_T_IS_UTF32)
  // When wchar_t is wider than UChar (16 bits), transform |wide| into a
  // UChar* string.  Size the UChar* buffer to be large enough to hold twice
  // as many UTF-16 code points as there are UTF-16 characters, in case each
  // character translates to a UTF-16 surrogate pair, and leave room for a NUL
  // terminator.
  std::vector<UChar> wide_uchar(wide.length() * 2 + 1);
  u_strFromWCS(&wide_uchar[0], wide_uchar.size(), &uchar_len,
               wide.c_str(), wide.length(), &status);
  uchar_src = &wide_uchar[0];
  DCHECK(U_SUCCESS(status)) << "failed to convert wstring to UChar*";
#endif  // defined(WCHAR_T_IS_UTF32)

  int encoded_max_length = UCNV_GET_MAX_BYTES_FOR_STRING(uchar_len,
    ucnv_getMaxCharSize(converter));
  encoded->resize(encoded_max_length);

  // Setup our error handler.
  switch (on_error) {
    case OnStringUtilConversionError::FAIL:
      ucnv_setFromUCallBack(converter, UCNV_FROM_U_CALLBACK_STOP, 0,
                            NULL, NULL, &status);
      break;
    case OnStringUtilConversionError::SKIP:
      ucnv_setFromUCallBack(converter, UCNV_FROM_U_CALLBACK_SKIP, 0,
                            NULL, NULL, &status);
      break;
    default:
      NOTREACHED();
  }

  // ucnv_fromUChars returns size not including terminating null
  int actual_size = ucnv_fromUChars(converter, &(*encoded)[0],
    encoded_max_length, uchar_src, uchar_len, &status);
  encoded->resize(actual_size);
  ucnv_close(converter);
  if (U_SUCCESS(status))
    return true;
  encoded->clear();  // Make sure the output is empty on error.
  return false;
}