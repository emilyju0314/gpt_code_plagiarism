VidStream* mpegVidRsrc( TimeStamp time_stamp, VidStream* vid_stream, int first )
{
    unsigned int data;
    int i, status;

    /*
    * If called for the first time, find start code, make sure it is a
    * sequence start code.
    */

    if( first )
    {
        vid_stream->num_left       = 0;
        vid_stream->leftover_bytes = 0;
        vid_stream->Parse_done     = FALSE;

        next_start_code(vid_stream);  /* sets curBits */
        show_bits32(data);
        if( data != SEQ_START_CODE )
        {
            vid_stream->_smpeg->SetError("Invalid sequence in video stream");
            /* Let whoever called NewVidStream call DestroyVidStream - KR
            DestroyVidStream( vid_stream );
            */
            return 0;
        }
    }
    else
    {
#ifdef UTIL2
        vid_stream->curBits = *vid_stream->buffer << vid_stream->bit_offset;
#else
        vid_stream->curBits = *vid_stream->buffer;
#endif
    }

    /* Get next 32 bits (size of start codes). */

    show_bits32(data);

    /* Check for end of file */
    if(vid_stream->EOF_flag)
    {
        /* Set ended flag first so that ExecuteDisplay may check it. */

        vid_stream->film_has_ended = TRUE;

        if( vid_stream->future != NULL )
        {
            vid_stream->current = vid_stream->future;
            vid_stream->_smpeg->ExecuteDisplay( vid_stream );
        }

#ifdef ANALYSIS
        PrintAllStats(vid_stream);
#endif
        goto done;
    }

    /*
    * Process according to start code (or parse macroblock if not a start code
    * at all).
    */

    switch( data )
    {
    case SEQ_END_CODE:
    case 0x000001b9:   /*  handle ISO_11172_END_CODE too */

#ifdef VERBOSE_DEBUG
        printf("SEQ_END_CODE\n");
#endif
        flush_bits32;
        goto done;
        break;

    case SEQ_START_CODE:

        /* Sequence start code. Parse sequence header. */

#ifdef VERBOSE_DEBUG
        printf("SEQ_START_CODE\n");
#endif
        if( ParseSeqHead( vid_stream ) != PARSE_OK )
        {
            fprintf( stderr, "mpegVidRsrc ParseSeqHead\n" );
            goto error;
        }

        /*
        * Return after sequence start code so that application above can use
        * info in header.
        */
        goto done;


    case GOP_START_CODE:

        /* Group of Pictures start code. Parse gop header. */

#ifdef VERBOSE_DEBUG
        printf("GOP_START_CODE\n");
#endif
        if( ParseGOP(vid_stream) != PARSE_OK )
        {
            fprintf( stderr, "mpegVidRsrc ParseGOP\n" );
            goto error;
        }
	/* need adjust current_frame (after Seek) */
	if (vid_stream->need_frameadjust) {
		int prev;
		prev = vid_stream->totNumFrames;
		vid_stream->current_frame = (int)
		(
		vid_stream->group.tc_hours * 3600 * vid_stream->rate_deal +
		vid_stream->group.tc_minutes * 60 * vid_stream->rate_deal +
		vid_stream->group.tc_seconds * vid_stream->rate_deal +
		vid_stream->group.tc_pictures);
		vid_stream->need_frameadjust=false;
		vid_stream->totNumFrames=vid_stream->current_frame;
#if 0
	printf("Adjusted Frame %d -> %d\n",prev,vid_stream->current_frame);
#endif
	}
        goto done;


    case PICTURE_START_CODE:

        /* Picture start code. Parse picture header and first slice header. */

#ifdef VERBOSE_DEBUG
        printf("PICTURE_START_CODE\n");
#endif
	if (vid_stream->timestamp_mark < vid_stream->buffer
	    && !vid_stream->timestamp_used){
	  vid_stream->timestamp_used = true;
	  status = ParsePicture( vid_stream, vid_stream->timestamp );
	} else
	  status = ParsePicture( vid_stream, -1);

        if((vid_stream->picture.code_type == B_TYPE) &&
            vid_stream->_skipFrame && (vid_stream->_jumpFrame < 0))
        {
            status = SKIP_PICTURE;
        }
	
	if( !vid_stream->current )
	    status = SKIP_PICTURE;

        if( status == SKIP_PICTURE )
        {
            //fprintf( stderr, "%d\r", vid_stream->totNumFrames );

            next_start_code( vid_stream );

            while( ! next_bits( 32, PICTURE_START_CODE, vid_stream ) )
            {
                if( next_bits( 32, GOP_START_CODE, vid_stream) )
                    break;
                else if( next_bits( 32, SEQ_END_CODE, vid_stream ) )
                    break;

                flush_bits( 24 );
                next_start_code( vid_stream );
            }

            vid_stream->_smpeg->timeSync( vid_stream );
            goto done;
        }
        else if( status != PARSE_OK )
        {
            fprintf( stderr, "mpegVidRsrc ParsePicture\n" );
            goto error;
        }


        if( ParseSlice(vid_stream) != PARSE_OK )
        {
            fprintf( stderr, "mpegVidRsrc ParseSlice\n" );
            goto error;
        }
        break;


    case SEQUENCE_ERROR_CODE:

#ifdef VERBOSE_DEBUG
        printf("SEQUENCE_ERROR_CODE\n");
#endif
        flush_bits32;
        next_start_code(vid_stream);
        goto done;


    default:

	/* No base picture for decoding */
	if( !vid_stream->current )
	{
	    flush_bits32;
	    next_start_code(vid_stream);
#ifdef VERBOSE_DEBUG
            printf("No base picture, flushing to next start code\n");
#endif
	    goto done;
	}

        /* Check for slice start code. */

        if( (data >= SLICE_MIN_START_CODE) && (data <= SLICE_MAX_START_CODE) )
        {
            /* Slice start code. Parse slice header. */
            if( ParseSlice(vid_stream) != PARSE_OK )
            {
                fprintf( stderr, "mpegVidRsrc ParseSlice\n" );
                goto error;
            }
        }
#ifdef VERBOSE_DEBUG
        else
            fprintf(stderr, "Unknown data [%x] - not slice start code!\n", data);
#endif
        break;
    }


    /* Parse next MB_QUANTUM macroblocks. */

    for( i = 0; i < MB_QUANTUM; i++ )
    {
        /* Check to see if actually a startcode and not a macroblock. */

        if( ! next_bits( 23, 0x00000000, vid_stream ) &&
            ! vid_stream->film_has_ended )
        {
            /* Not start code. Parse Macroblock. */

            if (ParseMacroBlock(vid_stream) != PARSE_OK)
            {
#ifdef VERBOSE_WARNINGS
                fprintf( stderr, "mpegVidRsrc ParseMacroBlock\n" );
#endif
                goto error;
            }
        }
        else
        {
            /* Not macroblock, actually start code. Get start code. */

            next_start_code(vid_stream);
            show_bits32(data);

            /*
            * If start code is outside range of slice start codes, frame is
            * complete, display frame.
            */

            if( ((data<SLICE_MIN_START_CODE) || (data>SLICE_MAX_START_CODE)) &&
                (data != SEQUENCE_ERROR_CODE) )
            {
                DoPictureDisplay( vid_stream );
            }
            goto done;
        }
    }


    /* Check if we just finished a picture on the MB_QUANTUMth macroblock */

    if( next_bits( 23, 0x00000000, vid_stream ) )
    {
        next_start_code(vid_stream);
        show_bits32(data);
        if( (data < SLICE_MIN_START_CODE) || (data > SLICE_MAX_START_CODE) )
        {
            DoPictureDisplay( vid_stream );
        }
    }

    goto done;

error:

    next_start_code( vid_stream );
    return vid_stream;

done:

    return vid_stream;
}