void Transform::setTranslation(float x, float y, float z)
{
	xt = x;
	yt = y;
	zt = z;

	bake();
}