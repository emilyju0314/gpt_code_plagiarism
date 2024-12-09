void lmtable::concatenate_all_levels(const char* fromfilename, const char* tofilename){
		//single level files should have a name derived from "filename"
		//there no control that the tables have the same size
		for (int i=1; i<=maxlevel(); i++) {
			concatenate_single_level(i, fromfilename, tofilename);
		}
	}