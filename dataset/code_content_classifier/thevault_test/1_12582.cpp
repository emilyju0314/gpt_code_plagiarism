int atoiExt(char* str)
{
	char *end;
	long value = strtol(str, &end, 10);
	if((end == str) || (*end != '\0'))
		throw string("Error: non-numeric value for a numeric argument.\n");
	return (int)value;
}