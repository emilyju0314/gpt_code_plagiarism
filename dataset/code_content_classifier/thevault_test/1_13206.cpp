void opNEG() {
	int iTemp;
  iTemp = atoi(AC.c_str());
  iTemp *= -1;
  AC = completeAC(iTemp);
  displayChanges();
}