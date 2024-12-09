int minProjections(int pairs) {
	double retVal = ( -1.0 + pow(1.0 + 8.0 * double(pairs), 0.5) ) / 2.0;
	//printf("%s << retVal(%d) = (%f)\n", __FUNCTION__, pairs, retVal);
	return int(ceil(retVal+1.0));
}