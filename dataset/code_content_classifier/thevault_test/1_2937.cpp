void SysManager::UpdateSlowImpl() {
    if (!m_readyForOperations) {
        return;
    }

    // CCIO-8 Auto-Rediscover
    CcioMgr.RefreshSlow();

    for (uint8_t iMotor = 0; iMotor < MOTOR_CON_CNT; iMotor++) {
        MotorConnectors[iMotor]->RefreshSlow();
    }
}