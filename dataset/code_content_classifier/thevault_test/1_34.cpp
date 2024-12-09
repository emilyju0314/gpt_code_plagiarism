bool requiresBracketWithSimpleAlgorithm(
    KORECompositePattern *outer, KORECompositePattern *leftCapture,
    KORECompositePattern *rightCapture, KOREPattern *inner, int position,
    PrettyPrintData const &data) {
  if (auto innerComposite = dynamic_cast<KORECompositePattern *>(inner)) {
    std::string innerName = innerComposite->getConstructor()->getName();
    if (innerName == outer->getConstructor()->getName()) {
      if (data.assoc.count(innerName)) {
        return false;
      }
    }
    if (innerName == "\\dv") {
      return false;
    }
    Fixity fixity = getFixity(position, outer->getConstructor(), data);
    if (fixity == EMPTY) {
      return false;
    }
    bool priority = isPriorityWrong(outer, innerComposite, position, data);
    if (priority) {
      return true;
    }
    if (data.terminals.at(innerName) == "0") {
      return false;
    }
    Fixity innerFixity = getFixity(innerComposite->getConstructor(), data);
    if ((innerFixity & BARE_RIGHT) && rightCapture != nullptr) {
      bool inversePriority = isPriorityWrong(
          innerComposite, rightCapture,
          innerComposite->getArguments().size() - 1, data);
      Fixity rightCaptureFixity
          = getFixity(rightCapture->getConstructor(), data);
      if (!inversePriority && (rightCaptureFixity & BARE_LEFT)) {
        return true;
      }
    }
    if ((innerFixity & BARE_LEFT) && leftCapture != nullptr) {
      bool inversePriority
          = isPriorityWrong(innerComposite, leftCapture, 0, data);
      Fixity leftCaptureFixity = getFixity(leftCapture->getConstructor(), data);
      if (!inversePriority && (leftCaptureFixity & BARE_RIGHT)) {
        return true;
      }
    }
    return false;
  } else {
    return false;
  }
}