std::string IzdvojiRijec(std::string s, int n)
{
   if(n<=0) throw std::range_error("IZUZETAK: Pogresan redni broj rijeci! ");
   int brojRijeci=0;
   std::string pomocni;
   int i(0);
   bool DesiloSe(true);
   while(i<s.length()) {
      if(s[i]!=' ') {
         brojRijeci++;
         if(brojRijeci == n) {
            DesiloSe = false;
            while(s[i]!=' ' && i<s.length()) {
               pomocni.push_back(s[i]);
               ++i;
            } 
            break;

         } else while(s[i]!=' ' && i<s.length()) i++;
      }

      if(i == s.length()) --i;
      i++;
   }
   if(DesiloSe) throw std::range_error("IZUZETAK: Pogresan redni broj rijeci! ");
   return pomocni;
}