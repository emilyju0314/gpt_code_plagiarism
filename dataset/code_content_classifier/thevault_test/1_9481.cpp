Vector3d interpoliereVektoren(Vector3d a,Vector3d b, double t)
{
	a.normalize();
	b.normalize();
	if(t<0)
	{
		b=b*-1;
		t=-t;
	}
	Vector3d v = (1-t)*a+t*b;
	v.normalize();
	return v;
}