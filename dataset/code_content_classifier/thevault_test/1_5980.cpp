YARPSendable(YARPPortContent *n_ypc, int n_owned = 1)
	{
		ypc = NULL;  owned = 0;
		Attach(n_ypc, n_owned);
	}