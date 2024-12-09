static void call_and_unlock(boost::function0<void> f, libport::Semaphore& s)
{
  f();
  s++;
}