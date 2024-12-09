tcu::TestNode::IterateResult SpirvValidationCapabilitiesTest::iterate()
{
	const Functions& gl = m_context.getRenderContext().getFunctions();

	for (int p = 0; p < (signed)m_pipelines.size(); ++p)
	{
		ProgramBinaries programBinaries;

		Pipeline& pipeline = m_pipelines[p];
		for (int s = 0; s < (signed)pipeline.size(); ++s)
		{
			ShaderStage& stage = pipeline[s];
#if defined				 DEQP_HAVE_GLSLANG
			stage.binary = spirvUtils::makeSpirV(m_context.getTestContext().getLog(), stage.source);
			std::stringstream ssw;
			if (stage.name.empty())
				ssw << "gl_cts/data/spirv/spirv_validation_capabilities/binary_p" << p << "s" << s << ".nspv";
			else
				ssw << "gl_cts/data/spirv/spirv_validation_capabilities/" << stage.name << ".nspv";
			commonUtils::writeSpirV(ssw.str().c_str(), stage.binary);
#else  // DEQP_HAVE_GLSLANG
			tcu::Archive&	 archive = m_testCtx.getArchive();
			std::stringstream ss;
			if (stage.name.empty())
				ss << "spirv/spirv_validation_capabilities/binary_p" << p << "s" << s << ".nspv";
			else
				ss << "spirv/spirv_validation_capabilities/" << stage.name << ".nspv";
			stage.binary = commonUtils::readSpirV(archive.getResource(ss.str().c_str()));
#endif // DEQP_HAVE_GLSLANG
			programBinaries << stage.binary;
		}

		ShaderProgram program(gl, programBinaries);
		if (!program.isOk())
		{
			std::stringstream ssLog;

			ssLog << "Program build failed [" << p << "].\n";
			if (program.hasShader(SHADERTYPE_COMPUTE))
				ssLog << "Compute: " << program.getShaderInfo(SHADERTYPE_COMPUTE).infoLog << "\n";
			if (program.hasShader(SHADERTYPE_VERTEX))
				ssLog << "Vertex: " << program.getShaderInfo(SHADERTYPE_VERTEX).infoLog << "\n";
			if (program.hasShader(SHADERTYPE_TESSELLATION_CONTROL))
				ssLog << "TessellationCtrl: " << program.getShaderInfo(SHADERTYPE_TESSELLATION_CONTROL).infoLog << "\n";
			if (program.hasShader(SHADERTYPE_TESSELLATION_EVALUATION))
				ssLog << "TessellationEval: " << program.getShaderInfo(SHADERTYPE_TESSELLATION_EVALUATION).infoLog
					  << "\n";
			if (program.hasShader(SHADERTYPE_GEOMETRY))
				ssLog << "Geometry: " << program.getShaderInfo(SHADERTYPE_GEOMETRY).infoLog << "\n";
			if (program.hasShader(SHADERTYPE_FRAGMENT))
				ssLog << "Fragment: " << program.getShaderInfo(SHADERTYPE_FRAGMENT).infoLog << "\n";
			ssLog << "Program: " << program.getProgramInfo().infoLog;

			m_testCtx.getLog() << tcu::TestLog::Message << ssLog.str() << tcu::TestLog::EndMessage;

			m_testCtx.setTestResult(QP_TEST_RESULT_FAIL, "Fail");
			return STOP;
		}

#if defined DEQP_HAVE_SPIRV_TOOLS
		for (int s = 0; s < (signed)pipeline.size(); ++s)
		{
			ShaderStage  stage  = pipeline[s];
			ShaderBinary binary = stage.binary;

			std::string spirVSource;
			spirvUtils::spirvDisassemble(spirVSource, binary.binary);

			for (int c = 0; c < (signed)stage.caps.size(); ++c)
			{
				std::string spirVSourceCut;
				int			foundCount = spirVCapabilityCutOff(spirVSource, spirVSourceCut, stage.caps, c);

				if (foundCount == 0)
				{
					m_testCtx.getLog()
						<< tcu::TestLog::Message << "OpCapability (" << stage.caps[c] << ") [" << p << "/" << s
						<< "].\n"
						<< "Neither capability nor capabilities that depends on this capability has been found."
						<< tcu::TestLog::EndMessage;
				}
				else
				{
					// Assemble and validate cut off SpirV source
					spirvUtils::spirvAssemble(binary.binary, spirVSourceCut);
					if (spirvUtils::spirvValidate(binary.binary, false))
					{
						m_testCtx.getLog() << tcu::TestLog::Message << "OpCapability (" << stage.caps[c] << ") [" << p
										   << "/" << s << "].\n"
										   << "Validation passed without corresponding OpCapability declared."
										   << tcu::TestLog::EndMessage;
					}
				}
			}
		}
#endif // DEQP_HAVE_SPIRV_TOOLS
	}

	m_testCtx.setTestResult(QP_TEST_RESULT_PASS, "Pass");
	return STOP;
}