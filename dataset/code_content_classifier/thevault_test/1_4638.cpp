void TheThreadManager::destroyInstance( ) {
      static TheThreadManager* debugStack = &getInstance( );
      if ( debugStack != nullptr ) {
         delete debugStack;
      }
   }