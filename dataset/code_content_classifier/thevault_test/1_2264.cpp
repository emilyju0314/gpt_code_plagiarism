std::string CodedNameForEnvelope(const fidl::coded::Type* type) {
  switch (type->kind) {
    case coded::Type::Kind::kPrimitive: {
      using fidl::types::PrimitiveSubtype;
      // To save space, all primitive types of the same underlying subtype
      // share the same table.
      std::string suffix =
          PrimitiveSubtypeToString(static_cast<const coded::PrimitiveType*>(type)->subtype);
      return "fidl_internal_k" + suffix;
    }
    default:
      return type->coded_name;
  }
}