BOOST_AUTO_TEST_CASE(sanity_2)
{
  size_t A_card = 1, B_card = 1;
  double pair_recall = compute_recall<pair_helper>({}, A_card, B_card, Lens{100}, Taus{1.0}, 0);
  double nucl_recall = compute_recall<nucl_helper>({}, A_card, B_card, Lens{100}, Taus{1.0}, 0);
  double tran_recall = compute_recall<tran_helper>({}, A_card, B_card, Lens{100}, Taus{1.0}, 0);
  CHECK_CLOSE(pair_recall, 0.0);
  CHECK_CLOSE(nucl_recall, 0.0);
  CHECK_CLOSE(tran_recall, 0.0);
}