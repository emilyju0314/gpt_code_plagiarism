static Demangle::NodePointer
_buildDemanglingForNominalType(const Metadata *type, Demangle::Demangler &Dem) {
  using namespace Demangle;

  const NominalTypeDescriptor *description;

  // Demangle the parent type, if any.
  switch (type->getKind()) {
  case MetadataKind::Class: {
    auto classType = static_cast<const ClassMetadata *>(type);
#if SWIFT_OBJC_INTEROP
    // Peek through artificial subclasses.
    while (classType->isTypeMetadata() && classType->isArtificialSubclass())
      classType = classType->SuperClass;
#endif
    description = classType->getDescription();
    break;
  }
  case MetadataKind::Enum:
  case MetadataKind::Optional: {
    auto enumType = static_cast<const EnumMetadata *>(type);
    description = enumType->Description;
    break;
  }
  case MetadataKind::Struct: {
    auto structType = static_cast<const StructMetadata *>(type);
    description = structType->Description;
    break;
  }
  default:
    return nullptr;
  }

  // Demangle the base name.
  auto node = Dem.demangleType(StringRef(description->Name));
  assert(node->getKind() == Node::Kind::Type);

  auto typeBytes = reinterpret_cast<const char *>(type);
  auto genericArgs = reinterpret_cast<const Metadata * const *>(
               typeBytes + sizeof(void*) * description->GenericParams.Offset);

  return _applyGenericArguments(genericArgs, description, node,
                                description->GenericParams.NestingDepth,
                                Dem);
}