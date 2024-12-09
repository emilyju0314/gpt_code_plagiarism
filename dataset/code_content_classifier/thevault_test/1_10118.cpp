TEST(PacketBuffer, IsObsoleteTimestamp) {
  TestIsObsoleteTimestamp(0);
  TestIsObsoleteTimestamp(1);
  TestIsObsoleteTimestamp(0xFFFFFFFF);  // -1 in uint32_t.
  TestIsObsoleteTimestamp(0x80000000);  // 2^31.
  TestIsObsoleteTimestamp(0x80000001);  // 2^31 + 1.
  TestIsObsoleteTimestamp(0x7FFFFFFF);  // 2^31 - 1.
}