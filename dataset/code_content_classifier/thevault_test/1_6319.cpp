YForce TransForce(const YForce& f,const YHmgTrsf& t)
{
	do {} while (&t == 0);
	return f;

#if 0
	Matrix jt(6,6);
	YForce fret;

	jt=0.0;
	
	jt.SubMatrix(1,3,1,3)=t.Rotation();
	jt.SubMatrix(4,6,4,6)=t.Rotation();
	jt.SubMatrix(1,3,4,6)=-t.Rotation()*(t.Position().CrossMatrix());
	fret=jt.t()*f;
	return fret;
#endif
}