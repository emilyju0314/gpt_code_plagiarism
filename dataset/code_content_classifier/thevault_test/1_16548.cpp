void Program::applyUniforms()
{
    unsigned int numUniforms = mUniformIndex.size();
    for (unsigned int location = 0; location < numUniforms; location++)
    {
        if (mUniformIndex[location].element != 0)
        {
            continue;
        }

        Uniform *targetUniform = mUniforms[mUniformIndex[location].index];

        if (targetUniform->dirty)
        {
            int arraySize = targetUniform->arraySize;
            GLfloat *f = (GLfloat*)targetUniform->data;
            GLint *i = (GLint*)targetUniform->data;
            GLboolean *b = (GLboolean*)targetUniform->data;

            switch (targetUniform->type)
            {
              case GL_BOOL:       applyUniform1bv(location, arraySize, b);       break;
              case GL_BOOL_VEC2:  applyUniform2bv(location, arraySize, b);       break;
              case GL_BOOL_VEC3:  applyUniform3bv(location, arraySize, b);       break;
              case GL_BOOL_VEC4:  applyUniform4bv(location, arraySize, b);       break;
              case GL_FLOAT:      applyUniform1fv(location, arraySize, f);       break;
              case GL_FLOAT_VEC2: applyUniform2fv(location, arraySize, f);       break;
              case GL_FLOAT_VEC3: applyUniform3fv(location, arraySize, f);       break;
              case GL_FLOAT_VEC4: applyUniform4fv(location, arraySize, f);       break;
              case GL_FLOAT_MAT2: applyUniformMatrix2fv(location, arraySize, f); break;
              case GL_FLOAT_MAT3: applyUniformMatrix3fv(location, arraySize, f); break;
              case GL_FLOAT_MAT4: applyUniformMatrix4fv(location, arraySize, f); break;
              case GL_SAMPLER_2D:
              case GL_SAMPLER_CUBE:
              case GL_INT:        applyUniform1iv(location, arraySize, i);       break;
              case GL_INT_VEC2:   applyUniform2iv(location, arraySize, i);       break;
              case GL_INT_VEC3:   applyUniform3iv(location, arraySize, i);       break;
              case GL_INT_VEC4:   applyUniform4iv(location, arraySize, i);       break;
              default:
                UNREACHABLE();
            }

            targetUniform->dirty = false;
        }
    }
}