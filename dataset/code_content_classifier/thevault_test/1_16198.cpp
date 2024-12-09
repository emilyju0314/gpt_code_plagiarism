void Cws_sqlEx::createXMLParams(StringBuffer & xmlparams, HPCCSQLTreeWalker* parsedSQL, IArrayOf<IConstNamedValue> *variables, IConstWorkUnit * cw)
{
    IArrayOf<IConstWUResult> expectedparams;

    if (cw)
    {
        IConstWUResultIterator &vars = cw->getVariables();
        ForEach(vars)
        {
            IConstWUResult &cur = vars.query();
            expectedparams.append(cur);
        }
    }

    if (expectedparams.length() > 0)
    {
        int totalvars = 0;
        if (variables)
            totalvars = variables->length();

        if (parsedSQL && parsedSQL->getSqlType() == SQLTypeCall)
        {
            IArrayOf<ISQLExpression> * embeddedparams = NULL;
            if (parsedSQL)
                embeddedparams = parsedSQL->getStoredProcParamList();

            int parametersidx = 0;
            int varsidx = 0;


            SCMStringBuffer varname;

            if (embeddedparams && embeddedparams->length()>0)
            {
              xmlparams.append("<root>");

              for(int i=0; i < embeddedparams->length() && i < expectedparams.length(); i++)
              {
                  expectedparams.item(i).getResultName(varname);
                  xmlparams.append("<").append(varname.s.str()).append(">");

                  ISQLExpression* paramcol = &embeddedparams->item(i);
                  if (paramcol->getExpType() == ParameterPlaceHolder_ExpressionType)
                  {
                      if (varsidx < totalvars)
                      {
                          IConstNamedValue &item = variables->item(varsidx++);
                          const char *value = item.getValue();
                          if(value && *value)
                              encodeXML(value, xmlparams);
                          // else ??
                      }
                  }
                  else
                  {
                      paramcol->toString(xmlparams,false);
                  }
                  xmlparams.append("</").append(varname.s.str()).append(">");
              }
              xmlparams.append("</root>");
            }
        }
        else
        {
            int parametersidx = 0;
            int varsidx = 0;

            SCMStringBuffer varname;

            xmlparams.append("<root>");

            for(int i=0; i < expectedparams.length() && i < totalvars; i++)
            {
                expectedparams.item(i).getResultName(varname);
                xmlparams.append("<").append(varname.s.str()).append(">");

                IConstNamedValue &item = variables->item(i);
                const char *value = item.getValue();
                if(value && *value)
                  encodeXML(value, xmlparams);
                // else ??

              xmlparams.append("</").append(varname.s.str()).append(">");
            }
            xmlparams.append("</root>");
        }
    }
}