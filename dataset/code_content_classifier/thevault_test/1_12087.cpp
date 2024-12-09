void CommandAdjustNodeGroup::InitSyntax()
    {
        GetSyntax().ReserveParameters(6);
        EMotionFX::ParameterMixinActorId::InitSyntax(GetSyntax(), /*isParameterRequired=*/ true);
        GetSyntax().AddRequiredParameter("name",             "The name of the node group to adjust.",                        MCore::CommandSyntax::PARAMTYPE_STRING);
        GetSyntax().AddParameter("newName",          "The new name of the node group.",                              MCore::CommandSyntax::PARAMTYPE_STRING,     "");
        GetSyntax().AddParameter("enabledOnDefault", "The enabled on default flag.",                                 MCore::CommandSyntax::PARAMTYPE_BOOLEAN,    "false");
        GetSyntax().AddParameter("nodeNames",        "A list of nodes that should be added to the node group.",      MCore::CommandSyntax::PARAMTYPE_STRING,     "");
        GetSyntax().AddParameter("nodeAction",       "The action to perform with the nodes passed to the command.",  MCore::CommandSyntax::PARAMTYPE_STRING,     "select");
    }