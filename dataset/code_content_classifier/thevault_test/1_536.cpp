void print_protobook(std::vector<BookNode>& pbook) {
    for (int i = 0; i < pbook.size(); ++i) {
        std::cout << pbook[i].key << std::endl;
        for (int j = 0; j < pbook[i].edges.size(); ++j) {
            std::cout << "(" << pbook[i].edges[j].move.to_string() << ", " << pbook[i].edges[j].child_node << ") | ";
        }
        std::cout << std::endl;
    }
}