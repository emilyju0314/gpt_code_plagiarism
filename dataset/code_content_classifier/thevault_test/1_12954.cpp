BOOST_AUTO_TEST_CASE(SimpleAcrobotTest)
{
  const Acrobot task = Acrobot();

  Acrobot::State state = task.InitialSample();
  Acrobot::Action action = Acrobot::Action::negativeTorque;
  double reward = task.Sample(state, action);

  BOOST_REQUIRE_EQUAL(reward, -1.0);
  BOOST_REQUIRE(!task.IsTerminal(state));
  BOOST_REQUIRE_EQUAL(3, Acrobot::Action::size);
}