void	Matrix::select_def_mat (std::string &mat, const ::VSFormat &fmt)
{
	if (mat.empty ())
	{
		switch (fmt.colorFamily)
		{
		case	::cmYUV:
			mat = "601";
			break;

		case	::cmYCoCg:
			mat = "ycgco";
			break;

		case	::cmGray:   // Should not happen actually
		case	::cmRGB:
		case	::cmCompat:
		default:
			// Nothing
			break;
		}
	}
}