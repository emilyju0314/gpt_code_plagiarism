void CTimer::updateThreadState( )
{
   if( thread )
      if( pthread_kill( thread, 0 ) != 0 )
          thread = 0;  // NOT running!
}