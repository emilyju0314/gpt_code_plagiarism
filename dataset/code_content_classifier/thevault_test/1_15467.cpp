int8_t ChronoChroma::attached() {
  if (EventReceiver::attached()) {
    event_color_shift.repurpose(CHRONOCHROMA_MSG_COLOR_SHF, (EventReceiver*) this);
    event_color_shift.incRefs();
    event_color_shift.specific_target = (EventReceiver*) this;
    event_color_shift.alterSchedulePeriod(30);
    event_color_shift.autoClear(false);
    event_color_shift.alterScheduleRecurrence(-1);
    platform.kernel()->addSchedule(&event_color_shift);

    event_display_refresh.repurpose(CHRONOCHROMA_MSG_DISP_UPDATE, (EventReceiver*) this);
    event_display_refresh.incRefs();
    event_display_refresh.specific_target = (EventReceiver*) this;
    event_display_refresh.alterSchedulePeriod(1000);
    event_display_refresh.autoClear(false);
    event_display_refresh.alterScheduleRecurrence(-1);
    platform.kernel()->addSchedule(&event_display_refresh);
    return 1;
  }
  return 0;
}