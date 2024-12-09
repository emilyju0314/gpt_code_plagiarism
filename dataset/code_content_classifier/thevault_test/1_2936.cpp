void SysManager::UpdateFastImpl() {
    CcioMgr.Refresh();
    AdcMgr.Update();
    StatusMgr.Refresh();
    UsbMgr.Refresh();
    InputMgr.UpdateBegin();

    if (SysMgr.Ready()) {
        for (uint8_t i = 0; i < CLEARCORE_PIN_MAX; i++) {
            Connectors[i]->Refresh();
        }
    }

    InputMgr.UpdateEnd();
    EncoderIn.Update();

    // Update subsystems in the background
    ShiftReg.Update();
    TimingMgr.Update();

    tickCnt++;
}