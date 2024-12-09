ast::Expr * createBitwiseAssignment (const ast::Expr * dst, const ast::Expr * src) {
		static ast::ptr<ast::FunctionDecl> assign = nullptr;
		if (!assign) {
			auto td = new ast::TypeDecl({}, "T", {}, nullptr, ast::TypeDecl::Dtype, true);
			assign = new ast::FunctionDecl({}, "?=?", {}, 
			{ new ast::ObjectDecl({}, "_dst", new ast::ReferenceType(new ast::TypeInstType("T", td))),
			  new ast::ObjectDecl({}, "_src", new ast::TypeInstType("T", td))},
			{ new ast::ObjectDecl({}, "_ret", new ast::TypeInstType("T", td))}, nullptr, {}, ast::Linkage::Intrinsic);
		}
		if (dst->result.as<ast::ReferenceType>()) {
			for (int depth = dst->result->referenceDepth(); depth > 0; depth--) {
				dst = new ast::AddressExpr(dst);
			}
		}
		else {
			dst = new ast::CastExpr(dst, new ast::ReferenceType(dst->result, {}));
		}
		if (src->result.as<ast::ReferenceType>()) {
			for (int depth = src->result->referenceDepth(); depth > 0; depth--) {
				src = new ast::AddressExpr(src);
			}
		}
		return new ast::ApplicationExpr(dst->location, ast::VariableExpr::functionPointer(dst->location, assign), {dst, src});
	}