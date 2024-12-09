matrix multMultiThread(matrix& m1, matrix& m2, unsigned int threads) {

#ifdef STATIC_4_T
	matrix	r1 = sub_matrix(m1, 0, m1.size() / 2, 0, m1[0].size()),
		r2 = sub_matrix(m1, m1.size() / 2, m1.size(), 0, m1[0].size());

	matrix	l1 = sub_matrix(m2, 0, m2.size(), 0, m2[0].size() / 2),
		l2 = sub_matrix(m2, 0, m2.size(), m2[0].size() / 2, m2[0].size());

	auto f1 = std::async([&]() {return r1 * l1; });
	auto f2 = std::async([&]() {return r1 * l2; });
	auto f3 = std::async([&]() {return r2 * l1; });
	auto f4 = std::async([&]() {return r2 * l2; });

	std::vector<matrix> mx = { f1.get(), f2.get(), f3.get(), f4.get() };

	int splits = 2;
#elif !STATIC_4_T

	int splits = sqrt(threads);

	std::vector<matrix> r, l;

	//split matrices
	for (size_t i = 0; i < splits; i++)
	{
		r.push_back(sub_matrix(m1, i * (m1.size() / splits), (i + 1) * (m1.size() / splits), 0, m1[0].size()));
		l.push_back(sub_matrix(m2, 0, m2.size(), i * (m2[0].size() / splits), (i + 1) * (m2[0].size() / splits)));
	}

	std::vector<std::future<matrix>> fs;
	//spawn threads via std::async, mainly used because it returns a future wich offers a syncronasation point
	for (size_t i = 0; i < splits; i++)
	{
		for (size_t j = 0; j < splits; j++)
		{
			fs.push_back(std::async([&, i, j]() {return r.at(i) * l.at(j); }));
		}
	}

	std::vector<matrix> mx;
	//wait for all thread to finish
	//wait is made so that the matrices are also in correct order
	for (size_t i = 0; i < threads; i++)
	{
		mx.push_back(fs[i].get());
	}
#endif
	auto res = merge_matrices(mx, splits);

	return res;
}