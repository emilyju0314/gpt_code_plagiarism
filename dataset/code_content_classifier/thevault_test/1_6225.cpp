int
YARPFlowTracker::GetDisplacement (CVisDVector& v1, CVisDVector& v2, CVisDVector& i1, CVisDVector& i2)
{
	CogGaze gaze;
	CVisDVector& head = seq->GetHeadPositionPtr()[contact_frame];
	double torso = seq->GetArmPositionPtr()[contact_frame](3);		// 3 is the torso YAW.
	
	JointPos hj;
	ArmJoints aj;

	for (int i = 1; i <= NumHeadJoints; i++) 
		hj(i) = head(i);

	memset (aj.j, 0, sizeof(double) * NumArmJoints);
	aj.j[2] = torso;

	gaze.Apply (hj, aj);

	// com_x, com_y, final_x, final_y need to be mapped to the wide camera.
	double cx = com_x, cy = com_y;
	i1(1) = cx;
	i1(2) = cy;
	YARPCogMapCameras::Foveal2WideangleSquashed (cx, cy, cx, cy);
	printf ("remapped starting point : %lf %lf\n", cx, cy);

	float t1, t2, t3;
	gaze.DeIntersect (float(cx), float(cy), t1, t2, t3);
	v1(1) = t1;
	v1(2) = t2;
	v1(3) = t3;

	cx = final_x;
	cy = final_y;
	i2(1) = cx;
	i2(2) = cy;
	YARPCogMapCameras::Foveal2WideangleSquashed (cx, cy, cx, cy);
	printf ("remapped ending point : %lf %lf\n", cx, cy);

	gaze.DeIntersect (float(cx), float(cy), t1, t2, t3);
	v2(1) = t1;
	v2(2) = t2;
	v2(3) = t3;

	return 0;	
}