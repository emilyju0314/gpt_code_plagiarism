static void DoPictureDisplay( VidStream *vid_stream )
{
#ifdef ANALYSIS
    EndTime();
    stat_a[0].totsize += bitCountRead() - pictureSizeCount;
#ifdef SHOWEACHFLAG
    PrintOneStat();
#endif
    CollectStats();
#endif

    /* Update past and future references if needed. */

    if( (vid_stream->picture.code_type == I_TYPE) ||
        (vid_stream->picture.code_type == P_TYPE) )
    {
        if( vid_stream->future == NULL )
        {
            vid_stream->future = vid_stream->current;
            vid_stream->future->locked |= FUTURE_LOCK;
        }
        else
        {
            if( vid_stream->past != NULL )
            {
                vid_stream->past->locked &= ~PAST_LOCK;
            }
            vid_stream->past = vid_stream->future;
            vid_stream->past->locked &= ~FUTURE_LOCK;
            vid_stream->past->locked |= PAST_LOCK;
            vid_stream->future = vid_stream->current;
            vid_stream->future->locked |= FUTURE_LOCK;
            vid_stream->current = vid_stream->past;

            vid_stream->_smpeg->ExecuteDisplay( vid_stream );
        }
    }
    else
    {
        vid_stream->_smpeg->ExecuteDisplay( vid_stream );
    }
}