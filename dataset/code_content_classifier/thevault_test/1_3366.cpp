void AstProgram::addRelation(std::unique_ptr<AstRelation> r) {
    const auto& name = r->getName();
    assert(relations.find(name) == relations.end() && "Redefinition of relation!");
    relations[name] = std::move(r);
}