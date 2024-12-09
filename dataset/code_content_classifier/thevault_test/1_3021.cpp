void Transform::translate(float x, float y, float z)
{
	xt += x;
	yt += y;
	zt += z;

	m.translate(x, y, z);
}