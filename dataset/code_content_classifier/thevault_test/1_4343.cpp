void findKindExpression(Expression *& untyped, const SymTab::Indexer & indexer, const std::string & kindStr, std::function<bool(const Alternative &)> pred, ResolvMode mode = ResolvMode{}) {
			if ( ! untyped ) return;
			Alternative choice;
			findUnfinishedKindExpression( untyped, choice, indexer, kindStr, pred, mode );
			finishExpr( choice.expr, choice.env, untyped->env );
			delete untyped;
			untyped = choice.expr;
			choice.expr = nullptr;
		}