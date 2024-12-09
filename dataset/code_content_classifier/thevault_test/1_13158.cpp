WDC_DEVICE_HANDLE open_device_linux(int dev_num)
{
   char buf[128] = {0};
   std::string mystr = "/dev/acl";
   mystr += ACL_BOARD_PKG_NAME;

   std::ostringstream temp;
   temp << dev_num;
   mystr += temp.str();

   //opening device
   ssize_t device = open(mystr.c_str(), O_RDWR);

   //expected version
   std::string expected_ver_string = ACL_BOARD_PKG_NAME;
   expected_ver_string += ".";
   expected_ver_string += KERNEL_DRIVER_VERSION_EXPECTED;

   // Return INVALID_DEVICE when the device is not available
   if (device == -1)
   {
      return INVALID_DEVICE;
   }

   // Make sure the Linux kernel driver is recent
   struct acl_cmd driver_cmd = { ACLPCI_CMD_BAR, ACLPCI_CMD_GET_DRIVER_VERSION,
                              NULL, buf, 0 };
   read (device, &driver_cmd, 0);

   /*if (expected_ver_string != std::string(buf))
   {
       std::cout << "ERROR: Kernel driver mismatch: "
                    "The board kernel driver version is " << buf <<
                    " but\nthis host program expects " << expected_ver_string <<
                    ".\n  Please reinstall the driver using aocl install.\n";

       return INVALID_DEVICE;
   }*/

   // Set the FD_CLOEXEC flag for the file handle to disable the child to
   // inherit this file handle. So the jtagd will not hold the file handle
   // of the device and keep sending bogus interrupts after we call quartus_pgm.
   int oldflags = fcntl( device, F_GETFD, 0);
   fcntl( device, F_SETFD, oldflags | FD_CLOEXEC );

   return device;
}