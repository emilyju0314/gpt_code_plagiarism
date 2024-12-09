static BOOLEAN SoundStopChannel(SOUNDTAG* channel)
{
	if (!fSoundSystemInit) return FALSE;

	if (channel->pSample == NULL) return FALSE;

	STLOGD("stopping channel channel {}", (channel - pSoundList));
	channel->State = CHANNEL_STOP;
	return TRUE;
}