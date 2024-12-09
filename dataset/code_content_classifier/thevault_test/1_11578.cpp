TYPED_TEST(HashtableIntTest, Typedefs) {
  // Make sure all the standard STL-y typedefs are defined.  The exact
  // key/value types don't matter here, so we only bother testing on
  // the int tables.  This is just a compile-time "test"; nothing here
  // can fail at runtime.
  this->ht_.set_deleted_key(-2);  // just so deleted_key succeeds
  typename TypeParam::key_type kt;               (void)kt;
  typename TypeParam::value_type vt;             (void)vt;  // value_type may not be copyable.  Easiest not to try.
  typename TypeParam::hasher h;
  typename TypeParam::key_equal ke;
  typename TypeParam::allocator_type at;

  typename TypeParam::size_type st;              (void)st;
  typename TypeParam::difference_type dt;        (void)dt;
  typename TypeParam::pointer p;                 (void)p;
  typename TypeParam::const_pointer cp;          (void)cp;

  typename TypeParam::iterator i;
  typename TypeParam::const_iterator ci;
  typename TypeParam::local_iterator li;
  typename TypeParam::const_local_iterator cli;

  // Now make sure the variables are used, so the compiler doesn't
  // complain.  Where possible, I "use" the variable by calling the
  // method that's supposed to return the unique instance of the
  // relevant type (eg. get_allocator()).  Otherwise, I try to call a
  // different, arbitrary function that returns the type.  Sometimes
  // the type isn't used at all, and there's no good way to use the
  // variable.
  kt = this->ht_.deleted_key();
  h = this->ht_.hash_funct();
  ke = this->ht_.key_eq();
  at = this->ht_.get_allocator();
  st = this->ht_.size();
  i = this->ht_.begin();
  ci = this->ht_.begin();
  li = this->ht_.begin(0);
  cli = this->ht_.begin(0);
}