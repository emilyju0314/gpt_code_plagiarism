unsigned NodePrinter::printFunctionSigSpecializationParam(NodePointer pointer,
                                                          unsigned Idx) {
  NodePointer firstChild = pointer->getChild(Idx);
  unsigned V = (unsigned)firstChild->getIndex();
  auto K = FunctionSigSpecializationParamKind(V);
  switch (K) {
  case FunctionSigSpecializationParamKind::BoxToValue:
  case FunctionSigSpecializationParamKind::BoxToStack:
    print(pointer->getChild(Idx++));
    return Idx;
  case FunctionSigSpecializationParamKind::ConstantPropFunction:
  case FunctionSigSpecializationParamKind::ConstantPropGlobal: {
    Printer << "[";
    print(pointer->getChild(Idx++));
    Printer << " : ";
    const auto &text = pointer->getChild(Idx++)->getText();
    std::string demangledName = demangleSymbolAsString(text);
    if (demangledName.empty()) {
      Printer << text;
    } else {
      Printer << demangledName;
    }
    Printer << "]";
    return Idx;
  }
  case FunctionSigSpecializationParamKind::ConstantPropInteger:
  case FunctionSigSpecializationParamKind::ConstantPropFloat:
    Printer << "[";
    print(pointer->getChild(Idx++));
    Printer << " : ";
    print(pointer->getChild(Idx++));
    Printer << "]";
    return Idx;
  case FunctionSigSpecializationParamKind::ConstantPropString:
    Printer << "[";
    print(pointer->getChild(Idx++));
    Printer << " : ";
    print(pointer->getChild(Idx++));
    Printer << "'";
    print(pointer->getChild(Idx++));
    Printer << "'";
    Printer << "]";
    return Idx;
  case FunctionSigSpecializationParamKind::ClosureProp:
    Printer << "[";
    print(pointer->getChild(Idx++));
    Printer << " : ";
    print(pointer->getChild(Idx++));
    Printer << ", Argument Types : [";
    for (unsigned e = (unsigned)pointer->getNumChildren(); Idx < e;) {
      NodePointer child = pointer->getChild(Idx);
      // Until we no longer have a type node, keep demangling.
      if (child->getKind() != Node::Kind::Type)
        break;
      print(child);
      ++Idx;

      // If we are not done, print the ", ".
      if (Idx < e && pointer->getChild(Idx)->hasText())
        Printer << ", ";
    }
    Printer << "]";
    return Idx;
  default:
    break;
  }

  assert(
      ((V & unsigned(FunctionSigSpecializationParamKind::OwnedToGuaranteed)) ||
       (V & unsigned(FunctionSigSpecializationParamKind::SROA)) ||
       (V & unsigned(FunctionSigSpecializationParamKind::Dead))) &&
      "Invalid OptionSet");
  print(pointer->getChild(Idx++));
  return Idx;
}