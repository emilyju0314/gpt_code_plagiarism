void job::resolve() {

   object *pTop = top();

   switch ( pTop -> ObjectType() ) {

   case object::number:
      return;

   default:
      operatorLoad();

   }

   return;
   }