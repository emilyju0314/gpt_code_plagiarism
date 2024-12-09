void opADD(string sDireccionamiento, string sExtra) {
	int iDir, iTemp, iTemp2;
  string sContenido;

  switch (sDireccionamiento[0]) {
    // Absoluto
    case '1': {
     	MAR = sExtra;
      displayChanges();
      iDir = atoi(MAR.c_str());
      MDR = data[iDir]; // MMRead
      displayChanges();
      iTemp = atoi(MDR.c_str());
      iTemp2 = atoi(AC.c_str());
      if (iTemp + iTemp2 > 99999 || iTemp + iTemp2 < -99999) {
       	cout << "OVERFLOW" << endl;
      }
      else {
        AC = completeAC(iTemp + iTemp2);
        displayChanges();
      }
      break;
    }
    // Indirecto
    case '2': {
    	MAR = sExtra;
      displayChanges();
    	iDir = atoi(MAR.c_str());
      MDR = data[iDir]; // MMRead
      displayChanges();
      MAR = MDR;
      displayChanges();
      iDir = atoi(MAR.c_str());
      MDR = data[iDir]; // MMRead
      displayChanges();
      iTemp = atoi(MDR.c_str());
      iTemp2 = atoi(AC.c_str());
      if (iTemp + iTemp2 > 99999 || iTemp + iTemp2 < -99999) {
       	cout << "OVERFLOW" << endl;
      }
      else {
        AC = completeAC(iTemp + iTemp2);
        displayChanges();
      }
      break;
    }
    // Inmediato
    case '3': {
      iTemp = atoi(sExtra.c_str());
      iTemp2 = atoi(AC.c_str());
      if (iTemp + iTemp2 > 99999 || iTemp + iTemp2 < -99999) {
       	cout << "OVERFLOW" << endl;
      }
      else {
        AC = completeAC(iTemp + iTemp2);
        displayChanges();
      }
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
        MDR = data[PC + iTemp]; // MMRead
        displayChanges();
        iTemp = atoi(MDR.c_str());
        iTemp2 = atoi(AC.c_str());
        AC = completeAC(iTemp + iTemp2);
        displayChanges();
      }
      break;
    }
    default: {
     	cout << "INSTRUCCION NO VALIDA" << endl;
    }
  }
}