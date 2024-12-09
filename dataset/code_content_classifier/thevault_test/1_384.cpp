int Skein_256_Final(Skein_256_Ctxt_t *ctx, u08b_t *hashVal)
{
    size_t n,byteCnt;
    u64b_t X[SKEIN_256_STATE_WORDS];
    Skein_Assert(ctx->h.bCnt <= SKEIN_256_BLOCK_BYTES,SKEIN_FAIL);    /* catch uninitialized context */

    ctx->h.T[1] |= SKEIN_T1_FLAG_FINAL;                 /* tag as the final block */
    if(ctx->h.bCnt < SKEIN_256_BLOCK_BYTES)            /* zero pad b[] if necessary */
        memset(&ctx->b[ctx->h.bCnt],0,SKEIN_256_BLOCK_BYTES - ctx->h.bCnt);

    Skein_256_Process_Block(ctx,ctx->b,1,ctx->h.bCnt);  /* process the final block */

    /* now output the result */
    byteCnt = (ctx->h.hashBitLen + 7) >> 3;             /* total number of output bytes */

    /* run Threefish in "counter mode" to generate output */
    memset(ctx->b,0,sizeof(ctx->b));  /* zero out b[], so it can hold the counter */
    //memcpy(X,ctx->X,sizeof(X));       /* keep a local copy of counter mode "key" */
    uint8_t *dst = (uint8_t *)X;
    uint8_t *src = (uint8_t *)ctx->X;
    std::copy(src, src + sizeof(X), dst);

    for(size_t i=0; i*SKEIN_256_BLOCK_BYTES < byteCnt; ++i)
    {
        ((u64b_t *)ctx->b)[0] = Skein_Swap64((u64b_t) i); /* build the counter block */
        Skein_Start_New_Type(ctx,OUT_FINAL);
        Skein_256_Process_Block(ctx,ctx->b,1,sizeof(u64b_t)); /* run "counter mode" */
        n = byteCnt - i*SKEIN_256_BLOCK_BYTES;   /* number of output bytes left to go */
        if(n >= SKEIN_256_BLOCK_BYTES)
            n  = SKEIN_256_BLOCK_BYTES;
        Skein_Put64_LSB_First(hashVal+i*SKEIN_256_BLOCK_BYTES,ctx->X,n);   /* "output" the ctr mode bytes */
        Skein_Show_Final(256,&ctx->h,n,hashVal+i*SKEIN_256_BLOCK_BYTES);
        //memcpy(ctx->X,X,sizeof(X));   /* restore the counter mode key for next time */
        dst = (uint8_t *)ctx->X;
        src = (uint8_t *)X;
        std::copy(src, src + sizeof(X), dst);
    }

    return SKEIN_SUCCESS;
}