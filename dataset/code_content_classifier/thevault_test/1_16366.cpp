bool Parser::matchOrSkipTo(SyntaxKind expectedTkK, LexedTokens::IndexType* tkIdx)
{
    if (match(expectedTkK, tkIdx))
        return true;
    skipTo(expectedTkK);
    return false;
}