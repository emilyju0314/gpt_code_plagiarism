void Transform::bake()
{
	m.identity();
	m.translate(xt, yt, zt);
	m.rotateX(xr);
	m.rotateY(yr);
	m.rotateZ(zr);
	m.scale(xs, ys, zs);
}