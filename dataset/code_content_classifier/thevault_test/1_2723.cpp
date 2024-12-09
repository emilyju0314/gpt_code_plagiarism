StringData* concat_si(StringData* v1, int64_t v2) {
  char intbuf[21];
  auto const s2 = conv_10(v2, intbuf + sizeof(intbuf));
  if (v1->cowCheck()) {
    auto const s1 = v1->slice();
    FOLLY_SDT(hhvm, hhvm_cow_concat, s1.size(), s2.size());
    auto const ret = StringData::Make(s1, s2);
    // Because v1 was shared, we know this won't release it.
    v1->decRefCount();
    return ret;
  }

  UNUSED auto const lsize = v1->size();
  FOLLY_SDT(hhvm, hhvm_mut_concat, lsize, s2.size());
  auto const ret = v1->append(s2);
  if (UNLIKELY(ret != v1)) {
    // had to realloc even though count==1
    assertx(v1->hasExactlyOneRef());
    v1->release();
  }
  return ret;
}