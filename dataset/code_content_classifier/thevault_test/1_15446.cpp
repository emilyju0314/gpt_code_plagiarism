Cart::Cart(std::string filename){
    Filename = filename;
    //zero out cart rom so no garbage is left over
    initCartRom();

    Logger::Write("getting file contents\n");
    
    if (hasEnding(filename, ".p8")){
        std::string cartStr; 

        if (filename == "__FAKE08-BIOS.p8") {
            cartStr = fake08BiosP8;
        }
        else {
            cartStr = get_file_contents(filename.c_str());
        }
        Logger::Write("Got file contents... parsing cart\n");

        fullCartText = cartStr;

        std::istringstream s(cartStr);
        std::string line;
        std::string currSec = "";
        
        while (std::getline(s, line)) {
            line = utils::trimright(line, " \n\r");
            line = convert_emojis(line);

            if (line.length() > 2 && line[0] == '_' && line[1] == '_') {
                currSec = line;
            }
            else if (currSec == "__lua__"){
                LuaString += line + "\n";
            }
            else if (currSec == "__gfx__"){
                SpriteSheetString += line + "\n";
            }
            else if (currSec == "__gff__"){
                SpriteFlagsString += line + "\n";
            }
            else if (currSec == "__map__"){
                MapString += line + "\n";
            }
            else if (currSec == "__sfx__"){
                SfxString += line + "\n";
            }
            else if (currSec == "__music__"){
                MusicString += line + "\n";
            }
        }

        Logger::Write("Setting cart graphics rom data from strings\n");
        setSpriteSheet(SpriteSheetString);
        setSpriteFlags(SpriteFlagsString);
        setMapData(MapString);

        Logger::Write("Setting cart audio rom data from strings\n");
        setSfx(SfxString);
        setMusic(MusicString);
    }
    else if (hasEnding(filename, ".p8.png")) {
        bool success = loadCartFromPng(filename);

        if (!success){
            return;
        }

        LoadError = "";
        Logger::Write("got valid png cart\n");
    }
    else {
        return;
    }

    const char * patched = getPatchedLua(LuaString.c_str());

    LuaString = patched;
    
    
    #if _TEST
    //run tests to make sure cart is parsed correctly
    //verifyFullCartText(cartStr);

    //verifyCart(this);

    #endif
}