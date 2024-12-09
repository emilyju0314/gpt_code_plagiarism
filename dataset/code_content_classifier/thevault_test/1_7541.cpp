static vector<player_save_info> _find_saved_characters()
{
    vector<player_save_info> chars;

    if (Options.no_save)
        return chars;

#ifndef DISABLE_SAVEGAME_LISTS
    string searchpath = _get_savefile_directory();

    if (searchpath.empty())
        searchpath = ".";

    for (const string &filename : get_dir_files_sorted(searchpath))
    {
        if (is_save_file_name(filename))
        {
            try
            {
                package save(_get_savedir_path(filename).c_str(), false);
                player_save_info p = _read_character_info(&save);
                if (!p.name.empty())
                {
                    p.filename = filename;
#ifdef USE_TILE
                    if (Options.tile_menu_icons && save.has_chunk("tdl"))
                        _fill_player_doll(p, &save);
#endif
                    chars.push_back(p);
                }
            }
            catch (ext_fail_exception &E)
            {
                dprf("%s: %s", filename.c_str(), E.what());
            }
            catch (game_ended_condition &E) // another process is using the save
            {
                if (E.exit_reason != game_exit::abort)
                    throw;
            }
        }
    }

    sort(chars.begin(), chars.end());
#endif // !DISABLE_SAVEGAME_LISTS
    return chars;
}