ExprStringType CHexEditDoc::get_str(CHexExpr::value_t val, int ii)
{
	if (val.typ == CHexExpr::TYPE_INT)
	{
		std::map<MSXML2::IXMLDOMElementPtr::Interface *, enum_t>::const_iterator pev =
			df_enum_.find((MSXML2::IXMLDOMElementPtr::Interface *)df_elt_[ii].m_pelt);
		if (pev != df_enum_.end())
		{
			enum_t::const_iterator pe = pev->second.find(val.int64);
			if (pe != pev->second.end())
			{
				return ExprStringType(pe->second);
			}
		}
	}

	return val.GetDataString("");
}