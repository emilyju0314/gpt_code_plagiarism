void fix(char *s) {
    int i = 0;
    while (s[i] != '\n')
        i++;
    s[i] = '\0';
}