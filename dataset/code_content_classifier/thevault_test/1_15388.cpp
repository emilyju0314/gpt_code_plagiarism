Handle<Object>  createObject(std::string line, std::string dataType) {
   
     
    std::vector<std::string> tokens = parseLine(line);
    Handle<Object> objectToAdd = nullptr;
    if (dataType == "Customer") {
        objectToAdd = makeObject<tpch::Customer>(atoi(tokens.at(0).c_str()),
                                                        tokens.at(1),
                                                        tokens.at(2),
                                                        atoi(tokens.at(3).c_str()),
                                                        tokens.at(4),
                                                        atof(tokens.at(5).c_str()),
                                                        tokens.at(6),
                                                        tokens.at(7));
    } else if (dataType == "LineItem") {
       objectToAdd = makeObject<LineItem>(atoi(tokens.at(0).c_str()),
                                                        atoi(tokens.at(1).c_str()),
                                                        atoi(tokens.at(2).c_str()),
                                                        atoi(tokens.at(3).c_str()),
                                                        atof(tokens.at(4).c_str()),
                                                        atof(tokens.at(5).c_str()),
                                                        atof(tokens.at(6).c_str()),
                                                        atof(tokens.at(7).c_str()),
                                                        tokens.at(8),
                                                        tokens.at(9),
                                                        tokens.at(10),
                                                        tokens.at(11),
                                                        tokens.at(12),
                                                        tokens.at(13),
                                                        tokens.at(14),
                                                        tokens.at(15));

    } else if (dataType == "Nation") {
       objectToAdd = makeObject<Nation>(atoi(tokens.at(0).c_str()),
                                                        tokens.at(1),
                                                        atoi(tokens.at(2).c_str()),
                                                        tokens.at(3));

    } else if (dataType == "Order") {
       objectToAdd = makeObject<Order>(atoi(tokens.at(0).c_str()),
                                                        atoi(tokens.at(1).c_str()),
                                                        tokens.at(2),
                                                        atof(tokens.at(3).c_str()),
                                                        tokens.at(4),
                                                        tokens.at(5),
                                                        tokens.at(6),
                                                        atoi(tokens.at(7).c_str()),
                                                        tokens.at(8));
    } else if (dataType == "Part") {
       objectToAdd = makeObject<Part>(atoi(tokens.at(0).c_str()),
                                                        tokens.at(1),
                                                        tokens.at(2),
                                                        tokens.at(3),
                                                        tokens.at(4),
                                                        atoi(tokens.at(5).c_str()),
                                                        tokens.at(6),
                                                        atof(tokens.at(7).c_str()),
                                                        tokens.at(8));
    } else if (dataType == "PartSupp") {
       objectToAdd = makeObject<PartSupp>(atoi(tokens.at(0).c_str()),
                                                        atoi(tokens.at(1).c_str()),
                                                        atoi(tokens.at(2).c_str()),
                                                        atof(tokens.at(3).c_str()),
                                                        tokens.at(4));

    } else if (dataType == "Region" ) {
       objectToAdd = makeObject<Region>(atoi(tokens.at(0).c_str()),
                                                        tokens.at(1),
                                                        tokens.at(2));
    } else if (dataType == "Supplier" ) {
       objectToAdd = makeObject<Supplier>(atoi(tokens.at(0).c_str()),
                                                        tokens.at(1),
                                                        tokens.at(2),
                                                        atoi(tokens.at(3).c_str()),
                                                        tokens.at(4),
                                                        atof(tokens.at(5).c_str()),
                                                        tokens.at(6));
    }
    return objectToAdd;
}