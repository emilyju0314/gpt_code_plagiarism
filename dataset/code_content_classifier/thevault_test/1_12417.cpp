TYPED_TEST(AnySizedTest, Any_SwapValidAndEmptyAny_IsValid)
        {
            {
                any a1((TypeParam(1)));
                any a2;
                EXPECT_EQ(TypeParam::s_count, 1);

                a2.swap(a1);

                EXPECT_EQ(TypeParam::s_count, 1);

                EXPECT_EQ(any_cast<const TypeParam&>(a2).val(), 1);
                EXPECT_TRUE(a1.empty());
            }

            EXPECT_EQ(TypeParam::s_count, 0);
        }