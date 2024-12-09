int check_media_iterator_next(JaniceMediaIterator it)
{
    JaniceImage image = nullptr;
    uint32_t frame, frame_count = 0;

    while (true) {
        JaniceError err = it->next(it, &image);

        JaniceError expected = JANICE_SUCCESS;
        ++frame_count;
        
        // On the last frame we loop back to the beginning
        if (frame_count == 90) {
            expected = JANICE_MEDIA_AT_END;
            frame_count = 0;
        }

        CHECK(err == expected,
            "Next should return JANICE_SUCCESS except for on the last frame",
            []() {})

        auto cleanup = [&]() {
            it->free_image(&image);
        };

        // Next, query the iterator for it's internal frame count
        JANICE_CALL(it->tell(it, &frame),
                    // Cleanup
                    cleanup)

        cleanup();

        if (expected == JANICE_MEDIA_AT_END)
            break;
    }

    return 0;
}