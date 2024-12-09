Status CheckHybridTimeSizeAndValueType(
    const rocksdb::Slice& key,
    int* ht_byte_size_dest) {
  RETURN_NOT_OK(
      DocHybridTime::CheckAndGetEncodedSize(key, ht_byte_size_dest));
  const size_t hybrid_time_value_type_offset = key.size() - *ht_byte_size_dest - 1;
  const ValueType value_type = DecodeValueType(key[hybrid_time_value_type_offset]);
  if (value_type != ValueType::kHybridTime) {
    return STATUS_FORMAT(
        Corruption,
        "Expected to find value type kHybridTime preceding the HybridTime component of the "
            "encoded key, found $0. DocHybridTime bytes: $1",
        value_type,
        ToShortDebugStr(rocksdb::Slice(key.data() + hybrid_time_value_type_offset,
                                       key.size() - hybrid_time_value_type_offset)));
  }

  return Status::OK();
}