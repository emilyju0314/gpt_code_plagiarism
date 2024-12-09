void bullAxisToMatrix(const btVector3 &axis, btMatrix3x3 &matrix) {
	btVector3 wup(0, 1, 0);

	// Handle cases where the axis is really close to up/down vector
	// Dot = cos(theta) (for dummies), looking for 0(1) to 180(-1) degrees difference
	btScalar dot = wup.dot(axis);
	if ((dot > 1.0f - SIMD_EPSILON) || (dot < -1.0f + SIMD_EPSILON)) {
		// Axis is really close to/is the up/down vector! We'll have to use a side vector as a base instead.
		btVector3 wside(0, 0, 1);

		// Normalize the cross products, as they may not be unit length.
		btVector3 up = wside.cross(axis);
		up.normalize();

		btVector3 side = axis.cross(up);
		side.normalize();

		// Fwd Up Right
		matrix.setValue(axis.x(), up.x(), side.x(),
						axis.y(), up.y(), side.y(),
						axis.z(), up.z(), side.z());
	} else {
		// Cross products may not be unit length!
		btVector3 side = wup.cross(axis);
		side.normalize();

		btVector3 up = side.cross(axis);
		up.normalize();

		matrix.setValue(axis.x(), up.x(), side.x(),
						axis.y(), up.y(), side.y(),
						axis.z(), up.z(), side.z());
	}
}