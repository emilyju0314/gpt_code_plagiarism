void ClientConnector :: MessageReceivedFromIOThread(const MessageRef & msg)
{
   MutexGuard mg(_replyQueueMutex);
   if (_replyQueue.IsEmpty()) RequestCallbackInDispatchThread();
   (void) _replyQueue.AddTail(msg);
}