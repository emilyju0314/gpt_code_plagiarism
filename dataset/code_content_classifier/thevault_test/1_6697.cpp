double TfrcAgent::initial_rate()
{
        if (rate_init_option_ == 1) {
		// init_option = 1: static initial rate of rate_init_
                return (rate_init_);
        }
        else if (rate_init_option_ == 2) {
                // do initial rate according to RFC 3390.
		return (rfc3390(size_));
        }
        // XXX what should we return here???
        fprintf(stderr, "Wrong number of rate_init_option_ %d\n",
                rate_init_option_);
        abort();
        return (2.0); // XXX make msvc happy.
}