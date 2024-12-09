mat(const T *data, bool columnMajor) {
		assert(data != nullptr);
		if (columnMajor) {
			for (int i = 0; i < C; ++i) {
				data_[i] = vec<T, R>(&data[i * R]);
			}
		} else {
			for (int i = 0; i < C; ++i) {
				for (int j = 0; j < R; ++j) {
					data_[i][j] = data[j * C + i];
				}
			}
		}
	}