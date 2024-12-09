void shooting::TimeoutOCPFunction(void *arg){
	void **userArgs = (void**) arg;
	shooting* This = (shooting*) userArgs[0];
	real* continuationStep = (real*) userArgs[1];
	int* info = (int*) userArgs[2];

	if (*continuationStep<=0){
		// no continuation
		*info = This->SolveShooting();
	}else{
		// discrete continuation with step "continuationStep"
		*info = This->SolveShootingContinuation(*continuationStep);
	}
}