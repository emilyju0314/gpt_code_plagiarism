int SerialConsole::svc()
{
    // Activate the task (thread) that reads from the keyboard.
    _mykeyboardreader.activate();
    for (;;)
    {
        //wait for the answer
        ACE_Message_Block * response_block;
        ACE_DEBUG((LM_NOTICE, ACE_TEXT("%N Line %l SerialConsole::svc Waiting Response\n")));
        getq(response_block);
        ACE_DEBUG((LM_NOTICE, ACE_TEXT("%N Line %l SerialConsole::svc Response Received\n")));
        response_block->rd_ptr()[response_block->length()] = '\0';
        ACE_OS::printf("%s", response_block->rd_ptr());
    }
    return 0;
}