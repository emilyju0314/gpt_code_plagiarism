ts::UString::size_type ts::UString::displayPosition(size_type count, size_type from, StringDirection direction) const
{
    const UChar* const base = data();
    switch (direction) {
        case LEFT_TO_RIGHT: {
            // Move forward.
            while (from < size() && count > 0) {
                if (!NoSpace(base[from])) {
                    --count;
                }
                ++from;
            }
            // Move after combining sequence.
            while (from < size() && NoSpace(base[from])) {
                ++from;
            }
            return std::min(from, size());
        }
        case RIGHT_TO_LEFT: {
            // Start at end of string, at worst.
            from = std::min(from, size());
            // Move backward.
            while (from > 0 && count > 0) {
                --from;
                if (!NoSpace(base[from])) {
                    --count;
                }
            }
            // Move at start of combining sequence.
            while (from > 0 && NoSpace(base[from])) {
                --from;
            }
            return from;
        }
        default: {
            // Should not get there.
            assert(false);
            return size();
        }
    }
}