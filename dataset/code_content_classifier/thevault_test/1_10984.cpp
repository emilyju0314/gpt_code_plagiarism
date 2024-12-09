bool WERD_RES::LogNewCookedChoice(int max_num_choices, bool debug,
                                  WERD_CHOICE *word_choice) {
  if (best_choice != nullptr) {
    // Throw out obviously bad choices to save some work.
    // TODO(rays) Get rid of this! This piece of code produces different
    // results according to the order in which words are found, which is an
    // undesirable behavior. It would be better to keep all the choices and
    // prune them later when more information is available.
    float max_certainty_delta = StopperAmbigThreshold(
        best_choice->adjust_factor(), word_choice->adjust_factor());
    if (max_certainty_delta > -kStopperAmbiguityThresholdOffset) {
      max_certainty_delta = -kStopperAmbiguityThresholdOffset;
    }
    if (word_choice->certainty() - best_choice->certainty() <
        max_certainty_delta) {
      if (debug) {
        std::string bad_string;
        word_choice->string_and_lengths(&bad_string, nullptr);
        tprintf(
            "Discarding choice \"%s\" with an overly low certainty"
            " %.3f vs best choice certainty %.3f (Threshold: %.3f)\n",
            bad_string.c_str(), word_choice->certainty(),
            best_choice->certainty(),
            max_certainty_delta + best_choice->certainty());
      }
      delete word_choice;
      return false;
    }
  }

  // Insert in the list in order of increasing rating, but knock out worse
  // string duplicates.
  WERD_CHOICE_IT it(&best_choices);
  const std::string &new_str = word_choice->unichar_string();
  bool inserted = false;
  int num_choices = 0;
  if (!it.empty()) {
    do {
      WERD_CHOICE *choice = it.data();
      if (choice->rating() > word_choice->rating() && !inserted) {
        // Time to insert.
        it.add_before_stay_put(word_choice);
        inserted = true;
        if (num_choices == 0) {
          best_choice = word_choice; // This is the new best.
        }
        ++num_choices;
      }
      if (choice->unichar_string() == new_str) {
        if (inserted) {
          // New is better.
          delete it.extract();
        } else {
          // Old is better.
          if (debug) {
            tprintf("Discarding duplicate choice \"%s\", rating %g vs %g\n",
                    new_str.c_str(), word_choice->rating(), choice->rating());
          }
          delete word_choice;
          return false;
        }
      } else {
        ++num_choices;
        if (num_choices > max_num_choices) {
          delete it.extract();
        }
      }
      it.forward();
    } while (!it.at_first());
  }
  if (!inserted && num_choices < max_num_choices) {
    it.add_to_end(word_choice);
    inserted = true;
    if (num_choices == 0) {
      best_choice = word_choice; // This is the new best.
    }
  }
  if (debug) {
    if (inserted) {
      tprintf("New %s", best_choice == word_choice ? "Best" : "Secondary");
    } else {
      tprintf("Poor");
    }
    word_choice->print(" Word Choice");
  }
  if (!inserted) {
    delete word_choice;
    return false;
  }
  return true;
}