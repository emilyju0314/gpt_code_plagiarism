size_t
decodeBCItoIndexValues ( uint64_t BCIval , std::vector<size_t>& indexVals )
{

   // SPDLOG Configuration within this method
   try {
     int log_console_num = console_count++;
     ostringstream ss;
     ss << "console" << log_console_num;
     string str = ss.str();
     auto console = spd::stdout_color_mt( str );
     console->set_level(spd::level::info);
     console->debug("*** [[ K-PARTIAL-SUMS (decodeBCItoIndexValues) ]] ***");
     console->debug("*** bciVal: [[ {} ]]",BCIval);
     console->debug("    remember: this is a BINARY CODED INDEX INTEGER");
     console->debug("    (integer value codes for permutation indices in array)");

     size_t numBits = 0;
     indexVals.clear();

     // it is VERY EASY to code the bit-shift loop by hand
     // STD::BITSET in C++11 is very convenient though
     //   e.g: any , none , all , first , count , addressable , etc
     // initialize std::bitset with integer value
     std::bitset< 8 * sizeof(BCIval) > bci_val_bitset( BCIval );

     console->debug("*** bitset COUNT   = [[ {} ]]", bci_val_bitset.count() );
     console->debug("*** bitset ULLONG  = [[ {} ]]", bci_val_bitset.to_ullong() );
     console->debug("*** bitset STRING  = [[ {} ]]", bci_val_bitset.to_string() );

   // while there are *ANY* bits set true/1 in the bitset
   // we search for (or define) any to be LEADING/LSB bits
   // then we always shift right ...
   size_t cbit = 0;
   while ( bci_val_bitset.any() ) {
     // while the first bit is not set, shift it away - and track it
     while( !bci_val_bitset.test(0) ) {
       // shift right - hey bus driver, remove that bit
       bci_val_bitset >>= 1;
       ++cbit;
     }
     console->debug("*** bitset PUSHING VALUE   = [[ {} ]]", cbit );
     indexVals.push_back( cbit );
     ++numBits;

     // REMEMBER TO KEEP ON GOING ON - more bits
     bci_val_bitset >>= 1;
     ++cbit;
   }


   // compact way to print vector to stringstream
   console->debug("*** [[ K-PARTIAL-SUMS (decodeBCItoIndexValues) ]] *** DONE");
   console->debug("***    TOTAL Number of Bits Found = [[ {} ]]", numBits );
     std::ostringstream oss;
     for( auto idx : indexVals ) { oss << idx << " , "; }
   console->debug("***    ARRAY INDICES FOUND = [[ {} ]]", oss.str() );
   console->debug("*** [[ K-PARTIAL-SUMS (decodeBCItoIndexValues) ]] *** DONE");
   return( numBits );

   } catch (const spd::spdlog_ex& ex) {
       std::cout << "*** FATAL( decodeBCItoIndexValues ): SPDLOG Log init failed: "
                 << ex.what() << std::endl;
     return(0);
   }
}