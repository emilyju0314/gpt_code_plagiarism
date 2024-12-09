bool CCalcDlg::put_bytes(FILE_ADDRESS addr)
{
	if (bits_ == 0 || bits_%8 != 0)
	{
		TaskMessageBox("Can't write to file",
			"The calculator integer size (Bits) must be a multiple of 8.  "
			"Only a whole number of bytes can be written to a file.");
		return false;
	}

	CHexEditView *pview = GetView();
	if (pview == NULL)
	{
		no_file_error();
		return false;
	}

	if (pview->ReadOnly())
	{
		TaskMessageBox("File is read only",
			"The calculator cannot write to the current file when it is open in read only mode.");
		return false;
	}

	FILE_ADDRESS dummy;
	switch (addr)
	{
	case -2:   // address of mark
		addr = pview->GetMark();
		break;
	case -3:   // address of start of selection
		pview->GetSelAddr(addr, dummy);
		break;
	}

	if (addr > pview->GetDocument()->length())
	{
		TaskMessageBox("Can't write past EOF",
			"An attempt was made to write at an address past the end of file.  "
			"The calculator won't extend a file to allow the bytes to be written.");
		return false;
	}
	if (!pview->OverType() && addr + bits_/8 > pview->GetDocument()->length())
	{
		TaskMessageBox("Write extends past EOF",
			"The bytes to be written extends past the end of file.  "
			"The calculator cannot write past EOF when the file is open in OVR mode.");
		return false;
	}

	// Get buffer for bytes (size rounded up to multiple of mpz limb size)
	int units = (bits_/8 + 3)/4; // number of DWORDs required
	mp_limb_t * buf = new mp_limb_t[units];

	// Get all limbs from the big integer (little-endian)

	// Make sure view and calculator endianness are in sync
	ASSERT(pview->BigEndian() == ((CButton*)GetDlgItem(IDC_BIG_ENDIAN_FILE_ACCESS))->GetCheck());
	if (pview->BigEndian())
		flip_bytes((unsigned char *)buf, bits_/8);   // Reverse the byte order to match that used internally (Intel=little-endian)

	pview->GetDocument()->Change(pview->OverType() ? mod_replace : mod_insert,
								addr, bits_/8, (unsigned char *)buf, 0, pview);
	delete[] buf;

	return true;
}