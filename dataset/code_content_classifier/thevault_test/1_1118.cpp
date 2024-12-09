tcu::TestNode::IterateResult SpirvGlslToSpirVEnableTest::iterate()
{

#if defined DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS
	{
		const Functions& gl = m_context.getRenderContext().getFunctions();

		ProgramBinaries binaries;
		ShaderBinary vertexBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), VertexSource(m_vertex));
		binaries << vertexBinary;
		ShaderProgram spirvProgram(gl, binaries);

		std::string spirvSource;
		spirvUtils::spirvDisassemble(spirvSource, vertexBinary.binary);

		if (spirvSource.find("OpName %enabled") == std::string::npos)
		{
			m_testCtx.getLog() << tcu::TestLog::Message << "GL_SPIRV not defined. Spir-V source:\n"
							   << spirvSource.c_str() << tcu::TestLog::EndMessage;

			m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
			return STOP;
		}

		if (!spirvProgram.isOk())
		{
			m_testCtx.getLog() << tcu::TestLog::Message << "Shader compilation failed. Source:\n"
							   << spirvSource.c_str() << "InfoLog:\n"
							   << spirvProgram.getShaderInfo(SHADERTYPE_VERTEX).infoLog << "\n"
							   << tcu::TestLog::EndMessage;

			m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
			return STOP;
		}

		m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	}
#else // DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS

	TCU_THROW(InternalError, "Either glslang or spirv-tools not available.");

#endif // DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS

	return STOP;
}