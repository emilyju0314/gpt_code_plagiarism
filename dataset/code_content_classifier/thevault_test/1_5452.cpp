bool tiramisu::computation::is_let_stmt() const
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    std::string s1 = "This computation is ";
    std::string s2 = (is_let?" a ":" not a ");
    std::string s3 = "let statement.";

    DEBUG(10, tiramisu::str_dump(s1 + s2 + s3));

    DEBUG_INDENT(-4);

    return is_let;
}