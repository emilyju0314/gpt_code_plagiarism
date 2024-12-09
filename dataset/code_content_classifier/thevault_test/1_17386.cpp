Mix_Chunk* const ModuleAudio::LoadChunk(const char* path)
{
	int ret = 0;

	for (int i = 0; i < MAX_EFFECTS; i++) {
		if (effects[i] == nullptr) {
			effects[i] = Mix_LoadWAV(path);
			ret = i;
			break;
		}
	}
	

	return effects[ret];
}