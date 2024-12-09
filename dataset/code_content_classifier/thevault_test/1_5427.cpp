void	Matrix::make_mat_ictcp (fmtcl::Mat4 &m, bool hlg_flag, bool to_lms_flag)
{
	fmtcl::Mat3    m3;
	m3[0][0] =  2048; m3[0][1] =   2048; m3[0][2] =    0;
	if (hlg_flag)
	{
		m3[1][0] =  3625; m3[1][1] =  -7465; m3[1][2] = 3840;
		m3[2][0] =  9500; m3[2][1] =  -9212; m3[2][2] = -288;
	}
	else
	{
		m3[1][0] =  6610; m3[1][1] = -13613; m3[1][2] = 7003;
		m3[2][0] = 17933; m3[2][1] = -17390; m3[2][2] = -543;
	}
	m3 *= 1.0 / 4096;

	if (to_lms_flag)
	{
		m3.invert ();
	}

	m.insert3 (m3);
	m.clean3 (1);
}