void PEM_From_P12(PA_PluginParameters params) {
    
    sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
    PackagePtr pParams = (PackagePtr)params->fParameters;
    
    C_BLOB Param1;
    C_BLOB Param2;
    C_TEXT Param3;
    C_LONGINT Param4; // Options
    
    C_TEXT returnValue;
    
    int i;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param3.fromParamAtIndex(pParams, 3);
    Param4.fromParamAtIndex(pParams, 4);
    
    BIO *bio = BIO_new_mem_buf((void *)Param1.getBytesPtr(), Param1.getBytesLength());
    
    if(bio){
        
        PKCS12 *p12 = d2i_PKCS12_bio(bio, NULL);
        
        if(p12){
            
            EVP_PKEY *key = NULL;
            X509 *cert = NULL;
            X509 *xtmp = NULL;
            STACK_OF(X509) *ca = NULL;
            
            CUTF8String pass;
            Param3.copyUTF8String(&pass);
            
            if(PKCS12_parse(p12, (const char *)pass.c_str(), &key, &cert, &ca)){
                
                BIO *pem = BIO_new(BIO_s_mem());
                
                if(pem){
                    
                    if(Param4.getIntValue() & 2) { // Print out X509 details if $4 second bit is 1
                        X509_print(pem,cert);
                    }
                    PEM_write_bio_PrivateKey(pem, key, NULL, NULL, NULL, NULL, (void *)pass.c_str());
                    
                    if (ca && (Param4.getIntValue() & 1 )) { // Print out all details of Certificate chain if $4 first bit is 1
                        for (i = 0;i < sk_X509_num(ca);i++) {
                            xtmp = sk_X509_value(ca, i);
                            if(Param4.getIntValue() & 2) {
                                X509_print(pem,xtmp);
                            }
                            PEM_write_bio_X509(pem,sk_X509_value(ca, i));
                        }
                    }

                    
                    char *buf = NULL;
                    
                    int len = (int)BIO_get_mem_data(pem, &buf);
                    
                    if(len){
                        Param2.setBytes((const uint8_t *)buf, len);
                        Param2.toParamAtIndex(pParams, 2);
                        CUTF8String pemStr = CUTF8String((const uint8_t *)buf, len);
                        returnValue.setUTF8String(&pemStr);
                    }
                    
                    BIO_free(pem);
                    
                }
            }
        }
        
        BIO_free(bio);
        
    }
    
    Param2.toParamAtIndex(pParams, 2);
    returnValue.setReturn(pResult);
}