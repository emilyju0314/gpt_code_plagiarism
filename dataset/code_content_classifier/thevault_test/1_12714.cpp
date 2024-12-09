m_real CFuzzyCluster::StepFcm(matrixn& x, vectorn* U, int cluster_n, int expo, std::deque<vectorn>& centers)
{
	int n = U[0].size();

	// MF matrix after exponential modification
	vectorn *mf = new vectorn [cluster_n];

	for (int i = 0; i < cluster_n; i++) {
		mf[i].setSize(n);

		for (int j = 0; j < n; j++) {
			mf[i][j] = pow(U[i][j], expo);
		}
	}

	// new center
	vectorn v(x.cols());
	vectorn tempV;

	for (int i = 0; i < cluster_n; i++) {
		m_real div = 0;

		for (int k = 0; k < v.size(); k++) {
			v[k] = 0;
		}

		for (int k = 0; k < n; k++) {
			tempV = x.row(k);
			tempV *= mf[i][k];
			v += tempV;
			div += mf[i][k];
		}
		v /= div;

		centers[i] = v;
	}

	// fill the distance matrix
	vectorn *dist = new vectorn [cluster_n];

	for (int i = 0; i < cluster_n; i++) {
		dist[i].setSize(n);

		for (int j = 0; j < n; j++) {
			tempV = x.row(j);
			tempV -= centers[i];
			dist[i][j] = tempV.length();
			if (dist[i][j] == 0) {
				dist[i][j] = 0.0000001f;
			}
		}
	}

	// objective function
	m_real obj_fcn = 0;
	for (int i = 0; i < cluster_n; i++) {
		for (int j = 0; j < n; j++) {
			obj_fcn += dist[i][j] * mf[i][j];
		}
	}

	// calculate new U
	assert(expo != 1);

	vectorn *tmp = new vectorn [cluster_n];
	m_real sum_tmp = 0;

	for (int i = 0; i < cluster_n; i++) {
		tmp[i].setSize(n);
		for (int j = 0; j < n; j++) {
			tmp[i][j] = pow(dist[i][j], -2 / (expo - 1));
			sum_tmp += tmp[i][j];
		}
	}

	for (int i = 0; i < cluster_n; i++) {
		for (int j = 0; j < n; j++) {
			U[i][j] = tmp[i][j] / sum_tmp;
		}
	}

	delete [] mf;
	delete [] tmp;
	delete [] dist;


	return obj_fcn;
}