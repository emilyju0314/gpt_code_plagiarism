BOOST_AUTO_TEST_CASE(SimpleMountainCarTest)
{
  const MountainCar task = MountainCar();

  MountainCar::State state = task.InitialSample();
  MountainCar::Action action = MountainCar::Action::backward;
  double reward = task.Sample(state, action);

  BOOST_REQUIRE_EQUAL(reward, -1.0);
  BOOST_REQUIRE(!task.IsTerminal(state));
  BOOST_REQUIRE_EQUAL(3, MountainCar::Action::size);
}