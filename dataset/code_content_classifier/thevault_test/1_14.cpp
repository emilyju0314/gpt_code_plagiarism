void
POPState::cache()
{
    if (!hash) {
	is_valid = false;
	return;
    }

    // Stash the original mesh bbox and the min and max bounds, which will be used in decoding
    {
	std::stringstream s;
	s.write(reinterpret_cast<const char *>(&bbmin), sizeof(bbmin));
	s.write(reinterpret_cast<const char *>(&bbmax), sizeof(bbmax));
	s.write(reinterpret_cast<const char *>(&minx), sizeof(minx));
	s.write(reinterpret_cast<const char *>(&miny), sizeof(miny));
	s.write(reinterpret_cast<const char *>(&minz), sizeof(minz));
	s.write(reinterpret_cast<const char *>(&maxx), sizeof(maxx));
	s.write(reinterpret_cast<const char *>(&maxy), sizeof(maxy));
	s.write(reinterpret_cast<const char *>(&maxz), sizeof(maxz));
	is_valid = cache_write(CACHE_OBJ_BOUNDS, s);
    }

    if (!is_valid)
	return;

    // Serialize triangle-specific data
    is_valid = cache_tri();
}