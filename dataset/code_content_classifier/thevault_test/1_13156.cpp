int save_pci_control_regs(WDC_DEVICE_HANDLE m_device)
{
   int save_failed = 1;
   struct acl_cmd cmd_save = { ACLPCI_CMD_BAR, ACLPCI_CMD_SAVE_PCI_CONTROL_REGS, NULL, NULL };

   //executes the save registers command and stores the pass/fail status in save_failed
   //because we only want to send a command and do not care about reading or writing a value
   //either read or write can be used to execute this command
   save_failed = read(m_device, &cmd_save, 0);

   return save_failed;
}