Mix_Music* const ModuleAudio::LoadMusic(const char* path)
{
	Mix_Music* music;
	music = Mix_LoadMUS(path);

	for (int i = 0; i < MAX_AUDIOS; i++) {
		if (musics[i] == nullptr) {
			musics[i] = music;
			break;
		}
	}

	return music;
}