void
runTest( int argc, char** argv) 
{
    // warm-up
    boxFilterRGBA(d_img, d_temp, d_temp, width, height, filter_radius, iterations, nthreads);

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStartTimer( timer));

    // execute the kernel
    boxFilterRGBA(d_img, d_temp, d_img, width, height, filter_radius, iterations, nthreads);

    // check if kernel execution generated an error
    cutilCheckMsg("Error: boxFilterRGBA Kernel execution failed!");

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer( timer));

    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
	printf("%.2f Mpixels/sec\n", (width*height / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);

    // allocate mem for the result on host side
    unsigned int size = width * height * sizeof(float);
    float* h_odata = (float*) malloc(size);
    // copy result from device to host
    cutilSafeCall( cudaMemcpy( h_odata, d_img, size, cudaMemcpyDeviceToHost) );

    cutilCheckError( cutSavePGMf( "data/output.pgm", h_odata, width, height));

    // compute reference solution
    float *h_odata_ref = (float*) malloc(size);
    cutilCheckError( cutStartTimer( timer));
//    computeGold(h_img, h_odata_ref, width, height, filter_radius);
    cutilCheckError( cutStopTimer( timer));
    printf("CPU Processing time: %f (ms)\n", cutGetTimerValue( timer));

    // check result
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "regression")) 
    {
        // write file for regression test
        cutilCheckError( cutSavePGMf( "data/regression.pgm", h_odata, width, height));
        printf("Wrote 'regression.pgm'\n");
    }
    else 
    {
        // custom output handling when no regression test running
        // in this case check if the result is equivalent to the expected soluion
        CUTBoolean res = cutComparefe( h_odata, h_odata_ref, width*height, MAX_EPSILON_ERROR );
        printf( "Test %s\n", (1 == res) ? "PASSED" : "FAILED");
    }

    free(h_odata);
    free(h_odata_ref);
}