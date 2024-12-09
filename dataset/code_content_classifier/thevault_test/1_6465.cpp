void
FullTcpAgent::usrclosed()
{
	curseq_ = maxseq_ - 1;	// now, no more data
	infinite_send_ = FALSE;	// stop infinite send

	switch (state_) {
	case TCPS_CLOSED:
	case TCPS_LISTEN:
		cancel_timers();
		newstate(TCPS_CLOSED);
		finish();
		break;
	case TCPS_SYN_SENT:
		newstate(TCPS_CLOSED);
		/* fall through */
	case TCPS_LAST_ACK:
		flags_ |= TF_NEEDFIN;
		send_much(1, REASON_NORMAL, maxburst_);
		break;
	case TCPS_SYN_RECEIVED:
	case TCPS_ESTABLISHED:
		newstate(TCPS_FIN_WAIT_1);
		flags_ |= TF_NEEDFIN;
		send_much(1, REASON_NORMAL, maxburst_);
		break;
	case TCPS_CLOSE_WAIT:
		newstate(TCPS_LAST_ACK);
		flags_ |= TF_NEEDFIN;
		send_much(1, REASON_NORMAL, maxburst_);
		break;
	case TCPS_FIN_WAIT_1:
	case TCPS_FIN_WAIT_2:
	case TCPS_CLOSING:
		/* usr asked for a close more than once [?] */
                if (debug_)
		         fprintf(stderr,
		           "%f FullTcpAgent(%s): app close in bad state %s\n",
		           now(), name(), statestr(state_));
		break;
	default:
                if (debug_)
		        fprintf(stderr,
		        "%f FullTcpAgent(%s): app close in unknown state %s\n",
		        now(), name(), statestr(state_));
	}

	return;
}