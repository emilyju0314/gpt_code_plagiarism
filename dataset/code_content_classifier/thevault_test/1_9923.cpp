std::string UniquifySymbol(const Module &M, GlobalVariable &Sym)
{
  std::string newName;
  std::string::size_type loc;
  auto filter = [](char c){ return !isalnum(c); };

  newName = M.getName();
  loc = newName.find_last_of('.');
  newName = newName.substr(0, loc) + "_" + Sym.getName().str() + "_";
  std::replace_if(newName.begin(), newName.end(), filter, '_');

  // Check if it's a string, and if so use string content to uniquify
  if(Sym.hasInitializer()) {
    Constant *Initializer = Sym.getInitializer();
    if(isa<ConstantDataSequential>(Initializer)) {
      ConstantDataSequential *CDS = cast<ConstantDataSequential>(Initializer);
      if(CDS->isString()) {
        std::string data = CDS->getAsString().substr(0, CHARS_FOR_NAME);
        std::replace_if(data.begin(), data.end(), filter, '_');
        newName += data;
      }
    }
  }

  return newName;
}