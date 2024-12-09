Expect<void> Loader::loadExpression(AST::Expression &Expr,
                                    std::optional<uint64_t> SizeBound) {
  if (auto Res = loadInstrSeq(SizeBound)) {
    // For the section size mismatch case, check in caller.
    Expr.getInstrs() = std::move(*Res);
  } else {
    spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Expression));
    return Unexpect(Res);
  }
  return {};
}