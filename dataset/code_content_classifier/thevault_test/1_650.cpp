void lmtable::delete_level(int level, const char* outfilename, int mmap){
		if (mmap>0)
			delete_level_mmap(level, outfilename);
		else {
			delete_level_nommap(level);
		}
	}