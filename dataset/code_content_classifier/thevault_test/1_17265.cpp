void NullFragmentShader::addDummyExportIfNecessary(Function *entryPoint) const {
  if (m_lgcContext->getTargetInfo().getGfxIpVersion().major < 10) {
    auto ret = cast<ReturnInst>(entryPoint->back().getTerminator());
    BuilderBase builder(ret);
    FragColorExport::addDummyExport(builder);
  }
}