Output makeOutputFromStore(const Store& store) {
    vector<string> destinationTokens;  // tokenize store.destination by whitespace
    {
        istringstream iss(store.destination);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(destinationTokens));

        if (destinationTokens.size() != 2)
            throw "unrecognized source string " + store.destination;
    }

    AttList columnsToStore = makeAttributeList(store.columnsToStore);
    TupleSpec toStore(store.columnsToStore.tableName, columnsToStore);

    Output out(toStore, destinationTokens[0], destinationTokens[1]);

    return out;
}