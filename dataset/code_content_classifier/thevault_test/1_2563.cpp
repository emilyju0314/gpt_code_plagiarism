Eigen::Affine3d CylinderTrackingROS::stateToMatrix(const Eigen::Matrix<double,6,1> & state)
{
	Eigen::Vector3d direction_vector=state.segment(3,3);
	Eigen::Matrix3d rotationMatrix=directionToRotation(direction_vector);
	Eigen::Translation<double, 3> translation(state(0),state(1),state(2));
	return Eigen::Affine3d(rotationMatrix*translation);
}