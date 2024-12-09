int RGBE_ReadPixels(FILE *fp, float *data, int numpixels) {
    unsigned char rgbe[4];

    while (numpixels-- > 0) {
        if (fread(rgbe, sizeof(rgbe), 1, fp) < 1)
            return rgbe_error(rgbe_read_error, NULL);
        rgbe2float(&data[RGBE_DATA_RED], &data[RGBE_DATA_GREEN],
                   &data[RGBE_DATA_BLUE], rgbe);
        data += RGBE_DATA_SIZE;
    }
    return RGBE_RETURN_SUCCESS;
}