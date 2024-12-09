bool WatchConsole::CheckForInput() {
   bool ret = false;

   if(_fut.valid() == true) {
      future_status result = _fut.wait_for(0ms);
      if(result == future_status::ready) {

         int stat = _fut.get();
         if(stat < 0){ // error
            BOOST_ASSERT_MSG(false, _errorStr.c_str());
         }
         else if(stat == 0){
            // 0 chars from stdin, user may have hit <cr> only
         }
         else { // stat == 1
            ret = true; // chars available 
         } // end if 
         
         _fut = std::async(std::launch::async, [this]() -> int { return GetUserInput(); });
      } // end if 
   }
   else {
      _fut = std::async(std::launch::async, [this]() -> int { return GetUserInput(); });
   } // end if 

   return ret;
}