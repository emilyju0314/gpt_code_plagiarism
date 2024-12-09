void YARPEurobotHeadKin::computeRay (__kinType k, YVector& v, int x, int y)
{
	if (k == KIN_LEFT)
	{
		x -= CenterFoveaX;
		y -= CenterFoveaY;

		YHmgTrsf ep = _leftCamera.endFrame();

		/// pixels -> mm
		double dx = double(x) / PixScaleX;
		double dy = double(y) / PixScaleY;

		v(1) = F * ep (1, 1) - dx * ep (1, 2) - dy * ep (1, 3);
		v(2) = F * ep (2, 1) - dx * ep (2, 2) - dy * ep (2, 3);
		v(3) = F * ep (3, 1) - dx * ep (3, 2) - dy * ep (3, 3);

		v /= v.norm2();
	}
	else
	if (k == KIN_LEFT_PERI)
	{
		x -= CenterPeripheryX;
		y -= CenterPeripheryY;

		int rx, ry;
		peripheryToFovea (x, y, rx, ry);

		YHmgTrsf ep = _leftCamera.endFrame();

		/// pixels -> mm
		double dx = double(rx) / PixScaleX;
		double dy = double(ry) / PixScaleY;

		v(1) = F * ep (1, 1) - dx * ep (1, 2) - dy * ep (1, 3);
		v(2) = F * ep (2, 1) - dx * ep (2, 2) - dy * ep (2, 3);
		v(3) = F * ep (3, 1) - dx * ep (3, 2) - dy * ep (3, 3);

		v /= v.norm2();
	}
	else
	if (k == KIN_RIGHT)
	{
		x -= CenterFoveaX;
		y -= CenterFoveaY;

		YHmgTrsf ep = _rightCamera.endFrame();

		/// pixels -> mm
		double dx = double(x) / PixScaleX;
		double dy = double(y) / PixScaleY;

		v(1) = F * ep (1, 1) - dx * ep (1, 2) - dy * ep (1, 3);
		v(2) = F * ep (2, 1) - dx * ep (2, 2) - dy * ep (2, 3);
		v(3) = F * ep (3, 1) - dx * ep (3, 2) - dy * ep (3, 3);

		v /= v.norm2();
	}
	else
	if (k == KIN_RIGHT_PERI)
	{
		x -= CenterPeripheryX;
		y -= CenterPeripheryY;

		int rx, ry;
		peripheryToFovea (x, y, rx, ry);

		YHmgTrsf ep = _rightCamera.endFrame();

		/// pixels -> mm
		double dx = double(rx) / PixScaleX;
		double dy = double(ry) / PixScaleY;

		v(1) = F * ep (1, 1) - dx * ep (1, 2) - dy * ep (1, 3);
		v(2) = F * ep (2, 1) - dx * ep (2, 2) - dy * ep (2, 3);
		v(3) = F * ep (3, 1) - dx * ep (3, 2) - dy * ep (3, 3);

		v /= v.norm2();
	}
	else
		v = 0;
}