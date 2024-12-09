static void
addAttribute(BMessage& msg, const char* name, const char* publicName,
	int32 type, int32 width)
{
	msg.AddString("attr:name", name);
	msg.AddString("attr:public_name", publicName);
	msg.AddInt32("attr:type", type);
	msg.AddInt32("attr:width", width);
	msg.AddInt32("attr:alignment", B_ALIGN_LEFT);
	msg.AddBool("attr:extra", false);
	msg.AddBool("attr:viewable", true);
	msg.AddBool("attr:editable", true);
}