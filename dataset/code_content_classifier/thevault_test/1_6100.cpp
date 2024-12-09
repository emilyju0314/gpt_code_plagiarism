void YARPEurobotHeadKin::intersectRay (__kinType k, const YVector& v, int& x, int& y)
{
	if (k == KIN_LEFT || k == KIN_LEFT_PERI)
	{
		YVector q(3), it(3);
		YHmgTrsf ep = _leftCamera.endFrame();

		YVector o(3), epx(3);
		o(1) = ep(1,4);
		o(2) = ep(2,4);
		o(3) = ep(3,4);
		epx(1) = ep(1,1);
		epx(2) = ep(2,1);
		epx(3) = ep(3,1);

		q = o + F * epx;

		/// intersect plane w/ old ray v.
		/// normal vector to plane is ep(1/2/3, 1)
		double t = F / (ep(1,1)*v(1) + ep(2,1)*v(2) + ep(3,1)*v(3));
		it = v * t + o - q;

		YVector tmp(3);

		///
		///tmp(1) = ep(1,1) * it(1) + ep(2,1) * it(2) + ep(3,1) * it(3);
		tmp(2) = ep(1,2) * it(1) + ep(2,2) * it(2) + ep(3,2) * it(3);
		tmp(3) = ep(1,3) * it(1) + ep(2,3) * it(2) + ep(3,3) * it(3);

		/// mm -> pixels
		x = int (-tmp(2) * PixScaleX + .5);
		y = int (-tmp(3) * PixScaleY + .5);

		if (k == KIN_LEFT_PERI)
		{
			int rx = x, ry = y;
			foveaToPeriphery (rx, ry, x, y);

			x += CenterPeripheryX;
			y += CenterPeripheryY;
		}
		else
		{
			x += CenterFoveaX;
			y += CenterFoveaY;
		}
	}
	else
	if (k == KIN_RIGHT || k == KIN_RIGHT_PERI)
	{
		YVector q(3), it(3);
		YHmgTrsf ep = _rightCamera.endFrame();

		YVector o(3), epx(3);
		o(1) = ep(1,4);
		o(2) = ep(2,4);
		o(3) = ep(3,4);
		epx(1) = ep(1,1);
		epx(2) = ep(2,1);
		epx(3) = ep(3,1);

		q = o + F * epx;

		/// intersect plane w/ old ray v.
		/// normal vector to plane is ep(1/2/3, 1)
		double t = F / (ep(1,1)*v(1) + ep(2,1)*v(2) + ep(3,1)*v(3));
		it = v * t + o - q;

		YVector tmp(3);

		///
		///tmp(1) = ep(1,1) * it(1) + ep(2,1) * it(2) + ep(3,1) * it(3);
		tmp(2) = ep(1,2) * it(1) + ep(2,2) * it(2) + ep(3,2) * it(3);
		tmp(3) = ep(1,3) * it(1) + ep(2,3) * it(2) + ep(3,3) * it(3);

		/// mm -> pixels
		x = int (-tmp(2) * PixScaleX + .5);
		y = int (-tmp(3) * PixScaleY + .5);

		if (k == KIN_RIGHT_PERI)
		{
			int rx = x, ry = y;
			foveaToPeriphery (rx, ry, x, y);
			x += CenterPeripheryX;
			y += CenterPeripheryY;
		}
		else
		{
			x += CenterFoveaX;
			y += CenterFoveaY;
		}
	}
	else
	{
		x = y = 0;
	}
}