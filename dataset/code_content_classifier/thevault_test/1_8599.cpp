BOOST_AUTO_TEST_CASE(UnsupportedEcEncryption)
{
  EcKeyTestData dataSet;

  PublicKey pKey;
  pKey.loadPkcs8Base64(reinterpret_cast<const uint8_t*>(dataSet.publicKeyPkcs8.c_str()),
                       dataSet.publicKeyPkcs8.size());
  BOOST_CHECK_EQUAL(pKey.getKeyType(), KeyType::EC);

  OBufferStream os;
  bufferSource("Y2lhbyFob2xhIWhlbGxvIQ==") >> base64Decode() >> streamSink(os);

  BOOST_CHECK_THROW(pKey.encrypt(os.buf()->data(), os.buf()->size()), PublicKey::Error);
}