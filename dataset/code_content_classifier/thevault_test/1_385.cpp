int Skein_512_Init(Skein_512_Ctxt_t *ctx, size_t hashBitLen)
{
    union
    {
        u08b_t  b[SKEIN_512_STATE_BYTES];
        u64b_t  w[SKEIN_512_STATE_WORDS];
    } cfg;                              /* config block */

    Skein_Assert(hashBitLen > 0,SKEIN_BAD_HASHLEN);
    ctx->h.hashBitLen = hashBitLen;         /* output hash bit count */

    uint8_t *src = 0;
    uint8_t *dst = (uint8_t *)ctx->X;

    switch (hashBitLen)
    {             /* use pre-computed values, where available */
#ifndef SKEIN_NO_PRECOMP
    case  512:
        //memcpy(ctx->X,SKEIN_512_IV_512,sizeof(ctx->X));
        src = (uint8_t *)SKEIN_512_IV_512;
        std::copy(src, src + sizeof(ctx->X), dst);
        break;
    case  384:
        //memcpy(ctx->X,SKEIN_512_IV_384,sizeof(ctx->X));
        src = (uint8_t *)SKEIN_512_IV_384;
        std::copy(src, src + sizeof(ctx->X), dst);
        break;
    case  256:
        //memcpy(ctx->X,SKEIN_512_IV_256,sizeof(ctx->X));
        src = (uint8_t *)SKEIN_512_IV_256;
        std::copy(src, src + sizeof(ctx->X), dst);
        break;
    case  224:
        //memcpy(ctx->X,SKEIN_512_IV_224,sizeof(ctx->X));
        src = (uint8_t *)SKEIN_512_IV_224;
        std::copy(src, src + sizeof(ctx->X), dst);
        break;
#endif
    default:
        /* here if there is no precomputed IV value available */
        /* build/process the config block, type == CONFIG (could be precomputed) */
        Skein_Start_New_Type(ctx,CFG_FINAL);        /* set tweaks: T0=0; T1=CFG | FINAL */

        cfg.w[0] = Skein_Swap64(SKEIN_SCHEMA_VER);  /* set the schema, version */
        cfg.w[1] = Skein_Swap64(hashBitLen);        /* hash result length in bits */
        cfg.w[2] = Skein_Swap64(SKEIN_CFG_TREE_INFO_SEQUENTIAL);
        memset(&cfg.w[3],0,sizeof(cfg) - 3*sizeof(cfg.w[0])); /* zero pad config block */

        /* compute the initial chaining values from config block */
        memset(ctx->X,0,sizeof(ctx->X));            /* zero the chaining variables */
        Skein_512_Process_Block(ctx,cfg.b,1,SKEIN_CFG_STR_LEN);
        break;
    }

    /* The chaining vars ctx->X are now initialized for the given hashBitLen. */
    /* Set up to process the data message portion of the hash (default) */
    Skein_Start_New_Type(ctx,MSG);              /* T0=0, T1= MSG type */

    return SKEIN_SUCCESS;
}