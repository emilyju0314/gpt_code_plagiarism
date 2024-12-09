executive::NVIDIAExecutableKernel::NVIDIAExecutableKernel(
	ir::IRKernel& kernel, const CUfunction& function, 
	executive::Device* d ): ExecutableKernel(kernel, d), 
	cuFunction(function) {
	
	report("NVIDIAExecutableKernel()");
	this->ISA = ir::Instruction::SASS;
	
	_argumentMemorySize = mapArgumentOffsets();
		
	cuda::CudaDriver::cuFuncGetAttribute((int*)&_registerCount, 
		CU_FUNC_ATTRIBUTE_NUM_REGS, cuFunction);
	report(" Registers - " << _registerCount);
	cuda::CudaDriver::cuFuncGetAttribute((int*)&_constMemorySize, 
		CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES, cuFunction);
	report(" Constant Memory - " << _constMemorySize);
	cuda::CudaDriver::cuFuncGetAttribute((int*)&_localMemorySize, 
		CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES, cuFunction);
	report(" Local Memory - " << _localMemorySize);
	cuda::CudaDriver::cuFuncGetAttribute((int*)&_sharedMemorySize, 
		CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES, cuFunction);
	report(" Shared Memory - " << _sharedMemorySize);

	report("  constructed new NVIDIAExecutableKernel");
}