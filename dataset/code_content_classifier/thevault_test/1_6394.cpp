BOOST_AUTO_TEST_CASE(one_to_two_split_alignment)
{
  tagged_alignment al1{ 0, 0, Segs{ {  0, 499, 0, 499, {}, {}} }, nan("") };
  tagged_alignment al2{ 0, 1, Segs{ {200, 299, 0,  99, {}, {}} }, nan("") };
  size_t A_card = 1, B_card = 2;
  Lens lens{500, 100};
  Taus taus{0.01, 0.99};
  double pair_recall = compute_recall<pair_helper>({al1, al2}, A_card, B_card, lens, taus, 0);
  double nucl_recall = compute_recall<nucl_helper>({al1, al2}, A_card, B_card, lens, taus, 0);
  double tran_recall = compute_recall<tran_helper>({al1, al2}, A_card, B_card, lens, taus, 0);
  CHECK_CLOSE(pair_recall, 1.0*(taus[0]*choose_2(200+1) + taus[1]*choose_2(100+1) + taus[0]*choose_2(200+1))/pair_denom(lens, taus));
  CHECK_CLOSE(nucl_recall, 1.0*(taus[0]*         200    + taus[1]*         100    + taus[0]*         200   )/nucl_denom(lens, taus));
  CHECK_CLOSE(tran_recall, taus[1]);
}