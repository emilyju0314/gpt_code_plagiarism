Module *NullFragmentShader::generateEmptyModule() const {
  Module *module = new Module("nullFragmentShader", getContext());
  TargetMachine *targetMachine = m_lgcContext->getTargetMachine();
  module->setTargetTriple(targetMachine->getTargetTriple().getTriple());
  module->setDataLayout(targetMachine->createDataLayout());
  return module;
}