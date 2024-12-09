TYPED_TEST(AnySizedTest, Any_CopyAssignEmptyAny_OldIsDestroyed)
        {
            {
                any lhs(TypeParam(1));
                any const rhs;

                EXPECT_EQ(TypeParam::s_count, 1);
                EXPECT_EQ(TypeParam::s_copied, 0);

                lhs = rhs;

                EXPECT_EQ(TypeParam::s_copied, 0);
                EXPECT_EQ(TypeParam::s_count, 0);

                EXPECT_TRUE(lhs.empty());
                EXPECT_TRUE(rhs.empty());
            }

            EXPECT_EQ(TypeParam::s_count, 0);
        }