void SMAC::update_myNeighbList()
{
        //we should update the schedTab[].numNodes before we call checkMySched()
        //to ensure the next available schedule is correct
        check_schedFlag();
        update_neighbList();
        updateNeighbList_ = 0;
        schedTab_[0].chkSched = 0;  //we already did checkMySched() in update_neighbList()
        txRequest_ = 0;
}