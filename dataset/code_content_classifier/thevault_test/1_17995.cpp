TYPED_TEST(BinaryReaderTestFixture, AlignmentZeroPadPastEnd) {
    this->br->seek(1);
    ASSERT_THROW(this->br->template alignZeroPad<sizeof(testData) + 1>(),
                 std::runtime_error); // Will throw before checking padding.
}