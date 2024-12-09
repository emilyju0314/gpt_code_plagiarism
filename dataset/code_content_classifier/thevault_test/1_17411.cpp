int separate_cmdline (char* cmdline, char* cmd_params[256])
{
    int index = 0; // index of a command line we are reading from
    int param = 0; // current parameter
    int param_index = 0; // current character in the parameter
    int in_single_quote = 0; // are we in a single quote
    int in_double_quote = 0; // are we in a double quote
    while (cmdline[index] != '\0')
    {
        // skip spaces
        while ((cmdline[index] != '\0') && (isspace(cmdline[index])))
            index++;

        // loop copying the parameter
        cmd_params[param] = &cmdline[param_index];
        while ((cmdline[index] != '\0') && ((!isspace(cmdline[index])) || in_single_quote || in_double_quote))
        {
            if (cmdline[index] == '\'')
                in_single_quote = !in_single_quote;
            if (cmdline[index] == '\"')
                in_double_quote = !in_double_quote;
            if ((cmdline[index] != '\'') && (cmdline[index] != '\"'))
            {
                cmdline[param_index] = cmdline[index];
                ++param_index;
            }
            ++index;
        }
        if (in_single_quote || in_double_quote)
        {
            // error if we reached the end of the command line and are still in a quote
            printf("command line error!\n");
            return -1;
        }
        cmdline[param_index] = '\0';
        ++param_index;
        ++param;
        ++index;
    }
    cmd_params[param] = NULL;
    return 0;
}