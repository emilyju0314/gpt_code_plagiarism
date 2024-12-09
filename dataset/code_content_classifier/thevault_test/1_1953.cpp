executive::CooperativeThreadArray::CooperativeThreadArray(
	EmulatedKernel *k, const ir::Dim3& grid, bool trace):
	blockDim(k->blockDim()),
	gridDim(grid),
	threadCount(blockDim.x*blockDim.y*blockDim.z),
	kernel(k),
	functionCallStack(blockDim.x*blockDim.y*blockDim.z, k->argumentMemorySize(), 
		k->parameterMemorySize(), k->registerCount(), k->localMemorySize(),
		k->globalLocalMemorySize(), k->totalSharedMemorySize()),
	clock(0),
	traceEvents(trace) {

	reconvergenceMechanism = getReconvergenceMechanism(this);

	initialize(blockDim);
}