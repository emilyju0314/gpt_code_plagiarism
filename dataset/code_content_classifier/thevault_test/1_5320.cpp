void ts::UString::justifyRight(size_type wid, UChar pad, bool truncate, size_t spacesAfterPad)
{
    const size_type len = width();
    if (truncate && len > wid) {
        truncateWidth(wid, RIGHT_TO_LEFT);
    }
    else if (len < wid) {
        spacesAfterPad = std::min(spacesAfterPad, wid - len);
        insert(0, spacesAfterPad, SPACE);
        insert(0, wid - len - spacesAfterPad, pad);
    }
}