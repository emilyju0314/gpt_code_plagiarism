void NodePrinter::printSimplifiedEntityType(NodePointer context,
                                            NodePointer entityType) {
  // Only do anything special to methods.
  if (!isMethodContext(context)) return print(entityType);

  // Strip off a single level of uncurried function type.
  NodePointer type = entityType;
  assert(type->getKind() == Node::Kind::Type);
  type = type->getChild(0);

  NodePointer generics;
  if (type->getKind() == Node::Kind::GenericType ||
      type->getKind() == Node::Kind::DependentGenericType) {
    generics = type->getChild(0);
    type = type->getChild(1)->getChild(0);
  }

  print(entityType);
}