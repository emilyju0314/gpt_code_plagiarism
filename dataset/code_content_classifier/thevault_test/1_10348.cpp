TexturePtr Application::getEmptyTexture()
{
	if (!emptyTexture)
	{
		emptyTexture = std::make_shared<Texture>();
		emptyTexture->createEmpty(sdl->getRenderer());
	}

	return emptyTexture;
}