void Tcp::stopReadThread()
{
	if(m_readThread)
	{
		printInfoMessage("Tcp::stopReadThread: Stopping thread.", m_beVerbose);
		
		m_readThread->m_threadShouldRun = false;
		m_readThread->join();
		delete m_readThread;
		m_readThread = 0;
		printInfoMessage("Tcp::stopReadThread: Done - Read thread is now closed.", m_beVerbose);
	}
}