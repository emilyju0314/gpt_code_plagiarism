static const char *radix_string(int radix)
{
	static char buf[20];

	switch (radix)
	{
	case 16:
		return " [hex]";
	case 10:
		return " [dec]";
	case 8:
		return " [oct]";
	case 2:
		return " [bin]";
	default:
		sprintf(buf, " [radix %d]", radix);
		return buf;
	}
}