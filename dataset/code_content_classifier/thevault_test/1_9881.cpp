VisItException::VisItException()
{
    filename = "Unknown";
    msg      = "Not set";
    type     = "VisItException";
    line     = -1;
    log      = NULL; //&debug1_real;
}