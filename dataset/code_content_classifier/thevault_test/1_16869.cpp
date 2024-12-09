int expected_frame_colors(int frame_number, uint8_t* r, uint8_t* g, uint8_t* b)
{
    // past end of video 
    if (frame_number >= 90)
        return 0;

    // solid colors, repeated for 10 frames each 
    int idx = frame_number / 10;

    *r = frame_color_lookup[idx][0];
    *g = frame_color_lookup[idx][1];
    *b = frame_color_lookup[idx][2];

    return 1;
}