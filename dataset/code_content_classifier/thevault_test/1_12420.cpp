TYPED_TEST(AnySizedTest, Any_PointerAnyCastValidAny_ReturnsValue)
                {
                    {
                        any a((TypeParam(42)));
                        any const& ca = a;
                        EXPECT_EQ(TypeParam::s_count, 1);
                        EXPECT_EQ(TypeParam::s_copied, 0);
                        EXPECT_EQ(TypeParam::s_moved, 1);

                        // Try a cast to a bad type.
                        // NOTE: Type cannot be an int.
                        EXPECT_EQ(any_cast<int>(&a), nullptr);
                        EXPECT_EQ(any_cast<int const>(&a), nullptr);

                        // Try a cast to the right type, but as a pointer.
                        EXPECT_EQ(any_cast<TypeParam*>(&a), nullptr);
                        EXPECT_EQ(any_cast<TypeParam const*>(&a), nullptr);

                        // Check getting a unqualified type from a non-const any.
                        TypeParam* v = any_cast<TypeParam>(&a);
                        EXPECT_NE(v, nullptr);
                        EXPECT_EQ(v->val(), 42);

                        // change the stored value and later check for the new value.
                        v->val() = 999;

                        // Check getting a const qualified type from a non-const any.
                        TypeParam const* cv = any_cast<TypeParam const>(&a);
                        EXPECT_NE(cv, nullptr);
                        EXPECT_EQ(cv, v);
                        EXPECT_EQ(cv->val(), 999);

                        // Check getting a unqualified type from a const any.
                        cv = any_cast<TypeParam>(&ca);
                        EXPECT_NE(cv, nullptr);
                        EXPECT_EQ(cv, v);
                        EXPECT_EQ(cv->val(), 999);

                        // Check getting a const-qualified type from a const any.
                        cv = any_cast<TypeParam const>(&ca);
                        EXPECT_NE(cv, nullptr);
                        EXPECT_EQ(cv, v);
                        EXPECT_EQ(cv->val(), 999);

                        // Check that no more objects were created, copied or moved.
                        EXPECT_EQ(TypeParam::s_count, 1);
                        EXPECT_EQ(TypeParam::s_copied, 0);
                        EXPECT_EQ(TypeParam::s_moved, 1);
                    }

                    EXPECT_EQ(TypeParam::s_count, 0);
                }