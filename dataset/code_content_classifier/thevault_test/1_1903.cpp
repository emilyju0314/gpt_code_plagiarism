void checkResultCuda(int argc, char** argv, const GLuint& vbo)
{
    cutilSafeCall(cudaGLUnregisterBufferObject(vbo));

    // map buffer object
    glBindBuffer(GL_ARRAY_BUFFER_ARB, vbo );
    float* data = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);

    // check result
    if(cutCheckCmdLineFlag(argc, (const char**) argv, "regression")) {
        // write file for regression test
        cutilCheckError(cutWriteFilef("./data/regression.dat",
            data, mesh_width * mesh_height * 3, 0.0));
    }

    // unmap GL buffer object
    if(! glUnmapBuffer(GL_ARRAY_BUFFER)) {
        fprintf(stderr, "Unmap buffer failed.\n");
        fflush(stderr);
    }

    cutilSafeCall(cudaGLRegisterBufferObject(vbo));

    CUT_CHECK_ERROR_GL();
}