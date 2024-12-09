void MaintTimer::timeOutCallback() {
    LOC_LOGd("maint timer fired");

    struct PerformMaintenanceReq : public LocMsg {
        PerformMaintenanceReq(LocationApiService* locationApiService) :
                mLocationApiService(locationApiService){}
        virtual ~PerformMaintenanceReq() {}
        void proc() const {
            mLocationApiService->performMaintenance();
        }
        LocationApiService* mLocationApiService;
    };
    mMsgTask.sendMsg(new (nothrow) PerformMaintenanceReq(mLocationApiService));
}