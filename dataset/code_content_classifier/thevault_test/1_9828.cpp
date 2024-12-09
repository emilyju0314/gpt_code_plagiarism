std::string CXTypeToType (const CXType &type) {
		switch (type.kind) {
			case CXType_Invalid: {
				return "invalid";
			}
			case CXType_Unexposed: {
				return "unexposed";
			}
			case CXType_Void: {
				return "void";
			}
			case CXType_Bool: {
				return "bool";
			}
			case CXType_Char_U: {
				return "char_u";
			}
			case CXType_UChar: {
				return "uchar";
			}
			case CXType_Char16: {
				return "char16";
			}
			case CXType_Char32: {
				return "char32";
			}
			case CXType_UShort: {
				return "ushort";
			}
			case CXType_UInt: {
				return "uint";
			}
			case CXType_ULong: {
				return "ulong";
			}
			case CXType_ULongLong: {
				return "ulonglong";
			}
			case CXType_UInt128: {
				return "uint123";
			}
			case CXType_Char_S: {
				return "char_s";
			}
			case CXType_SChar: {
				return "s_char";
			}
			case CXType_WChar: {
				return "w_char";
			}
			case CXType_Short: {
				return "short";
			}
			case CXType_Int: {
				return "int";
			}
			case CXType_Long: {
				return "long";
			}
			case CXType_LongLong: {
				return "long_long";
			}
			case CXType_Int128: {
				return "int_128";
			}
			case CXType_Float: {
				return "float";
			}
			case CXType_Double: {
				return "double";
			}
			case CXType_LongDouble: {
				return "long_double";
			}
			case CXType_NullPtr: {
				return "null";
			}
			case CXType_ObjCId: {
				return "id";
			}
			case CXType_ObjCClass: {
				return "Class";
			}
			case CXType_ObjCSel: {
				return "SEL";
			}
			case CXType_Complex: {
				return "complex";
			}
			case CXType_Pointer: {
				return "pointer";
			}
			case CXType_BlockPointer: {
				return "block";
			}
			case CXType_LValueReference: {
				return "lvalue_ref";
			}
			case CXType_RValueReference: {
				return "rvalue_ref";
			}
			case CXType_Record: {
				return "record";
			}
			case CXType_Enum: {
				return "enum";
			}
			case CXType_Typedef: {
				return "typedef";
			}
			case CXType_ObjCInterface: {
				return "obj_interface";
			}
			case CXType_ObjCObjectPointer: {
				return "objc_pointer";
			}
			case CXType_FunctionNoProto: {
				return "function_noproto";
			}
			case CXType_FunctionProto: {
				return "function_proto";
			}
			case CXType_ConstantArray: {
				return "constant_array";
			}
			case CXType_Vector: {
				return "vector";
			}
			case CXType_IncompleteArray: {
				return "incomplete_array";
			}
			case CXType_VariableArray: {
				return "variable_array";
			}
			case CXType_DependentSizedArray: {
				return "dependent_sized_array";
			}
			case CXType_MemberPointer: {
				return "member_pointer";
			}
			case CXType_ExtVector: {
				// fallback to unexposed since external vectors have no encoding yet
				// @see http://llvm.org/viewvc/llvm-project?view=revision&revision=216301
				return "unexposed";
			}
			default: {
				std::stringstream ss;
				ss << "unknown type: ";
				ss << type.kind;
				return ss.str();
			}
		}
	}