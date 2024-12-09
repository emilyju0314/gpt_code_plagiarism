tcu::TestNode::IterateResult SpirvGlslToSpirVSpecializationConstantsTest::iterate()
{
	const Functions& gl = m_context.getRenderContext().getFunctions();

	const GLfloat vertices[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };

	GLuint vao;
	gl.genVertexArrays(1, &vao);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glGenVertexArrays");
	gl.bindVertexArray(vao);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glBindVertexArray");

	GLuint vbo;
	gl.genBuffers(1, &vbo);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glGenBuffers");
	gl.bindBuffer(GL_ARRAY_BUFFER, vbo);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glBindBuffer");

	gl.bufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), (GLvoid*)vertices, GL_DYNAMIC_DRAW);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glBufferData");

	ShaderBinary vertexBinary;
	ShaderBinary fragmentBinary;
#if defined		 DEQP_HAVE_GLSLANG
	{
		vertexBinary   = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), VertexSource(m_vertex));
		fragmentBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), FragmentSource(m_fragment));
	}
#else  // DEQP_HAVE_GLSLANG
	{
		tcu::Archive& archive = m_testCtx.getArchive();
		vertexBinary =
			commonUtils::readSpirV(archive.getResource("spirv/glsl_to_spirv_specialization_constants/vertex.nspv"));
		fragmentBinary =
			commonUtils::readSpirV(archive.getResource("spirv/glsl_to_spirv_specialization_constants/fragment.nspv"));
	}
#endif // DEQP_HAVE_GLSLANG
	fragmentBinary << SpecializationData(10, 128);

	ProgramBinaries binaries;
	binaries << vertexBinary;
	binaries << fragmentBinary;
	ShaderProgram spirvProgram(gl, binaries);

	if (!spirvProgram.isOk())
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "Shader compilation failed.\n"
						   << "Vertex:\n"
						   << m_vertex.c_str() << "Fragment:\n"
						   << m_fragment.c_str() << "InfoLog:\n"
						   << spirvProgram.getShaderInfo(SHADERTYPE_VERTEX).infoLog << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	gl.useProgram(spirvProgram.getProgram());
	GLU_EXPECT_NO_ERROR(gl.getError(), "glUseProgram");

	gl.clearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glClearColor");
	gl.clear(GL_COLOR_BUFFER_BIT);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glClear");

	gl.enableVertexAttribArray(0);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glEnableVertexAttribArray");

	gl.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, DE_NULL);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glVertexAttribPointer");

	gl.drawArrays(GL_TRIANGLES, 0, 3);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glDrawArray");

	gl.disableVertexAttribArray(0);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glDisableVertexAttribArray");

	GLuint output;

	gl.readPixels(16, 16, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)&output);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glReadPixels");

	if (output != 0xFFFF0080)
	{
		m_testCtx.getLog() << tcu::TestLog::Message
						   << "Color value read from framebuffer is wrong. Expected: " << 0xFFFF0080
						   << ", Read: " << output << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	return STOP;
}