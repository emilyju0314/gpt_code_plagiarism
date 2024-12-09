double atofExt(char* str)
{
	char *end;
	double value = strtod(str, &end);
	if((end == str) || (*end != '\0'))
		throw string("Error: non-numeric value for a numeric argument.\n");
	return value;
}