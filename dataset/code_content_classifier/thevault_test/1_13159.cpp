int disable_interrupts(WDC_DEVICE_HANDLE m_device)
{
    int data                  = 0;
    int address               = PCIE_CRA_IRQ_ENABLE;

    struct acl_cmd driver_cmd;
    driver_cmd.bar_id         = ACL_PCI_GLOBAL_MEM_BAR;
    driver_cmd.command        = ACLPCI_CMD_DEFAULT;

    //both user_addr and device_addr fields need an address pointer
    driver_cmd.device_addr    = reinterpret_cast<void *>(address);//address to write to in the PCI address space, driver requires this to be a void pointer
    driver_cmd.user_addr      = &data;//address to read from in user address space
    driver_cmd.size           = sizeof(data);

    //endianness does not matter for this operation
    driver_cmd.is_diff_endian = 0;

    return write (m_device, &driver_cmd, sizeof(driver_cmd));
}