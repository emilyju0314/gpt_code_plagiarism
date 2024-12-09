string completePC(int iPC) {
 	string myPC = toString(iPC);
  ostringstream complete;

  for(int i = 0; i < 3 - myPC.length(); i++) {
  	complete << 0;
  }

  complete << myPC;
  return complete.str();
}