void TypedefTable::makeTypedef( const string & name, int kind ) {
//    Check for existence is necessary to handle:
//        struct Fred {};
//        void Fred();
//        void fred() {
//           struct Fred act; // do not add as type in this scope
//           Fred();
//        }
	if ( ! typedefTable.exists( name ) ) {
		typedefTable.addToEnclosingScope( name, kind, "MTD" );
	} // if
}