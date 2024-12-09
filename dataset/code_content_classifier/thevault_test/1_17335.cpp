void FunctionDumper::addPHIDeclaration(llvm::PHINode *phi) {
    string name = localNames.getOrCreateName(phi);
    string declaration = typeDumper->dumpType(phi->getType()) + " " + name;
    phiDeclarationsByName[name] = declaration;
}