in6_addr parse_ip_v6(cstr ip_v6, bool *valid)
{
	in6_addr a = IN6ADDR_ANY_INIT;
	int r = INET_PTON(AF_INET6, ip_v6, &a);
	if (valid)
		*valid = (bool)(r == 1);
	return a;
}