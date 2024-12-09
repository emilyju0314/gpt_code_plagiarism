void CClientPIC::SetVelocity(byte addr, long newvel){
   PICdefaultvel[addr-1] = newvel;
   PICdefaultacc[addr-1] = newvel * 20;
   printf("PICdefaultvel for axis %d is now %d\n",(int)addr, newvel);
 }