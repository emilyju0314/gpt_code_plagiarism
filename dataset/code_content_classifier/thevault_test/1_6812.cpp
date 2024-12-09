void BayFullTcpAgent::usrclosed()
{

	switch (state_) {
	case TCPS_CLOSED:
	case TCPS_LISTEN:
	case TCPS_SYN_SENT:
		state_ = TCPS_CLOSED;
		break;
	case TCPS_SYN_RECEIVED:
	case TCPS_ESTABLISHED:
		state_ = TCPS_FIN_WAIT_1;
		send_much(1, REASON_NORMAL, 0);
		break;
	}
	return;
}