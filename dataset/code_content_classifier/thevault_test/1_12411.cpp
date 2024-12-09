TYPED_TEST(AnyConversionTest, Any_CopyAssignAny_OldIsDestroyed)
        {
            using LHS = typename TestFixture::LHS;
            using RHS = typename TestFixture::RHS;
            {
                any lhs(LHS(1));
                any const rhs(RHS(2));

                EXPECT_EQ(LHS::s_count, 1);
                EXPECT_EQ(RHS::s_count, 1);
                EXPECT_EQ(RHS::s_copied, 0);

                lhs = rhs;

                EXPECT_EQ(RHS::s_copied, 1);
                EXPECT_EQ(LHS::s_count, 0);
                EXPECT_EQ(RHS::s_count, 2);

                EXPECT_EQ(any_cast<const RHS&>(lhs).val(), 2);
                EXPECT_EQ(any_cast<const RHS&>(rhs).val(), 2);
            }

            EXPECT_EQ(LHS::s_count, 0);
            EXPECT_EQ(RHS::s_count, 0);
        }