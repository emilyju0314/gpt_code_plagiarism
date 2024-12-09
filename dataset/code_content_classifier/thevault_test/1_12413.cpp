TYPED_TEST(AnyConversionTest, Any_MoveAssignAny_OldIsDestroyed)
        {
            using LHS = typename TestFixture::LHS;
            using RHS = typename TestFixture::RHS;
            {
                LHS const s1(1);
                any a(s1);
                RHS const s2(2);
                any a2(s2);

                EXPECT_EQ(LHS::s_count, 2);
                EXPECT_EQ(RHS::s_count, 2);

                a = AZStd::move(a2);

                EXPECT_EQ(LHS::s_count, 1);
                EXPECT_EQ(RHS::s_count, 2);

                EXPECT_EQ(any_cast<const RHS&>(a).val(), 2);
                EXPECT_TRUE(a2.empty());
            }

            EXPECT_EQ(LHS::s_count, 0);
            EXPECT_EQ(RHS::s_count, 0);
        }