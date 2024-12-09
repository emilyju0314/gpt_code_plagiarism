void HDLC::recvOutgoing(Packet* p)
{
	ARQstate *a;
	int next_hop = getRoute(p);
	
	//if (disconnect_) {
		
		// if (!sentDISC_) {
// 			sendUA(p, DISC);
// 			sentDISC_ = 1;
// 			set_rtx_timer();
// 			drop(p);
			
// 			return;
// 		}
// 		drop(p);
// 		return;
// 	}
	
	a = checkState(next_hop);
	if (a == 0)
		a = createState(next_hop);
	
	if (!(a->SABME_req_) && a->t_seqno_ == 0) {
		// this is the first pkt being sent
		// send out SABME request to start connection
		
		sendUA(p, SABME);

		// set SABME request flag to 1
		// have sent request, not yet confirmed
		a->SABME_req_ = 1;
		
		// set some timer for SABME?
		set_rtx_timer(a);
		
	}
        
        // place pkt in outgoing queue
	inSendBuffer(p, a);
	
	// send data pkts only after recving UA
	// in reply to SABME request
	if (a->SABME_req_ == 2) 
		sendMuch(a);
	
}