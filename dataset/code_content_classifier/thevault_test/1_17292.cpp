TEST(remove_if, ExampleOne) {
    std::string s = "*h_e_*l_l*_o";
    const auto isNotLowercaseLetter = [](unsigned char c)->bool{ return !(c >= 'a' && c <= 'z'); };
    std::remove_if(s.begin(), s.end(), isNotLowercaseLetter);
    EXPECT_EQ(s, "hello*l_l*_o");

    // Using erase-remove idiom:
    std::string s2 = "*h_e_*l_l*_o";
    s2.erase(std::remove_if(s2.begin(), s2.end(), isNotLowercaseLetter), s2.end());
    EXPECT_EQ(s2, "hello");
}