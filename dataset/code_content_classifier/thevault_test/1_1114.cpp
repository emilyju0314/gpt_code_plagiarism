tcu::TestNode::IterateResult SpirvModulesStateQueriesTest::iterate()
{
	const Functions& gl = m_context.getRenderContext().getFunctions();

	ProgramBinaries binaries;
	ShaderBinary	vertexBinary;

#if defined DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS
	{
		vertexBinary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), VertexSource(m_vertex));

		// Disassemble Spir-V module
		std::string output;
		spirvUtils::spirvDisassemble(output, vertexBinary.binary);

		// Remove name reflection for defined variables
		std::vector<std::string> lines = de::splitString(output, '\n');
		std::string				 input;
		for (int i = 0; i < (signed)lines.size(); ++i)
		{
			if (lines[i].find("OpName") != std::string::npos)
				continue;

			if (lines[i].find("OpMemberName") != std::string::npos)
				continue;

			input.append(lines[i] + "\n");
		}

		// Assemble Spir-V module
		vertexBinary.binary.clear();
		spirvUtils::spirvAssemble(vertexBinary.binary, input);
		spirvUtils::spirvValidate(vertexBinary.binary, true);
	}
#else  // DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS
	tcu::Archive& archive = m_testCtx.getArchive();
	vertexBinary		  = commonUtils::readSpirV(archive.getResource("spirv/modules_state_queries/vertex.nspv"));
#endif // DEQP_HAVE_GLSLANG && DEQP_HAVE_SPIRV_TOOLS

	binaries << vertexBinary;
	ShaderProgram program(gl, binaries);

	Shader* shader = program.getShader(SHADERTYPE_VERTEX);

	// 1) Check compile status
	if (!program.getShaderInfo(SHADERTYPE_VERTEX).compileOk)
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "Check compile status failed.\n"
						   << "Vertex: " << program.getShaderInfo(SHADERTYPE_VERTEX).infoLog << "\n"
						   << m_vertex << "\n"
						   << "Program: " << program.getProgramInfo().infoLog << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	// 2) Check if SPIR_V_BINARY_ARB state is TRUE
	GLint shaderState;
	gl.getShaderiv(shader->getShader(), GL_SPIR_V_BINARY_ARB, &shaderState);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getShaderiv");
	if (shaderState != GL_TRUE)
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "SPIR_V_BINARY_ARB state set to FALSE. Expected TRUE."
						   << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	// 3) Check if queries for ACTIVE_ATTRIBUTE_MAX_LENGTH, ACTIVE_UNIFORM_MAX_LENGTH,
	//    ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH and TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH return
	//    value equal to 1
	GLint programState[4];
	GLint expectedValues[4] = {1, 1, 1, 1};
	gl.getProgramiv(program.getProgram(), GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &programState[0]);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getProgramiv");

	gl.getProgramiv(program.getProgram(), GL_ACTIVE_UNIFORM_MAX_LENGTH, &programState[1]);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getProgramiv");

	gl.getProgramiv(program.getProgram(), GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, &programState[2]);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getProgramiv");

	gl.getProgramiv(program.getProgram(), GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH, &programState[3]);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getProgramiv");

	bool programStateResult = true;
	for (int i = 0; i < 4; ++i)
	{
		if (programState[i] != expectedValues[i])
		{
			m_testCtx.getLog() << tcu::TestLog::Message << "Check max name length [" << i << "] failed. "
                                                          << "Expected: " << expectedValues[i] <<", Queried: "
                                                          << programState[i] << "\n"
                                                          << tcu::TestLog::EndMessage;
			programStateResult = false;
		}
	}

	if (!programStateResult)
	{
		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	// 4) Check if ShaderSource command usage on Spir-V binary shader will change SPIR_V_BINARY_ARB state to FALSE
	const char* source = m_vertex.c_str();
	const int   length = m_vertex.length();
	gl.shaderSource(shader->getShader(), 1, &source, &length);
	GLU_EXPECT_NO_ERROR(gl.getError(), "shaderSource");

	gl.getShaderiv(shader->getShader(), GL_SPIR_V_BINARY_ARB, &shaderState);
	GLU_EXPECT_NO_ERROR(gl.getError(), "getShaderiv");
	if (shaderState != GL_FALSE)
	{
		m_testCtx.getLog() << tcu::TestLog::Message << "SPIR_V_BINARY_ARB state set to TRUE. Expected FALSE."
						   << tcu::TestLog::EndMessage;

		m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
		return STOP;
	}

	m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	return STOP;
}