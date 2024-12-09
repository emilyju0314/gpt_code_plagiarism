bool
MPEGvideo:: SetDisplay(MPEG_DisplayCallback callback, void *data, SDL_mutex *lock)
{
    _callback = callback;
    _callback_data = data;
    _callback_lock = lock;

    if ( !_stream ) {
        decodeInitTables();

        InitCrop();
        InitIDCT();

        _stream = NewVidStream( (unsigned int) BUF_LENGTH );
        if( _stream ) {
            _stream->_smpeg        = this;
            _stream->ditherType    = FULL_COLOR_DITHER;

            if( mpegVidRsrc( 0, _stream, 1 ) == NULL ) {
                SetError("Not an MPEG video stream");
                return false;
            }
        }

        if ( ! InitPictImages(_stream, _w, _h) )
            return false;
    }
    return true;
}