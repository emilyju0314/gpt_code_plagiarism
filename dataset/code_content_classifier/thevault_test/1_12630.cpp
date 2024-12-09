void CMB_Scheduler :: CMB_recv_incoming_messages()
{
    int received = 0;
    do {
        Message_s& msg = TheMessenger.irecv_message(&received);
	if(received != 0) {
	    switch(msg.type) {
	        case Message_s :: M_UINT32:
	        case Message_s :: M_UINT64:
	        case Message_s :: M_SERIAL:
		    break;
	        case Message_s :: M_PROTO1:
		    handle_proto1(msg);
		    break;
		default:
		    std::cerr << "unknown message type" << std::endl;
		    exit(1);
	    }//switch
	}
    }while(received != 0);

    //Receive NULL message too to prevent sender from blocking
    //if(m_end == false) //this if maybe correct, but won't gain much with it.
    TheMessenger.RecvPendingNullMsg();
}