void process(int pbo_in, int pbo_out, int width, int height, int radius) 
{
    int *in_data;
    int* out_data;

    // map buffer objects to get CUDA device pointers
    cutilSafeCall(cudaGLMapBufferObject( (void**)&in_data, pbo_in));
    cutilSafeCall(cudaGLMapBufferObject( (void**)&out_data, pbo_out));

    // calculate grid size
    dim3 block(16, 16, 1);
    dim3 grid(width / block.x, height / block.y, 1);
    int sbytes = (block.x+(2*radius))*(block.y+(2*radius))*sizeof(int);

    // execute CUDA kernel
    launch_cudaProcess(grid, block, sbytes, 
                       in_data, out_data, width, height, 
                       block.x+(2*radius), radius, 0.8f, 4.0f);

    cutilSafeCall(cudaGLUnmapBufferObject( pbo_in));
    cutilSafeCall(cudaGLUnmapBufferObject( pbo_out));
}