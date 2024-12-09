Expect<void> Loader::loadSegment(AST::ElementSegment &ElemSeg) {
  // Element segment binary format:
  // ---------------------------------------------------------------------------
  //  byte | TableIdx | OffExpr | ElemKind | RefType | vec(FuncIdx) | vec(expr)
  // ------|----------|---------|----------|---------|--------------|-----------
  //  0x00 |          |    v    |          |         |       v      |
  //  0x01 |          |         |    v     |         |       v      |
  //  0x02 |    v     |    v    |    v     |         |       v      |
  //  0x03 |          |         |    v     |         |       v      |
  //  0x04 |          |    v    |          |         |              |     v
  //  0x05 |          |         |          |    v    |              |     v
  //  0x06 |    v     |    v    |          |    v    |              |     v
  //  0x07 |          |         |          |    v    |              |     v
  // ---------------------------------------------------------------------------
  // TableIdx: target table index, u32
  // OffExpr: init offset expression, expr
  // ElemKind: byte 0x00, RefType::FuncRef
  // RefType: reference type, RefType
  // vec(FuncIdx): function index vector, vec(u32)
  // vec(expr): reference init list, vec(expr)

  // Read the checking byte.
  uint32_t Check;
  if (auto Res = FMgr.readU32()) {
    Check = *Res;
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Seg_Element);
  }
  // Check > 0 cases are for BulkMemoryOperations or ReferenceTypes proposal.
  if (Check > 0 && !Conf.hasProposal(Proposal::BulkMemoryOperations) &&
      !Conf.hasProposal(Proposal::ReferenceTypes)) {
    return logNeedProposal(ErrCode::ExpectedZeroByte,
                           Proposal::BulkMemoryOperations, FMgr.getLastOffset(),
                           ASTNodeAttr::Seg_Element);
  }

  // Check the prefix byte.
  switch (Check) {
  case 0x00:
  case 0x02:
  case 0x04:
  case 0x06:
    ElemSeg.setMode(AST::ElementSegment::ElemMode::Active);
    break;

  case 0x01:
  case 0x05:
    ElemSeg.setMode(AST::ElementSegment::ElemMode::Passive);
    break;

  case 0x03:
  case 0x07:
    ElemSeg.setMode(AST::ElementSegment::ElemMode::Declarative);
    break;

  default:
    // TODO: Correctness the error code once there's spec test.
    return logLoadError(ErrCode::IllegalGrammar, FMgr.getLastOffset(),
                        ASTNodeAttr::Seg_Element);
  }

  // Read the table index.
  ElemSeg.setIdx(0);
  switch (Check) {
  case 0x02:
  case 0x06:
    if (auto Res = FMgr.readU32()) {
      ElemSeg.setIdx(*Res);
    } else {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Element);
    }
    break;

  default:
    break;
  }

  // Read the expression.
  switch (Check) {
  case 0x00:
  case 0x02:
  case 0x04:
  case 0x06:
    if (auto Res = loadExpression(ElemSeg.getExpr()); unlikely(!Res)) {
      spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Seg_Element));
      return Unexpect(Res);
    }
    break;

  default:
    break;
  }

  // Read element kind and init function indices.
  ElemSeg.setRefType(RefType::FuncRef);
  switch (Check) {
  case 0x01:
  case 0x02:
  case 0x03:
    if (auto Res = FMgr.readByte()) {
      if (*Res != 0x00U) {
        return logLoadError(ErrCode::ExpectedZeroByte, FMgr.getLastOffset(),
                            ASTNodeAttr::Seg_Element);
      }
    } else {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Element);
    }
    [[fallthrough]];

  case 0x00: {
    uint32_t VecCnt = 0;
    if (auto Res = FMgr.readU32()) {
      VecCnt = *Res;
    } else {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Element);
    }
    for (uint32_t I = 0; I < VecCnt; ++I) {
      // For each element in vec(funcidx), make expr(ref.func idx end).
      ElemSeg.getInitExprs().emplace_back();
      AST::Instruction RefFunc(OpCode::Ref__func);
      AST::Instruction End(OpCode::End);
      if (auto Res = loadInstruction(RefFunc); unlikely(!Res)) {
        spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Seg_Element));
        return Unexpect(Res);
      }
      ElemSeg.getInitExprs().back().getInstrs().emplace_back(
          std::move(RefFunc));
      ElemSeg.getInitExprs().back().getInstrs().emplace_back(std::move(End));
    }
    break;
  }
  default:
    break;
  }

  // Read the reference type and init expressions.
  switch (Check) {
  case 0x05:
  case 0x06:
  case 0x07:
    if (auto Res = FMgr.readByte(); unlikely(!Res)) {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Element);
    } else {
      ElemSeg.setRefType(static_cast<RefType>(*Res));
    }
    if (auto Res =
            checkRefTypeProposals(ElemSeg.getRefType(), FMgr.getLastOffset(),
                                  ASTNodeAttr::Seg_Element);
        unlikely(!Res)) {
      return Unexpect(Res);
    }
    [[fallthrough]];

  case 0x04: {
    uint32_t VecCnt = 0;
    if (auto Res = FMgr.readU32(); unlikely(!Res)) {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Seg_Element);
    } else {
      VecCnt = *Res;
    }
    ElemSeg.getInitExprs().clear();
    ElemSeg.getInitExprs().reserve(VecCnt);
    for (uint32_t I = 0; I < VecCnt; ++I) {
      ElemSeg.getInitExprs().emplace_back();
      if (auto Res = loadExpression(ElemSeg.getInitExprs().back());
          unlikely(!Res)) {
        spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Seg_Element));
        return Unexpect(Res);
      }
    }
    break;
  }

  default:
    break;
  }

  return {};
}