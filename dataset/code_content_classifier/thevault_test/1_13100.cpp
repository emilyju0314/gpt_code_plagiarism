void XConfig::CreateFromMe(XConfig & myConfig)
{
    Clear();

    for (int i = 0; i < myConfig.GetItemNum(); i++)
        Add(myConfig.GetItem(i), i);
}