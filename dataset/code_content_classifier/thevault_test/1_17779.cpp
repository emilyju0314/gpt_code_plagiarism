std::u16string applyArabicShaping(const std::u16string& input) {
    UErrorCode errorCode = U_ZERO_ERROR;

    const int32_t outputLength =
        u_shapeArabic(mbgl::utf16char_cast<const UChar*>(input.c_str()), static_cast<int32_t>(input.size()), nullptr, 0,
                      (U_SHAPE_LETTERS_SHAPE & U_SHAPE_LETTERS_MASK) |
                          (U_SHAPE_TEXT_DIRECTION_LOGICAL & U_SHAPE_TEXT_DIRECTION_MASK),
                      &errorCode);

    // Pre-flighting will always set U_BUFFER_OVERFLOW_ERROR
    errorCode = U_ZERO_ERROR;

    std::u16string outputText(outputLength, 0);

    u_shapeArabic(mbgl::utf16char_cast<const UChar*>(input.c_str()), static_cast<int32_t>(input.size()), mbgl::utf16char_cast<UChar*>(&outputText[0]), outputLength,
                  (U_SHAPE_LETTERS_SHAPE & U_SHAPE_LETTERS_MASK) |
                      (U_SHAPE_TEXT_DIRECTION_LOGICAL & U_SHAPE_TEXT_DIRECTION_MASK),
                  &errorCode);

    // If the algorithm fails for any reason, fall back to non-transformed text
    if (U_FAILURE(errorCode))
        return input;

    return outputText;
}