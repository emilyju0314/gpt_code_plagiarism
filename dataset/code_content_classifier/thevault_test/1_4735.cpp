Expect<void> Loader::loadCompiled(AST::Module &Mod) {
  auto &FuncTypes = Mod.getTypeSection().getContent();
  for (size_t I = 0; I < FuncTypes.size(); ++I) {
    const std::string Name = "t" + std::to_string(I);
    if (auto Symbol =
            LMgr.getSymbol<AST::FunctionType::Wrapper>(Name.c_str())) {
      FuncTypes[I].setSymbol(std::move(Symbol));
    }
  }
  size_t Offset = 0;
  for (const auto &ImpDesc : Mod.getImportSection().getContent()) {
    if (ImpDesc.getExternalType() == ExternalType::Function) {
      ++Offset;
    }
  }
  auto &CodeSegs = Mod.getCodeSection().getContent();
  for (size_t I = 0; I < CodeSegs.size(); ++I) {
    const std::string Name = "f" + std::to_string(I + Offset);
    if (auto Symbol = LMgr.getSymbol<void>(Name.c_str())) {
      CodeSegs[I].setSymbol(std::move(Symbol));
    }
  }
  return {};
}