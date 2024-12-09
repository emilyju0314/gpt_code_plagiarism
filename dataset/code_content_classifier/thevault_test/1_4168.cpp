bool parse(btosgDictionary& dictionary, int argc, char* argv[])
{
    g_argv = argv; // global access
    int number;

    std::cout << "Running command line script:" << std::endl;
    for (IP = 1; IP < argc; ++IP)
    {
        const char* word = argv[IP];

        std::cout << "Forth: Execute word '" << word << "'" << std::endl;
        auto it = dictionary.find(word);
        if (it != dictionary.end())
        {
            it->second(); // execute its definition
        }
        else if (isInteger(word, number))
        {
            std::cout << "Is int ? " << word << std::endl;
            DS.push(number);
        }
        else
        {
            std::cerr << "Forth: Unknown word '" << word
                      << "'. Abort !" << std::endl;
            return false;
        }
    }

    return true;
}