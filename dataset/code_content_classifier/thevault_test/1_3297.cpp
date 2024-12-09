void CHexEditDoc::OpenDataFormatFile(LPCTSTR data_file_name /*=NULL*/)
{
	CheckSaveTemplate();   // allow user to save changes to current template (if any)

	int saved_file_num = xml_file_num_;
	xml_file_num_ = -1;  // Default to no file found

	CString filename;

	if (data_file_name == NULL)
	{
		// Work out what data format (XML) file to use
		int recent_file_index = -1;
		CHexFileList *pfl = theApp.GetFileList();

		if (pfile1_ != NULL)
			recent_file_index = pfl->GetIndex(pfile1_->GetFilePath());

		if (recent_file_index != -1)
		{
			// Get data format file from file settings for this file
			filename = pfl->GetData(recent_file_index, CHexFileList::FORMAT);
//            if (!filename.IsEmpty() && _access(theApp.xml_dir_+filename, 0) == -1)
//                filename.Empty();

			// Find this filename in the list of current XML files
			if (filename.CompareNoCase("default") != 0)
				xml_file_num_ = theApp.FindXMLFile(filename);
		}

		// If none found above then use default for this file extension
		if (xml_file_num_ == -1 && pfile1_ != NULL)
		{
			// Get file extension and change "." to "_"
			CString ss = pfile1_->GetFileName();
			if (ss.ReverseFind('.') != -1)
			{
				filename = CString("_") + ss.Mid(ss.ReverseFind('.')+1);

				// Check that a file exists for this extension
//                if (_access(theApp.xml_dir_+filename, 0) == -1)
//                    filename.Empty();            // No file so don't use this file name
				xml_file_num_ = theApp.FindXMLFile(filename);
			}
		}

		// Lastly use "default" .XML if present
		if (xml_file_num_ == -1)
		{
			filename = "default";

			// Find it in the list
			xml_file_num_ = theApp.FindXMLFile(filename);
		}
	}
	else
	{
		ASSERT(data_file_name != NULL);
		// Check if specified file name is there
//        if (_access(theApp.xml_dir_+data_file_name, 0) != -1)
//            filename = data_file_name;
		xml_file_num_ = theApp.FindXMLFile(data_file_name);
		if (xml_file_num_ != -1)
			filename = data_file_name;
	}

	// If we got a file name to use then use it
	// Note xml_file_num_ should not be -1 now but this cann occur if the "default"
	// template was not found or a template file has suddenly disappeared.
	if (xml_file_num_ != -1)
	{
		ASSERT(!filename.IsEmpty());

		CXmlTree *saved_ptree = ptree_;

		CString ss;

		ptree_ = new CXmlTree(theApp.xml_dir_ + filename + CString(".xml"));
		if (ptree_->Error())
		{
			ss.Format("XML parse error in file \"%s.XML\"\nLine %ld:%s\n%s", 
					  filename, long(ptree_->ErrorLine()),
					  ptree_->ErrorLineText(), ptree_->ErrorMessage());
			TaskMessageBox("Template Error", ss);
			delete ptree_;

			// Restore previous file
			ptree_ = saved_ptree;
			xml_file_num_ = saved_file_num;
		}
		else if (ptree_->GetDTDName() != "binary_file_format")
		{
			ss.Format("Invalid DTD used with XML file \"%s\"", ptree_->GetFileName());
			TaskMessageBox("Template Error", ss);
			delete ptree_;

			// Restore previous file
			ptree_ = saved_ptree;
			xml_file_num_ = saved_file_num;
		}
		else if (saved_ptree != NULL)
		{
			// Destroy previous file
			delete saved_ptree;
		}
	}
	else
		xml_file_num_ = saved_file_num;

	// If we are using the default template the user will more than likely want to change it so allow editing
	if (filename == "default")
		dffd_edit_mode_ = 1;
	else if (ptree_ != NULL && !ptree_->Error() && dffd_edit_mode_ == 1)
	{
		// Turn off edit mode if template says to
		CString ss;
		ss = ptree_->GetRoot().GetAttr("allow_editing");
		dffd_edit_mode_ = (ss.CompareNoCase("false") != 0);
	}
}