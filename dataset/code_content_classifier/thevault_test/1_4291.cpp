static inline bool isReservedTysysIdOnlyName( const std::string & name ) {
		// name's prefix was __CFA_tysys_id_only, before it got wrapped in __..._generic
		int foundAt = name.find("__CFA_tysys_id_only");
		if (foundAt == 0) return true;
		if (foundAt == 2 && name[0] == '_' && name[1] == '_') return true;
		return false;
	}