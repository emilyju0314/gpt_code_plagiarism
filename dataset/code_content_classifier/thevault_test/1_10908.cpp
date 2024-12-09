void RecodeBeamSearch::ExtractBestPathAsWords(const TBOX &line_box,
                                              float scale_factor, bool debug,
                                              const UNICHARSET *unicharset,
                                              PointerVector<WERD_RES> *words,
                                              int lstm_choice_mode) {
  words->truncate(0);
  std::vector<int> unichar_ids;
  std::vector<float> certs;
  std::vector<float> ratings;
  std::vector<int> xcoords;
  std::vector<const RecodeNode *> best_nodes;
  std::vector<const RecodeNode *> second_nodes;
  character_boundaries_.clear();
  ExtractBestPaths(&best_nodes, &second_nodes);
  if (debug) {
    DebugPath(unicharset, best_nodes);
    ExtractPathAsUnicharIds(second_nodes, &unichar_ids, &certs, &ratings,
                            &xcoords);
    tprintf("\nSecond choice path:\n");
    DebugUnicharPath(unicharset, second_nodes, unichar_ids, certs, ratings,
                     xcoords);
  }
  // If lstm choice mode is required in granularity level 2, it stores the x
  // Coordinates of every chosen character, to match the alternative choices to
  // it.
  ExtractPathAsUnicharIds(best_nodes, &unichar_ids, &certs, &ratings, &xcoords,
                          &character_boundaries_);
  int num_ids = unichar_ids.size();
  if (debug) {
    DebugUnicharPath(unicharset, best_nodes, unichar_ids, certs, ratings,
                     xcoords);
  }
  // Convert labels to unichar-ids.
  int word_end = 0;
  float prev_space_cert = 0.0f;
  for (int word_start = 0; word_start < num_ids; word_start = word_end) {
    for (word_end = word_start + 1; word_end < num_ids; ++word_end) {
      // A word is terminated when a space character or start_of_word flag is
      // hit. We also want to force a separate word for every non
      // space-delimited character when not in a dictionary context.
      if (unichar_ids[word_end] == UNICHAR_SPACE) {
        break;
      }
      int index = xcoords[word_end];
      if (best_nodes[index]->start_of_word) {
        break;
      }
      if (best_nodes[index]->permuter == TOP_CHOICE_PERM &&
          (!unicharset->IsSpaceDelimited(unichar_ids[word_end]) ||
           !unicharset->IsSpaceDelimited(unichar_ids[word_end - 1]))) {
        break;
      }
    }
    float space_cert = 0.0f;
    if (word_end < num_ids && unichar_ids[word_end] == UNICHAR_SPACE) {
      space_cert = certs[word_end];
    }
    bool leading_space =
        word_start > 0 && unichar_ids[word_start - 1] == UNICHAR_SPACE;
    // Create a WERD_RES for the output word.
    WERD_RES *word_res =
        InitializeWord(leading_space, line_box, word_start, word_end,
                       std::min(space_cert, prev_space_cert), unicharset,
                       xcoords, scale_factor);
    for (int i = word_start; i < word_end; ++i) {
      auto *choices = new BLOB_CHOICE_LIST;
      BLOB_CHOICE_IT bc_it(choices);
      auto *choice = new BLOB_CHOICE(unichar_ids[i], ratings[i], certs[i], -1,
                                     1.0f, static_cast<float>(INT16_MAX), 0.0f,
                                     BCC_STATIC_CLASSIFIER);
      int col = i - word_start;
      choice->set_matrix_cell(col, col);
      bc_it.add_after_then_move(choice);
      word_res->ratings->put(col, col, choices);
    }
    int index = xcoords[word_end - 1];
    word_res->FakeWordFromRatings(best_nodes[index]->permuter);
    words->push_back(word_res);
    prev_space_cert = space_cert;
    if (word_end < num_ids && unichar_ids[word_end] == UNICHAR_SPACE) {
      ++word_end;
    }
  }
}