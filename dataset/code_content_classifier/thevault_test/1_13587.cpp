IceUtilInternal::Options::StringVector
IceUtilInternal::Options::parse(const StringVector& args)
{
    RecMutex::Lock sync(_m);

    if(parseCalled)
    {
        throw APIException(__FILE__, __LINE__, "cannot call parse() more than once on the same Option instance");
    }
    parseCalled = true;

    set<string> seenNonRepeatableOpts; // To catch repeated non-repeatable options.

    StringVector result;

    string::size_type i;
    for(i = 1; i < args.size(); ++i)
    {
        if(args[i] == "-" || args[i] == "--")
        {
            ++i;
            break; // "-" and "--" indicate end of options.
        }

        string opt;
        ValidOpts::iterator pos;
        bool argDone = false;

        if(args[i].compare(0, 2, "--") == 0)
        {
            //
            // Long option. If the option has an argument, it can either be separated by '='
            // or appear as a separate argument. For example, "--name value" is the same
            // as "--name=value".
            //
            string::size_type p = args[i].find('=', 2);
            if(p != string::npos)
            {
                opt = args[i].substr(2, p - 2);
            }
            else
            {
                opt = args[i].substr(2);
            }

            pos = checkOpt(opt, LongOpt);

            if(pos->second->repeat == NoRepeat)
            {
                set<string>::iterator seenPos = seenNonRepeatableOpts.find(opt);
                if(seenPos != seenNonRepeatableOpts.end())
                {
                    string err = "`--";
                    err += opt + ":' option cannot be repeated";
                    throw BadOptException(__FILE__, __LINE__, err);
                }
                seenNonRepeatableOpts.insert(seenPos, opt);
                string synonym = getSynonym(opt);
                if(!synonym.empty())
                {
                    seenNonRepeatableOpts.insert(synonym);
                }
            }

            if(p != string::npos)
            {
                if(pos->second->arg == NoArg)
                {
                    string err = "`";
                    err += opt;
                    err += "': option does not take an argument";
                    throw BadOptException(__FILE__, __LINE__, err);
                }
                else if(pos->second->arg == NeedArg && p == args[i].size() - 1)
                {
                    string err = "`";
                    err += opt;
                    err += "': option requires an argument";
                    throw BadOptException(__FILE__, __LINE__, err);
                }
                setOpt(opt, "", args[i].substr(p + 1), pos->second->repeat);
                argDone = true;
            }
        }
        else if(!args[i].empty() && args[i][0] == '-')
        {
            //
            // Short option.
            //
            for(string::size_type p = 1; p < args[i].size(); ++p)
            {
                opt.clear();
                opt.push_back(args[i][p]);
                pos = checkOpt(opt, ShortOpt);

                if(pos->second->repeat == NoRepeat)
                {
                    set<string>::iterator seenPos = seenNonRepeatableOpts.find(opt);
                    if(seenPos != seenNonRepeatableOpts.end())
                    {
                        string err = "`-";
                        err += opt + ":' option cannot be repeated";
                        throw BadOptException(__FILE__, __LINE__, err);
                    }
                    seenNonRepeatableOpts.insert(seenPos, opt);
                    string synonym = getSynonym(opt);
                    if(!synonym.empty())
                    {
                        seenNonRepeatableOpts.insert(synonym);
                    }
                }

                if(pos->second->arg == NeedArg)
                {
                    if(p != args[i].size() - 1)
                    {
                        string optArg = args[i].substr(p + 1);
                        setOpt(opt, "", optArg, pos->second->repeat);
                        argDone = true;
                        break;
                    }
                }
                else
                {
                    setOpt(opt, "", "1", pos->second->repeat);
                    argDone = true;
                }
            }
        }
        else
        {
            //
            // Not an option or option argument.
            //
            result.push_back(args[i]);
            argDone = true;
        }

        if(!argDone)
        {
            if(pos->second->arg == NeedArg) // Need an argument that is separated by whitespace.
            {
                if(i == args.size() - 1)
                {
                    string err = "`-";
                    if(opt.size() != 1)
                    {
                        err += "-";
                    }
                    err += opt;
                    err += "' option requires an argument";
                    throw BadOptException(__FILE__, __LINE__, err);
                }
                setOpt(opt, "", args[++i], pos->second->repeat);
            }
            else
            {
                setOpt(opt, "", "1", pos->second->repeat);
            }
        }
    }

    _synonyms.clear(); // Don't need the contents anymore.

    while(i < args.size())
    {
        result.push_back(args[i++]);
    }

    return result;
}