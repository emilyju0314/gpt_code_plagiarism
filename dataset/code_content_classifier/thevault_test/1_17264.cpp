Module *NullFragmentShader::generate() {
  Module *module = generateEmptyModule();
  Function *entryPoint = FragColorExport::generateNullFragmentShader(*module, getGlueShaderName());
  addDummyExportIfNecessary(entryPoint);
  return module;
}