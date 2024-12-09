inline Point3 rotate3D(Point3 point, double s_yaw, double c_yaw, double s_pitch, double c_pitch, double s_roll, double c_roll) {
	double old_x = point.x;
	double old_y = point.y;

	// Rotation matrix for the yaw and pitch rotations
	point.x = point.x * c_yaw + point.z * s_yaw;
	point.z = point.z * c_yaw - old_x * s_yaw;
	point.y = point.y * c_pitch + point.z * s_pitch;
	point.z = point.z * c_pitch - old_y * s_pitch;

	old_x = point.x;
	old_y = point.y;

	// Rotates the roll rotation as in 2D
	point.x = old_x * c_roll - old_y * -s_roll;
	point.y = old_x * -s_roll + old_y * c_roll;
	return point;
}