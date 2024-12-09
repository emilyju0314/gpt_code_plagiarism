bool isOfRootType(const Type& type, const Type& root) {
    struct visitor : public VisitOnceTypeVisitor<bool> {
        const Type& root;

        visitor(const Type& root) : root(root) {}

        bool visitPredefinedType(const PredefinedType& type) const override {
            return type == root;
        }
        bool visitPrimitiveType(const PrimitiveType& type) const override {
            return type == root || type.getBaseType() == root || isOfRootType(type.getBaseType(), root);
        }
        bool visitUnionType(const UnionType& type) const override {
            if (type.getElementTypes().empty()) {
                return false;
            }
            auto fit = [&](const Type* cur) { return visit(*cur); };
            return all_of(type.getElementTypes(), fit);
        }
        bool visitType(const Type& /*unused*/) const override {
            return false;
        }
    };

    return visitor(root).visit(type);
}