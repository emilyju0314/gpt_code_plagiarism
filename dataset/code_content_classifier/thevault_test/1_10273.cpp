std::unique_ptr<lexer_namespace::Token> Parser::accept(std::initializer_list<lexer_namespace::Token::Symbol> token_types)
{
    bool ok = false;
    for(auto token : token_types)
    {
        if(currentToken->getSymbol() == token)
        {
            ok = true;
            break;
        }
    }
    if(!ok)
    {
        std::string msg = "expected token types:";
        for(auto token : token_types)
            msg += " " + lexer_namespace::Token::typeToString(token);
        error(std::move(msg)); // in this situation parser can NOT 'ignore' the lack of expected token
    }
    std::unique_ptr<lexer_namespace::Token> retval = std::move(currentToken);
    nextToken();
    return std::move(retval);
}