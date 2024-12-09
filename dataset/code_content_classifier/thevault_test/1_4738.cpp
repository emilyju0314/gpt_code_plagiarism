Expect<void> Loader::loadSegment(AST::CodeSegment &CodeSeg) {
  // Read the code segment size.
  if (auto Res = FMgr.readU32()) {
    CodeSeg.setSegSize(*Res);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Seg_Code);
  }
  auto ExprSizeBound = FMgr.getOffset() + CodeSeg.getSegSize();

  // Read the vector of local variable counts and types.
  uint32_t VecCnt = 0;
  if (auto Res = FMgr.readU32()) {
    VecCnt = *Res;
    CodeSeg.getLocals().clear();
    CodeSeg.getLocals().reserve(VecCnt);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Seg_Code);
  }
  uint32_t TotalLocalCnt = 0;
  for (uint32_t I = 0; I < VecCnt; ++I) {
    uint32_t LocalCnt = 0;
    ValType LocalType = ValType::None;
    if (auto Res = FMgr.readU32(); unlikely(!Res)) {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Code);
    } else {
      LocalCnt = *Res;
    }
    // Total local variables should not more than 2^32.
    if (UINT32_MAX - TotalLocalCnt < LocalCnt) {
      return logLoadError(ErrCode::TooManyLocals, FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Code);
    }
    TotalLocalCnt += LocalCnt;
    // Read the number type.
    if (auto Res = FMgr.readByte(); unlikely(!Res)) {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Code);
    } else {
      LocalType = static_cast<ValType>(*Res);
    }
    if (auto Res = checkValTypeProposals(LocalType, FMgr.getLastOffset(),
                                         ASTNodeAttr::Seg_Code);
        unlikely(!Res)) {
      return Unexpect(Res);
    }
    CodeSeg.getLocals().push_back(std::make_pair(LocalCnt, LocalType));
  }

  if (IsUniversalWASM || IsSharedLibraryWASM) {
    // For the AOT mode, skip the function body.
    FMgr.seek(ExprSizeBound);
  } else {
    // Read function body with expected expression size.
    if (auto Res = loadExpression(CodeSeg.getExpr(), ExprSizeBound);
        unlikely(!Res)) {
      spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Seg_Code));
      return Unexpect(Res);
    }
  }

  return {};
}