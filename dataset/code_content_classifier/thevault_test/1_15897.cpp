void ArgParser::displayInfo()
{
    fprintf(stderr, "%s\nAvailable options:\n", m_preInfo.c_str());
    for (size_t i=0; i<m_args.size(); i++)
    {
        std::string type;
        switch (m_args[i].argType)
        {
        case ARG_UINT:
            type = " <int>";
            break;
        case ARG_FLOAT:
            type = " <float>";
            break;
        case ARG_STRING:
            type = " <string>";
            break;
        case ARG_FLAG:
        case ARG_NONE:
            type = "";
            break;
        }
        fprintf(stderr, "  %-15s  %-25s\t:  %s\n",
                (m_args[i].shortName + type + ",").c_str(),
                (m_args[i].name + type).c_str(),
                m_args[i].description.c_str());
    }
    fprintf(stderr, "%s\n", m_postInfo.c_str());
}