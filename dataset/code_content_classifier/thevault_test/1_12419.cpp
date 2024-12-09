TEST_F(AnyTest, Any_PointerAnyCastEmptyAny_ReturnsNullptr)
                {
                    {
                        any a;
                        EXPECT_EQ(nullptr, any_cast<int>(&a));
                        EXPECT_EQ(nullptr, any_cast<int const>(&a));

                        any const& ca = a;
                        EXPECT_EQ(nullptr, any_cast<int>(&ca));
                        EXPECT_EQ(nullptr, any_cast<int const>(&ca));
                    }

                    // Create as non-empty, then make empty and run test.
                    {
                        any a(42);
                        a.clear();
                        EXPECT_EQ(nullptr, any_cast<int>(&a));
                        EXPECT_EQ(nullptr, any_cast<int const>(&a));

                        any const& ca = a;
                        EXPECT_EQ(nullptr, any_cast<int>(&ca));
                        EXPECT_EQ(nullptr, any_cast<int const>(&ca));
                    }
                }