void shooting::ShootingFunctionParallel(int n, std::vector<real> const& param, std::vector<real> & fvec, int iflag) const
{
	int numParam = data->numParam;

	// Get the timeline
	std::vector<real> timeLine(data->numMulti + 1);
	ComputeTimeLine(param, timeLine);

	// Process multiple shooting
	for (int i = 0; i<data->numThread; i++) {
		data->threadNum[i] = i;
		data->userThreadData[i][0] = (void*) this;
		data->userThreadData[i][1] = (void*)&n;
		data->userThreadData[i][2] = (void*)param.data();
		data->userThreadData[i][3] = (void*)fvec.data();
		data->userThreadData[i][4] = (void*)&data->threadNum[i];
		data->userThreadData[i][5] = (void*)&timeLine;

		// Create thread for multi-shooting
		data->mulThread[i].create(StaticShootingParallelFunction, (void*)data->userThreadData[i].data());
	}

	for (int i = 0; i<data->numThread; i++) {
		data->mulThread[i].join();
	}
}