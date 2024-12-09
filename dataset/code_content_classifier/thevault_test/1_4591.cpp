void CActiveMasternode::ManageStatus()
{
    std::string errorMessage;

    if(!fMasterNode) return;

    LogPrintf("CActiveMasternode::ManageStatus() - Begin\n");

    //need correct blocks to send ping
    if(Params().NetworkIDString() != CBaseChainParams::REGTEST && !masternodeSync.IsBlockchainSynced()) {
        status = ACTIVE_MASTERNODE_SYNC_IN_PROCESS;
        LogPrintf("CActiveMasternode::ManageStatus() - %s\n", GetStatus());
        return;
    }

    if(status == ACTIVE_MASTERNODE_SYNC_IN_PROCESS) 
        status = ACTIVE_MASTERNODE_INITIAL;

    if(status == ACTIVE_MASTERNODE_INITIAL) {
        CMasternode *pmn;
        pmn = mnodeman.Find(pubKeyMasternode);
        if(pmn != NULL) {
            pmn->Check();
            if (pmn->IsEnabled() && pmn->protocolVersion == PROTOCOL_VERSION) {
                EnableHotColdMasterNode(pmn->vin, pmn->addr);
                if (!pmn->vchSignover.empty()) {
                    if (pmn->pubkey.Verify(pubKeyMasternode.GetHash(), pmn->vchSignover)) {
                        LogPrintf("%s: Verified pubkey2 signover for staking\n", __func__);
                        activeMasternode.vchSigSignover = pmn->vchSignover;
                    } else {
                        LogPrintf("%s: Failed to verify pubkey on signover!\n", __func__);
                    }
                } else {
                    LogPrintf("%s: NOT SIGNOVER!\n", __func__);
                }
            }
        }
    }


    if(status != ACTIVE_MASTERNODE_STARTED) {

        // Set defaults
        status = ACTIVE_MASTERNODE_NOT_CAPABLE;
        notCapableReason = "";

        const auto pwallet = GetMainWallet();

        if (pwallet && pwallet->IsLocked()) {
            notCapableReason = "Wallet is locked.";
            LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
            return;
        }

        if(!pwallet || (pwallet && pwallet->GetBalance().m_mine_trusted == CAmountMap())){
            notCapableReason = "Masternode configured correctly and ready, please use your local wallet to start it -Start alias-.";
            LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
            return;
        }

        if(strMasterNodeAddr.empty()) {
            if(!GetLocal(service)) {
                notCapableReason = "Can't detect external address. Please use the masternodeaddr configuration option.";
                LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
                return;
            }
        } else {
            service = CService(LookupNumeric(strMasterNodeAddr, Params().GetDefaultPort()));
        }

        if(Params().NetworkIDString() == CBaseChainParams::MAIN) {
            if(service.GetPort() != Params().GetDefaultPort()) {
                notCapableReason = strprintf("Invalid port: %u - only %u is supported on mainnet.", service.GetPort(), Params().GetDefaultPort());
                LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
                return;
            }
        } else if(service.GetPort() == Params().GetDefaultPort()) {
            notCapableReason = strprintf("Invalid port: %u - %u is only supported on mainnet.", service.GetPort(), Params().GetDefaultPort());
            LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
            return;
        }

        LogPrintf("CActiveMasternode::ManageStatus() - Checking inbound connection to '%s'\n", service.ToString());

        SOCKET hSocket = INVALID_SOCKET;
        hSocket = CreateSocket(service);
        if (hSocket == INVALID_SOCKET) {
            LogPrintf("CActiveMasternode::ManageStateInitial -- Could not create socket '%s'\n", service.ToString());
            return;
        }
        bool fConnected = ConnectSocketDirectly(service, hSocket, nConnectTimeout, true) && IsSelectableSocket(hSocket);
        CloseSocket(hSocket);

        if(!fConnected) {
            notCapableReason = "Could not connect to " + service.ToString();
            LogPrintf("CActiveMasternode::ManageStatus() - not capable: %s\n", notCapableReason);
            return;
        }

        // Choose coins to use
        CPubKey pubKeyCollateralAddress;
        CKey keyCollateralAddress;

        if(pwallet->GetMasternodeVinAndKeys(vin, pubKeyCollateralAddress, keyCollateralAddress)) {

            if(GetUTXOConfirmations(vin.prevout) < MASTERNODE_MIN_CONFIRMATIONS){
                status = ACTIVE_MASTERNODE_INPUT_TOO_NEW;
                notCapableReason = strprintf("%s - %d confirmations", GetStatus(), GetUTXOConfirmations(vin.prevout));
                LogPrintf("CActiveMasternode::ManageStatus() - %s\n", notCapableReason);
                return;
            }

            LOCK(pwallet->cs_wallet);
            pwallet->LockCoin(vin.prevout);

            // send to all nodes
            CPubKey pubKeyMasternode;
            CKey keyMasternode;

            if (!legacySigner.SetKey(strMasterNodePrivKey, keyMasternode, pubKeyMasternode)) {
                notCapableReason = "Error upon calling SetKey: " + errorMessage;
                LogPrintf("Register::ManageStatus() - %s\n", notCapableReason);
                return;
            }

            CMasternodeBroadcast mnb;
            bool fSignOver = true;
            if(!CMasternodeBroadcast::Create(vin, service, keyCollateralAddress, pubKeyCollateralAddress, keyMasternode, pubKeyMasternode, fSignOver, errorMessage, mnb)) {
                notCapableReason = "Error on CreateBroadcast: " + errorMessage;
                LogPrintf("Register::ManageStatus() - %s\n", notCapableReason);
                return;
            }

            //update to masternode list
            LogPrintf("CActiveMasternode::ManageStatus() - Update Masternode List\n");
            mnodeman.UpdateMasternodeList(mnb);

            //send to all peers
            LogPrintf("CActiveMasternode::ManageStatus() - Relay broadcast vin = %s\n", vin.ToString());
            mnb.Relay();

            LogPrintf("CActiveMasternode::ManageStatus() - Is capable master node!\n");
            status = ACTIVE_MASTERNODE_STARTED;

            return;
        } else {
            notCapableReason = "Could not find suitable coins!";
            LogPrintf("CActiveMasternode::ManageStatus() - %s\n", notCapableReason);
            return;
        }
    }

    LogPrintf("CActiveMasternode::ManageStatus() - 4\n");

    //send to all peers
    if(!SendMasternodePing(errorMessage)) {
        LogPrintf("CActiveMasternode::ManageStatus() - Error on Ping: %s\n", errorMessage);
    }
}