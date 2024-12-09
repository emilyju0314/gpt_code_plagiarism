void ts::UString::justifyCentered(size_type wid, UChar pad, bool truncate, size_t spacesAroundPad)
{
    const size_type len = width();
    if (truncate && len > wid) {
        truncateWidth(wid);
    }
    else if (len < wid) {
        const size_type leftSize = (wid - len) / 2;
        const size_type leftSpaces = std::min(spacesAroundPad, leftSize);
        const size_type rightSize = wid - len - leftSize;
        const size_type rightSpaces = std::min(spacesAroundPad, rightSize);
        insert(0, leftSpaces, SPACE);
        insert(0, leftSize - leftSpaces, pad);
        append(rightSpaces, SPACE);
        append(rightSize - rightSpaces, pad);
    }
}