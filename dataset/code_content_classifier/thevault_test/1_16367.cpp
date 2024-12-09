void Parser::skipTo(SyntaxKind tkK)
{
    auto curTkK = peek().kind();
    while (curTkK != tkK) {
        if (curTkK == EndOfFile)
            return;
        consume();
        curTkK = peek().kind();
    }
}