inline bool validate(const types::authority& auth) {
   const types::key_permission_weight* prev = nullptr;
   decltype(auth.threshold) totalWeight = 0;

   for( const auto& k : auth.keys ) {
      if( !prev ) prev = &k;
      else if( prev->key < k.key ) return false;
      totalWeight += k.weight;
   }
   const types::account_permission_weight* pa = nullptr;
   for( const auto& a : auth.accounts ) {
      if( !pa ) pa = &a;
      else if( pa->permission < a.permission ) return false;
      totalWeight += a.weight;
   }
   return totalWeight >= auth.threshold;
}