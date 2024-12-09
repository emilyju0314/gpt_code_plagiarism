static std::vector<std::string> load_label(const std::string &labelfile)
{
    std::vector<std::string> classes;
    std::ifstream file(labelfile);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            // remove \r in the end of line
            if (!line.empty() && line[line.size() - 1] == '\r')
            {
                line.erase(line.size() - 1);
            }
            classes.push_back(line);
        }

        file.close();
    }
    else
    {
        std::cerr << "Cannot open labelfile " << labelfile << std::endl;
        std::cerr << "Labels will not be available." << std::endl;
    }

    return classes;
}