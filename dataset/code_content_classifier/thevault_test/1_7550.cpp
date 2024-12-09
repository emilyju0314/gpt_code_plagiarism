static bool _restore_game(const string& filename)
{
    if (Options.no_save)
        return false;

    // In webtiles, a more before the player is loaded will crash when it tries
    // to send enough information to the webtiles client to render the display.
    // This is just cosmetic for other build targets.
    unwind_bool save_more(crawl_state.show_more_prompt, false);
    game_type menu_game_type = crawl_state.type;

    clear_message_store();

    you.save = new package((_get_savefile_directory() + filename).c_str(), true);

    if (!_read_char_chunk(you.save))
    {
        // Note: if we are here, the save info was properly read, it would
        // raise an exception otherwise.
        if (yesno(("There is an existing game for name '" + you.your_name +
                   "' from an incompatible version of Crawl ("
                   + you.prev_save_version + ").\n"
                   "Unless you reinstall that version, you can't load it.\n"
                   "Do you want to DELETE that game and start a new one?"
                  ).c_str(),
                  true, 'n'))
        {
            you.save->unlink();
            you.save = 0;
            return false;
        }
        if (Options.remember_name)
            crawl_state.default_startup_name = you.your_name; // for main menu
        you.save->abort();
        delete you.save;
        you.save = 0;
        game_ended(game_exit::abort,
            you.your_name + " is from an incompatible version and can't be loaded.");
    }

    if (!crawl_state.bypassed_startup_menu
        && menu_game_type != crawl_state.type)
    {
        if (!yesno(("You already have a "
                        + _type_name_processed(crawl_state.type) +
                    " game saved under the name '" + you.your_name + "';\n"
                    "do you want to load that instead?").c_str(),
                   true, 'n'))
        {
            you.save->abort(); // don't even rewrite the header
            delete you.save;
            you.save = 0;
            game_ended(game_exit::abort,
                "Please use a different name to start a new " +
                _type_name_processed(menu_game_type) + " game, then.");
        }
    }

    if (Options.remember_name)
        crawl_state.default_startup_name = you.your_name; // for main menu

    if (numcmp(you.prev_save_version.c_str(), Version::Long, 2) == -1
        && version_is_stable(you.prev_save_version.c_str()))
    {
        if (!yesno(("This game comes from a previous release of Crawl (" +
                    you.prev_save_version + ").\n\nIf you load it now,"
                    " you won't be able to go back. Continue?").c_str(),
                    true, 'n'))
        {
            you.save->abort(); // don't even rewrite the header
            delete you.save;
            you.save = 0;
            game_ended(game_exit::abort, "Please use version " +
                you.prev_save_version + " to load " + you.your_name + " then.");
        }
    }

    _restore_tagged_chunk(you.save, "you", TAG_YOU, "Save data is invalid.");

    _convert_obsolete_species();

    const int minorVersion = crawl_state.minor_version;

    if (you.save->has_chunk(CHUNK("st", "stashes")))
    {
        reader inf(you.save, CHUNK("st", "stashes"), minorVersion);
        StashTrack.load(inf);
    }

#ifdef CLUA_BINDINGS
    if (you.save->has_chunk("lua"))
    {
        vector<char> buf;
        chunk_reader inf(you.save, "lua");
        inf.read_all(buf);
        buf.push_back(0);
        clua.execstring(&buf[0]);
    }
#endif

    if (you.save->has_chunk(CHUNK("kil", "kills")))
    {
        reader inf(you.save, CHUNK("kil", "kills"),minorVersion);
        you.kills.load(inf);
    }

    if (you.save->has_chunk(CHUNK("tc", "travel_cache")))
    {
        reader inf(you.save, CHUNK("tc", "travel_cache"), minorVersion);
        travel_cache.load(inf, minorVersion);
    }

    if (you.save->has_chunk(CHUNK("nts", "notes")))
    {
        reader inf(you.save, CHUNK("nts", "notes"), minorVersion);
        load_notes(inf);
    }

    /* hints mode */
    if (you.save->has_chunk(CHUNK("tut", "tutorial")))
    {
        reader inf(you.save, CHUNK("tut", "tutorial"), minorVersion);
        load_hints(inf);
    }

    /* messages */
    if (you.save->has_chunk(CHUNK("msg", "messages")))
    {
        reader inf(you.save, CHUNK("msg", "messages"), minorVersion);
        load_messages(inf);
    }

    return true;
}