void close_leap_sec_file()
{
    if (ls_stream != 0) {
        fclose(ls_stream);
        ls_stream = 0;
    }
}