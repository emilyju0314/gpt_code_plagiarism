bool SockAddr::is_mapped_v4() const
{
        if (get_family() != AF_INET6) {
            return false;
        }
	return IN6_IS_ADDR_V4MAPPED((in6_addr*)_sin6);
}