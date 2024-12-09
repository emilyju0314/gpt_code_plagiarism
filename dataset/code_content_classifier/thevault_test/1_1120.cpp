tcu::TestNode::IterateResult SpirvGlslToSpirVBuiltInFunctionsTest::iterate()
{
	const Functions& gl = m_context.getRenderContext().getFunctions();

	for (int i = 0; i < (signed)m_sources.size(); ++i)
	{
		ShaderSource shaderSource = m_sources[i];

		ProgramSources  sources;
		ProgramBinaries binaries;

		if (shaderSource.shaderType != glu::SHADERTYPE_COMPUTE)
		{
			ShaderSource vertexSource(glu::SHADERTYPE_VERTEX, m_commonVertex);

			sources << vertexSource;
			ShaderBinary vertexBinary;
#if defined				 DEQP_HAVE_GLSLANG
			vertexBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), vertexSource);
#else  // DEQP_HAVE_GLSLANG
			tcu::Archive& archive = m_testCtx.getArchive();
			vertexBinary =
				commonUtils::readSpirV(archive.getResource("spirv/glsl_to_spirv_builtin_functions/common_vertex.nspv"));
#endif //DEQP_HAVE_GLSLANG
			binaries << vertexBinary;
		}

		sources << shaderSource;
		ShaderBinary shaderBinary;
		std::string  spirvSource;

#if defined DEQP_HAVE_GLSLANG
		shaderBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), shaderSource);
#else  // DEQP_HAVE_GLSLANG
		{
			std::stringstream ss;
			ss << "spirv/glsl_to_spirv_builtin_functions/binary_" << i << ".nspv";

			tcu::Archive& archive = m_testCtx.getArchive();
			shaderBinary		  = commonUtils::readSpirV(archive.getResource(ss.str().c_str()));
		}
#endif // DEQP_HAVE_GLSLANG

#if defined DEQP_HAVE_SPIRV_TOOLS
		{
			spirvUtils::spirvDisassemble(spirvSource, shaderBinary.binary);

			if (!spirvUtils::verifyMappings(shaderSource.source, spirvSource, m_mappings, false))
			{
				m_testCtx.getLog() << tcu::TestLog::Message << "Mappings for shader failed.\n"
								   << "GLSL source:\n"
								   << shaderSource.source.c_str() << "\n"
								   << "SpirV source:\n"
								   << spirvSource.c_str() << tcu::TestLog::EndMessage;

				TCU_THROW(InternalError, "Mappings for shader failed.");
			}
		}
#else  // DEQP_HAVE_SPIRV_TOOLS
		spirvSource				  = "Could not disassemble Spir-V module. SPIRV-TOOLS not available.";
#endif // DEQP_HAVE_SPIRV_TOOLS

		binaries << shaderBinary;

		if (shaderSource.shaderType == glu::SHADERTYPE_TESSELLATION_CONTROL)
		{
			ShaderSource tessEvalSource(glu::SHADERTYPE_TESSELLATION_EVALUATION, m_commonTessEval);

			sources << tessEvalSource;
			ShaderBinary tessEvalBinary;
#if defined				 DEQP_HAVE_GLSLANG
			tessEvalBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), tessEvalSource);
#else  // DEQP_HAVE_GLSLANG
			tcu::Archive& archive = m_testCtx.getArchive();
			tessEvalBinary		  = commonUtils::readSpirV(
				archive.getResource("spirv/glsl_to_spirv_builtin_functions/common_tesseval.nspv"));
#endif // DEQP_HAVE_GLSLANG
			binaries << tessEvalBinary;
		}

		ShaderProgram glslProgram(gl, sources);
		if (!glslProgram.isOk())
		{
			m_testCtx.getLog() << tcu::TestLog::Message << "GLSL shader compilation failed. Source:\n"
							   << shaderSource.source.c_str() << "InfoLog:\n"
							   << glslProgram.getShaderInfo(shaderSource.shaderType).infoLog << "\n"
							   << tcu::TestLog::EndMessage;

			m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
			return STOP;
		}

		ShaderProgram spirvProgram(gl, binaries);
		if (!spirvProgram.isOk())
		{
			m_testCtx.getLog() << tcu::TestLog::Message << "SpirV shader compilation failed. Source:\n"
							   << spirvSource.c_str() << "InfoLog:\n"
							   << spirvProgram.getShaderInfo(shaderSource.shaderType).infoLog << "\n"
							   << tcu::TestLog::EndMessage;

			m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
			return STOP;
		}
	}

	m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	return STOP;
}