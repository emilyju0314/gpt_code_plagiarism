void process( int width, int height, int radius) 
{
    cudaArray *in_array; 
    unsigned int* out_data;

#ifdef USE_TEXSUBIMAGE2D
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_dest_resource, 0));    
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&out_data, &num_bytes, 
                                                       cuda_pbo_dest_resource));
    //printf("CUDA mapped pointer of pbo_out: May access %ld bytes, expected %d\n", num_bytes, size_tex_data);
#else
    out_data = cuda_dest_resource;
#endif

    // map buffer objects to get CUDA device pointers
    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_tex_screen_resource, 0));
    //printf("Mapping tex_in\n");
    cutilSafeCall(cudaGraphicsSubResourceGetMappedArray(&in_array, cuda_tex_screen_resource, 0, 0));

    // calculate grid size
    dim3 block(16, 16, 1);
    //dim3 block(16, 16, 1);
    dim3 grid(width / block.x, height / block.y, 1);
    int sbytes = (block.x+(2*radius))*(block.y+(2*radius))*sizeof(unsigned int);

    // execute CUDA kernel
    launch_cudaProcess(grid, block, sbytes, 
                       in_array, out_data, width, height, 
                       block.x+(2*radius), radius, 0.8f, 4.0f);

    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_tex_screen_resource, 0));
#ifdef USE_TEXSUBIMAGE2D
    cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_dest_resource, 0));
#endif
}