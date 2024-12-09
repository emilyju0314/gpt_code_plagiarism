Expect<void> Loader::loadDesc(AST::ExportDesc &ExpDesc) {
  // Read external name to export.
  if (auto Res = FMgr.readName()) {
    ExpDesc.setExternalName(*Res);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Export);
  }

  // Read external type.
  if (auto Res = FMgr.readByte()) {
    ExpDesc.setExternalType(static_cast<ExternalType>(*Res));
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Export);
  }
  switch (ExpDesc.getExternalType()) {
  case ExternalType::Function:
  case ExternalType::Table:
  case ExternalType::Memory:
  case ExternalType::Global:
    break;
  default:
    return logLoadError(ErrCode::MalformedExportKind, FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Export);
  }

  // Read external index to export.
  if (auto Res = FMgr.readU32()) {
    ExpDesc.setExternalIndex(*Res);
  } else {
    return logLoadError(Res.error(), FMgr.getLastOffset(),
                        ASTNodeAttr::Desc_Export);
  }
  return {};
}