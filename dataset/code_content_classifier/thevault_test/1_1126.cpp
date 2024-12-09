void GlSpirvTests::init()
{
	addChild(new SpirvModulesPositiveTest(m_context));
	addChild(new SpirvShaderBinaryMultipleShaderObjectsTest(m_context));
	addChild(new SpirvModulesStateQueriesTest(m_context));
	addChild(new SpirvModulesErrorVerificationTest(m_context));
	addChild(new SpirvGlslToSpirVEnableTest(m_context));
	addChild(new SpirvGlslToSpirVBuiltInFunctionsTest(m_context));
	addChild(new SpirvGlslToSpirVSpecializationConstantsTest(m_context));
	addChild(new SpirvValidationBuiltInVariableDecorationsTest(m_context));
	addChild(new SpirvValidationCapabilitiesTest(m_context));
}