static gchar* convertUniCharToUTF8(const UChar* characters, gint length, int from, int to)
{
    CString stringUTF8 = UTF8Encoding().encode(characters, length, QuestionMarksForUnencodables);
    gchar* utf8String = utf8Substr(stringUTF8.data(), from, to);
    if (!g_utf8_validate(utf8String, -1, 0)) {
        g_free(utf8String);
        return 0;
    }
    gsize len = strlen(utf8String);
    GString* ret = g_string_new_len(0, len);
    gchar* ptr = utf8String;

    // WebCore introduces line breaks in the text that do not reflect
    // the layout you see on the screen, replace them with spaces
    while (len > 0) {
        gint index, start;
        pango_find_paragraph_boundary(ptr, len, &index, &start);
        g_string_append_len(ret, ptr, index);
        if (index == start)
            break;
        g_string_append_c(ret, ' ');
        ptr += start;
        len -= start;
    }

    g_free(utf8String);
    return g_string_free(ret, FALSE);
}