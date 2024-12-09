void runAutoTest()
{
    // execute the kernel
    launch_kernel((float4 *)d_vbo_buffer, mesh_width, mesh_height, g_fAnim);

    cutilSafeCall( cutilDeviceSynchronize() );
    cutilCheckMsg("launch_kernel failed");

    cutilSafeCall( cudaMemcpy( g_CheckRender->imageData(), d_vbo_buffer, mesh_width*mesh_height*sizeof(float), cudaMemcpyDeviceToHost) );
    g_CheckRender->dumpBin((void *)g_CheckRender->imageData(), mesh_width*mesh_height*sizeof(float), "simpleGL.bin");
    if (!g_CheckRender->compareBin2BinFloat("simpleGL.bin", "ref_simpleGL.bin", mesh_width*mesh_height*sizeof(float), MAX_EPSILON_ERROR, THRESHOLD))
       g_TotalErrors++;
}