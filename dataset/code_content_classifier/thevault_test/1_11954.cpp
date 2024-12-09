void CommandAdjustMotion::InitSyntax()
    {
        GetSyntax().ReserveParameters(6);
        GetSyntax().AddRequiredParameter("motionID",         "The id of the motion to adjust.",                                                     MCore::CommandSyntax::PARAMTYPE_INT);
        GetSyntax().AddParameter("dirtyFlag",                "The dirty flag indicates whether the user has made changes to the motion or not.",    MCore::CommandSyntax::PARAMTYPE_BOOLEAN, "false");
        GetSyntax().AddParameter("name",                     "The name of the motion.",                                                             MCore::CommandSyntax::PARAMTYPE_STRING, "Unknown Motion");
        GetSyntax().AddParameter("motionExtractionFlags",    "The motion extraction flags value.",                                                  MCore::CommandSyntax::PARAMTYPE_INT, "0");
    }