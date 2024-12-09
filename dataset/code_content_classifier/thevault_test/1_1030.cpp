void musicBuffer::updateBufferStream(){
	ALint processed, state;


	alGetError();

	//check status of speakers
	alGetSourcei(se_source, AL_SOURCE_STATE, &state);
	//check amnt of buffers processed
	alGetSourcei(se_source, AL_BUFFERS_PROCESSED, &processed);

	if (alGetError() != AL_NO_ERROR)
	{
		throw("error checking music source state");
	}


	while (processed > 0){
		ALuint bufid;
		sf_count_t slen;

		alSourceUnqueueBuffers(se_source, 1, &bufid);
		processed--;

		//read the rest of the data, refill the buffers and re-queue
		slen = sf_readf_short(se_sndfile, se_membuf, b_samples);
		if (slen > 0){
			slen *= se_sfinfo.channels * (sf_count_t)sizeof(short);
			alBufferData(bufid, se_format, se_membuf, (ALsizei)slen,
				se_sfinfo.samplerate);
			alSourceQueueBuffers(se_source, 1, &bufid);
		}

		if (alGetError() != AL_NO_ERROR){
			throw("error buffering music data");
		}
	}

	//checking if source is underrun
	if (state != AL_PLAYING && state != AL_PAUSED){
		ALint queued;

		//if there isnt any buffers queued it means playback is done
		alGetSourcei(se_source, AL_BUFFERS_QUEUED, &queued);
		if (queued == 0)
			return;

		alSourcePlay(se_source);
		if (alGetError() != AL_NO_ERROR)
		{
			throw("error restarting music playback");
		}
	}

}