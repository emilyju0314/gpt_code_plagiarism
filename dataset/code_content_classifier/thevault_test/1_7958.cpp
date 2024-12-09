std::string GetVariableName(const insn_t& instruction, uint8_t operand_num) {
  if (!IsStackVariable(instruction.ea, operand_num)) {
    return "";
  }

  const member_t* stack_variable =
      get_stkvar(0, instruction, instruction.ops[operand_num],
                 instruction.ops[operand_num].addr);
  if (!stack_variable) {
    return "";
  }

  std::string name = ToString(get_struc_name(stack_variable->id));

  // The parsing is in here because IDA puts in some strange segment prefix or
  // something like that.
  name = name.substr(name.find('.', 4) + 1);
  if (name[0] != ' ') {
    func_t* function = get_func(instruction.ea);
    if (!function) {
      return name;
    }

    const ea_t offset =
        calc_stkvar_struc_offset(function, instruction, operand_num);
    if (offset == BADADDR) {
      return name;
    }

    std::string result;

    // The following comment is from the Python exporter:
    // 4 is the value of the stack pointer register SP/ESP in x86. This should
    // not break other archs but needs to be here or otherwise would need to
    // override the whole method in metapc...
    tid_t id = 0;
    adiff_t disp = 0;
    adiff_t delta = 0;
    if (get_struct_operand(&disp, &delta, &id, instruction.ea, operand_num) &&
        instruction.ops[operand_num].reg == 4) {
      int delta = get_spd(function, instruction.ea);
      delta = -delta - function->frregs;
      if (delta) {
        absl::StrAppend(&result, IdaHexify(delta), "+");
      }

      // TODO(soerenme): This must be recursive for nested structs.
      if (const struc_t* structure = get_struc(id)) {
        if (const member_t* member = get_member(structure, disp)) {
          std::string member_name = ToString(get_member_name(member->id));
          absl::StrAppend(&result, name, ".", member_name, disp);
          if (delta) {
            absl::StrAppend(&result, delta > 0 ? "+" : "", delta);
          }
          return result;
        }
      }
    } else {
      return name;
    }

    absl::StrAppend(&result, name);
    const int var_delta = offset - stack_variable->soff;
    if (var_delta) {
      absl::StrAppend(&result, "+0x", absl::Hex(var_delta));
    }
    return result;
  }
  return "";
}