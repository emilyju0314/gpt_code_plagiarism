size_t
decodeBCItoIndexValues
(
   uint64_t BCIval ,
   std::vector<size_t>& indexVals
)
{
   size_t retNumBits = 0;
   std::bitset< sizeof(BCIval) > bitVals( BCIval );
   retNumBits = bitVals.count();
   return( retNumBits );
}