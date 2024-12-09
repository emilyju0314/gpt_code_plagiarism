BOOST_AUTO_TEST_CASE(AddReturn) {
  {
    MeanImage mi(false, 1);
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == true);               // should be done after adding one image
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == true);               // and again...
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == true);               // and again..
    BOOST_REQUIRE(mi.addWeighted(generateRandomImage(1, 1), 1.0) == true);  // and again..
  }
  {
    MeanImage mi(false, 2);
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == false);               // need one more
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == true);                // should be done after adding two images
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == false);               // reset and need one more
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == true);                // should be done after adding two images
    BOOST_REQUIRE(mi.addWeighted(generateRandomImage(1, 1), 1.0) == false);  // reset and need one more
    BOOST_REQUIRE(mi.addWeighted(generateRandomImage(1, 1), 1.0) == true);   // should be done after adding two images
  }
  {
    MeanImage mi(false, 0);
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == false);               // will never be done
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == false);               // never
    BOOST_REQUIRE(mi.addWeighted(generateRandomImage(1, 1), 1.0) == false);  // ever
    BOOST_REQUIRE(mi.add(generateRandomImage(1, 1)) == false);               // forever
  }
}