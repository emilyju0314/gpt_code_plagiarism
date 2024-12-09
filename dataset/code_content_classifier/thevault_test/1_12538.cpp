static int ProcessCertificate(ztlsContextImpl * ctx, ztlsHsState * hs, const uint8_t * data, size_t length, const char * sni)
{
	CertificateInfo cert;
	int res = ExtractCertificateInfo(&cert, length, data, sni);
	if (res <= 0) {
		return ZTLS_ERR_BAD_CERTIFICATE;
	}

	int index = hs->certList.count;
	if (index >= MaxCertificates) {
		return ZTLS_ERR_OVERFLOW;
	}

	CertificateEntry * ce = (CertificateEntry*)((uint8_t*)ctx + hs->certList.offset);
	ce += index;

	// compute how much memory to dalloc
	size_t sigHashSize = GetSignatureSize(cert.signType);
	size_t slice = ctx->sendBufferOffset - (cert.signature.length + cert.publicKey.length + sigHashSize);

	uint8_t *target = (uint8_t*)ctx + slice;

	uint8_t *tip = ctx->RecvBuffer() + ctx->recvOffset + ctx->recvSize;

	//### check limits
	// Don't overwrite the received data
	if (tip > target) {
		return ZTLS_ERR_OVERFLOW;
	}

	ce->signType = cert.signType;
	ce->keyType = cert.keyType;
	ce->restricted = cert.restricted;
	ce->chainLength = cert.chainLength;

	if (cert.issuer.length <= 20) {
		memset(ce->issuerHash, 0, 20);
		memcpy(ce->issuerHash, cert.issuer.data, cert.issuer.length);
	} else {
		SHA1_State h;
		sha1Init(&h);
		sha1Update(&h, cert.issuer.data, cert.issuer.length);
		sha1Finish(&h, ce->issuerHash);
	}
	if (cert.subject.length <= 20) {
		memset(ce->subjectHash, 0, 20);
		memcpy(ce->subjectHash, cert.subject.data, cert.subject.length);
	} else {
		SHA1_State h;
		sha1Init(&h);
		sha1Update(&h, cert.subject.data, cert.subject.length);
		sha1Finish(&h, ce->subjectHash);
	}

	ce->dataOffset = slice;
	ce->publicKeySize = cert.publicKey.length;
	ce->signatureSize = cert.signature.length;
	ce->hashSize = sigHashSize;

	memcpy(target, cert.publicKey.data, cert.publicKey.length);
	target += cert.publicKey.length;
	memcpy(target, cert.signature.data, cert.signature.length);
	target += cert.signature.length;
	int computedSize = ComputeSignatureHash(cert.signType, data + cert.payloadOffset, cert.payloadLength, (uint32_t*)target);
	computedSize *= 4;

	if (computedSize != sigHashSize) {
		return ZTLS_ERR_BAD_CERTIFICATE;
	}

	hs->certList.count++;
	ctx->sendBufferOffset = slice;

	return 1;
}