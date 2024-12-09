TYPED_TEST(HashtableAllTest, BracketOperatorCrashing) {
  this->ht_.set_deleted_key(this->UniqueKey(1));
  for (int iters = 0; iters < 10; iters++) {
    // We start at 33 because after shrinking, we'll be at 32 buckets.
    for (int i = 33; i < 133; i++) {
      this->ht_.bracket_assign(this->UniqueKey(i),
                               this->ht_.get_data(this->UniqueObject(i)));
    }
    this->ht_.clear_no_resize();
    // This will force a shrink on the next insert, which we want to test.
    this->ht_.bracket_assign(this->UniqueKey(2),
                             this->ht_.get_data(this->UniqueObject(2)));
    this->ht_.erase(this->UniqueKey(2));
  }
}