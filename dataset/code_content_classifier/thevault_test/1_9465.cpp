void fix_double_notation(char *str)
{
    int i;
    for (i = 1; i < strlen(str) - 1; i++) {
        if ((str[i] == 'd') || (str[i] == 'D')) {
            if (isdigit(str[i - 1]) && (isdigit(str[i + 1]) ||
                               (str[i + 1] == '-') || (str[i + 1] == '+'))) {
                str[i] = 'e';
            }
        }
    }
}