void DumpTypeDescription(const LazySymbol& lazy_type, OutputBuffer* out) {
  out->Append("  Type: ");
  if (const Type* type = lazy_type.Get()->AsType()) {
    // Use GetFullName() instead of GetIdentifier() because modified types like pointers don't
    // map onto identifiers.
    out->Append(type->GetFullName());
  } else {
    out->Append(Syntax::kError, "[Bad type]");
  }
  out->Append("\n");
}