double TcpAgent::increase_param()
{
	double increase, decrease, p, answer;
	/* extending the slow-start for high-speed TCP */

	/* for highspeed TCP -- from Sylvia Ratnasamy, */
	/* modifications by Sally Floyd and Evandro de Souza */
 	// p ranges from 1.5/W^2 at congestion window low_window_, to
	//    high_p_ at congestion window high_window_, on a log-log scale.
        // The decrease factor ranges from 0.5 to high_decrease
	//  as the window ranges from low_window to high_window, 
	//  as the log of the window. 
	// For an efficient implementation, this would just be looked up
	//   in a table, with the increase and decrease being a function of the
	//   congestion window.

       if (cwnd_ <= low_window_) { 
		answer = 1 / cwnd_;
       		return answer; 
       } else if (cwnd_ >= hstcp_.cwnd_last_ && 
	      cwnd_ < hstcp_.cwnd_last_ + cwnd_range_) {
	      // cwnd_range_ can be set to 0 to be disabled,
	      //  or can be set from 1 to 100 
       		answer = hstcp_.increase_last_ / cwnd_;
              	return answer;
       } else { 
		// OLD:
 		// p = exp(linear(log(cwnd_), log(low_window_), log(hstcp_.low_p), log(high_window_), log(high_p_)));
		// NEW, but equivalent:
        	p = exp(hstcp_.p1 + log(cwnd_) * hstcp_.p2);  
        	decrease = decrease_param();
		// OLD:
		// increase = cwnd_*cwnd_*p *(2.0*decrease)/(2.0 - decrease); 
		// NEW, but equivalent:
		increase = cwnd_ * cwnd_ * p /(1/decrease - 0.5);
		//	if (increase > max_increase) { 
		//		increase = max_increase;
		//	} 
		answer = increase / cwnd_;
		hstcp_.cwnd_last_ = cwnd_;
		hstcp_.increase_last_ = increase;
       		return answer;
	}       
}