bool CmbSyncAlg :: isSafeToProcess_send_null_if_safe(double requestTime)
{
    static bool Initialized = false;

    static std::vector<LpId_t>* succs=&(Manifold::get_scheduler()->get_successors());
    static size_t SuccsSize = 0;

    if(!Initialized) {
	UpdateEitSet();
	UpdateEotSet();
	SuccsSize=succs->size();
	Initialized = true;
    }

    // Second, check the input buffer for pending time synch messages:
    NullMsg_t* msg;
    do {
	msg=TheMessenger.RecvPendingNullMsg();
	if(msg) {
	    // We have a message, let's update:
	    Time_t oldEit=m_eits[msg->src];
	    Time_t newEit=msg->t;
	    if(newEit>oldEit) m_eits[msg->src]=newEit;
	    #ifdef STATS
	    stats_received_null[msg->src]++;
	    #endif
        }
    } while(msg);

    // Third, compute time of earliest possible local event:
    Time_t earliestLocalEvent=requestTime;
    bool result=true;
    for(ts_t::iterator it=m_eits.begin();it!=m_eits.end();++it) {
	Time_t itTime=it->second;
	if(itTime<earliestLocalEvent) {
	    earliestLocalEvent=itTime;
	    result=false; // We now already know that the min EIT is smaller than requestTime
	    return result;
	}
    }


    int src=Manifold::GetRank();

    for(size_t i=0;i<SuccsSize;i++) {
	Time_t newEot=earliestLocalEvent + m_lookahead->GetLookahead(src, (*succs)[i]);
	Time_t oldEot=m_eots[i];
	assert(newEot>=oldEot);
    
	if(newEot>oldEot) { // only send if necessary
	    msg=new NullMsg_t();
	    msg->src = src;
	    msg->dst = (*succs)[i];
	    m_eots[i]=newEot;
	    msg->t=newEot;
	    TheMessenger.SendNullMsg(msg);
	    delete msg;
	    #ifdef STATS
	    stats_sent_null[(*succs)[i]]++;
	    #endif
	}
    }

    // Last, but not least: return result:
    return result;

}