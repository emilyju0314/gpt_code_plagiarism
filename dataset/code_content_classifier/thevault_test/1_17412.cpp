int launch (int pipefd, char* source_filename, xrmCuPoolProperty* xrm_transcode_cu_pool_prop, char* pre_src_cmdline, int log_en)
{
    // initialize
    xrmContext *ctx = (xrmContext *)xrmCreateContext(XRM_API_VERSION_1);
    if (ctx == NULL)
    {
       printf ("Create context failed\n");
       return -1;
    }

    // allocate resources
    uint64_t reservation_id = xrmCuPoolReserve(ctx, xrm_transcode_cu_pool_prop);
    if (reservation_id == 0)
    {
        printf("xrmCuPoolReserve: fail to reserve transcode cu pool :%lu\n",reservation_id);
        if (ctx)
            xrmDestroyContext(ctx);
	return -1;
    }

    // send signal to parent process that allocation is complete
    char buf = '\0';
    (void) !write (pipefd, &buf, 1);
    close (pipefd);

    // set environmant variable with service id
    char alloc_reservation_id[16];
    sprintf (alloc_reservation_id, "%lu", reservation_id);

    setenv ("XRM_RESERVE_ID", alloc_reservation_id, 1);
    if (log_en == 1)
       printf("xrm_reservation_id =%lu \n",reservation_id);

    // write console output to seperate log files with '-enable-logging' option 
    int file_out = -1; 
    char fname[256]; 
    struct stat dstat; 
    int ret = -1; 
    if (log_en == 1) 
    { 
       if (stat("/var/tmp/xilinx", &dstat) == -1) 
       { 
          ret = mkdir("/var/tmp/xilinx",0777); 
          if (ret != 0) 
          { 
            printf("Couldn't create /var/tmp/xilinx folder to write logs. Err = %s", strerror(errno));
            return EXIT_FAILURE; 
          }         
       } 
       sprintf(fname,"/var/tmp/xilinx/job_%lu_res.log",reservation_id); 
       file_out =  open(fname,O_RDWR | O_CREAT, 0644); 
    } 

    
    // fork new process
    int pid = fork ();
    if (pid < 0)
    {
        perror("worker.cpp::launch() Fork failed\n") ;
        if (ctx && reservation_id)
	{
	    if(xrmCuPoolRelinquish (ctx, reservation_id))
     	    {
                if (log_en == 1)
                    printf("xrmCuPoolRelinquish = %lu\n",reservation_id);
        	if(xrmDestroyContext(ctx) != XRM_SUCCESS)
          	    printf("XRM destroy context failed! %lu\n",reservation_id);
            }
	}
	else
	{
            if(!ctx)
		printf("Null XRM context. xrmCuPoolRelinquish & xrmDestroyContext failed!\n");
	    else		
		printf("Null reservation id. xrmCuPoolRelinquish failed!\n");
	}
        return -1;
    }
    if (pid == 0) 
    {
    // insert source file into command lineand add ReservationID to the output for each process
    char cpy_pre_out_cmdline[4096];
    strcpy (cpy_pre_out_cmdline, pre_src_cmdline);

    char cmdline_test[4096];
    memset (cmdline_test, 0, sizeof (cmdline_test));

    char*word;
    char c_id[256];

    sprintf(c_id,"%lu",reservation_id);

    word =strtok(cpy_pre_out_cmdline, " ");
    strcpy(cmdline_test,word);
    if (strstr(word, "ffmpeg") != NULL) {
        prepare_ffmpeg_run_cmd(source_filename, c_id, cmdline_test);
    } else if (strstr(word, "mpsoc_app") != NULL) {
        prepare_mpsoc_app_run_cmd(source_filename, c_id, cmdline_test);
    } else {
        printf("Error : Unknown Executable %s\n", word);
        return -1;
    }

     //printf("command:\n%s\n",cmdline_test);

     // separate command line into array of arguments
     char* cmd_params[256];
     if (separate_cmdline (cmdline_test, cmd_params))
         return -1;
    char cmd[256];
    strcpy (cmd, cmd_params[0]);
    const char* file = strrchr (cmd, '/');
    if (file)
          file++;
    else
          file = cmd;
    strcpy (cmd_params[0], file);

    if (log_en == 1) 
    { 
       if (dup2(file_out, 0) < 0)
          printf("LOG_INFO: Unable to copy log file descriptor to stdin\n"); 
       if (dup2(file_out, 1) < 0)
          printf("LOG_INFO: Unable to copy log file descriptor to stdout\n"); 
       if (dup2(file_out, 2) < 0)
          printf("LOG_INFO: Unable to copy log file descriptor to stderr\n");  
 
       close (file_out); 
    } 

    // execute command
    if (execvp (cmd, cmd_params) != 0)
    {
        printf("somthing is wrong (%s)\nffmpeg failed\n", strerror(errno));
        //exit(1);//if want to exit when there is a error
    }

        return 0;
    }

    // wait for child to finish
    int wstatus;
    waitpid (pid, &wstatus, 0);
    // release resources
    if(xrmCuPoolRelinquish (ctx, reservation_id))
    {
       if (log_en == 1)
          printf("------------xrmCuPoolRelinquish =%lu\n",reservation_id);

       if(xrmDestroyContext(ctx) != XRM_SUCCESS)
         printf("XRM destroy context failed! %lu\n",reservation_id);
    }
    
    if (WIFEXITED(wstatus))
        return WEXITSTATUS(wstatus);
    else
        return -1;
}