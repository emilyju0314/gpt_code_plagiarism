Thread::Thread (const String& threadName_, const size_t stackSize)
    : threadName (threadName_),
      threadHandle (nullptr),
      threadId (0),
      threadPriority (5),
      threadStackSize (stackSize),
      affinityMask (0),
      shouldExit (false)
{
}