fmtcl::ColorSpaceH265	Matrix::find_cs_from_mat_str (const vsutl::FilterBase &flt, const std::string &mat, bool allow_2020cl_flag)
{
	fmtcl::ColorSpaceH265   cs = fmtcl::ColorSpaceH265_UNSPECIFIED;

	if (mat.empty () || mat == "rgb")
	{
		cs = fmtcl::ColorSpaceH265_RGB;
	}
	else if (mat == "601")
	{
		cs = fmtcl::ColorSpaceH265_SMPTE170M;
	}
	else if (mat == "709")
	{
		cs = fmtcl::ColorSpaceH265_BT709;
	}
	else if (mat == "240")
	{
		cs = fmtcl::ColorSpaceH265_SMPTE240M;
	}
	else if (mat == "fcc")
	{
		cs = fmtcl::ColorSpaceH265_FCC;
	}
	else if (mat == "ycgco" || mat == "ycocg")
	{
		cs = fmtcl::ColorSpaceH265_YCGCO;
	}
	else if (mat == "2020")
	{
		cs = fmtcl::ColorSpaceH265_BT2020NCL;
	}
	else if (mat == "2020cl" && allow_2020cl_flag)
	{
		cs = fmtcl::ColorSpaceH265_BT2020CL;
	}
	else if (mat == "ydzdx")
	{
		cs = fmtcl::ColorSpaceH265_YDZDX;
	}
	else if (mat == "lms")
	{
		cs = fmtcl::ColorSpaceH265_LMS;
	}
	else if (mat == "ictcp_pq")
	{
		cs = fmtcl::ColorSpaceH265_ICTCP_PQ;
	}
	else if (mat == "ictcp_hlg")
	{
		cs = fmtcl::ColorSpaceH265_ICTCP_HLG;
	}
	else
	{
		flt.throw_inval_arg ("unknown matrix identifier.");
	}

	return (cs);
}