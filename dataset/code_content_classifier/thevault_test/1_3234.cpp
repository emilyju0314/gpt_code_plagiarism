const char * mpz_set_bytes(mpz_ptr p, FILE_ADDRESS addr, int count)
{
	CHexEditView *pview = GetView();
	if (pview == NULL)
		return "No file open to read from";

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

	if (addr + count > pview->GetDocument()->length())
		return "Not enough bytes before end of file";

	int units = (count + 3)/4; // number of DWORDs required
	mp_limb_t * buf = new mp_limb_t[units];
	buf[units - 1] = 0;          // make sure end bytes are zero in case not used

	if (pview->GetDocument()->GetData((unsigned char *)buf, count, addr) < count)
		return "Could not read from file";

	// Make sure view and calculator endianness are in sync
	if (pview->BigEndian())
		flip_bytes((unsigned char *)buf, count);   // Reverse the byte order to match that used internally (Intel=little-endian)

	// This assumes 4-byte units and little-endian order
	mpz_import(p, units, -1, 4, -1, 0, buf);
	delete[] buf;

	return NULL;
}