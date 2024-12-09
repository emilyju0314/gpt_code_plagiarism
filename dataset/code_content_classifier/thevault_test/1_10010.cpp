static
bool isRelatedType(const Metadata *type, const void *candidate,
                   bool candidateIsMetadata) {

  while (true) {
    if (type == candidate && candidateIsMetadata)
      return true;

    // If the type is resilient or generic, see if there's a witness table
    // keyed off the nominal type descriptor.
    const auto *description = type->getNominalTypeDescriptor();
    if (description == candidate && !candidateIsMetadata)
      return true;

    // If the type is a class, try its superclass.
    if (const ClassMetadata *classType = type->getClassObject()) {
      if (classHasSuperclass(classType)) {
        type = getMetadataForClass(classType->SuperClass);
        continue;
      }
    }

    break;
  }

  return false;
}