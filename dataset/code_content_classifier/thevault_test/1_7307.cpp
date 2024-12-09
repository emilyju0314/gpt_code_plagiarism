int fl_utf_strncasecmp(const char *s1, const char *s2, int n)
{
        int i;
        int s1_l;
        int s2_l;
        char *e1, *e2; // string end pointers

        s1_l = 0;
        while (s1_l < n && s1[s1_l]) s1_l++;
        s2_l = 0;
        while (s2_l < n && s2[s2_l]) s2_l++;

        if (s1_l < s2_l) {
                return -1;
        } else if (s1_l > s2_l) {
                return 1;
        }
		e1 = (char *)&s1[s1_l]; // last char to test
		e2 = (char *)&s2[s2_l];
        for (i = 0; i < n;) {
                int l1, l2;
                unsigned int u1, u2;
                int res;

//              l1 = fl_utf2ucs((unsigned char*)s1 + i, n - i, &u1);
                u1 = fl_utf8decode(s1 + i, e1, &l1);
//              l2 = fl_utf2ucs((unsigned char*)s2 + i, n - i, &u2);
                u2 = fl_utf8decode(s2 + i, e2, &l2);
                if (l1 - l2 != 0) return l1 - l2;
                res = XUtf8Tolower(u1) - XUtf8Tolower(u2);
                if (res != 0) return res;
                if (l1 < 1) {
                        i += 1;
                } else {
                        i += l1;
                }
        }
        return 0;
}