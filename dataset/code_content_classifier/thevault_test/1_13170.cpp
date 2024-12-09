BoundingSphere(const Eigen::Vector3d& a, const Eigen::Vector3d& b, const Eigen::Vector3d& c)
	{
		const Eigen::Vector3d ba = b - a;
		const Eigen::Vector3d ca = c - a;
		const Eigen::Vector3d baxca = ba.cross(ca);
		Eigen::Vector3d r;
		Eigen::Matrix3d T;
		T << ba[0], ba[1], ba[2],
			ca[0], ca[1], ca[2],
			baxca[0], baxca[1], baxca[2];

		r[0] = 0.5 * ba.squaredNorm();
		r[1] = 0.5 * ca.squaredNorm();
		r[2] = 0.0;

		m_x = T.inverse() * r;
		m_r = m_x.norm();
		m_x += a;
	}