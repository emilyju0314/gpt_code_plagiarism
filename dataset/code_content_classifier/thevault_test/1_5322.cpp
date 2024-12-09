void ts::UString::justify(const UString& right, size_type wid, UChar pad, size_t spacesAroundPad)
{
    const size_type len = this->width() + right.width();
    if (len < wid) {
        const size_t padWidth = wid - len;
        const size_t leftSpaces = std::min(spacesAroundPad, padWidth);
        const size_t rightSpaces = std::min(spacesAroundPad, padWidth - leftSpaces);
        append(leftSpaces, SPACE);
        append(padWidth - rightSpaces - leftSpaces, pad);
        append(rightSpaces, SPACE);
    }
    append(right);
}