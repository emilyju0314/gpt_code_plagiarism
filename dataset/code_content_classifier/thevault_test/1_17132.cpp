TEST(HistogramTest, GetPeakBucketSize) {
  Histogram* histogram = static_cast<Histogram*>(
      Histogram::FactoryGet("Histogram",
                            /*minimum=*/1,
                            /*maximum=*/64,
                            /*bucket_count=*/8,
                            /*flags=*/HistogramBase::kNoFlags));

  // Add 1 sample to 0th bucket; 2 to 6th; 3 to 313th.
  for (int i = 0; i < 1; i++) {
    histogram->Add(0);
  }
  for (int i = 0; i < 2; i++) {
    histogram->Add(6);
  }
  for (int i = 0; i < 3; i++) {
    histogram->Add(313);
  }

  // The largest bucket size should be 3.
  EXPECT_EQ(3, histogram->GetPeakBucketSize(*histogram->SnapshotAllSamples()));
}