void War::tie() {

  // For loop which executes (tiebreaker - 1) times
  for (int i = 1; i < J1val; i++) {

    // Output all except tiebreaker card
    cout << "\t" << "J1: "
    << mainDeck.asCard(J1Deck[J1Deck.size() - 1 - tieback.size()])
    << "\t J2: "
    << mainDeck.asCard(J2Deck[J2Deck.size() - 1 - tieback.size()]) << endl;

    // push into tieback vector
    tieback.push_back(0);
  }

  // Output tiebreaker card
  cout << "\t" << "J1: "
  << mainDeck.asCard(J1Deck[J1Deck.size() - 1 - tieback.size()])
  << "\t J2: "
  << mainDeck.asCard(J2Deck[J2Deck.size() - 1 - tieback.size()]);

  // J1val and J2val correspond to the value of a card
  // stoi() is called on the result of assignVal on the first 2 characters
  // of the card corresponding to the back of each player's deck

  J1val = stoi( assignVal(mainDeck.asCard(J1Deck[J1Deck.size()  - 1 - tieback.size()]).substr(0, 1)) );
  J2val = stoi( assignVal(mainDeck.asCard(J2Deck[J2Deck.size()  - 1 - tieback.size()]).substr(0, 1)) );

  // Consier the tiebreaker card
  tieback.push_back(0);

  // J1 has a better hand
  if (J1val > J2val) {

    // Run the tieback function
    applyTieback("J1");

    // Output result
    cout << "\t\tGana J1. Total cartas: " << J1Deck.size()
    << " / " << J2Deck.size() << endl;

    return;

  // J2 has a better hand
  } else if (J1val < J2val) {

    // Run the tieback function
    applyTieback("J2");

    // Output result
    cout << "\t\tGana J2. Total cartas: " << J1Deck.size()
    << " / " << J2Deck.size() << endl;

    return;

  // J1 and J2 drew the same value
  } else {

    // The value was 'A' == 0
    if (J1val == 0) {
      cout << "\t\tEmpate! Pero no se lanzarán barajas." << endl;
      J1Deck.pop_back();
      J2Deck.pop_back();

    // The value was 1
    } else if (J1val == 1) {
        cout << "\t\tEmpate! Se lanzará 1 baraja." << endl;
        J1Deck.pop_back();
        J2Deck.pop_back();
        duel();

    // The value was greater than 1
    } else {
      cout << "\t\tEmpate! Se lanzarán " << J1val << " barajas." << endl;

      // J1 cannot draw sufficient cards
      if (J1Deck.size() - J1val <= 0 || J1Deck.size() - J1val > 52) {
        stop("J2");
      }

      // J2 cannot draw sufficient cards
      else if (J2Deck.size() - J1val <= 0 || J1Deck.size() - J1val > 52) {
        stop("J1");
      }

      // Go to a recursive tiebreaker
      else { tie(); }
    }
  }

  return;
}