void AstProgram::addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration> f) {
    const auto& name = f->getName();
    assert(functors.find(name) == functors.end() && "Redefinition of relation!");
    functors[name] = std::move(f);
}