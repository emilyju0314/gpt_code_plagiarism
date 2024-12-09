void
computeIsosurface()
{
    int threads = 128;
    dim3 grid(numVoxels / threads, 1, 1);
    // get around maximum grid size of 65535 in each dimension
    if (grid.x > 65535) {
        grid.y = grid.x / 32768;
        grid.x = 32768;
    }

    // calculate number of vertices need per voxel
    launch_classifyVoxel(grid, threads, 
						d_voxelVerts, d_voxelOccupied, d_volume, 
						gridSize, gridSizeShift, gridSizeMask, 
						numVoxels, voxelSize, isoValue);
#if DEBUG_BUFFERS
    printf("voxelVerts:\n");
    dumpBuffer(d_voxelVerts, numVoxels, sizeof(uint));
#endif

#if SKIP_EMPTY_VOXELS
    // scan voxel occupied array
    cudppScan(scanplan, d_voxelOccupiedScan, d_voxelOccupied, numVoxels);
#if DEBUG_BUFFERS
    printf("voxelOccupiedScan:\n");
    dumpBuffer(d_voxelOccupiedScan, numVoxels, sizeof(uint));
#endif

    // read back values to calculate total number of non-empty voxels
    // since we are using an exclusive scan, the total is the last value of
    // the scan result plus the last value in the input array
    {
        uint lastElement, lastScanElement;
        cutilSafeCall(cudaMemcpy((void *) &lastElement, 
                       (void *) (d_voxelOccupied + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        cutilSafeCall(cudaMemcpy((void *) &lastScanElement, 
                       (void *) (d_voxelOccupiedScan + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        activeVoxels = lastElement + lastScanElement;
    }

    if (activeVoxels==0) {
        // return if there are no full voxels
        totalVerts = 0;
        return;
    }

    // compact voxel index array
    launch_compactVoxels(grid, threads, d_compVoxelArray, d_voxelOccupied, d_voxelOccupiedScan, numVoxels);
    cutilCheckMsg("compactVoxels failed");

#endif // SKIP_EMPTY_VOXELS

    // scan voxel vertex count array
    cudppScan(scanplan, d_voxelVertsScan, d_voxelVerts, numVoxels);
#if DEBUG_BUFFERS
    printf("voxelVertsScan:\n");
    dumpBuffer(d_voxelVertsScan, numVoxels, sizeof(uint));
#endif

    // readback total number of vertices
    {
        uint lastElement, lastScanElement;
        cutilSafeCall(cudaMemcpy((void *) &lastElement, 
                       (void *) (d_voxelVerts + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        cutilSafeCall(cudaMemcpy((void *) &lastScanElement, 
                       (void *) (d_voxelVertsScan + numVoxels-1), 
                       sizeof(uint), cudaMemcpyDeviceToHost));
        totalVerts = lastElement + lastScanElement;
    }

    // generate triangles, writing to vertex buffers
    if (!g_bQAReadback) {
		size_t num_bytes;
	    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&d_pos, posVbo));
	    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_posvbo_resource, 0));
	    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&d_pos, &num_bytes, cuda_posvbo_resource));

	    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&d_normal, normalVbo));
	    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_normalvbo_resource, 0));
	    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&d_normal, &num_bytes, cuda_normalvbo_resource));
    }

#if SKIP_EMPTY_VOXELS
    dim3 grid2((int) ceil(activeVoxels / (float) NTHREADS), 1, 1);
#else
    dim3 grid2((int) ceil(numVoxels / (float) NTHREADS), 1, 1);
#endif
    while(grid2.x > 65535) {
        grid2.x/=2;
        grid2.y*=2;
    }
#if SAMPLE_VOLUME
    launch_generateTriangles2(grid2, NTHREADS, d_pos, d_normal, 
                                            d_compVoxelArray, 
                                            d_voxelVertsScan, d_volume, 
                                            gridSize, gridSizeShift, gridSizeMask, 
                                            voxelSize, isoValue, activeVoxels, 
                                            maxVerts);
#else
    launch_generateTriangles(grid2, NTHREADS, d_pos, d_normal, 
                                           d_compVoxelArray, 
                                           d_voxelVertsScan, 
                                           gridSize, gridSizeShift, gridSizeMask, 
                                           voxelSize, isoValue, activeVoxels, 
                                           maxVerts);
#endif

    if (!g_bQAReadback) {
        // DEPRECATED: 		cutilSafeCall(cudaGLUnmapBufferObject(normalVbo));
		cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_normalvbo_resource, 0));
        // DEPRECATED: 		cutilSafeCall(cudaGLUnmapBufferObject(posVbo));
		cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_posvbo_resource, 0));
    }
}