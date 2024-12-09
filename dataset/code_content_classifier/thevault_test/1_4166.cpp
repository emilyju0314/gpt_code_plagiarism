int AshmemCreate(const char *name, size_t size)
{
    int ret;
    int fd = AshmemOpen();
    if (fd < 0) {
        UTILS_LOGE("%{public}s: Failed to exec AshmemOpen fd = %{public}d", __func__, fd);
        return fd;
    }

    if (name != nullptr) {
        char buf[ASHMEM_NAME_LEN] = {0};
        ret = strcpy_s(buf, sizeof(buf), name);
        if (ret != EOK) {
            UTILS_LOGE("%{public}s: Failed to exec strcpy_s, name= %{public}s, ret= %{public}d", __func__, name, ret);
            close(fd);
            return -1;
        }
        ret = TEMP_FAILURE_RETRY(ioctl(fd, ASHMEM_SET_NAME, buf));
        if (ret < 0) {
            UTILS_LOGE("%{public}s: Failed to set name, name= %{public}s, ret= %{public}d", __func__, name, ret);
            close(fd);
            return ret;
        }
    }

    ret = TEMP_FAILURE_RETRY(ioctl(fd, ASHMEM_SET_SIZE, size));
    if (ret < 0) {
        UTILS_LOGE("%{public}s: Failed to set size, size= %{public}zu", __func__, size);
        close(fd);
        return ret;
    }
    return fd;
}