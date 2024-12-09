static SAMPLETAG* SoundLoadBuffer(UINT8* inMemoryBuffer, UINT32 uiBufferSize, ma_format format, UINT32 channels, int freq)
{
	try {
		SAMPLETAG* s = SoundGetEmptySample();

		// if we don't have a sample slot
		if (s == NULL)
		{
			throw std::runtime_error("sound channels are full");
		}

		ma_data_converter_config config = ma_data_converter_config_init(
			format,
			SOUND_MA_SOUND_FORMAT,
			channels,
			gTargetAudioSpec.channels,
			freq,
			gTargetAudioSpec.freq
		);
		ma_data_converter* converter = (ma_data_converter*)ma_malloc(sizeof(ma_data_converter), NULL);
		auto result = ma_data_converter_init(&config, converter);
		if (result != MA_SUCCESS) {
			throw std::runtime_error(ST::format("ma_data_converter_init: {}", ma_result_description(result)).c_str());
		}

		s->pInMemoryBuffer = inMemoryBuffer;
		s->uiBufferSize = uiBufferSize;
		s->pDataConverter = converter;
		s->eInMemoryFormat = format;
		s->uiInMemoryChannels = channels;

		s->uiFlags |= SAMPLE_ALLOCATED;

		SLOGD("SoundLoadBuffer Success");
		return s;
	} catch (const std::runtime_error& err) {
		SLOGE("SoundLoadBuffer Error: {}", err.what());
		return NULL;
	}
}