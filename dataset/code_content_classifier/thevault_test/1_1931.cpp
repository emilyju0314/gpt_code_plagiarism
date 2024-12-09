void
CmdArgReader::init( const int argc, const char** argv) 
{  
    if ( NULL != self) 
    {
        return;
    }

    // command line arguments 
    if (( 0 == argc) || ( 0 == argv)) 
    {
        LOGIC_EXCEPTION( "No command line arguments given.");
    }

    self = new CmdArgReader();

    self->createArgsMaps( argc, argv);

    rargc = argc;
    rargv = const_cast<char**>( argv);
}