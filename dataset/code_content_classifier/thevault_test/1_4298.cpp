CompoundStmt * TryMutatorCore::create_single_matcher(
			DeclarationWithType * except_obj, CatchStmt * modded_handler ) {
		// {
		//     `modded_handler.decl`
		//     if ( `decl.name = (virtual `decl.type`)`except`
		//             [&& `modded_handler.cond`] ) {
		//         `modded_handler.body`
		//     }
		// }

		CompoundStmt * block = new CompoundStmt();

		// Local Declaration
		ObjectDecl * local_except =
			dynamic_cast<ObjectDecl *>( modded_handler->get_decl() );
		assert( local_except );
		block->push_back( new DeclStmt( local_except ) );

		// Check for type match.
		VirtualCastExpr * vcex = new VirtualCastExpr(
			nameOf( except_obj ),
			local_except->get_type()->clone()
			);
		vcex->location = modded_handler->location;
		Expression * cond = UntypedExpr::createAssign(
			nameOf( local_except ), vcex );

		// Add the check on the conditional if it is provided.
		if ( modded_handler->get_cond() ) {
			cond = new LogicalExpr( cond, modded_handler->get_cond() );
		}
		// Construct the match condition.
		block->push_back( new IfStmt(
			cond, modded_handler->get_body(), nullptr ) );

		modded_handler->set_decl( nullptr );
		modded_handler->set_cond( nullptr );
		modded_handler->set_body( nullptr );
		delete modded_handler;
		return block;
	}