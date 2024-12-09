uint32_t ts::Service::getFields() const
{
    uint32_t fields = 0;
    if (_id.set()) {
        fields |= ID;
    }
    if (_tsid.set()) {
        fields |= TSID;
    }
    if (_onid.set()) {
        fields |= ONID;
    }
    if (_pmt_pid.set()) {
        fields |= PMT_PID;
    }
    if (_lcn.set()) {
        fields |= LCN;
    }
    if (_type_dvb.set()) {
        fields |= TYPE_DVB;
    }
    if (_type_atsc.set()) {
        fields |= TYPE_ATSC;
    }
    if (_name.set()) {
        fields |= NAME;
    }
    if (_provider.set()) {
        fields |= PROVIDER;
    }
    if (_eits_present.set()) {
        fields |= EITS;
    }
    if (_eitpf_present.set()) {
        fields |= EITPF;
    }
    if (_ca_controlled.set()) {
        fields |= CA;
    }
    if (_running_status.set()) {
        fields |= RUNNING;
    }
    if (_major_id_atsc.set()) {
        fields |= MAJORID_ATSC;
    }
    if (_minor_id_atsc.set()) {
        fields |= MINORID_ATSC;
    }
    return fields;
}