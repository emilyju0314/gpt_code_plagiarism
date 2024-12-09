TEST(EulerTests, Problem0001) {
 auto n = cpplinq::from(
			boost::iterators::counting_iterator<int>(0),
			boost::iterators::counting_iterator<int>(1000))
		.where([](auto x) { 
			return (x % 3 == 0) || (x % 5 == 0);
		})
		.sum();
 
 EXPECT_EQ(233168, n);
}