void CMB_TickedOptScheduler::Run()
{
    CmbSyncAlg* CMB = dynamic_cast<CmbSyncAlg*>(m_syncAlg);
    assert(CMB);

    TheMessenger.barrier();

    m_num_fini = 0; //number of nodes that have exited main loop

    bool processed = false; //a clock edge was just processed; no null msg sent yet
    struct timeval t_null;
    t_null.tv_sec = 0;

    stats_blocking_time = 0;

    while(!m_halted) {
        // Next we  need to find the clock object with the next earliest tick
	GET_NEXT_TICK_TIME; 


        if(CMB->isSafeToProcess(nextClockTime))
        {
#ifdef GET_BLOCKING_TIME
if(processed == false) { //first safe after null was sent
    struct timeval t_safe;
    gettimeofday(&t_safe, NULL);
    if(t_null.tv_sec != 0) { //the very first safe doen't count because no null-msg has been sent
	//blocking time = from sending null-msg to the next safe processing
        stats_blocking_time += (t_safe.tv_sec - t_null.tv_sec)*1000000 + (t_safe.tv_usec - t_null.tv_usec);
    }
    //cout << "safe " << t_safe.tv_sec*1000000 + t_safe.tv_usec << endl;
}
processed = true;
#endif
            assert(nextClockTime>=m_simTime);
            m_simTime = nextClockTime;
            nextClock->ProcessThisTick(); //note m_halted may be set to true as a result
	    if(m_halted)
		break;
        }
        else {
	    //send null messages
	    if(CMB->send_null_msgs(nextClock)) { //returns true when null-msg is actually sent.
#ifdef GET_BLOCKING_TIME
    processed = false;
    gettimeofday(&t_null, NULL);
    //cout << "null " << t_null.tv_sec*1000000 + t_null.tv_usec << endl;
#endif
	    }
	}

        CMB_handle_incoming_messages(); //check incoming messages

    }//while(!m_halted)

    post_main_loop();

}