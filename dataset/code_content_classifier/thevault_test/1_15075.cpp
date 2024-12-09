static void SoundShutdownHardware(void)
{
	if (bufferServiceThread != NULL) {
		{
			std::lock_guard<std::mutex> lk(mutexBuffersNeedService);
			fShutdownBufferServiceThread = true;
		}
		conditionBuffersNeedService.notify_one();
		int returnValue = 1;
		SDL_WaitThread(bufferServiceThread, &returnValue);
		if (returnValue != 0) {
			SLOGE("SoundManBufferServiceThread exited with code: %d", returnValue);
		}
	}
	for(auto channel = std::begin(pSoundList); channel != std::end(pSoundList); ++channel) {
		if (channel->pRingBuffer != NULL) {
			ma_pcm_rb_uninit(channel->pRingBuffer);
			ma_free(channel->pRingBuffer, NULL);
			channel->pRingBuffer = NULL;
		}
	}
	if (SDL_WasInit(SDL_INIT_AUDIO) != 0) {
		SDL_QuitSubSystem(SDL_INIT_AUDIO);
	}
}