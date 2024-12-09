Graph* GraphExecutioner::importFromFlatBuffers(const char *filename) {
            auto data = readFlatBuffers(filename);
            auto restoredGraph = importFromFlatPointer(reinterpret_cast<Nd4jPointer>(data));
            delete[] data;
            return restoredGraph;
        }