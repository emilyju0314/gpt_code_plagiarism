void CommandRemoveMotion::InitSyntax()
    {
        GetSyntax().ReserveParameters(1);
        GetSyntax().AddRequiredParameter("filename", "The filename of the motion file to remove.", MCore::CommandSyntax::PARAMTYPE_STRING);
    }