ST::string GetShortSectorString(INT16 sMapX, INT16 sMapY)
{
	// OK, build string id like J11
	return ST::format("{c}{}", 'A' - 1 + sMapY, sMapX);
}