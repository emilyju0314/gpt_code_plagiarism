dualQuaternion dualQuaternion::sScLERP(double inT, dualQuaternion const& inFrom, dualQuaternion const& inTo)
{
	assert(0.0<=inT && inT<=1.0);	
	assert(inFrom.isUnit() && inTo.isUnit());

	// Make sure dot product is >= 0
	double quat_dot = inFrom.dotReal(inTo);
	dualQuaternion to_sign_corrected = (quat_dot>=0.0) ? inTo : -inTo;

	dualQuaternion dif_dq = inFrom.inverse() * to_sign_corrected;
	
	double  angle, pitch;
	vector3 direction, moment;
	dif_dq.toScrew(angle, pitch, direction, moment);

	angle *= inT; 
	pitch *= inT;
	dif_dq.setFromScrew(angle, pitch, direction, moment);

	return inFrom * dif_dq;
}