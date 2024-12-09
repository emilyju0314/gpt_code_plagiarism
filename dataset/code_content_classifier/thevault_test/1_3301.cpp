BOOL CHexExpr::sym_found(const char * sym, int ii, CHexExpr::value_t &val, int *pac,
						 __int64 &sym_size, __int64 &sym_address)
{
	if (ii >= (int)pdoc->df_address_.size())
		return FALSE;

	if (pdoc->df_type_[ii] == CHexEditDoc::DF_JUMP)
		return sym_found(sym, ii+1, val, pac, sym_size, sym_address);
	else if (pdoc->df_type_[ii] == CHexEditDoc::DF_IF)
	{
		++ii;                           // Move to sub-element of IF
		if (ii >= (int)pdoc->df_address_.size())
			return FALSE;

		// Check IF part first
		BOOL found_in_if = sym_found(sym, ii, val, pac, sym_size, sym_address);

		if (found_in_if && val.typ != TYPE_NONE && !val.error)
		{
			return TRUE;               // Found in IF part and its not empty
		}

		// Skip forward to ELSE part which must have same indentation as main IF part
		int curr_indent = pdoc->df_indent_[ii];
		++ii;
		while (ii < (int)pdoc->df_address_.size() && pdoc->df_indent_[ii] > curr_indent)
			++ii;

		// If no ELSE part return what we found in IF part
		if (ii == (int)pdoc->df_address_.size() || pdoc->df_indent_[ii] < curr_indent)
			return found_in_if;

		CHexExpr::value_t val2;
		int ac2;
		__int64 sym_size2, sym_address2;
		if (!sym_found(sym, ii, val2, &ac2, sym_size2, sym_address2))
			return found_in_if;
		else if (val2.typ != TYPE_NONE || !found_in_if)
		{
			// Set returned values to what we found in ELSE part
			val = val2;
			*pac = ac2;
			sym_size = sym_size2;
			sym_address = sym_address2;
			return TRUE;
		}
		else
			return found_in_if;
	}
	else if (pdoc->df_type_[ii] == CHexEditDoc::DF_SWITCH)
	{
		++ii;                                    // First case in switch is next
		if (ii >= (int)pdoc->df_address_.size())
			return FALSE;

		int curr_indent = pdoc->df_indent_[ii];  // indent of all cases in the switch

		BOOL found = FALSE;
		while (ii < (int)pdoc->df_address_.size() && pdoc->df_indent_[ii] == curr_indent)
		{
			// There are 3 situations:
			// 1. the case is the "taken" case and the symbol of the sub-element matches sym
			//   sym_found() returns TRUE and val is valid so just return TRUE
			// 2. the symbol matches but it is not the taken case or the location is invalid (eg past EOF)
			//   sym_found() returns TRUE but val is invalid so keep looking
			// 3. the symbol does not match
			if (sym_found(sym, ii, val, pac, sym_size, sym_address))
			{
				found = TRUE;
				if (val.typ != TYPE_NONE && !val.error)
					return TRUE;               // Found the case with the valid value

				// else we continue since a following case may have the same symbol name and actually be valid
			}

			// Skip children (ie higher indent level) until next case of switch or end of switch
			++ii;
			while (ii < (int)pdoc->df_address_.size() && pdoc->df_indent_[ii] > curr_indent)
				++ii;
		}
		return found;
	}
	else if (pdoc->df_elt_[ii].GetAttr("name") == sym)
	{
		val = get_value(ii, sym_size, sym_address);
		if (ii > *pac)                  // If this symbol is further forward than any seen before ...
			*pac = ii;                  // ... update the last accessed symbol ptr
		return TRUE;
	}
	else
		return FALSE;
}