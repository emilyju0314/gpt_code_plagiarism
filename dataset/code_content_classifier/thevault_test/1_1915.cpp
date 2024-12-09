void renderImage(bool bUseOpenGL)
{
#if RUN_TIMING
    pass = 0;
#endif
	if (pass < 128) {
		if (g_runCPU) {
			int startPass = pass;
			float xs, ys;
			cutResetTimer(hTimer);

            if (bUseOpenGL) {
			    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&d_dst, gl_PBO));
			    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
				size_t num_bytes;
			    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&d_dst, &num_bytes, cuda_pbo_resource));
            }

			// Get the anti-alias sub-pixel sample location
			GetSample(pass & 127, xs, ys);

			// Get the pixel scale and offset
			double s = scale / (double)imageW;
			double x = (xs - (double)imageW * 0.5f) * s + xOff;
			double y = (ys - (double)imageH * 0.5f) * s + yOff;

			// Run the mandelbrot generator
			if (pass && !startPass) { // Use the adaptive sampling version when animating.
				if (precisionMode)
					RunMandelbrotDSGold1(h_Src, imageW, imageH, crunch, x, y, 
					xJParam, yJParam, s, colors, pass++, animationFrame, g_isJuliaSet);
				else 
					RunMandelbrotGold1(h_Src, imageW, imageH, crunch, x, y, 
					xJParam, yJParam, s, colors, pass++, animationFrame, g_isJuliaSet);
			}
			else {
				if (precisionMode) 
					RunMandelbrotDSGold0(h_Src, imageW, imageH, crunch, x, y, 
					xJParam, yJParam, s, colors, pass++, animationFrame, g_isJuliaSet);
				else 
					RunMandelbrotGold0(h_Src, imageW, imageH, crunch, x, y, 
					xJParam, yJParam, s, colors, pass++, animationFrame, g_isJuliaSet);
			}
			cutilSafeCall(cudaMemcpy(d_dst, h_Src, imageW * imageH * sizeof(uchar4), cudaMemcpyHostToDevice));

            if (bUseOpenGL) {
                // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(gl_PBO));
				cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));
			}
#if RUN_TIMING
			printf("CPU = %5.8f\n", 0.001f * cutGetTimerValue(hTimer));
#endif
		}
		else {
			float timeEstimate;
			int startPass = pass;
		    cutResetTimer(hTimer);

            if (bUseOpenGL) {
			    // DEPRECATED: cutilSafeCall(cudaGLMapBufferObject((void**)&d_dst, gl_PBO));
			    cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_resource, 0));
				size_t num_bytes;
			    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&d_dst, &num_bytes, cuda_pbo_resource));
            }

			// Render anti-aliasing passes until we run out time (60fps approximately)
			do {
				float xs, ys;

				// Get the anti-alias sub-pixel sample location
				GetSample(pass & 127, xs, ys);

				// Get the pixel scale and offset
				double s = scale / (float)imageW;
				double x = (xs - (double)imageW * 0.5f) * s + xOff;
				double y = (ys - (double)imageH * 0.5f) * s + yOff;


				// Run the mandelbrot generator
				if (!haveDoubles) {
					if (pass && !startPass) // Use the adaptive sampling version when animating.
						RunMandelbrot1_sm11(d_dst, imageW, imageH, crunch, x, y, 
						xJParam, yJParam, s, colors, pass++, animationFrame, precisionMode, numSMs, g_isJuliaSet);
					else
						RunMandelbrot0_sm11(d_dst, imageW, imageH, crunch, x, y, 
						xJParam, yJParam, s, colors, pass++, animationFrame, precisionMode, numSMs, g_isJuliaSet);
				} else {
					if (pass && !startPass) // Use the adaptive sampling version when animating.
						RunMandelbrot1_sm13(d_dst, imageW, imageH, crunch, x, y, 
						xJParam, yJParam, s, colors, pass++, animationFrame, precisionMode, numSMs, g_isJuliaSet);
					else
						RunMandelbrot0_sm13(d_dst, imageW, imageH, crunch, x, y, 
						xJParam, yJParam, s, colors, pass++, animationFrame, precisionMode, numSMs, g_isJuliaSet);
				}
				cudaThreadSynchronize();

				// Estimate the total time of the frame if one more pass is rendered
				timeEstimate = 0.001f * cutGetTimerValue(hTimer) * ((float)(pass + 1 - startPass) / (float)(pass - startPass));
			} while ((pass < 128) && (timeEstimate < 1.0f / 60.0f) && !RUN_TIMING);

            if (bUseOpenGL) {
                // DEPRECATED: cutilSafeCall(cudaGLUnmapBufferObject(gl_PBO));
				cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0));
            }
#if RUN_TIMING
			printf("GPU = %5.8f\n", 0.001f * cutGetTimerValue(hTimer));
#endif
		}
	}
}