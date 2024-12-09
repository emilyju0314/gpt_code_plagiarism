int HumdrumFileBase::getMeasureNumber(int line) {
   HumdrumFileBase& infile = *this;
   int j;
   if (!infile[line].isBarline()) {
      // Return -1 if not a barline.  May be changed in the future
      // to return the measure number of the previous barline.
      return -1;
   }
   HumRegex hre;
   int measurenumber = -1;
   for (j=0; j<infile[line].getFieldCount(); j++) {
      if (hre.search(*infile.token(line, j), "^=[^\\d]*(\\d+)")) {
         measurenumber = hre.getMatchInt(1);
         return measurenumber;
      }
   }
	return -1;
}