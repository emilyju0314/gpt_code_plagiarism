MEDIA_PARSER::MEDIA_TYPE MediaParser::GetMediaType(const XString& type)
{
    if(type == STRING_H264 || type == MEDIA_TYPE_STRING_H264 || type == MIME_TYPE_H264 || type == MIME_TYPE_H264_NSD)
        return MEDIA_TYPE_H264;

    if(type.ToUpper() == STRING_MPEG4 || type == MEDIA_TYPE_STRING_MPEG4 || type == MIME_TYPE_MPEG4 || type == MIME_TYPE_MPEG4_NSD)
        return MEDIA_TYPE_MPEG4;

    // G711
    if(type == STRING_PCM_MULAW || type.ToUpper() == MEDIA_TYPE_STRING_PCM_MULAW || type == MIME_TYPE_PCM_MULAW)
        return MEDIA_TYPE_PCM_MULAW;

    if(type == STRING_MJPEG || type == MIME_TYPE_MJPEG) //MEDIA_TYPE_STRING_MJPEG is the same as STRING_MJPEG.
        return MEDIA_TYPE_MJPEG;

    if(type == STRING_LINEAR_16BIT || type == MIME_TYPE_LINEAR_16BIT)  //MEDIA_TYPE_STRING_LINEAR_16BIT is the same as STRING_LINEAR_16BIT.
        return MEDIA_TYPE_LINEAR_16BIT;

    if(type == STRING_META)  //MEDIA_TYPE_STRING_META is the same as STRING_META.
        return MEDIA_TYPE_META;

    return MEDIA_TYPE_UNKNOWN;
}