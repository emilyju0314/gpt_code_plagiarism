Expect<void> Loader::loadDesc(AST::ImportDesc &ImpDesc) {
  // Read the module name.
  if (auto Res = FMgr.readName()) {
    ImpDesc.setModuleName(*Res);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Import);
  }

  // Read the external name.
  if (auto Res = FMgr.readName()) {
    ImpDesc.setExternalName(*Res);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Import);
  }

  // Read the external type.
  if (auto Res = FMgr.readByte()) {
    ImpDesc.setExternalType(static_cast<ExternalType>(*Res));
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Import);
  }

  // Make content node according to external type.
  switch (ImpDesc.getExternalType()) {
  case ExternalType::Function: {
    // Read the function type index.
    if (auto Res = FMgr.readU32()) {
      ImpDesc.setExternalFuncTypeIdx(*Res);
    } else {
      return logLoadError(Res.error(), FMgr.getLastOffset(),
                          ASTNodeAttr::Desc_Import);
    }
    break;
  }
  case ExternalType::Table: {
    // Read the table type node.
    return loadType(ImpDesc.getExternalTableType());
  }
  case ExternalType::Memory: {
    // Read the memory type node.
    return loadType(ImpDesc.getExternalMemoryType());
  }
  case ExternalType::Global: {
    // Read the global type node.
    if (auto Res = loadType(ImpDesc.getExternalGlobalType()); !Res) {
      return Unexpect(Res.error());
    }
    // Import the mutable globals are for ImportExportMutGlobals proposal.
    if (ImpDesc.getExternalGlobalType().getValMut() == ValMut::Var &&
        unlikely(!Conf.hasProposal(Proposal::ImportExportMutGlobals))) {
      return logNeedProposal(ErrCode::InvalidMut,
                             Proposal::ImportExportMutGlobals,
                             FMgr.getLastOffset(), ASTNodeAttr::Desc_Import);
    }
    return {};
  }
  default:
    return logLoadError(ErrCode::MalformedImportKind, FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Import);
  }
  return {};
}