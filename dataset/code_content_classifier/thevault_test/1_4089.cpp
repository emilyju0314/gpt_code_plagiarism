int Decoder::impl::queue_page(ogg_page *page) {
        if (theoraHeaders) ogg_stream_pagein(&theoraStreamState, page);
        if (vorbisHeaders) ogg_stream_pagein(&vorbisStreamState, page);
#ifdef OPUS
        if (opusHeaders) ogg_stream_pagein(&opusStreamState, page);
#endif
        if (skeletonHeaders) ogg_stream_pagein(&skeletonStreamState, page);
        return 0;
    }