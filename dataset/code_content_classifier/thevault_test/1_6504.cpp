void SMAC::update_schedTab_neighbList()
{
        //update schedTab and neighbList if flag is set
        //we should update the schedTab[].numNodes before we call checkMySched()
        //to ensure the next available schedule is correct
        check_schedFlag();
        if (updateNeighbList_ == 1) {
                update_neighbList();
                updateNeighbList_ = 0;
                schedTab_[0].chkSched = 0;  //we already did checkMySched() in update_neighbList()
        } else if (schedTab_[0].chkSched == 1) {
                checkMySched();
                schedTab_[0].chkSched = 0;
        }
}