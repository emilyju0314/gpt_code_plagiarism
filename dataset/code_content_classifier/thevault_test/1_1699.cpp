TEST(InteractionTest, Episode1) {
  // Test a common walkthrough.
  //
  // 1: H1 C1 <= button
  // 2: H2 H3 <= big blind
  // 3: C2 D5 <= small blind
  // 4: C9 S9
  // B: H4 H5 D6 D9 H9

  Dummy dm;
  DummyBackdoor dbd(dm);
  const auto &players = dbd.GetPlayerStat();
  const auto &board = dbd.GetBoard();

  ASSERT_EQ(dm.Join("Alice"), 1);
  ASSERT_EQ(dm.Join("Bob"), 2);
  ASSERT_EQ(dm.Join("Carl"), 3);
  ASSERT_EQ(dm.Join("Diana"), 4);
  ASSERT_EQ(dm.Topup(1, 10), 10);
  ASSERT_EQ(dm.Topup(2, 10), 10);
  ASSERT_EQ(dm.Topup(3, 10), 10);
  ASSERT_EQ(dm.Topup(4, 10), 10);
  ASSERT_EQ(dm.Begin(), Dummy::READY);
  ASSERT_EQ(board.size(), 0);

  using namespace poker;

  dbd.SetDeck({H9, D9, D6, H5, H4, S9, C9, D5, C2, H3, H2, C1, H1});
  dbd.RedealCards();

  // Check hands after redealing.
  ASSERT_EQ(players.at(1).holecards[0], H1);
  ASSERT_EQ(players.at(1).holecards[1], C1);
  ASSERT_EQ(players.at(2).holecards[0], H2);
  ASSERT_EQ(players.at(2).holecards[1], H3);
  ASSERT_EQ(players.at(3).holecards[0], C2);
  ASSERT_EQ(players.at(3).holecards[1], D5);
  ASSERT_EQ(players.at(4).holecards[0], C9);
  ASSERT_EQ(players.at(4).holecards[1], S9);

  // Begin with a pair of 9, Diana is confident.
  ASSERT_EQ(dm.Play(4, 4), Dummy::READY);
  // Alice has a pair of A, nothing to be afraid.
  ASSERT_EQ(dm.Play(1, 4), Dummy::READY);
  // Bob expects a straight.
  ASSERT_EQ(dm.Play(2, 4), Dummy::READY);
  // Carl chooses to drop.
  ASSERT_EQ(dm.Play(3, -1), Dummy::READY);

  // Now we got 3 guys alive with a raised round.
  // Thus we are still in the flop round.
  ASSERT_EQ(board.size(), 0);
  // Everyone calls within this round.
  ASSERT_EQ(dm.Play(4, 4), Dummy::READY);
  ASSERT_EQ(dm.Play(1, 4), Dummy::READY);
  ASSERT_EQ(dm.Play(2, 4), Dummy::READY);
  // Round ends without raised, flop cards should be dealed.
  ASSERT_EQ(board.size(), 3);
  ASSERT_EQ(board[0], H4);
  ASSERT_EQ(board[1], H5);
  ASSERT_EQ(board[2], D6);

  // Diana chooses to check, because she is at the first position.
  ASSERT_EQ(dm.Play(4, 4), Dummy::READY);
  // Nothing to be afraid after all, Alice raises by 2.
  ASSERT_EQ(dm.Play(1, 6), Dummy::READY);
  // Bob gets his straight, so he raises as well.
  ASSERT_EQ(dm.Play(2, 10), Dummy::READY);

  // 3 guys alive with a raised round, so we are still in the river round.
  ASSERT_EQ(board.size(), 3);

  // Diana is scared, choosing to drop.
  ASSERT_EQ(dm.Play(4, -1), Dummy::READY);
  // "I got a pair of Ace.", thinks Alice.
  ASSERT_EQ(dm.Play(1, 10), Dummy::STOP);

  // Now we got last 2 guys all-in.
  // Dummy should deal last two cards and evaluate the winner.
  ASSERT_EQ(board.size(), 5);
  ASSERT_EQ(board[3], D9);
  ASSERT_EQ(board[4], H9);
  // The winner is Bob with his straight of course.
  const auto &winners = dbd.GetWinners();
  ASSERT_EQ(winners.size(), 1);
  ASSERT_EQ(winners[0], 2);

  // Check chip liquidation.
  ASSERT_EQ(players.at(1).bankroll, 0);
  ASSERT_EQ(players.at(2).bankroll, 26);
  ASSERT_EQ(players.at(3).bankroll, 8);
  ASSERT_EQ(players.at(4).bankroll, 6);
}