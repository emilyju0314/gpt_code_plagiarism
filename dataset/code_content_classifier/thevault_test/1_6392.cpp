BOOST_AUTO_TEST_CASE(mostly_covered_two_to_one)
{
  tagged_alignment al1{ 0, 0, Segs{ {0, 989,   0, 989, {}, {}} }, nan("") };
  tagged_alignment al2{ 1, 0, Segs{ {0, 499, 500, 999, {}, {}} }, nan("") };
  size_t A_card = 2, B_card = 1;
  double pair_recall = compute_recall<pair_helper>({al1, al2}, A_card, B_card, Lens{1000}, Taus{1.0}, 20);
  double nucl_recall = compute_recall<nucl_helper>({al1, al2}, A_card, B_card, Lens{1000}, Taus{1.0}, 20);
  double tran_recall = compute_recall<tran_helper>({al1, al2}, A_card, B_card, Lens{1000}, Taus{1.0}, 20);
  CHECK_CLOSE(pair_recall, 1.0*choose_2(990+1)/choose_2(1000+1));
  CHECK_CLOSE(nucl_recall, 1.0*990/1000);
  CHECK_CLOSE(tran_recall, 1.0);
}