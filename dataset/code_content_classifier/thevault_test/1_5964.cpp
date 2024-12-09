Semaphore::Semaphore(int init) {
    DEBUG("Semaphore::Constructor\n");

    error_   = 0;
    init_id_ = 1237;
    unsigned int seed = getpid();
    do {
        if (init) sem_id_ = semget(init_id_ , 1 , 0666 | IPC_CREAT | IPC_EXCL);
        else
            sem_id_ = semget(init_id_ , 1 , 0666);
        if (sem_id_ == -1) init_id_ = rand_r(&seed);
    } while ((errno == EEXIST) && (sem_id_ == -1));
    error_ = 0;
    if (sem_id_ == -1) {
        error_ = 1;
        perror("Semaphore::Constructor ");
        return;
    }

    if (init) {
        if (!set_semvalue()) {
            printf("Failed to initialize semaphore\n");
            error_ = 1;
        }
    }
}