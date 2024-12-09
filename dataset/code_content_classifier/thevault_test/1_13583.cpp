int checkIdentifier(string& id)
{
    // check whether the identifier is scoped
    size_t scopeIndex = id.rfind("::");
    bool isScoped = scopeIndex != string::npos;
    string name;
    if(isScoped)
    {
        name = id.substr(scopeIndex + 2); // Only check the unscoped identifier for syntax
    }
    else
    {
        name = id;
    }

    // check the identifier for reserved suffixes
    static const string suffixBlacklist[] = { "Helper", "Holder", "Prx", "Ptr" };
    for(size_t i = 0; i < sizeof(suffixBlacklist) / sizeof(*suffixBlacklist); ++i)
    {
        if(name.find(suffixBlacklist[i], name.size() - suffixBlacklist[i].size()) != string::npos)
        {
            unit->error("illegal identifier `" + name + "': `" + suffixBlacklist[i] + "' suffix is reserved");
        }
    }

    // check the identifier for illegal underscores
    size_t index = name.find('_');
    if(index == 0)
    {
        unit->error("illegal leading underscore in identifier `" + name + "'");
    }
    else if(name.rfind('_') == (name.size() - 1))
    {
        unit->error("illegal trailing underscore in identifier `" + name + "'");
    }
    else if(name.find("__") != string::npos)
    {
        unit->error("illegal double underscore in identifier `" + name + "'");
    }
    else if(index != string::npos && unit->currentIncludeLevel() == 0 && !unit->allowUnderscore())
    {
        DefinitionContextPtr dc = unit->currentDefinitionContext();
        assert(dc);
        if(dc->findMetaData("underscore") != "underscore") // no 'underscore' file metadata
        {
            unit->error("illegal underscore in identifier `" + name + "'");
        }
    }

    // Check the identifier for illegal ice prefixes
    if(unit->currentIncludeLevel() == 0 && !unit->allowIcePrefix() && name.size() > 2)
    {
        DefinitionContextPtr dc = unit->currentDefinitionContext();
        assert(dc);
        if(dc->findMetaData("ice-prefix") != "ice-prefix") // no 'ice-prefix' metadata
        {
            string prefix3;
            prefix3 += ::tolower(static_cast<unsigned char>(name[0]));
            prefix3 += ::tolower(static_cast<unsigned char>(name[1]));
            prefix3 += ::tolower(static_cast<unsigned char>(name[2]));
            if(prefix3 == "ice")
            {
                unit->error("illegal identifier `" + name + "': `" + name.substr(0, 3) + "' prefix is reserved");
            }
        }
    }

    return isScoped ? ICE_SCOPED_IDENTIFIER : ICE_IDENTIFIER;
}