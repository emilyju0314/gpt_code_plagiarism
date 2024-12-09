int check_media_iterator_seek(JaniceMediaIterator it)
{
    uint32_t frame;

    // Let's do some random seeks
    CHECKED_RANDOM_SEEK( 0, frame)
    CHECKED_RANDOM_SEEK( 8, frame)
    CHECKED_RANDOM_SEEK(15, frame)
    CHECKED_RANDOM_SEEK(33, frame)
    CHECKED_RANDOM_SEEK(47, frame)
    CHECKED_RANDOM_SEEK(58, frame)
    CHECKED_RANDOM_SEEK(74, frame)
    CHECKED_RANDOM_SEEK(89, frame)

    // And let's do an out of bounds seek
    CHECK(it->seek(it, 100) == JANICE_OUT_OF_BOUNDS_ACCESS,
          "Out of bounds seek returned incorrect error",
          [](){})

    return 0;
}