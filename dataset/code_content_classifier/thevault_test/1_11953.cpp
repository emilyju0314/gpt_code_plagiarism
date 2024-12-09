void CommandStopMotionInstances::InitSyntax()
    {
        GetSyntax().ReserveParameters(1);
        GetSyntax().AddRequiredParameter("filename", "The filename of the motion file to stop all motion instances for.", MCore::CommandSyntax::PARAMTYPE_STRING);
    }