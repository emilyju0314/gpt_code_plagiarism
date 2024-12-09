bool RTCPReceiver::NTP(uint32_t* ReceivedNTPsecs,
                       uint32_t* ReceivedNTPfrac,
                       uint32_t* RTCPArrivalTimeSecs,
                       uint32_t* RTCPArrivalTimeFrac,
                       uint32_t* rtcp_timestamp) const
{
    CriticalSectionScoped lock(_criticalSectionRTCPReceiver);
    if(ReceivedNTPsecs)
    {
        *ReceivedNTPsecs = _remoteSenderInfo.NTPseconds; // NTP from incoming SendReport
    }
    if(ReceivedNTPfrac)
    {
        *ReceivedNTPfrac = _remoteSenderInfo.NTPfraction;
    }
    if(RTCPArrivalTimeFrac)
    {
        *RTCPArrivalTimeFrac = _lastReceivedSRNTPfrac; // local NTP time when we received a RTCP packet with a send block
    }
    if(RTCPArrivalTimeSecs)
    {
        *RTCPArrivalTimeSecs = _lastReceivedSRNTPsecs;
    }
    if (rtcp_timestamp) {
      *rtcp_timestamp = _remoteSenderInfo.RTPtimeStamp;
    }
    return true;
}