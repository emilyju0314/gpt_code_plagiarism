Hasher::digest UHF::hash(const void* x, size_t n) const
	{
	static_assert(std::is_same<highwayhash::SipHashState::Key, decltype(seed.h)>::value,
	              "Seed value is not the same type as highwayhash key");
	return highwayhash::SipHash(seed.h, reinterpret_cast<const char*>(x), n);
	}