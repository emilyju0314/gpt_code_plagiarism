bool RTPPacketHistory::FindSeqNum(uint16_t sequence_number,
                                  int32_t* index) const {
  uint16_t temp_sequence_number = 0;
  if (prev_index_ > 0) {
    *index = prev_index_ - 1;
    temp_sequence_number = stored_packets_[*index].sequence_number;
  } else {
    *index = stored_packets_.size() - 1;
    temp_sequence_number = stored_packets_[*index].sequence_number;  // wrap
  }

  int32_t idx = (prev_index_ - 1) - (temp_sequence_number - sequence_number);
  if (idx >= 0 && idx < static_cast<int>(stored_packets_.size())) {
    *index = idx;
    temp_sequence_number = stored_packets_[*index].sequence_number;
  }

  if (temp_sequence_number != sequence_number) {
    // We did not found a match, search all.
    for (uint16_t m = 0; m < stored_packets_.size(); m++) {
      if (stored_packets_[m].sequence_number == sequence_number) {
        *index = m;
        temp_sequence_number = stored_packets_[*index].sequence_number;
        break;
      }
    }
  }
  if (temp_sequence_number == sequence_number) {
    // We found a match.
    return true;
  }
  return false;
}