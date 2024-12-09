static void PropagateAttributes(Operation *src, Operation *dst) {
  auto device = mlir::Identifier::get("device", src->getContext());
  for (auto named_attr : src->getAttrs()) {
    if (*named_attr.first.begin() == '_' || named_attr.first == device)
      dst->setAttr(named_attr.first, named_attr.second);
  }
}