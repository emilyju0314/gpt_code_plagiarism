void ts::UString::truncateWidth(size_type maxWidth, StringDirection direction)
{
    switch (direction) {
        case LEFT_TO_RIGHT: {
            const size_t pos = displayPosition(maxWidth, 0, LEFT_TO_RIGHT);
            resize(pos);
            break;
        }
        case RIGHT_TO_LEFT: {
            const size_t pos = displayPosition(maxWidth, length(), RIGHT_TO_LEFT);
            erase(0, pos);
            break;
        }
        default: {
            // Should not get there.
            assert(false);
        }
    }
}