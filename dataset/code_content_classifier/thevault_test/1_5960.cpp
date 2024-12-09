void MhProtoClient::createError(const char *file) {
    int fd = open(file, O_WRONLY);

    if (fd == -1) {
        perror("Fail to open file for test.");
        exit(1);
    }

    write(fd, "Error", strlen("Error"));

    close(fd);
}