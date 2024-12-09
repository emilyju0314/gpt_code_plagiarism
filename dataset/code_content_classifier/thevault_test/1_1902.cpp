void runCuda(GLuint vbo)
{
    // map OpenGL buffer object for writing from CUDA
    float4 *dptr;
    cutilSafeCall(cudaGLMapBufferObject((void**)&dptr, vbo));

    // execute the kernel
//    dim3 block(8, 8, 1);
//    dim3 grid(mesh_width / block.x, mesh_height / block.y, 1);
//    kernel<<< grid, block>>>(dptr, mesh_width, mesh_height, anim);

    launch_kernel(dptr, mesh_width, mesh_height, anim);

    // unmap buffer object
    cutilSafeCall(cudaGLUnmapBufferObject(vbo));
}