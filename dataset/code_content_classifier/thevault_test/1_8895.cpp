status_t
ThemesAddon::CompareToCurrent(BMessage &theme)
{
	FENTRY;
	BMessage current, a, b;
	BackupCurrent(current);
	status_t err;
	
	if (!MessageName())
		return B_OK;
	
	err = theme.FindMessage(MessageName(), &a);
	if (err)
		return err;
	err = current.FindMessage(MessageName(), &b);
	if (err)
		return err;
	if (!CompareMessages(a, b))
		return 1;
	
	return B_OK;
}