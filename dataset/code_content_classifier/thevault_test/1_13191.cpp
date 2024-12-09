void* ubertooth_cap_thread(void* arg)
{
	PacketSource_Ubertooth* ubertooth = (PacketSource_Ubertooth*) arg;

	ubertooth_bulk_init(ubertooth->ut);

	ubertooth_bulk_thread_start();

	cmd_rx_syms(ubertooth->ut->devh);

	while (ubertooth->thread_active) {
		ubertooth_bulk_receive(ubertooth->ut, cb_cap, ubertooth);
	}

	ubertooth->thread_active = -1;
	close(ubertooth->fake_fd[1]);
	ubertooth->fake_fd[1] = -1;
	pthread_exit((void *) 0);
}