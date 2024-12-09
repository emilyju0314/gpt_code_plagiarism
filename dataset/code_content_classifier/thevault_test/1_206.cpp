static bool IsStoreOrigin(std::uint8_t* signatureBuffer, std::uint32_t cbSignatureBuffer)
    {
        unique_BIO bmem(BIO_new_mem_buf(signatureBuffer, cbSignatureBuffer));
        unique_PKCS7 p7(d2i_PKCS7_bio(bmem.get(), nullptr));

        STACK_OF(X509) *certStack = p7.get()->d.sign->cert;
        for (int i = 0; i < sk_X509_num(certStack); i++)
        {
            X509* cert = sk_X509_value(certStack, i);
            STACK_OF(X509_EXTENSION) *exts = cert->cert_info.extensions;
            for (int i = 0; i < sk_X509_EXTENSION_num(exts); i++) 
            {
                X509_EXTENSION *ext = sk_X509_EXTENSION_value(exts, i);
                if (ext)
                {
                    if (X509_EXTENSION_get_object(ext))
                    {
                        unique_BIO extbio(BIO_new(BIO_s_mem()));
                        if (!X509V3_EXT_print(extbio.get(), ext, 0, 0)) 
                        {
                            ASN1_STRING_print(extbio.get(), X509_EXTENSION_get_data(ext));
                        }

                        BUF_MEM *bptr = nullptr;
                        BIO_get_mem_ptr(extbio.get(), &bptr);
                        
                        if (bptr && bptr->data && 
                            std::string((char*)bptr->data, bptr->length).find(OID::WindowsStore()) != std::string::npos)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }