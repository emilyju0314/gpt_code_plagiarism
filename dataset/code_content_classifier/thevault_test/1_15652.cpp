TEST_F(TransportDescriptionFactoryTest, TestAnswerHybridDtlsToHybridDtls) {
  f1_.set_protocol(cricket::ICEPROTO_HYBRID);
  f1_.set_secure(cricket::SEC_ENABLED);
  f1_.set_identity(id1_.get());

  f2_.set_protocol(cricket::ICEPROTO_HYBRID);
  f2_.set_secure(cricket::SEC_ENABLED);
  f2_.set_identity(id2_.get());
  // f2_ produces the answer that is being checked in this test, so the
  // answer must contain fingerprint lines with id2_'s digest algorithm.
  std::string digest_alg2;
  ASSERT_TRUE(id2_->certificate().GetSignatureDigestAlgorithm(&digest_alg2));

  scoped_ptr<TransportDescription> offer(
      f1_.CreateOffer(TransportOptions(), NULL));
  ASSERT_TRUE(offer.get() != NULL);
  scoped_ptr<TransportDescription> desc(
      f2_.CreateAnswer(offer.get(), TransportOptions(), NULL));
  CheckDesc(desc.get(), cricket::NS_JINGLE_ICE_UDP, "", "", "", digest_alg2);
  f2_.set_secure(cricket::SEC_REQUIRED);
  desc.reset(f2_.CreateAnswer(offer.get(), TransportOptions(),
                              NULL));
  CheckDesc(desc.get(), cricket::NS_JINGLE_ICE_UDP, "", "", "", digest_alg2);
}