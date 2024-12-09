inline CUdevice findCudaDevice(int argc, char **argv, int *p_devID)
{
    CUdevice cuDevice;
    int devID = 0;
    // If the command-line has a device number specified, use it
    if( checkCmdLineFlag(argc, (const char**)argv, "device") ) {
        devID = cudaDeviceInit(argc, argv);
        if (devID < 0) {
            printf("exiting...\n");
            exit(0);
        }
    } else {
        // Otherwise pick the device with highest Gflops/s
        char name[100];
        devID = getMaxGflopsDeviceId();
        checkCudaErrors(cuDeviceGet(&cuDevice, devID));
        cuDeviceGetName(name, 100, cuDevice);
        printf("> Using CUDA Device [%d]: %s\n", devID, name);
    }
    cuDeviceGet(&cuDevice, devID);
    if (p_devID) *p_devID = devID;
    return cuDevice;
}