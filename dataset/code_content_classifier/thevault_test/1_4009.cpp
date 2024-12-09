bool CTimer::isRunning( )
{
   updateThreadState();
   if( thread == 0 )
   {
      return false;
   }
   else
   {
      return true;
   }
}