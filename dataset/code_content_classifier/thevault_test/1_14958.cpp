static void MusicStop(void)
{
	SLOGD("Music Stop %d %d %d", fMusicPlaying, uiMusicHandle, gubMusicMode);
	if(!fMusicPlaying)
	{
		return;
	}

	if(uiMusicHandle!=NO_SAMPLE)
	{
		SoundStop(uiMusicHandle);
		uiMusicHandle = NO_SAMPLE;
	}
	else if(!gfMusicEnded)
	{
		SLOGW("expected either music data or the end of the music (mode=%d, handle=%d, ended=%d)", gubMusicMode, uiMusicHandle, gfMusicEnded);
	}
	fMusicPlaying = FALSE;
}