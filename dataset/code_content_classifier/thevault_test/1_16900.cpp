void CountingBloomFilter::Add(const zeek::detail::HashKey* key)
	{
	detail::Hasher::digest_vector h = hasher->Hash(key);

	for ( size_t i = 0; i < h.size(); ++i )
		cells->Increment(h[i] % cells->Size());
	}