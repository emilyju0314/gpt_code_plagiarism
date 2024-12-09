VisItException::VisItException(const vtkstd::string &m)
{
    filename = "Unknown";
    vtkstd::string mtmp = vtkstd::string(m,0,16);
    if (mtmp.find(':') == vtkstd::string::npos)
        msg = /*vtkstd::string(Init::GetComponentName())*/ + ": " + m;
    else
    {
        if (mtmp.find("avtprep:") == 0 ||
            mtmp.find("cli:") == 0 ||
            mtmp.find("engine:") == 0 ||
      mtmp.find("gui:") == 0 ||
            mtmp.find("launcher:") == 0 ||
            mtmp.find("mdserver:") == 0 ||
      mtmp.find("viewer:") == 0)
            msg = m;
        else
            msg = /*vtkstd::string(Init::GetComponentName())*/ + ": " + m;
    }
    type     = "VisItException";
    line     = -1;
    log      = NULL; //&debug1_real;
}