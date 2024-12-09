void extractReactionMacro(std::vector<AstNode*> nodeArray, ostringstream& oss_preprocessor, string out_fn_base) {
    string cinclude_str = "";
    string cdefine_str = "";
	for (auto node : nodeArray) {
        if(typeContains(node, "IncludeNode")) {
            IncludeNode* includenode = dynamic_cast<IncludeNode*>(node);
            if(includenode->macrotype_==IncludeNode::C) {
                if(includenode->toString().find("include")!=string::npos) {
                    cinclude_str += includenode->toString();
                    cinclude_str += "\n";
                } else if (includenode->toString().find("define")!=string::npos) {
                    cdefine_str += includenode->toString();
                    cdefine_str += "\n";
                }
            }
        }
    }

    // Keep preprocessor other than include
    oss_preprocessor << cdefine_str;
    // Include preprocessor goes to seperate tmp file
    std::ofstream os;
    os.open(out_fn_base+"_mantis.include");
    os << cinclude_str << endl;
    os.close();
}