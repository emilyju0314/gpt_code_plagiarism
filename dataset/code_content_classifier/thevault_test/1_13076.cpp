void TranslationConfig::Load(int argsNum, const char** args)
{
    Create(argsNum, args);
    LoadString("input", inputFN, "");
    LoadString("output", outputFN, "");
    LoadInt("beam", &beamSize, 1);
    LoadInt("maxlen", &maxLen, 200);
    LoadFloat("lenalpha", &lenAlpha, 0.6F);
    LoadFloat("maxlenalpha", &maxLenAlpha, 1.25F);
}