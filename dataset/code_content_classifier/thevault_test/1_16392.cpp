TEST_F(UniscribeTest, TooBig)
{
    // Make a large string with an e with a zillion combining accents.
    String input(L"e");
    for (int i = 0; i < 100000; i++)
        input.append(static_cast<UChar>(0x301)); // Combining acute accent.

    SCRIPT_CACHE* scriptCache;
    HFONT hfont = MakeFont(L"Times New Roman", &scriptCache);
    ASSERT_TRUE(hfont);

    // Test a long string without the normal length protection we have. This
    // will cause shaping to fail.
    {
        UniscribeHelper uniscribe(
            input.characters(), static_cast<int>(input.length()),
            false, hfont, scriptCache, &properties);
        uniscribe.initWithOptionalLengthProtection(false);

        // There should be one shaping entry, with nothing in it.
        ASSERT_EQ(1, uniscribe.m_shapes.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_glyphs.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_logs.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_visualAttributes.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_advance.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_offsets.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_justify.size());
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_abc.abcA);
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_abc.abcB);
        EXPECT_EQ(0, uniscribe.m_shapes[0].m_abc.abcC);

        // The sizes of the other stuff should match the shaping entry.
        EXPECT_EQ(1, uniscribe.m_runs.size());
        EXPECT_EQ(1, uniscribe.m_screenOrder.size());

        // Check that the various querying functions handle the empty case
        // properly.
        EXPECT_EQ(0, uniscribe.width());
        EXPECT_EQ(0, uniscribe.firstGlyphForCharacter(0));
        EXPECT_EQ(0, uniscribe.firstGlyphForCharacter(1000));
        EXPECT_EQ(0, uniscribe.xToCharacter(0));
        EXPECT_EQ(0, uniscribe.xToCharacter(1000));
    }

    // Now test the very large string and make sure it is handled properly by
    // the length protection.
    {
        UniscribeHelper uniscribe(
            input.characters(), static_cast<int>(input.length()),
            false, hfont, scriptCache, &properties);
        uniscribe.initWithOptionalLengthProtection(true);

        // There should be 0 runs and shapes.
        EXPECT_EQ(0, uniscribe.m_runs.size());
        EXPECT_EQ(0, uniscribe.m_shapes.size());
        EXPECT_EQ(0, uniscribe.m_screenOrder.size());

        EXPECT_EQ(0, uniscribe.width());
        EXPECT_EQ(0, uniscribe.firstGlyphForCharacter(0));
        EXPECT_EQ(0, uniscribe.firstGlyphForCharacter(1000));
        EXPECT_EQ(0, uniscribe.xToCharacter(0));
        EXPECT_EQ(0, uniscribe.xToCharacter(1000));
    }
}