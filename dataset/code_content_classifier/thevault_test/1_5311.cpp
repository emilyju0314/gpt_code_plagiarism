ts::UString::size_type ts::UString::width() const
{
    if (empty()) {
        return 0;
    }
    else {
        // Ignore all combining diacritical and trailing surrogate characters and after the first one.
        // A diacritical character in first position does count since it cannot be combined with the previous one.
        // We do not check that surrogate pairs are correctly formed, we just skip trailing ones.
        size_type wid = 1;
        for (const UChar* p = data() + 1; p < last(); ++p) {
            if (!NoSpace(*p)) {
                ++wid;
            }
        }
        return wid;
    }
}