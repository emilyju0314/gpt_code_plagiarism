void MutationCheck(ObjHeader* obj) {
  if (obj->local()) return;
  auto* container = containerFor(obj);
  if (container == nullptr || container->frozen())
    ThrowInvalidMutabilityException(obj);
}