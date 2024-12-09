Type* Builder::GetBuiltInTy(
    BuiltInKind   builtIn,            // Built-in kind
    InOutInfo     inOutInfo)          // Extra input/output info (shader-defined array size)
{
    enum TypeCode: uint32_t
    {
        a2f32,
        a4f32,
        af32,
        ai32,
        f32,
        i1,
        i32,
        i64,
        mask,
        v2f32,
        v3f32,
        v3i32,
        v4f32,
        v4i32,
    };

    uint32_t arraySize = inOutInfo.GetArraySize();
    TypeCode typeCode = TypeCode::i32;
    switch (builtIn)
    {
#define BUILTIN(name, number, out, in, type) \
    case BuiltIn ## name: \
        typeCode = TypeCode:: type; \
        break;
#include "llpcBuilderBuiltIns.h"
#undef BUILTIN
    default:
        LLPC_NEVER_CALLED();
        break;
    }

    switch (typeCode)
    {
    case TypeCode::a2f32: return ArrayType::get(getFloatTy(), 2);
    case TypeCode::a4f32: return ArrayType::get(getFloatTy(), 4);
    // For ClipDistance and CullDistance, the shader determines the array size.
    case TypeCode::af32: return ArrayType::get(getFloatTy(), arraySize);
    // For SampleMask, the shader determines the array size.
    case TypeCode::ai32: return ArrayType::get(getInt32Ty(), arraySize);
    case TypeCode::f32: return getFloatTy();
    case TypeCode::i1: return getInt1Ty();
    case TypeCode::i32: return getInt32Ty();
    case TypeCode::i64: return getInt64Ty();
    case TypeCode::v2f32: return VectorType::get(getFloatTy(), 2);
    case TypeCode::v3f32: return VectorType::get(getFloatTy(), 3);
    case TypeCode::v4f32: return VectorType::get(getFloatTy(), 4);
    case TypeCode::v3i32: return VectorType::get(getInt32Ty(), 3);
    case TypeCode::v4i32: return VectorType::get(getInt32Ty(), 4);
    default:
        LLPC_NEVER_CALLED();
        return nullptr;
    }
}