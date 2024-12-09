Configuration *Configuration::Bootstrap(const char *_bootstrap)
{
	StringCchCopyA(bootstrap, 2048, _bootstrap);

	return this;
}