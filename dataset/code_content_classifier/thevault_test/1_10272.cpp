void Parser::consume(lexer_namespace::Token::Symbol token_type)
{
    if(currentToken->getSymbol() != token_type)
        error("expected token " + lexer_namespace::Token::typeToString(token_type)); // in this situation parser can 'ignore' the lack of expected token
    nextToken();
}