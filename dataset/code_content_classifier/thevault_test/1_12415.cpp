TYPED_TEST(AnySizedTest, Any_MoveAssignEmptyAny_OldIsDestroyed)
        {
            {
                any a((TypeParam(1)));
                any a2;

                EXPECT_EQ(TypeParam::s_count, 1);

                a = std::move(a2);

                EXPECT_EQ(TypeParam::s_count, 0);

                EXPECT_TRUE(a.empty());
                EXPECT_TRUE(a2.empty());
            }

            EXPECT_EQ(TypeParam::s_count, 0);
        }