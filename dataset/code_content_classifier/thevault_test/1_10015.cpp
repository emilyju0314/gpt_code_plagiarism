void SILWalaInstructionVisitor::updateInstrSourceInfo(SILInstruction *I) {
  SourceManager &srcMgr = I->getModule().getSourceManager();

  // Get file-line-col information for the source
  SILLocation debugLoc = I->getDebugLocation().getLocation();
  SILLocation::DebugLoc debugInfo = debugLoc.decodeDebugLoc(srcMgr);

  InstrInfo->Filename = debugInfo.Filename;

  if (I->getLoc().isNull()) {
    InstrInfo->srcType = -1;
  } else {

    SourceRange srcRange = I->getLoc().getSourceRange();
    SourceLoc srcStart = srcRange.Start;
    SourceLoc srcEnd = srcRange.End;

    if (srcStart.isValid()) {

      InstrInfo->srcType = 0;

      auto startLineCol = srcMgr.getLineAndColumn(srcStart);
      InstrInfo->startLine = startLineCol.first;
      InstrInfo->startCol = startLineCol.second;

    } else {
      InstrInfo->startLine = debugInfo.Line;
      InstrInfo->startCol = debugInfo.Column;
    }

    if (srcEnd.isValid()) {

      auto endLineCol = srcMgr.getLineAndColumn(srcEnd);
      InstrInfo->endLine = endLineCol.first;
      InstrInfo->endCol = endLineCol.second;
    } else {
      InstrInfo->srcType = 1;
    }
  }
}