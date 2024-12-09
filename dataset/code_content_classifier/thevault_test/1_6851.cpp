void SRR::enque(Packet* pkt)
{
	PacketSRR *q;
	//PacketSRR *remq;
	int flowid, queueid;
	int weight;

	hdr_cmn *ch=hdr_cmn::access(pkt);
	hdr_ip *iph = hdr_ip::access(pkt);

	flowid= iph->flowid(); 		//get the flowid
	queueid= f2q[flowid]; 	// get the corresponding queue id

	if(queueid > maxqueuenumber_)
	{
		fprintf(stderr, "queueid too big\n");
		exit(1);
	}

#ifdef DEBUG_SRR
	printf("   in enque\n"); fflush(0);
#endif
	

// we drop packets from the longest queue
/*	if( bytecnt+ ch->size() > blimit_){

		drop(pkt);
		return;
	}
*/
	
	q=&srr[queueid];

	if(q->pkts==qlim_){

		drop(pkt);
		return;
	}

	q->enque(pkt);

	++q->pkts;
	++pktcnt;
	q->bcount += ch->size();
	bytecnt +=ch->size();


	if (q->pkts==1)
	{
			//add to the WM
			// adjust currMaxColumn
			// if it is a first active flow, put the pwmPtr
		        // all the above works are done in add_to_WM
			weight= private_rate[queueid];
			weight/=granularity_;
			
			add_to_WM(queueid, weight);
			
			q->deficitCounter=0;
	}

}