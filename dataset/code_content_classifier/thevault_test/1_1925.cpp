void
runBenchmark( ) 
{
    shrLog("\nrunBenchmark...\n\n");

    // warm-up
    boxFilterRGBA(d_img, d_temp, d_temp, width, height, filter_radius, iterations, nthreads);
    cutilSafeCall( cudaThreadSynchronize() );

	// Start round-trip timer and process iCycles loops on the GPU
    iterations = 1;     // standard 1-pass filtering
    const int iCycles = 150;
    double dProcessingTime = 0.0;
    shrLog("\nRunning BoxFilterGPU for %d cycles...\n\n", iCycles);
	shrDeltaT(2);
    for (int i = 0; i < iCycles; i++)
    {
        dProcessingTime += boxFilterRGBA(d_img, d_temp, d_img, width, height, filter_radius, iterations, nthreads);
    }

    // check if kernel execution generated an error and sync host
    cutilCheckMsg("Error: boxFilterRGBA Kernel execution FAILED");
    cutilSafeCall(cudaThreadSynchronize());

    // Get average computation time
    dProcessingTime /= (double)iCycles;

    // log testname, throughput, timing and config info to sample and master logs
    shrLogEx(LOGBOTH | MASTER, 0, "boxFilter-texture, Throughput = %.4f M RGBA Pixels/s, Time = %.5f s, Size = %u RGBA Pixels, NumDevsUsed = %u, Workgroup = %u\n", 
                                  (1.0e-6 * width * height)/dProcessingTime, dProcessingTime, 
                                  (width * height), 1, nthreads); 
    shrLog("\n");
}