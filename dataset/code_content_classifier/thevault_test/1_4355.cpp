bool Resolver_new::on_error(ast::ptr<ast::Decl> & decl) {
		if (auto functionDecl = decl.as<ast::FunctionDecl>()) {
			// xxx - can intrinsic gen ever fail?
			if (functionDecl->linkage == ast::Linkage::AutoGen) { 
				auto mutDecl = mutate(functionDecl);
				mutDecl->isDeleted = true;
				mutDecl->stmts = nullptr;
				decl = mutDecl;
				return false;
			}
		}
		return true;
	}