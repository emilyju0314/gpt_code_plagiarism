void VariableSerializer::writeArrayKey(
  const Variant& key,
  VariableSerializer::ArrayKind kind
) {
  using AK = VariableSerializer::ArrayKind;
  auto const keyCell = tvAssertPlausible(key.asTypedValue());
  bool const skey = isStringType(keyCell->m_type);

  ArrayInfo &info = m_arrayInfos.back();

  switch (m_type) {
  case Type::DebuggerDump:
  case Type::PrintR: {
    indent();
    if (kind == AK::Keyset) return;
    m_buf->append('[');
    if (info.is_object && skey) {
      writePropertyKey(String{keyCell->m_data.pstr});
    } else {
      m_buf->append(key);
    }
    m_buf->append("] => ");
    break;
  }

  case Type::VarExport:
  case Type::PHPOutput:
    indent();
    if (kind == AK::Vec || kind == AK::Keyset) return;
    if ((kind == AK::VArray || kind == AK::MarkedVArray) &&
        (RO::EvalHackArrDVArrVarExport || m_type == Type::PHPOutput)) {
      return;
    }
    write(key, true);
    m_buf->append(" => ");
    break;

  case Type::VarDump:
  case Type::DebugDump:
    if (kind == AK::Vec || kind == AK::Keyset ||
        kind == AK::VArray || kind == AK::MarkedVArray) {
      return;
    }
    indent();
    m_buf->append('[');
    if (!skey) {
      m_buf->append(keyCell->m_data.num);
    } else {
      m_buf->append('"');
      if (info.is_object) {
        writePropertyKey(String{keyCell->m_data.pstr});
      } else {
        m_buf->append(keyCell->m_data.pstr);
        m_buf->append('"');
      }
    }
    m_buf->append("]=>\n");
    break;

  case Type::APCSerialize:
    if (kind == AK::Vec || kind == AK::Keyset || kind == AK::VArray) return;
    if (skey) {
      write(StrNR(keyCell->m_data.pstr).asString());
      return;
    }

  case Type::Serialize:
  case Type::Internal:
  case Type::DebuggerSerialize:
    if (kind == AK::Vec || kind == AK::MarkedVArray ||
        kind == AK::Keyset || kind == AK::VArray) return;
    write(key);
    break;

  case Type::JSON:
    if (!info.is_vector && kind != ArrayKind::Keyset) {
      if (!info.first_element) {
        m_buf->append(',');
      }
      if (UNLIKELY(m_option & k_JSON_PRETTY_PRINT)) {
        if (!info.first_element) {
          m_buf->append("\n");
        }
        indent();
      }
      if (skey) {
        auto const sdata = keyCell->m_data.pstr;
        const char *k = sdata->data();
        int len = sdata->size();
        if (info.is_object && !*k && len) {
          while (*++k) len--;
          k++;
          len -= 2;
        }
        write(k, len, true);
      } else {
        m_buf->append('"');
        m_buf->append(keyCell->m_data.num);
        m_buf->append('"');
      }
      m_buf->append(':');
      if (UNLIKELY(m_option & k_JSON_PRETTY_PRINT)) {
        m_buf->append(' ');
      }
    }
    break;

  default:
    assertx(false);
    break;
  }
}