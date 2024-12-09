int VorbisClose(void *datasource /*this is a pointer to the data we passed into ov_open_callbacks (our SOggFile struct*/)
    {
        // This file is called when we call ov_close.  If we wanted, we could free our memory here, but
        // in this case, we will free the memory in the main body of the program, so dont do anything
        AudioAssetReader*	vorbisData;		// The data we passed in (for the typecast)
        
        // Get the data in the right format
        vorbisData = (AudioAssetReader*)datasource;
        
        delete vorbisData;
        return 1;
    }