void REMQueue::run_updaterule()
{

	double in, in_avg, nqueued, pl, pr;

        // link price, the congestion measure

	pl = remv_.v_pl;

	// in is the number of bytes (if qib_ is true) or packets (otherwise)
	// arriving at the link (input rate) during one update time interval

	in = remv_.v_count;
       
	// in_avg is the low pss filtered input rate
	// which is in bytes if qib_ is true and in packets otherwise.

	in_avg = remv_.v_ave;
  
	in_avg *= (1.0 - remp_.p_inw);
	
	if (qib_) {
		in_avg += remp_.p_inw*in/remp_.p_pktsize; 
		nqueued = bcount_/remp_.p_pktsize; 
        }
	else {
		in_avg += remp_.p_inw*in;
		nqueued = q_ -> length();
	}


	// c measures the maximum number of packets that 
	// could be sent during one update interval.

	double c  = remp_.p_updtime*remp_.p_ptc;

	pl = pl + remp_.p_gamma*( in_avg + 0.1*(nqueued-remp_.p_bo) - c );

	if ( pl < 0.0) {
	    pl = 0.0;
	}

	double pow1 = pow (remp_.p_phi, -pl);
	pr = 1.0-pow1;


	remv_.v_count = 0.0;
	remv_.v_ave = in_avg;
	remv_.v_pl = pl;
	remv_.v_prob = pr;
}