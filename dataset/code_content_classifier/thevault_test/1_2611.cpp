Effect* SoundManager::ResourceLoader::CreateEffect(const std::string& fileName)
{
    Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
    if (!pChunk)
        printf("Failed to load sound effect %s: %s\n", fileName.c_str(), Mix_GetError());
    Effect* res = new Effect(soundManager_, pChunk);
    return res;
}