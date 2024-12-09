bool CheckRenderD3D9::PPMvsPPM( const char *src_file, const char *ref_file, const char *exec_path, 
                                const float epsilon, const float threshold )
{
    char *ref_file_path = cutFindFilePath(ref_file, exec_path);
    if (ref_file_path == NULL) {
        printf("CheckRenderD3D9::PPMvsPPM unable to find <%s> in <%s> Aborting comparison!\n", ref_file, exec_path);
        printf(">>> Check info.xml and [project//data] folder <%s> <<<\n", ref_file);
        printf("Aborting comparison!\n");
        printf("  FAILURE!\n");
        return false;
    }

    return (cutComparePPM( src_file, ref_file_path, epsilon, threshold, true ) == CUTTrue);
}