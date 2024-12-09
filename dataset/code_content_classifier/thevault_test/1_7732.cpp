void  LocApiV02 :: reportSystemInfo(
    const qmiLocSystemInfoIndMsgT_v02* system_info_ptr){

    if (system_info_ptr == nullptr) {
        return;
    }

    LOC_LOGe("system info type: %d, leap second valid: %d "
             "current gps time:valid:%d, week: %d, msec: %d,"
             "current leap second:valid %d, seconds %d, "
             "next gps time: valid %d, week: %d, msec: %d,"
             "next leap second: valid %d, seconds %d",
             system_info_ptr->systemInfo,
             system_info_ptr->nextLeapSecondInfo_valid,
             system_info_ptr->nextLeapSecondInfo.gpsTimeCurrent_valid,
             system_info_ptr->nextLeapSecondInfo.gpsTimeCurrent.gpsWeek,
             system_info_ptr->nextLeapSecondInfo.gpsTimeCurrent.gpsTimeOfWeekMs,
             system_info_ptr->nextLeapSecondInfo.leapSecondsCurrent_valid,
             system_info_ptr->nextLeapSecondInfo.leapSecondsCurrent,
             system_info_ptr->nextLeapSecondInfo.gpsTimeNextLsEvent_valid,
             system_info_ptr->nextLeapSecondInfo.gpsTimeNextLsEvent.gpsWeek,
             system_info_ptr->nextLeapSecondInfo.gpsTimeNextLsEvent.gpsTimeOfWeekMs,
             system_info_ptr->nextLeapSecondInfo.leapSecondsNext_valid,
             system_info_ptr->nextLeapSecondInfo.leapSecondsNext);

    LocationSystemInfo systemInfo = {};
    if ((system_info_ptr->systemInfo == eQMI_LOC_NEXT_LEAP_SECOND_INFO_V02) &&
        (system_info_ptr->nextLeapSecondInfo_valid == 1)) {

        const qmiLocNextLeapSecondInfoStructT_v02 &nextLeapSecondInfo =
            system_info_ptr->nextLeapSecondInfo;

        if (nextLeapSecondInfo.gpsTimeNextLsEvent_valid &&
                nextLeapSecondInfo.leapSecondsCurrent_valid &&
                nextLeapSecondInfo.leapSecondsNext_valid) {

            systemInfo.systemInfoMask |= LOCATION_SYS_INFO_LEAP_SECOND;
            systemInfo.leapSecondSysInfo.leapSecondInfoMask |=
                    LEAP_SECOND_SYS_INFO_LEAP_SECOND_CHANGE_BIT;

            LeapSecondChangeInfo &leapSecondChangeInfo =
                    systemInfo.leapSecondSysInfo.leapSecondChangeInfo;
            leapSecondChangeInfo.gpsTimestampLsChange.systemWeek =
                    nextLeapSecondInfo.gpsTimeNextLsEvent.gpsWeek;
            leapSecondChangeInfo.gpsTimestampLsChange.systemMsec =
                    nextLeapSecondInfo.gpsTimeNextLsEvent.gpsTimeOfWeekMs;
            leapSecondChangeInfo.gpsTimestampLsChange.validityMask =
                    (GNSS_SYSTEM_TIME_WEEK_VALID | GNSS_SYSTEM_TIME_WEEK_MS_VALID);

            leapSecondChangeInfo.leapSecondsBeforeChange =
                    nextLeapSecondInfo.leapSecondsCurrent;
            leapSecondChangeInfo.leapSecondsAfterChange =
                    nextLeapSecondInfo.leapSecondsNext;
        }

        if (nextLeapSecondInfo.leapSecondsCurrent_valid) {
            systemInfo.systemInfoMask |= LOCATION_SYS_INFO_LEAP_SECOND;
            systemInfo.leapSecondSysInfo.leapSecondInfoMask |=
                    LEAP_SECOND_SYS_INFO_CURRENT_LEAP_SECONDS_BIT;
            systemInfo.leapSecondSysInfo.leapSecondCurrent =
                    nextLeapSecondInfo.leapSecondsCurrent;
        }
    }

    if (systemInfo.systemInfoMask) {
        LocApiBase::reportLocationSystemInfo(systemInfo);
    }
}