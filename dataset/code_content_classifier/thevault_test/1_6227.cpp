inline int PicoloResources::_intialize (const PicoloOpenParameters& params)
{
	_init (params);
	open_bttvx();
	BttvxSetImageBuffer(params._unit_number,_rawBuffer);
	return YARP_OK;
}