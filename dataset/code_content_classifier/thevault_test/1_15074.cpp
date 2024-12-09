static BOOLEAN SoundInitHardware(void)
{
	try {
		if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
			throw std::runtime_error(ST::format("SDL_InitSubSystem returned error: {}", SDL_GetError()).c_str());
		}

		gTargetAudioSpec.freq     = SOUND_FREQ;
		gTargetAudioSpec.format   = SOUND_FORMAT;
		gTargetAudioSpec.channels = SOUND_CHANNELS;
		gTargetAudioSpec.samples  = SOUND_SAMPLES;
		gTargetAudioSpec.callback = SoundCallback;
		gTargetAudioSpec.userdata = NULL;

		if (SDL_OpenAudio(&gTargetAudioSpec, NULL) != 0) {
			throw std::runtime_error(ST::format("SDL_OpenAudio returned error: {}", SDL_GetError()).c_str());
		}

		gTargetDecoderConfig = ma_decoder_config_init(SOUND_MA_SOUND_FORMAT, gTargetAudioSpec.channels, gTargetAudioSpec.freq);

		std::fill(std::begin(pSoundList), std::end(pSoundList), SOUNDTAG{});
		for(auto channel = std::begin(pSoundList); channel != std::end(pSoundList); ++channel) {
			channel->pRingBuffer = (ma_pcm_rb*)ma_malloc(sizeof(ma_pcm_rb), NULL);
			ma_result result = ma_pcm_rb_init(SOUND_MA_SOUND_FORMAT, SOUND_CHANNELS, SOUND_RING_BUFFER_SIZE, NULL, NULL, channel->pRingBuffer);
			if (result != MA_SUCCESS) {
				throw std::runtime_error(ST::format(
					"ma_pcm_rb_init for channel {} returned error: {}",
					channel - pSoundList,
					ma_result_description(result)
				).c_str());
			}
		}

		fShutdownBufferServiceThread = FALSE;
		bufferServiceThread = SDL_CreateThread(SoundServiceBuffers, "SoundManBufferServiceThread", (void *)NULL);
		if (bufferServiceThread == NULL) {
			throw std::runtime_error(ST::format("SDL_CreateThread for SoundManBufferServiceThread returned error: {}", SDL_GetError()).c_str());
		}

		SDL_PauseAudio(0);
		return TRUE;
		
	} catch (const std::runtime_error& err) {
		SLOGE(ST::format(
			"SoundInitHardware: {}",
			err.what()
		).c_str());
		SoundShutdownHardware();
		return FALSE;
	}
}