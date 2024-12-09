void CommandScaleMotionData::InitSyntax()
    {
        GetSyntax().ReserveParameters(4);
        GetSyntax().AddParameter("id",                      "The identification number of the motion we want to scale.",                    MCore::CommandSyntax::PARAMTYPE_INT,        "-1");
        GetSyntax().AddParameter("scaleFactor",             "The scale factor, for example 10.0 to make the motion pose 10x as large.",     MCore::CommandSyntax::PARAMTYPE_FLOAT,      "1.0");
        GetSyntax().AddParameter("unitType",                "The unit type to convert to, for example 'meters'.",                           MCore::CommandSyntax::PARAMTYPE_STRING,     "meters");
        GetSyntax().AddParameter("skipInterfaceUpdate",     ".",                                                                            MCore::CommandSyntax::PARAMTYPE_BOOLEAN,    "false");
    }