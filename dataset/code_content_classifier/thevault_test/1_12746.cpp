m_real	vectorn::angle2D(vectorn const& b) const
{
	vectorn const& a=*this;

	m_real rad=a.angle(b);
	// length 가 0인경우 발생.
	ASSERT(rad==rad);
	if(a.sinTheta(b)<0)
		return (m_real)(2.0*M_PI-rad);

	return rad;
}