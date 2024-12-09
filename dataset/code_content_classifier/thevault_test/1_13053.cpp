int VorbisSeek(void *datasource		/*this is a pointer to the data we passed into ov_open_callbacks (our SOggFile struct*/, 
                   ogg_int64_t offset	/*offset from the point we wish to seek to*/, 
                   int whence			/*where we want to seek to*/)
    {
        AudioAssetReader*	vorbisData;		// The data we passed in (for the typecast)
        
        // Get the data in the right format
        vorbisData = (AudioAssetReader*)datasource;
        vorbisData->Seek( offset, whence );
        
        return 0;
    }