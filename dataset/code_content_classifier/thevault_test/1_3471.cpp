status_t OMXCameraAdapter::encodeImageCodingFormatCap(OMX_IMAGE_CODINGTYPE format,
        const CapCodingFormat *cap,
        size_t capCount,
        char * buffer) {

    status_t ret = NO_ERROR;

    LOG_FUNCTION_NAME;

    if ( ( NULL == buffer ) || ( NULL == cap ) ) {
        CAMHAL_LOGEA("Invalid input arguments");
        ret = -EINVAL;
    }

    if ( NO_ERROR == ret ) {
        for ( unsigned int i = 0 ; i < capCount ; i++ ) {
            if ( format == cap[i].imageCodingFormat ) {
                if (buffer[0] != '\0') {
                    strncat(buffer, PARAM_SEP, ((((int)MAX_PROP_VALUE_LENGTH - 1 - (int)strlen(buffer)) < 0) ? 0 : (MAX_PROP_VALUE_LENGTH - 1 - strlen(buffer))));
                }
                strncat(buffer, cap[i].param,  ((((int)MAX_PROP_VALUE_LENGTH - 1 - (int)strlen(buffer)) < 0) ? 0 : (MAX_PROP_VALUE_LENGTH - 1 - strlen(buffer))));
            }
        }
    }

    LOG_FUNCTION_NAME_EXIT;

    return ret;
}