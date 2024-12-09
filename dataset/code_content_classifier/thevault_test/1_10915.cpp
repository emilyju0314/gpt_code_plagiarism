void RecodeBeamSearch::ContinueContext(
    const RecodeNode *prev, int index, const float *outputs,
    TopNState top_n_flag, const UNICHARSET *charset, double dict_ratio,
    double cert_offset, double worst_dict_cert, RecodeBeam *step) {
  RecodedCharID prefix;
  RecodedCharID full_code;
  const RecodeNode *previous = prev;
  int length = LengthFromBeamsIndex(index);
  bool use_dawgs = IsDawgFromBeamsIndex(index);
  NodeContinuation prev_cont = ContinuationFromBeamsIndex(index);
  for (int p = length - 1; p >= 0; --p, previous = previous->prev) {
    while (previous != nullptr &&
           (previous->duplicate || previous->code == null_char_)) {
      previous = previous->prev;
    }
    if (previous != nullptr) {
      prefix.Set(p, previous->code);
      full_code.Set(p, previous->code);
    }
  }
  if (prev != nullptr && !is_simple_text_) {
    if (top_n_flags_[prev->code] == top_n_flag) {
      if (prev_cont != NC_NO_DUP) {
        float cert =
            NetworkIO::ProbToCertainty(outputs[prev->code]) + cert_offset;
        PushDupOrNoDawgIfBetter(length, true, prev->code, prev->unichar_id,
                                cert, worst_dict_cert, dict_ratio, use_dawgs,
                                NC_ANYTHING, prev, step);
      }
      if (prev_cont == NC_ANYTHING && top_n_flag == TN_TOP2 &&
          prev->code != null_char_) {
        float cert = NetworkIO::ProbToCertainty(outputs[prev->code] +
                                                outputs[null_char_]) +
                     cert_offset;
        PushDupOrNoDawgIfBetter(length, true, prev->code, prev->unichar_id,
                                cert, worst_dict_cert, dict_ratio, use_dawgs,
                                NC_NO_DUP, prev, step);
      }
    }
    if (prev_cont == NC_ONLY_DUP) {
      return;
    }
    if (prev->code != null_char_ && length > 0 &&
        top_n_flags_[null_char_] == top_n_flag) {
      // Allow nulls within multi code sequences, as the nulls within are not
      // explicitly included in the code sequence.
      float cert =
          NetworkIO::ProbToCertainty(outputs[null_char_]) + cert_offset;
      PushDupOrNoDawgIfBetter(length, false, null_char_, INVALID_UNICHAR_ID,
                              cert, worst_dict_cert, dict_ratio, use_dawgs,
                              NC_ANYTHING, prev, step);
    }
  }
  const std::vector<int> *final_codes = recoder_.GetFinalCodes(prefix);
  if (final_codes != nullptr) {
    for (int code : *final_codes) {
      if (top_n_flags_[code] != top_n_flag) {
        continue;
      }
      if (prev != nullptr && prev->code == code && !is_simple_text_) {
        continue;
      }
      float cert = NetworkIO::ProbToCertainty(outputs[code]) + cert_offset;
      if (cert < kMinCertainty && code != null_char_) {
        continue;
      }
      full_code.Set(length, code);
      int unichar_id = recoder_.DecodeUnichar(full_code);
      // Map the null char to INVALID.
      if (length == 0 && code == null_char_) {
        unichar_id = INVALID_UNICHAR_ID;
      }
      if (unichar_id != INVALID_UNICHAR_ID && charset != nullptr &&
          !charset->get_enabled(unichar_id)) {
        continue; // disabled by whitelist/blacklist
      }
      ContinueUnichar(code, unichar_id, cert, worst_dict_cert, dict_ratio,
                      use_dawgs, NC_ANYTHING, prev, step);
      if (top_n_flag == TN_TOP2 && code != null_char_) {
        float prob = outputs[code] + outputs[null_char_];
        if (prev != nullptr && prev_cont == NC_ANYTHING &&
            prev->code != null_char_ &&
            ((prev->code == top_code_ && code == second_code_) ||
             (code == top_code_ && prev->code == second_code_))) {
          prob += outputs[prev->code];
        }
        cert = NetworkIO::ProbToCertainty(prob) + cert_offset;
        ContinueUnichar(code, unichar_id, cert, worst_dict_cert, dict_ratio,
                        use_dawgs, NC_ONLY_DUP, prev, step);
      }
    }
  }
  const std::vector<int> *next_codes = recoder_.GetNextCodes(prefix);
  if (next_codes != nullptr) {
    for (int code : *next_codes) {
      if (top_n_flags_[code] != top_n_flag) {
        continue;
      }
      if (prev != nullptr && prev->code == code && !is_simple_text_) {
        continue;
      }
      float cert = NetworkIO::ProbToCertainty(outputs[code]) + cert_offset;
      PushDupOrNoDawgIfBetter(length + 1, false, code, INVALID_UNICHAR_ID, cert,
                              worst_dict_cert, dict_ratio, use_dawgs,
                              NC_ANYTHING, prev, step);
      if (top_n_flag == TN_TOP2 && code != null_char_) {
        float prob = outputs[code] + outputs[null_char_];
        if (prev != nullptr && prev_cont == NC_ANYTHING &&
            prev->code != null_char_ &&
            ((prev->code == top_code_ && code == second_code_) ||
             (code == top_code_ && prev->code == second_code_))) {
          prob += outputs[prev->code];
        }
        cert = NetworkIO::ProbToCertainty(prob) + cert_offset;
        PushDupOrNoDawgIfBetter(length + 1, false, code, INVALID_UNICHAR_ID,
                                cert, worst_dict_cert, dict_ratio, use_dawgs,
                                NC_ONLY_DUP, prev, step);
      }
    }
  }
}