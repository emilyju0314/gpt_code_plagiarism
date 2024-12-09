bool UsbManager::CBLineStateChanged(usb_cdc_control_signal_t state) {
    UsbMgr.m_lineState = state;
    if (state.rs232.DTR) {
        // Callbacks must be registered after endpoint allocation
        cdcdf_acm_register_callback(CDCDF_ACM_CB_READ, (FUNC_PTR)RxComplete);
        cdcdf_acm_register_callback(CDCDF_ACM_CB_WRITE, (FUNC_PTR)TxComplete);
        // Start Rx
        cdcdf_acm_read(UsbMgr.m_usbReadBuf, sizeof(UsbMgr.m_usbReadBuf));
    }
    else {
        // Callbacks must be registered after endpoint allocation
        cdcdf_acm_register_callback(CDCDF_ACM_CB_READ, (FUNC_PTR)NULL);
        cdcdf_acm_register_callback(CDCDF_ACM_CB_WRITE, (FUNC_PTR)NULL);
        // Stop Rx/Tx
        cdcdf_acm_stop_xfer();
        if (cdcdf_acm_get_line_coding()->dwDTERate == 1200) {
            SysMgr.ResetBoard(SysManager::RESET_TO_BOOTLOADER);
        }
    }

    // No error
    return false;
}