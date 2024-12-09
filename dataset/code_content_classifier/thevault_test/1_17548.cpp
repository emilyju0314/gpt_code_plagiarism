void
printPath(llvm::raw_ostream& out, std::vector<llvm::BasicBlock*>& blocks) {
  unsigned line = 0;
  llvm::StringRef file;
  for (auto* bb : blocks) {
    for (auto& instruction : *bb) {
      llvm::DILocation* loc = instruction.getDebugLoc();
      if (loc && (loc->getLine() != line || loc->getFilename() != file)) {
        line = loc->getLine();
        file = loc->getFilename();
        out << ", " << file.str() << ", " << line;
      }
    }
  }
}