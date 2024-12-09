BoundingSphere(const Eigen::Vector3d& a, const Eigen::Vector3d& b)
	{
		const Eigen::Vector3d ba = b - a;

		m_x = (a + b) * 0.5;
		m_r = 0.5 * ba.norm();
	}