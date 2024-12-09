ts::UString ts::UString::Float(double value, size_type width, size_type precision, bool force_sign)
{
    // Slightly oversized buffer.
    char valueStr[10 + std::numeric_limits<double>::digits - std::numeric_limits<double>::min_exponent];
    if (force_sign) {
        std::snprintf(valueStr, sizeof(valueStr), "%+*.*f", int(width), int(precision), value);
    }
    else {
        std::snprintf(valueStr, sizeof(valueStr), "%*.*f", int(width), int(precision), value);
    }
    return FromUTF8(valueStr);
}