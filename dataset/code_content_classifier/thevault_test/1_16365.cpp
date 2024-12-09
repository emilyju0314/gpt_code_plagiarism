bool Parser::match(SyntaxKind expectedTkK, LexedTokens::IndexType* tkIdx)
{
    auto curTkK = peek().kind();
    if (curTkK == expectedTkK)
    {
        *tkIdx = consume();
        return true;
    }

    diagnosticsReporter_.ExpectedToken(SyntaxKind(expectedTkK));

    if (curTkK != EndOfFile)
        consume();
    *tkIdx = LexedTokens::invalidIndex();
    return false;
}