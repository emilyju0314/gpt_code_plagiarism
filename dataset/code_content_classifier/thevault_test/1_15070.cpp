static SAMPLETAG* SoundLoadDisk(const char* pFilename)
{
	Assert(pFilename != NULL);

	if(pFilename[0] == '\0') {
		SLOGA("SoundLoadDisk Error: pFilename is an empty string.");
		return NULL;
	}

	UINT8* inMemoryBuffer = NULL;
	SGPFile* hFile = NULL;
	SDL_RWops* rwOps = NULL;
	ma_decoder* decoder = NULL;

	try
	{
		auto isStreamed = TRUE;
		SAMPLETAG* s = SoundGetEmptySample();
		
		// if we don't have a sample slot
		if (s == NULL)
		{
			throw std::runtime_error("sound channels are full");
		}

		hFile = GCM->openGameResForReading(pFilename);
		rwOps = hFile->getRwOps();
		auto hFileLen = hFile->size();
		if (hFileLen <= SOUND_FILE_STREAMING_THRESHOLD) {
			// If the file length is below the streaming threshold we store the raw data in the inMemoryBuffer
			inMemoryBuffer = new UINT8[hFileLen]{};
			if (SDL_RWread(rwOps, inMemoryBuffer, sizeof(UINT8), hFileLen) != hFileLen) {
				throw std::runtime_error("Could not read the whole file");
			}
			SDL_RWclose(rwOps);
			rwOps = SDL_RWFromConstMem(inMemoryBuffer, hFileLen);
			hFile = NULL;
			isStreamed = FALSE;
		}

		// Initialize decoder to convert WAV/MP3/OGG data to raw sample data
		decoder = (ma_decoder*)ma_malloc(sizeof(ma_decoder), NULL);
		auto result = ma_decoder_init(MiniaudioReadProc, MiniaudioSeekProc, rwOps, &gTargetDecoderConfig, decoder);
		if (result != MA_SUCCESS) {
			throw std::runtime_error(ST::format("Error initializing sound decoder for file \"{}\"- {}", pFilename, ma_result_description(result)).c_str());
		}
		s->pFile = hFile;
		s->pInMemoryBuffer = inMemoryBuffer;
		s->pRWOps = rwOps;
		s->pDecoder = decoder;
		s->pName = pFilename;

		s->uiFlags |= SAMPLE_ALLOCATED;

		if (isStreamed) {
			SLOGD("SoundLoadDisk success creating file stream for \"%s\"", pFilename);
		} else {
			SLOGD("SoundLoadDisk success creating in-memory stream for \"%s\"", pFilename);
		}
		return s;
	}
	catch (const std::runtime_error& err)
	{
		SLOGE("SoundLoadDisk Error for \"%s\": %s", pFilename, err.what());
		// Clean up possible allocations
		if (hFile != NULL) {
			delete hFile;
		}
		if (rwOps != NULL) {
			SDL_FreeRW(rwOps);
		}
		if (decoder != NULL) {
			ma_free(decoder, NULL);
		}
		return NULL;
	}
}