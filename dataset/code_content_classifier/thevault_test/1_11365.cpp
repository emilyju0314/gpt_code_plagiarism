static int precedence(TOKID::ID op){ 
  switch (op) {
  case TOKID::NOT: case TOKID::NEG:
    return 15 - 2;
  case TOKID::MUL: case TOKID::DIV: 
    return 15 - 3;
  case TOKID::ADD: case TOKID::SUB:
    return 15 - 4;
  case TOKID::SHL: case TOKID::SHR:
    return 15 - 5;
  case TOKID::LT: case TOKID::LE: case TOKID::GE: case TOKID::GT:
    return 15 - 6;
  case TOKID::EQU: case TOKID::NEQ:
    return 15 - 7;
  case TOKID::AND:
    return 15 - 8;
  case TOKID::XOR:
    return 15 - 9;
  case TOKID::OR:
    return 15 - 10;
  case TOKID::lAND:
    return 15 - 11;
  case TOKID::lOR:
    return 15 - 12;
  case TOKID::HI: case TOKID::LO:
    return 15 - 13;
  case TOKID::LPAR:
    return 15 - 15;
  default:
    assert(0);
    return 15;
  }
}