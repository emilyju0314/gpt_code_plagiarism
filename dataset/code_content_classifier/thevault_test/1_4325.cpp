bool paramListsPolyCompatible( const list< Expression* >& aparams, const list< Expression* >& bparams ) {
			if ( aparams.size() != bparams.size() ) return false;

			for ( list< Expression* >::const_iterator at = aparams.begin(), bt = bparams.begin();
					at != aparams.end(); ++at, ++bt ) {
				TypeExpr *aparam = dynamic_cast< TypeExpr* >(*at);
				assertf(aparam, "Aggregate parameters should be type expressions");
				TypeExpr *bparam = dynamic_cast< TypeExpr* >(*bt);
				assertf(bparam, "Aggregate parameters should be type expressions");

				// xxx - might need to let VoidType be a wildcard here too; could have some voids
				// stuffed in for dtype-statics.
				// if ( is<VoidType>( aparam->get_type() ) || is<VoidType>( bparam->get_type() ) ) continue;
				if ( ! typesPolyCompatible( aparam->get_type(), bparam->get_type() ) ) return false;
			}

			return true;
		}