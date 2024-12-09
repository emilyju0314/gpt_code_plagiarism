TYPED_TEST(AnySizedTest, Any_MoveAssignAny_IsValid)
        {
            {
                any a;
                any a2((TypeParam(1)));

                EXPECT_EQ(TypeParam::s_count, 1);

                a = std::move(a2);

                EXPECT_EQ(TypeParam::s_count, 1);

                EXPECT_EQ(any_cast<const TypeParam&>(a).val(), 1);
                EXPECT_TRUE(a2.empty());
            }

            EXPECT_EQ(TypeParam::s_count, 0);
        }