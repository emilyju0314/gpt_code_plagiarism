bool k2h_pcks7_remove_padding(const unsigned char* data, int& length)
{
	if(!data || length <= 0){
		ERR_K2HPRN("parameters are wrong.");
		return false;
	}

	unsigned char	lastdata = data[length - 1];
	if(length < static_cast<int>(lastdata)){
		ERR_K2HPRN("padding data length is over all data length.");
		return false;
	}
	length = length - static_cast<int>(lastdata);

	return true;
}