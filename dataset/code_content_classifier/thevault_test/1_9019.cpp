static Optional<AttributeInsertion>
createAttributeInsertion(const NamedDecl *D, const SourceManager &SM,
                         const LangOptions &LangOpts) {
  if (isa<ObjCPropertyDecl>(D))
    return AttributeInsertion::createInsertionAfter(D);
  if (const auto *MD = dyn_cast<ObjCMethodDecl>(D)) {
    if (MD->hasBody())
      return None;
    return AttributeInsertion::createInsertionAfter(D);
  }
  if (const auto *TD = dyn_cast<TagDecl>(D)) {
    SourceLocation Loc =
        Lexer::getLocForEndOfToken(TD->getInnerLocStart(), 0, SM, LangOpts);
    if (Loc.isInvalid())
      return None;
    // Insert after the 'struct'/whatever keyword.
    return AttributeInsertion::createInsertionAfter(Loc);
  }
  return AttributeInsertion::createInsertionBefore(D);
}