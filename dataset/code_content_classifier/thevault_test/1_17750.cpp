int RGBE_WritePixels(FILE *fp, float *data, int numpixels) {
    unsigned char rgbe[4];

    while (numpixels-- > 0) {
        float2rgbe(rgbe, data[RGBE_DATA_RED],
                   data[RGBE_DATA_GREEN], data[RGBE_DATA_BLUE]);
        data += RGBE_DATA_SIZE;
        if (fwrite(rgbe, sizeof(rgbe), 1, fp) < 1)
            return rgbe_error(rgbe_write_error, NULL);
    }
    return RGBE_RETURN_SUCCESS;
}