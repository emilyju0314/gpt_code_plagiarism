void WERD_RES::FilterWordChoices(int debug_level) {
  if (best_choice == nullptr || best_choices.singleton()) {
    return;
  }

  if (debug_level >= 2) {
    best_choice->print("\nFiltering against best choice");
  }
  WERD_CHOICE_IT it(&best_choices);
  int index = 0;
  for (it.forward(); !it.at_first(); it.forward(), ++index) {
    WERD_CHOICE *choice = it.data();
    float threshold = StopperAmbigThreshold(best_choice->adjust_factor(),
                                            choice->adjust_factor());
    // i, j index the blob choice in choice, best_choice.
    // chunk is an index into the chopped_word blobs (AKA chunks).
    // Since the two words may use different segmentations of the chunks, we
    // iterate over the chunks to find out whether a comparable blob
    // classification is much worse than the best result.
    unsigned i = 0, j = 0, chunk = 0;
    // Each iteration of the while deals with 1 chunk. On entry choice_chunk
    // and best_chunk are the indices of the first chunk in the NEXT blob,
    // i.e. we don't have to increment i, j while chunk < choice_chunk and
    // best_chunk respectively.
    auto choice_chunk = choice->state(0), best_chunk = best_choice->state(0);
    while (i < choice->length() && j < best_choice->length()) {
      if (choice->unichar_id(i) != best_choice->unichar_id(j) &&
          choice->certainty(i) - best_choice->certainty(j) < threshold) {
        if (debug_level >= 2) {
          choice->print("WorstCertaintyDiffWorseThan");
          tprintf(
              "i %u j %u Choice->Blob[i].Certainty %.4g"
              " WorstOtherChoiceCertainty %g Threshold %g\n",
              i, j, choice->certainty(i), best_choice->certainty(j), threshold);
          tprintf("Discarding bad choice #%d\n", index);
        }
        delete it.extract();
        break;
      }
      ++chunk;
      // If needed, advance choice_chunk to keep up with chunk.
      while (choice_chunk < chunk && ++i < choice->length()) {
        choice_chunk += choice->state(i);
      }
      // If needed, advance best_chunk to keep up with chunk.
      while (best_chunk < chunk && ++j < best_choice->length()) {
        best_chunk += best_choice->state(j);
      }
    }
  }
}