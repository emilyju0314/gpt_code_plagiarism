void cache::setInitDB(){
   string tempcache = TEMPCACHE;
   ofstream myfile;
   string cache = getenv("HOME") + tempcache;
   myfile.open (cache.c_str());
   myfile << DBlocation.c_str();
   myfile.close();
}