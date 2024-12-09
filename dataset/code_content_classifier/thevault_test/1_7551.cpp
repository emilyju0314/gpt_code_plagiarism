bool restore_game(const string& filename)
{
    try
    {
        return _restore_game(filename);
    }
    catch (corrupted_save &err)
    {
        if (yesno(make_stringf(
                   "There exists a save by that name but it appears to be invalid.\n"
                   "Do you want to delete it?\n"
                   "Error: %s", err.what()).c_str(), // TODO linebreak error
                  true, 'n'))
        {
            if (you.save)
                you.save->unlink();
            you.save = 0;
            return false;
        }
        // Shouldn't crash probably...
        fail("Aborting; you may try to recover it somehow.");
    }
}