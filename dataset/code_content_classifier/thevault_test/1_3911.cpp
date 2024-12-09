bool lex_stream_t::implementation_t::is_compound(char c, stream_lex_token_t& result)
{
    char next_char (compound_match_g[(unsigned char)c]);
    
    if (next_char == '0') return false;
    
    int actual_char (_super::peek_char());
    
    if (actual_char == EOF || actual_char != next_char) return false;
    
    _super::ignore_char();
    
    /*
    There is only a single 3 character compound. It is special cased here rather than adding an
    additional table. The token is '<=='.
    */
    
    if (c == '<' && _super::peek_char() == '=')
    {
        _super::ignore_char();
        result = stream_lex_token_t(is_k, any_regular_t());
        return true;
    }

    result = stream_lex_token_t(name_table_g[compound_index_g[(unsigned char)c]], any_regular_t());
    return true;
}