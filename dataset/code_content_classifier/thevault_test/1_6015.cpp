int CClientPIC::CalibrateAxis(int addr)
 {
   //do this twice b/c sometime encoder doesn't always get zeroed after 1 reset
   
   D_ResetEncoder((byte)addr);
   D_ResetEncoder((byte)addr);
   //for now just set calibrated flag to 1
     calibrated[addr-1] = 1;  
   
   return 0;
 }