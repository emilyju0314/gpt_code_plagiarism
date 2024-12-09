void File_Mpeg4v::user_data_start()
{
    Element_Name("user_data_start");

    //Sony SNC files (security video)
    if (Element_Size>=120 && Element_Size<=140)
    {
        int64u SNC_Identifier;
        Peek_B8(SNC_Identifier);
        if (SNC_Identifier==0x43616D54696D3A20ULL)
        {
            user_data_start_SNC();
            return;
        }
    }

    //Rejecting junk at the begin
    size_t Library_Start_Offset=0;
    while (Library_Start_Offset+4<=Element_Size)
    {
        bool OK=true;
        for (size_t Pos=0; Pos<4; Pos++)
        {
            if (!((Buffer[Buffer_Offset+Library_Start_Offset+Pos]==0x20 && Pos)
               || Buffer[Buffer_Offset+Library_Start_Offset+Pos]==0x22
               || Buffer[Buffer_Offset+Library_Start_Offset+Pos]==0x27
               || Buffer[Buffer_Offset+Library_Start_Offset+Pos]==0x28
               || (Buffer[Buffer_Offset+Library_Start_Offset+Pos]==0x29 && Pos)
               || (Buffer[Buffer_Offset+Library_Start_Offset+Pos]>=0x30 && Buffer[Buffer_Offset+Library_Start_Offset+Pos]<=0x3F)
               || (Buffer[Buffer_Offset+Library_Start_Offset+Pos]>=0x41 && Buffer[Buffer_Offset+Library_Start_Offset+Pos]<=0x7D)))
            {
                OK=false;
                break;
            }
        }
        if (OK)
            break;
        Library_Start_Offset++;
    }
    if (Library_Start_Offset+4>Element_Size)
    {
        Skip_XX(Element_Size,                                   "junk");
        return; //No good info
    }

    //Accepting good data after junk
    size_t Library_End_Offset=Library_Start_Offset+4;
    while (Library_End_Offset<Element_Size
        && (Buffer[Buffer_Offset+Library_End_Offset]==0x0D
         || Buffer[Buffer_Offset+Library_End_Offset]==0x0A
         || (Buffer[Buffer_Offset+Library_End_Offset]>=0x20 && Buffer[Buffer_Offset+Library_End_Offset]<=0x3F)
         || (Buffer[Buffer_Offset+Library_End_Offset]>=0x41 && Buffer[Buffer_Offset+Library_End_Offset]<=0x7D)))
        Library_End_Offset++;

    //Parsing
    string Temp;
    if (Library_Start_Offset>0)
        Skip_XX(Library_Start_Offset,                           "junk");
    if (Library_End_Offset-Library_Start_Offset)
        Get_String(Library_End_Offset-Library_Start_Offset, Temp,"data");
    if (Element_Offset<Element_Size)
        Skip_XX(Element_Size-Element_Offset,                    "junk");

    //Cleanup
    while(Temp.size()>3 && Temp[1]==__T('e') && Temp[2]==__T('n') && Temp[3]==__T('c'))
        Temp.erase(0, 1);
    while(Temp.size()>5 && Temp[3]==__T('M') && Temp[4]==__T('P') && Temp[5]==__T('E'))
        Temp.erase(0, 1);

    FILLING_BEGIN();
        if (Temp.size()>=4)
        {
            if (Temp.find("build")==0)
                Library+=Ztring().From_UTF8(" "+Temp);
            else
                Library.From_UTF8(Temp);

            //Library
            if (Library.find(__T("DivX50"))==0)
            {
                Library_Name=__T("DivX");
                Ztring Version=Library.SubString(__T("Build"), __T(""));
                if (Version.empty())
                    Version=Library.SubString(__T("b"), __T("p"));
                if (Version.empty())
                    Version=Library.SubString(__T("b"), __T(""));
                Library_Version=MediaInfoLib::Config.Library_Get(InfoLibrary_Format_DivX, Version, InfoLibrary_Version);
                if (Library_Version.empty())
                    Library_Version=Version;
                Library_Date=MediaInfoLib::Config.Library_Get(InfoLibrary_Format_DivX, Version, InfoLibrary_Date);
            }
            if (Library.find(__T("XviD"))==0)
            {
                Library_Name=__T("XviD");
                if (Library.find(__T("build="))==std::string::npos)
                {
                    Ztring Version=Library.SubString(__T("XviD"), __T(""));
                    Version.FindAndReplace(__T("C"), __T(""));
                    Version.TrimLeft(__T('0'));
                    Library_Version=MediaInfoLib::Config.Library_Get(InfoLibrary_Format_XviD, Version, InfoLibrary_Version);
                    if (Library_Version.empty())
                        Library_Version=Version;
                    Library_Date=MediaInfoLib::Config.Library_Get(InfoLibrary_Format_XviD, Version, InfoLibrary_Date);
                }
                else
                {
                    Library_Version=Library.SubString(__T("XviD"), __T(""));
                    Ztring Date=Library.SubString(__T(" build="), __T(""));
                    if (Date.size()==10)
                    {
                        Date[4]=__T('-');
                        Date[7]=__T('-');
                        Library_Date=__T("UTC ")+Date;
                    }
                }
            }
        }
    FILLING_END();
}