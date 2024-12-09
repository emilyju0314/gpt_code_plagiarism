BOOST_AUTO_TEST_CASE(parseEvaluation)
{
    const std::string input = R"(
    x = evaluate(4, a+bc +   d);
    )";
    INIT_BOILERPLATE
    auto st = parser.parseStatement();
    BOOST_REQUIRE(st->toString() == "x = evaluate(4, a + bc + d)");
}