void AesContainer::setIV(unsigned char *iv) {
	char defaultVector[16] = {35, 34, 100, 35, 81, 125, 77, 40, 51, 55, 42, 71, 111, 70, 77, 101}; //Every char in iv must be lesser than 128 !
	if(iv == nullptr){
		strncpy((char*)m_iv, defaultVector, 16);
	} else
		strncpy((char*)m_iv, (char*)iv, 16);
}