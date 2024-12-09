bool cache::initDB(){
   bool found = false;
   char PrefIn[100];
   FILE* fp;
   string tempcache = TEMPCACHE;
   string Cache = getenv("HOME") + tempcache;
   fp = fopen(Cache.c_str(), "r");   /// open cached db location
   if(fp != NULL){
       cout << "cache found " << endl;
       rewind(fp);
       while(!feof(fp)){
           fscanf(fp, "%s", &PrefIn);
           found = true;
       }
   }
   else{
       return false;
   }

   if(found){   // if the db (listed in this text cache) exists
       setSQL(PrefIn);  /// set SQL location
       fclose(fp);
       return true;
   }
   else{
       fclose(fp);
       return false;
   }
}