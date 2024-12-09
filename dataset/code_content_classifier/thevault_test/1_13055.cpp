long VorbisTell(void *datasource /*this is a pointer to the data we passed into ov_open_callbacks (our SOggFile struct*/)
    {
        AudioAssetReader*	vorbisData;		// The data we passed in (for the typecast)
        
        // Get the data in the right format
        vorbisData = (AudioAssetReader*)datasource;
        
        // We just want to tell the vorbis libs how much we have read so far
        return vorbisData->Tell();
    }