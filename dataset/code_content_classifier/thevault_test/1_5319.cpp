void ts::UString::justifyLeft(size_type wid, UChar pad, bool truncate, size_t spacesBeforePad)
{
    const size_type len = width();
    if (truncate && len > wid) {
        truncateWidth(wid);
    }
    else if (len < wid) {
        spacesBeforePad = std::min(spacesBeforePad, wid - len);
        append(spacesBeforePad, SPACE);
        append(wid - len - spacesBeforePad, pad);
    }
}