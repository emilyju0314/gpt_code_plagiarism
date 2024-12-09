const char* BencodedDict::GetString(const char* key, size_t *length) const
{
	const BencEntityMem *pMem = AsBencString(Get(key));
	return (pMem?pMem->GetString(length):NULL);
}