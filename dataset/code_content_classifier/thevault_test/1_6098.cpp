void YARPEurobotHeadKin::computeDirect (const YVector &joints)
{
	ACE_ASSERT (joints.Length() == 5); 

	// the joint vector is devided into right and left
	// I *KNOW* this is awful because doesn't use n_ref_frame
	_leftJoints(1) = joints(1);
	_leftJoints(2) = joints(2);
	_leftJoints(3) = joints(3);
	_leftJoints(4) = joints(5);

	_rightJoints(1) = joints(1);
	_rightJoints(2) = joints(2);
	_rightJoints(3) = joints(3);
	_rightJoints(4) = joints(4);

	_leftCamera.computeDirect (_leftJoints);
	_rightCamera.computeDirect (_rightJoints);

	_computeFixation (_rightCamera.endFrame(), _leftCamera.endFrame());
}