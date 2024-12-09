CUresult util::KernelExtractorDriver::cuLaunch ( CUfunction f ) {
	trace();	
	if (enabled) {
		kernelLaunch(f);
	}
	
	CUresult res = cudaDriver.cuLaunch(f);
	if (enabled) {
		kernelReturn(res);
	}
	
	RETURN( res );
}