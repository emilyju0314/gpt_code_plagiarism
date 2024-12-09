fmtcl::PrimariesPreset	Primaries::conv_string_to_primaries (const std::string &str)
{
	fmtcl::PrimariesPreset  preset = fmtcl::PrimariesPreset_UNDEF;

	if (        str == "709"
	         || str == "1361"
	         || str == "61966-2-1"
	         || str == "61966-2-4"
	         || str == "hdtv"
	         || str == "srgb")
	{
		preset = fmtcl::PrimariesPreset_BT709;
	}
	else if (   str == "470m"
	         || str == "ntsc")
	{
		preset = fmtcl::PrimariesPreset_FCC;
	}
	else if (   str == "470m93"
	         || str == "ntscj")
	{
		preset = fmtcl::PrimariesPreset_NTSCJ;
	}
	else if (   str == "470bg"
	         || str == "601-625"
	         || str == "1358-625"
	         || str == "1700-625"
	         || str == "pal"
	         || str == "secam")
	{
		preset = fmtcl::PrimariesPreset_BT470BG;
	}
	else if (   str == "170m"
	         || str == "601-525"
	         || str == "1358-525"
	         || str == "1700-525")
	{
		preset = fmtcl::PrimariesPreset_SMPTE170M;
	}
	else if (   str == "240m")
	{
		preset = fmtcl::PrimariesPreset_SMPTE240M;
	}
	else if (   str == "filmc")
	{
		preset = fmtcl::PrimariesPreset_GENERIC_FILM;
	}
	else if (   str == "2020"
	         || str == "2100"
	         || str == "uhdtv")
	{
		preset = fmtcl::PrimariesPreset_BT2020;
	}
	else if (   str == "61966-2-2"
	         || str == "scrgb")
	{
		preset = fmtcl::PrimariesPreset_SCRGB;
	}
	else if (   str == "adobe98")
	{
		preset = fmtcl::PrimariesPreset_ADOBE_RGB_98;
	}
	else if (   str == "adobewide")
	{
		preset = fmtcl::PrimariesPreset_ADOBE_RGB_WIDE;
	}
	else if (   str == "apple")
	{
		preset = fmtcl::PrimariesPreset_APPLE_RGB;
	}
	else if (   str == "photopro"
	         || str == "romm")
	{
		preset = fmtcl::PrimariesPreset_ROMM;
	}
	else if (   str == "ciergb")
	{
		preset = fmtcl::PrimariesPreset_CIERGB;
	}
	else if (   str == "ciexyz")
	{
		preset = fmtcl::PrimariesPreset_CIEXYZ;
	}
	else if (   str == "p3d65"
	         || str == "dcip3")
	{
		preset = fmtcl::PrimariesPreset_P3D65;
	}
	else if (   str == "aces")
	{
		preset = fmtcl::PrimariesPreset_ACES;
	}
	else if (   str == "ap1")
	{
		preset = fmtcl::PrimariesPreset_ACESAP1;
	}
	else if (   str == "sgamut"
	         || str == "sgamut3")
	{
		preset = fmtcl::PrimariesPreset_SGAMUT;
	}
	else if (   str == "sgamut3cine")
	{
		preset = fmtcl::PrimariesPreset_SGAMUT3CINE;
	}
	else if (   str == "alexa")
	{
		preset = fmtcl::PrimariesPreset_ALEXA;
	}
	else if (   str == "vgamut")
	{
		preset = fmtcl::PrimariesPreset_VGAMUT;
	}
	else if (   str == "p3dci")
	{
		preset = fmtcl::PrimariesPreset_P3DCI;
	}
	else if (   str == "p3d60")
	{
		preset = fmtcl::PrimariesPreset_P3D60;
	}
	else if (   str == "3213")
	{
		preset = fmtcl::PrimariesPreset_EBU3213E;
	}

	return preset;
}