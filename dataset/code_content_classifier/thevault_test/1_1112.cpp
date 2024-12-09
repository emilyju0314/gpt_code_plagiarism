tcu::TestNode::IterateResult SpirvShaderBinaryMultipleShaderObjectsTest::iterate()
{
	const Functions& gl = m_context.getRenderContext().getFunctions();

	const GLfloat vertices[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };

	GLuint texture;
	GLuint fbo;

	gl.genTextures(1, &texture);
	GLU_EXPECT_NO_ERROR(gl.getError(), "genTextures");
	gl.bindTexture(GL_TEXTURE_2D, texture);
	GLU_EXPECT_NO_ERROR(gl.getError(), "bindTexture");
	gl.texStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, 32, 32);
	GLU_EXPECT_NO_ERROR(gl.getError(), "texStorage2D");

	gl.genFramebuffers(1, &fbo);
	GLU_EXPECT_NO_ERROR(gl.getError(), "genFramenuffers");
	gl.bindFramebuffer(GL_FRAMEBUFFER, fbo);
	GLU_EXPECT_NO_ERROR(gl.getError(), "bindFramebuffer");
	gl.framebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	GLU_EXPECT_NO_ERROR(gl.getError(), "framebufferTexture2D");

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

#if defined DEQP_HAVE_SPIRV_TOOLS
	ShaderBinary binary;
	binary << SHADERTYPE_VERTEX << "mainv";
	binary << SHADERTYPE_FRAGMENT << "mainf";

	spirvUtils::spirvAssemble(binary.binary, m_spirv);
	spirvUtils::spirvValidate(binary.binary, true);
#else  // DEQP_HAVE_SPIRV_TOOLS
	tcu::Archive& archive = m_testCtx.getArchive();
	ShaderBinary  binary  = commonUtils::readSpirV(
		archive.getResource("spirv/spirv_modules_shader_binary_multiple_shader_objects/binary.nspv"));
#endif // DEQP_HAVE_SPIRV_TOOLS

	ProgramBinaries binaries;
	binaries << binary;
	ShaderProgram program(gl, binaries);

	if (!program.isOk())
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "Shader build failed.\n"
						   << "Vertex: " << program.getShaderInfo(SHADERTYPE_VERTEX).infoLog << "\n"
						   << "Fragment: " << program.getShaderInfo(SHADERTYPE_FRAGMENT).infoLog << "\n"
						   << "Program: " << program.getProgramInfo().infoLog << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	gl.viewport(0, 0, 32, 32);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glViewport");

	gl.useProgram(program.getProgram());
	GLU_EXPECT_NO_ERROR(gl.getError(), "glUseProgram");

	gl.clearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glClearColor");
	gl.clear(GL_COLOR_BUFFER_BIT);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glClear");

	gl.enableVertexAttribArray(0);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glEnableVertexAttribArray");

	gl.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, DE_NULL);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glVertexAttribPointer");

	gl.drawArrays(GL_TRIANGLE_STRIP, 0, 3);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glDrawArray");

	gl.disableVertexAttribArray(0);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glDisableVertexAttribArray");

	GLuint insidePixel;
	GLuint outsidePixel;
	gl.readPixels(16, 16, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)&insidePixel);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glReadPixels");
	gl.readPixels(2, 30, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)&outsidePixel);
	GLU_EXPECT_NO_ERROR(gl.getError(), "glReadPixels");

	if (vbo)
	{
		gl.deleteBuffers(1, &vbo);
		GLU_EXPECT_NO_ERROR(gl.getError(), "glDeleteBuffers");
	}

	if (vao)
	{
		gl.deleteVertexArrays(1, &vao);
		GLU_EXPECT_NO_ERROR(gl.getError(), "glDeleteVertexArrays");
	}

	if (fbo)
	{
		gl.deleteFramebuffers(1, &fbo);
		GLU_EXPECT_NO_ERROR(gl.getError(), "glDeleteFramebuffers");
	}

	if (texture)
	{
		gl.deleteTextures(1, &texture);
		GLU_EXPECT_NO_ERROR(gl.getError(), "glDeleteTextures");
	}

	if (insidePixel == 0xFFFFFFFF && outsidePixel == 0xFF000000)
		m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	else
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "Wrong pixels color read.\n"
						   << "Expected (inside/outside): " << 0xFFFFFFFF << "/" << 0xFF000000 << "\n"
						   << "Read: " << insidePixel << "/" << outsidePixel << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
	}

	return STOP;
}