bool TrackerStatus::noSignal(StrawId const& sid) const {
    static StrawStatus mask = StrawStatus(StrawStatus::absent) |
      StrawStatus(StrawStatus::nowire) |
      StrawStatus(StrawStatus::noHV) |
      StrawStatus(StrawStatus::noLV) |
      StrawStatus(StrawStatus::nogas) |
      StrawStatus(StrawStatus::lowgasgain) |
      StrawStatus(StrawStatus::noHVPreamp) |
      StrawStatus(StrawStatus::noCalPreamp) |
      StrawStatus(StrawStatus::disabled);
    StrawStatus status = strawStatus(sid);
    return status.hasAnyProperty(mask);
  }