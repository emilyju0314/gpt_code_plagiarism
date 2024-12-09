int load_pci_control_regs(WDC_DEVICE_HANDLE m_device)
{
   int load_failed = 1;
   struct acl_cmd cmd_load = { ACLPCI_CMD_BAR, ACLPCI_CMD_LOAD_PCI_CONTROL_REGS, NULL, NULL };

   //executes load registers command and stores the pass/fail status in load_failed
   //because we only want to send a command and do not care about reading or writing a value
   //either read or write can be used to execute this command
   load_failed = read(m_device, &cmd_load, 0);

   return load_failed;
}