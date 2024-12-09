void Bsec::beginCommon(void)
{
	status = bsec_init();

	getVersion();
	
	bme680Status = bme680_init(&_bme680);
}