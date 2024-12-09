uint32_t ProcessLanguageValue(int32_t LangVal)
{
    if (LangVal > -1)
        return LangVal;

    if (LangVal == -1)
        return 0;

    if (LangVal < 0)
        return (LangVal * -1) - 1;

    return LangVal;

}