void War::applyTieback(string s) {

  // J1 won the tiebreaker
  if (s == "J1") {

    // while the tieback vector has elements
    while (!tieback.empty()) {

      // Assign the elements to J1
      J1Deck.push_front(J1Deck.back());
      J1Deck.push_front(J2Deck.back());
      J1Deck.pop_back();
      J2Deck.pop_back();

      tieback.pop_back();
    }

  // J2 won the tiebreaker
  } else {

    // while the tieback vector has elements
    while (!tieback.empty()) {

      // Assign the elements to J2
      J2Deck.push_front(J2Deck.back());
      J2Deck.push_front(J1Deck.back());
      J1Deck.pop_back();
      J2Deck.pop_back();

      tieback.pop_back();
    }
  }
}