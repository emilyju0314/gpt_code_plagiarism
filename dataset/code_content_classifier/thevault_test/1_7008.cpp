std::deque <int> IzdvojiElemente(const std::deque <int> v, bool Vrijednost){
   std::deque <int> Novi;
   
   for(int x : v){
      bool manji = false;
      if(x<0) { manji=true; x*=-1; }
      int suma(0);
      int pamti=x;
      while(pamti!=0){
         int zadnjaCifra = pamti % 10;
         suma += zadnjaCifra;
         pamti/=10;
      }
      if(manji) x*=-1;
      if(suma%2==0 && Vrijednost) Novi.push_front(x); // parna suma
      if(suma%2!=0 && !Vrijednost) Novi.push_front(x); // neparna suma
   }
   
   return Novi;
}