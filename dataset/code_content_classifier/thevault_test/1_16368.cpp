TranslationUnitSyntax* Parser::parse()
{
    auto unit = makeNode<TranslationUnitSyntax>();
    parseTranslationUnit(unit);
    return unit;
}