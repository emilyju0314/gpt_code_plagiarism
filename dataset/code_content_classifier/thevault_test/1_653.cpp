void lmtable::loadbin_level(istream& inp, int level)
	{
		VERBOSE(2,"loadbin_level (level " << level << std::endl);
		
		if (isQtable)
		{
			loadbin_codebook(inp,level);
		}
		if ((memmap == 0) || (level < memmap))
		{
			VERBOSE(2,"loading " << cursize[level] << " " << level << "-grams" << std::endl);
			table[level]=new char[(table_pos_t) cursize[level] * nodesize(tbltype[level])];
			inp.read(table[level],(table_pos_t) cursize[level] * nodesize(tbltype[level]));
		} else {
			
#ifdef WIN32
			error((char*)"mmap not available under WIN32\n");
#else
			VERBOSE(2,"mapping " << cursize[level] << " " << level << "-grams" << std::endl);
			tableOffs[level]=inp.tellg();
			table[level]=(char *)MMap(diskid,PROT_READ,
																tableOffs[level], (table_pos_t) cursize[level]*nodesize(tbltype[level]),
																&tableGaps[level]);
			table[level]+=(table_pos_t) tableGaps[level];
			VERBOSE(2,"tableOffs " << tableOffs[level] << " tableGaps" << tableGaps[level] << "-grams" << std::endl);
			inp.seekg((table_pos_t) cursize[level]*nodesize(tbltype[level]),ios_base::cur);
#endif
		}
		VERBOSE(2,"done (level " << level << std::endl);
	}