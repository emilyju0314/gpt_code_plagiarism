inline void parse_vertlist(
        stringstream& ss, vector<obj_vertex>& elems, const obj_vertex& vert_size) {
      elems.clear();
      while (true) {
        auto tok = string();
        parse_val(ss, tok);
        if (tok.empty()) break;
        auto toks = split(tok, "/");
        if (toks.empty()) break;
        auto v = obj_vertex{-1, -1, -1, -1, -1};
        for (auto i = 0; i < min(5, (int)toks.size()); i++) {
          if (toks[i] == "") continue;
          ((int*)&v)[i] = (int)atoi(toks[i].c_str());
          ((int*)&v)[i] = (((int*)&v)[i] < 0) ?
                          ((int*)&vert_size)[i] + ((int*)&v)[i] :
                          ((int*)&v)[i] - 1;
        }
        elems.push_back(v);
      }
    }