view_t CHexEditDoc::GetCompareFile(view_t view_type, bool & auto_sync, bool & auto_scroll, CString & compareFile, bool bForcePrompt /*=false*/)
{
	CNewCompare dlg;

	// Get previous compare file name (if any) to be used as the default
	compareFile = GetCompFileName();

	dlg.orig_shared_ = shared_ ? true : false;
	dlg.compare_type_ = shared_ ? 0 : 1;       // default to self-compare if file is opened shared

	if (compareFile.IsEmpty())
	{
		// Looks like there was no previous compare for this file so use last file name for any file
		dlg.file_name_ = 	theApp.GetProfileString("File-Settings", "LastCompareFile", ""); // but get last used file name
	}
	else if (compareFile.Compare("*") == 0)
	{
		// If we don't have to prompt then we can proceed with self-compare
		if (!bForcePrompt)
		{
			return view_type;                 // return asked for view type (or error if asked for type is 0)
		}
		dlg.file_name_ = 	theApp.GetProfileString("File-Settings", "LastCompareFile", ""); // but also get last used file name (disabled)
	}
	else
	{
		// If we don't have to prompt and the current file name exists then we can proceed using that file
		if (!bForcePrompt && _access(compareFile, 0) != -1)
			return view_type;                 // return asked for view type (or error if asked for type is 0)

		dlg.compare_type_ = 1;                // Default to file compare since we have a file name
		dlg.file_name_ = compareFile;
	}
	dlg.compare_display_ = int(view_type) - 1;
	if (compMinMatch_ == 0)
	{
		dlg.insdel_ = 0;
		dlg.minmatch_ = 8;
	}
	else
	{
		dlg.insdel_ = 1;
		dlg.minmatch_ = compMinMatch_;
	}
	dlg.auto_sync_ = auto_sync;
	dlg.auto_scroll_= auto_scroll;

	if (dlg.DoModal() != IDOK)              // === run dialog ===
		return none;

	// Store selected values
	if (!dlg.insdel_)
	{
		compMinMatch_ = 0;
	}
	else
	{
		compMinMatch_ = dlg.minmatch_;
	}
	auto_sync = dlg.auto_sync_ != 0;
	auto_scroll = dlg.auto_scroll_ != 0;

	if (dlg.compare_type_ == 0)
	{
		if (pfile1_ == NULL)
		{
			TaskMessageBox("File has not been saved to disk", "You have not yet saved the current file to disk. "
						   "A self compare detects changes as they are made on disk. \n\n"
						   "Please save the file to disk before performing a \"self compare\".");
			return none;
		}
		compareFile = "*";
	}
	else
	{
		compareFile = dlg.file_name_;
		theApp.WriteProfileString("File-Settings", "LastCompareFile", compareFile);   // last used - may be used for default next time
	}

	return view_t(dlg.compare_display_ + 1);
}