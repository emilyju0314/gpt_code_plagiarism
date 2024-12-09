void AstProgram::addType(std::unique_ptr<AstType> type) {
    auto& cur = types[type->getName()];
    assert(!cur && "Redefinition of type!");
    cur = std::move(type);
}