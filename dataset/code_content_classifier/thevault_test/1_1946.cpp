int chooseCudaDevice(int argc, char **argv, bool bUseOpenGL)
{
    int result = 0;
    if (bUseOpenGL) {
        result = cutilChooseCudaGLDevice(argc, argv);
    } else {
        result = cutilChooseCudaDevice(argc, argv);
    }
    return result;
}