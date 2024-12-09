BOOL CHexEditDoc::ScanFile()
{
	df_init_ = TRUE;

	if (ptree_ == NULL || ptree_->Error())
	{
		df_mess_ = "No data description file is available";
		return FALSE;
	}

	CWaitCursor wait;

	// Init progress bar
	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	m_last_checked = clock();

	df_mess_.Empty();
	max_indent_ = 1;

	df_type_.clear();
	df_address_.clear();
	df_size_.clear();
	df_extra_.clear();
	df_indent_.clear();
	df_elt_.clear();
	df_info_.clear();
	df_enum_.clear();
	ASSERT(ptree_->GetRoot().GetName() == "binary_file_format");

	default_byte_order_ = ptree_->GetRoot().GetAttr("default_byte_order");
	default_read_only_ = ptree_->GetRoot().GetAttr("default_read_only");
	default_char_set_ = ptree_->GetRoot().GetAttr("default_char_set");

	// Add info for root element
	df_type_.push_back(DF_FILE);            // type representing all of file
	df_address_.push_back(0);               // address is start of file
	df_size_.push_back(0);                  // size is not yet known (filled in later)
	df_extra_.push_back(-1);                // arrays only
	df_indent_.push_back(1);                // represents root of tree view
	df_elt_.push_back(ptree_->GetRoot());   // root element in CXmlTree
	df_info_.push_back(ExprStringType());
	in_jump_ = 0;                           // we are not in any JUMPs
	bits_used_ = 0;                         // we have not seen a bitfield yet
	last_size_ = 0;                         // store 0 when bits_used_ == 0

	FILE_ADDRESS size_tmp;
	CHexExpr ee(this);
	try
	{
		add_branch(ptree_->GetRoot(), 0, 2, ee, size_tmp); // process whole tree (getting size)
		ASSERT(bits_used_ == 0);                           // Bitfields should have been terminated

		df_size_[0] = size_tmp;
		if (!df_mess_.IsEmpty())
		{
			// Display any error message
			TaskMessageBox("Template Scan Error", df_mess_);
			df_address_[0] = -1;
		}
		else
		{
			CString dispStr = ptree_->GetRoot().GetAttr("expr");
			if (!dispStr.IsEmpty())
			{
				// Generate display "expr" for the whole template (displayed next to root elt name)
				int expr_ac;                            // Last node accessed by expression

				if (dispStr.Find('{') == -1)
					dispStr = CString("{") + dispStr + "}";  // This makes evaluate handle the errors

				CHexExpr::value_t tmp = Evaluate(dispStr, ee, 0, expr_ac);

				if (tmp.typ == CHexExpr::TYPE_STRING)
					df_info_[0] = *tmp.pstr;
			}
		}

		// Check that we're at EOF
		if (size_tmp < length_)
		{
			TaskMessageBox("Template Warning", "Data past expected end of file");

			df_type_.push_back(DF_EXTRA);           // represents extra unexpected data
			df_address_.push_back(size_tmp);        // address is where EOF expected
			df_size_.push_back(length_ - size_tmp); // size is distance to real EOF
			df_extra_.push_back(-1);                // used for arrays only
			df_indent_.push_back(1);                // this is the only other tree element at root
			df_elt_.push_back(ptree_->GetRoot());   // what else can we use here?
			df_info_.push_back(ExprStringType("Expected EOF"));
		}
	}
	catch (const char *mess)
	{
		(void)mess;
		TRACE1("Caught %s in ScanFile\n", mess);
	}

	mm->Progress(-1);  // Turn off progress now
	update_needed_ = false;
	return TRUE;
}