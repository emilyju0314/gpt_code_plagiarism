asynStatus NDFileTIFF::populateAsciiFieldInfo(TIFFFieldInfo *fieldInfo, int fieldTag, const char *tagName)
{
    asynStatus status = asynSuccess;

    if (fieldInfo) {
        fieldInfo->field_tag = fieldTag;
        fieldInfo->field_readcount = 1;
        fieldInfo->field_writecount = 1;
        fieldInfo->field_type = TIFF_ASCII;
        fieldInfo->field_bit = FIELD_CUSTOM;
        fieldInfo->field_oktochange = 1;
        fieldInfo->field_passcount = 0;
        if (tagName) {
            fieldInfo->field_name = (char *)tagName;
        } else {
            status = asynError;
        }
    } else {
        status = asynError;
    }
  
    return status;

}