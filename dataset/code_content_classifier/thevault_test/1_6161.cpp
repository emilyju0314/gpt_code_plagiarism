void Port::Share(Sendable *nsendable)
{
	okay_to_send.Wait();
	out_mutex.Wait();
	p_sendable.Set(nsendable);
	out_mutex.Post();

	/// this simply pulses the mutex on the sender thread.
	/// cost an additional thread but hopefully saves a costly message
	/// through the port socket.
	tsender.pulseGo ();
}