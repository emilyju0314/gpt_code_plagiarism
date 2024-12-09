std::string to_wgsl_type(const Type& type) {
    // TODO(skia:13092): Handle array, matrix, sampler types.
    switch (type.typeKind()) {
        case Type::TypeKind::kScalar:
            return std::string(to_scalar_type(type));
        case Type::TypeKind::kVector:
            return "vec" + std::to_string(type.columns()) + "<" +
                   std::string(to_scalar_type(type.componentType())) + ">";
        default:
            break;
    }
    return std::string(type.name());
}