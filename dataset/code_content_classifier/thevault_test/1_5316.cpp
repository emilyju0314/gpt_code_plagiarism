void ts::UString::indent(size_t count)
{
    if (count > 0) {
        bool atbol = true; // at beginning of a line
        for (size_type i = 0; i < size(); ++i) {
            const UChar c = at(i);
            if (c == LINE_FEED) {
                atbol = true;
            }
            else if (atbol && !IsSpace(c)) {
                atbol = false;
                insert(i, count, SPACE);
                i += count;
            }
        }
    }
}