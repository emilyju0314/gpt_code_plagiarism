int program_core_with_PR ( WDC_DEVICE_HANDLE device, char *core_bitstream, size_t core_rbf_len)
{
    int pr_result = 1;   // set to default - failure
    struct acl_cmd cmd_pr = { ACLPCI_CMD_BAR, ACLPCI_CMD_DO_PR, NULL, NULL };
    cmd_pr.user_addr = core_bitstream;
    cmd_pr.size      = core_rbf_len;
    //this invoces a special driver function that is used to send the bitstream to the PR controller
    pr_result = read( device, &cmd_pr, sizeof(cmd_pr) );
    return pr_result;
}