void ModelConfig::Load(int argsNum, const char** args)
{
    Create(argsNum, args);

    LoadBool("bigatt", &useBigAtt, false);
    LoadBool("encprenorm", &encPreLN, true);
    LoadBool("decprenorm", &decPreLN, true);
    LoadBool("encl1norm", &encoderL1Norm, false);
    LoadBool("decl1norm", &decoderL1Norm, false);
    LoadBool("decoderonly", &decoderOnly, false);
    LoadBool("enchistory", &useEncHistory, false);
    LoadBool("dechistory", &useDecHistory, false);
    LoadBool("encfinalnorm", &encFinalNorm, true);
    LoadBool("decfinalnorm", &decFinalNorm, true);
    LoadBool("shareencdec", &shareEncDecEmb, false);
    LoadBool("sharedec", &shareDecInputOutputEmb, false);

    LoadInt("pad", &pad, -1);
    LoadInt("sos", &sos, -1);
    LoadInt("eos", &eos, -1);
    LoadInt("unk", &unk, -1);
    LoadInt("encemb", &encEmbDim, 512);
    LoadInt("decemb", &decEmbDim, 512);
    LoadInt("maxsrc", &maxSrcLen, 200);
    LoadInt("maxtgt", &maxTgtLen, 200);
    LoadInt("enclayer", &encLayerNum, 6);
    LoadInt("declayer", &decLayerNum, 6);
    LoadInt("maxrp", &maxRelativeLength, -1);
    LoadInt("encffn", &encFFNHiddenDim, 1024);
    LoadInt("decffn", &decFFNHiddenDim, 1024);
    LoadInt("srcvocabsize", &srcVocabSize, -1);
    LoadInt("tgtvocabsize", &tgtVocabSize, -1);
    LoadInt("encheads", &encSelfAttHeadNum, 4);
    LoadInt("decheads", &decSelfAttHeadNum, 4);
    LoadInt("encdecheads", &encDecAttHeadNum, 4);

    LoadFloat("dropout", &dropout, 0.3F);
    LoadFloat("ffndropout", &ffnDropout, 0.1F);
    LoadFloat("attdropout", &attDropout, 0.1F);
}