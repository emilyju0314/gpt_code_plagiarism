vec4 SphericalToCartesian(float r, float phi, float theta)
{
	vec4 cartesian;
	cartesian.x = r * sin(theta) * sin(phi);
	cartesian.y = r * cos(phi);
	cartesian.z = r * cos(theta) * sin(phi);
	cartesian.w = 1.0f;
	return cartesian;
}