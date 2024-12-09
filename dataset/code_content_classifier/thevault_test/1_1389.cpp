mat(const mat<T, C + 1, R + 1> &m, int col, int row) {
		assert(col <= C && row <= R);
		for (int i = 0; i < C; ++i) {
			if (i < col)
				data_[i] = vec<T, R>{ m[i], row };
			else
				data_[i] = vec<T, R>{ m[i + 1], row };
		}
	}