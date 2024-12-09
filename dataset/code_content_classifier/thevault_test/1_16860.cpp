void HardwareReadHandler(void){
	Alf_Log::alf_log_write("Started HardwareReadHandler thread", log_info);
	Alf_Drive_Info drive_info_local_copy;
	uint32_t irq_info;
	int ret;
	ssize_t nb;
    struct pollfd fds = {
        .fd = fd,
        .events = POLLIN,
    };
	while(run_threads){
	    irq_info = 1; /* unmask */

	    nb = write(fd, &irq_info, sizeof(irq_info));
	    if (nb < sizeof(irq_info)){
	    	Alf_Log::alf_log_write("Cannot write to fd", log_error);
	    	run_threads = false;
	    	break;
	    }

		ret = poll(&fds, 1, -1);	//waiting until interrupt was coming
        if (ret >= 1) {
            nb = read(fd, &irq_info, sizeof(irq_info));
            if (nb == sizeof(irq_info)) {
            	shared_mem.ReadInterruptHandler();
            	notify_ServerWrite_Task = true;
            	Run_ServerWrite_Task.notify_one();
            }
        } else {
            Alf_Log::alf_log_write("Error while handling interrupt in user mode!", log_error);
            run_threads = false;
        }
	}
	uint32_t end = ALF_END_ID;
	shared_mem.Write(end);
	Alf_Log::alf_log_write("Ended HardwareReadHandler thread", log_info);
}