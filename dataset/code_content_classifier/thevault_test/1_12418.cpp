TYPED_TEST(AnySizedTest, Any_ValidAny_NotIsEmpty)
        {
            TypeParam const s(1);
            any a(s);
            EXPECT_FALSE(a.empty());
        }