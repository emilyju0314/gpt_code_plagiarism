int DGSNetworkHandler::svc()
{
    ACE_TRACE("DGSNetworkHandler::svc");
    ACE_DEBUG((LM_NOTICE, ACE_TEXT("%N Line %l DGSNetworkHandler::svc Starting SVC\n"))); 

    for (;;)
    {
        ACE_Message_Block * response_block;
        getq(response_block);
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("%N Line %l DGSNetworkHandler::svc Getting a message\n"))); 
        writer_.write( *response_block, response_block->length());
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("%N Line %l DGSNetworkHandler::svc Sending a message back\n"))); 
        //response_block->release();
    }
    ACE_DEBUG((LM_NOTICE, ACE_TEXT("%N Line %l DGSNetworkHandler::svc Finising SVC\n")));
    return 0;
}