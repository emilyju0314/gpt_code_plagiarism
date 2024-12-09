int fl_utf_strcasecmp(const char *s1, const char *s2)
{
	int s1_l = strlen(s1);
	int s2_l = strlen(s2);

        if (s1_l < s2_l) {
                return -1;
        } else if (s1_l > s2_l) {
                return 1;
	}
	return fl_utf_strncasecmp(s1, s2, s1_l);
}