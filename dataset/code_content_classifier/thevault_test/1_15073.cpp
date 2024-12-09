static void SoundFreeSample(SAMPLETAG* s)
{
	if (!(s->uiFlags & SAMPLE_ALLOCATED)) return;

	SLOGD("SoundFreeSample: Freeing sample %d", s - pSampleList);

	assert(s->uiInstances == 0);

	if (s->pDecoder != NULL) {
		ma_decoder_uninit(s->pDecoder);
		ma_free(s->pDecoder, NULL);
	}
	if (s->pDataConverter != NULL) {
		ma_data_converter_uninit(s->pDataConverter);
		ma_free(s->pDataConverter, NULL);
	}
	if (s->pRWOps != NULL) {
		SDL_RWclose(s->pRWOps);
	}
	// Note: s->pFile is closed and deleted by SDL_RWclose implicitly, but s->pInMemoryBuffer is not
	if (s->pInMemoryBuffer != NULL) {
		delete[] s->pInMemoryBuffer;
	}
	*s = SAMPLETAG{};
}