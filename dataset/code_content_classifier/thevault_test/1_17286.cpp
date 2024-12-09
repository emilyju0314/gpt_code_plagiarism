void XMLNode::DebugPrint(std::ostream& os, uint32_t level) const
{
	// Always start new line for new node
	os << std::endl;

	// Indent
	for(uint32_t ctr = 0; ctr < level; ctr++)
		os << "\t";

	os << "<" << GetPrefixName();
	for(XMLAttributeList::const_iterator iter = mAttributeList.begin(); iter != mAttributeList.end(); iter++)
	{
		os << " " << (*iter)->Name() << "=\"" << (*iter)->Value() << "\"";
	}
	
	// See if we have an empty tag and close it
	if (mData.empty() && mChildren.empty())
	{
		os << "/>" << std::endl;
		return;
	}
	else
		os << ">";
	
	// Now do children
	for(XMLNodeList::const_iterator iter = mChildren.begin(); iter != mChildren.end(); iter++)
	{
		(*iter)->DebugPrint(os, level + 1);
	}
	
	// Now do data
	if (!mData.empty())
		GenerateData(os, mData);
	
	// Indent
	if (mChildren.size() != 0)
	{
		for(uint32_t ctr = 0; ctr < level; ctr++)
			os << "\t";
	}

	// End tag
	os << "</" << GetPrefixName() << ">" << std::endl;
}