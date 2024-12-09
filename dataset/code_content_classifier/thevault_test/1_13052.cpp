size_t VorbisRead(void *ptr			/* ptr to the data that the vorbis files need*/, 
                      size_t byteSize	/* how big a byte is*/, 
                      size_t sizeToRead /* How much we can read*/, 
                      void *datasource	/* this is a pointer to the data we passed into ov_open_callbacks (our SOggFile struct*/)
    {
        AudioAssetReader*	vorbisData;			// Our vorbis data, for the typecast
        
        // Get the data in the right format
        vorbisData = (AudioAssetReader*)datasource;
        
        return vorbisData->Read(ptr,sizeToRead*byteSize);
    }