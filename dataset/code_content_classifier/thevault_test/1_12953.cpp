BOOST_AUTO_TEST_CASE(SimpleContinuousMountainCarTest)
{
  const ContinuousMountainCar task = ContinuousMountainCar();

  ContinuousMountainCar::State state = task.InitialSample();
  ContinuousMountainCar::Action action;
  action.action[0] = math::Random(-1.0, 1.0);
  double reward = task.Sample(state, action);
  // Maximum reward possible is 100.
  BOOST_REQUIRE(reward <= 100.0);
  BOOST_REQUIRE(!task.IsTerminal(state));
  BOOST_REQUIRE_EQUAL(1, action.size);
}