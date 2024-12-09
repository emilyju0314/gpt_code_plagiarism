void opSTA(string sDireccionamiento, string sExtra) {
	int iDir, iTemp;
  string sContenido;

  switch (sDireccionamiento[0]) {
    // Absoluto
    case '1': {
     	MAR = sExtra;
      displayChanges();
      iDir = atoi(MAR.c_str());
      MDR = AC;
      displayChanges();
      data[iDir] = MDR; // MMWrite
      displayChanges();
      break;
    }
    // Indirecto
    case '2': {
    	MAR = sExtra;
      displayChanges();
    	iDir = atoi(MAR.c_str());
      MDR = data[iDir];
      displayChanges();
      MAR = MDR;
      displayChanges();
      iDir = atoi(MAR.c_str());
      MDR = AC;
      displayChanges();
      data[iDir] = MDR; // MMWrite
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
        MDR = AC;
        displayChanges();
        data[PC + iTemp] = MDR; // MMWrite
        displayChanges();
      }
      break;
    }
    default: {
     	cout << "INSTRUCCION NO VALIDA" << endl;
    }
  }
}