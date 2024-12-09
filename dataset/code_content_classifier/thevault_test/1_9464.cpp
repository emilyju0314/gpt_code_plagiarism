int next_group()
{
    char line_str[85];
    int char_flag = 0;
    while (char_flag == 0) {
        if (fgets(line_str, 84, inst) == NULL) {
            return -1;
        }
	int i;
        for (i = strlen(line_str) - 1; i >= 0; i--) {
            if ((line_str[i] == ' ') || (line_str[i] == '\n')) {
                line_str[i] = '\0';
            } else {
                char_flag++;
                break;
            }
        }
    }
    char group[85];
    int group_num;
    sscanf(line_str, "%s %d", group, &group_num);
    if (strcmp(group, "GROUP")) {
        printf("Expected group line not seen (%s)\n", line_str);
        return -1;
    }
//    Found the header.  Read the blank line so we can get at the data.
    fgets(line_str, 84, inst);
    return group_num;
}