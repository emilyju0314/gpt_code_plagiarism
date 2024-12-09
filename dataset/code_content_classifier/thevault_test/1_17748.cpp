int RGBE_WriteHeader(FILE *fp, int width, int height, rgbe_header_info *info) {
    const char *programtype = "RGBE";

    if (info && (info->valid & RGBE_VALID_PROGRAMTYPE))
        programtype = info->programtype;
    if (fprintf(fp, "#?%s\n", programtype) < 0)
        return rgbe_error(rgbe_write_error, NULL);
    /* The #? is to identify file type, the programtype is optional. */
    if (info && (info->valid & RGBE_VALID_GAMMA)) {
        if (fprintf(fp, "GAMMA=%g\n", info->gamma) < 0)
            return rgbe_error(rgbe_write_error, NULL);
    }
    if (info && (info->valid & RGBE_VALID_EXPOSURE)) {
        if (fprintf(fp, "EXPOSURE=%g\n", info->exposure) < 0)
            return rgbe_error(rgbe_write_error, NULL);
    }
    if (fprintf(fp, "FORMAT=32-bit_rle_rgbe\n\n") < 0)
        return rgbe_error(rgbe_write_error, NULL);
    if (fprintf(fp, "-Y %d +X %d\n", height, width) < 0)
        return rgbe_error(rgbe_write_error, NULL);
    return RGBE_RETURN_SUCCESS;
}