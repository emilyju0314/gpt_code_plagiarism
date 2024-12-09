std::vector<AstRelation*> AstProgram::getRelations() const {
    std::vector<AstRelation*> res;
    for (const auto& rel : relations) {
        res.push_back(rel.second.get());
    }
    return res;
}