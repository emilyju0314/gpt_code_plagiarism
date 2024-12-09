bool is_quoted_char(char c)
{
    // 0x7F is the Delete key which is viewed as a control
    // here we accept all characters over 127 in case the user
    // has UTF-8 as input data
    return c == '\t' || c >= ' ' && c != 0x7F;
}