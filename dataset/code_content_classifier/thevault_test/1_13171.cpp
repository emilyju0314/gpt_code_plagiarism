BoundingSphere(const std::vector<Eigen::Vector3d>& p)
	{
		m_r = 0;
		m_x.setZero();
		setPoints(p);
	}