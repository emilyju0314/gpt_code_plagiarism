uint16_t DOSDate(tm* t)
    {
        return static_cast<uint16_t>(
            ((t->tm_year - 80) << 9)
            | (t->tm_mon << 5)
            | t->tm_mday);
    }