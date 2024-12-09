void TcshButtonCB(Fl_Widget*, void *cbdata) {
    MyTerminal *term = (MyTerminal*)cbdata;
    std::string errmsg;
    char *cmd_argv[10];
    int i = 0;
    cmd_argv[i++] = "/bin/tcsh";
    cmd_argv[i++] = "-is";
    cmd_argv[i++] = 0;
    if ( term->StartChild(cmd_argv, errmsg) < 0 ) {
	term->append("ERROR: ");
	term->append(errmsg.c_str());
    } else {
        term->append("\n\n*** tcsh(1) started\n");
    }
    Fl::focus(term);		// return focus to editor
}