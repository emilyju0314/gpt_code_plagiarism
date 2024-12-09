int
IKSolver::limbIK( const vector3& goal, const vector3& sh, const vector3& v1, const vector3& v2,
			quater& qq1, quater& qq2, m_real ii, const vector3& axis , vector3* v3, vector3* v4)
{
	vector3 d, dx;
	quater qk, q1, q2;
	m_real theta, l1, l2, ccc;
	int ret=0;

	d=goal-sh;

	angleRot(theta, v1, v2, &qk); // qk.axisToAxis(v1,v2); taesoo's interpretation.


	m_real theta_o=theta;
	l1=v1.length(), l2=v2.length();
	ccc=(l1*l1+l2*l2-d%d)/(2*l1*l2);
	if( ccc>1 || ccc<-1 ){	theta = 0; ret=1; }
	else
		theta=(m_real)M_PI-(m_real)acos( ccc );

	// knee damping suggested in Foot skate cleanup by kovar
	if(v3)
	{
		m_real theta_o;
		angleRot(theta_o, *v3, *v4);

		// unlike KOVAR's original version (theta=M_PI when leg is flat),
		// we use theta=0 when leg is flat.
		theta=M_PI-theta;
		theta_o=M_PI-theta_o;

		m_real dtheta=theta-theta_o;

		// f(x) = 1, x< ro
		// f(x) = 2x^3+3x^2+1, otherwise
		// theta= theta_o + \integral _theta_o ^ {theta+dtheta}  f(x) dx

		m_real ro=TO_RADIAN(130);

		if(theta>ro || theta_o >ro )
			theta=theta_o+integral_f(theta_o, theta, ro);

		theta=M_PI-theta;
	}

	/*
	((vector3&)axis).cross(v2, v1);
	((vector3&)axis).normalize();*/


	q2.exp(theta/2*axis);

	dx.rotate(q2,v2);
	dx+=v1;

	quater qexp;
	angleRot(theta, dx, d, &qexp);

	d.normalize();

	q1=findNearest( qexp, qq1, d );  //
	quater iqk;
	iqk.inverse(qk);
	q2=q1*q2*iqk;
	if( qq1%q1<0 ) q1=-q1;
	if( qq2%q2<0 ) q2=-q2;
	qq1.slerp(qq1,q1,ii);
	qq2.slerp(qq2,q2,ii);
	return ret;
}