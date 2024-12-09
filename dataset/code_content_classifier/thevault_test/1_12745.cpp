m_real	vectorn::angle(vectorn const& b) const 
{
	vectorn const& a=*this;
	return (m_real)(ACOS(a.cosTheta(b)));
}