void opJMP(string sDireccionamiento, string sExtra) {
	int iDir, iTemp;
  string sContenido;

  switch (sDireccionamiento[0]) {
    // Absoluto
    case '1': {
      PCprev = PC;
     	PC = atoi(sExtra.c_str());
      displayChanges();
      break;
    }
    // Indirecto
    case '2': {
    	MAR = sExtra;
      displayChanges();
    	iDir = atoi(MAR.c_str());
      MDR = data[iDir]; // MMREad
      displayChanges();
      MAR = MDR;
      displayChanges();
      iDir = atoi(MAR.c_str());
      MDR = data[iDir]; // MMRead
      displayChanges();
      PCprev = PC;
      PC = atoi(MDR.c_str());
      displayChanges();
      break;
    }
    // Relativo
    case '4': {
     	iTemp = atoi(sExtra.c_str());
      if (PC + iTemp < 0 || PC + iTemp > 999) {
       	cout << "OUT OF BOUNDS" << endl;
      }
      else {
        if (PC + iTemp < 100) {
          if (PC + iTemp < 10) {
            MAR = "00" + toString(PC + iTemp);
          }
          else {
            MAR = "0" + toString(PC + iTemp);
          }
        }
        else {
          MAR = toString(PC + iTemp);
        }
        displayChanges();
        PCprev = PC;
        PC = atoi(MAR.c_str());
        displayChanges();
      }
    	break;
		}
    default: {
    	cout << "INPUT ERROR" << endl;
    }
  }
}