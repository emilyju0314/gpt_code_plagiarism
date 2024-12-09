void close_iers_file()
{
    if (iers_stream != 0) {
        fclose(iers_stream);
        iers_stream = 0;
    }
}