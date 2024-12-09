pp::Instance* FujiModule::CreateInstance(PP_Instance instance)
{
	// fuji doesn't support multiple instances
	assert(!pInstance);

	pInstance = new Fuji(instance);
	return pInstance;
}