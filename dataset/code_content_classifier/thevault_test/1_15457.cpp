K2HTransDynLib* K2HTransDynLib::get(void)
{
	static K2HTransDynLib	dynlib;					// singleton
	return &dynlib;
}