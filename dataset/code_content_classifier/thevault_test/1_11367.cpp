RegExp::REBase*
RegExp::CompileWildcardExp(const char* pzPattern)
{
  std::stack<REBase*>
    patternStack;

  REBase* pNew;
  while(*pzPattern)
  {
    pNew = 0;
    switch(*pzPattern)
    {
    case '?':
      pNew = new REAnyChar;
      break;

    case '*':
      {
        REBase* pChild = new REAnyChar;
        RESubExpression* pSubExpression = new RESubExpression(0, INT_MAX);
        pSubExpression->_pcChild = pChild;
        pNew = pSubExpression;
      }
      break;

    default:
      pNew = new REChar(*pzPattern);
      break;
    }
    patternStack.push(pNew);
    pzPattern++;
  }
  REBase* pFirst = 0;
  while (!patternStack.empty())
  {
    REBase* pFront = patternStack.top();
    patternStack.pop();
    pFront->_pcNext = pFirst;
    pFirst = pFront;
  }
  return pFirst;
}