inline bool ProcessSubstitution(const Formula*f, State*s, VariableQueue*v)
{
	uint var;
	bool sat = true;
	while (v->top_index > 0 && sat)
	{
		v->top_index--;
		var = v->queue[v->top_index];
		if(s->info[var] == True)
		{
			//turn off positive occurences and test unitness in negative occurences
			TurnOffClauses(f, f->pos_occurences + f->pos_occurences_index[var], 
							f->pos_occurences + f->pos_occurences_index[var+1], 
							s, v);
			sat = TestUnit(f, f->neg_occurences + f->neg_occurences_index[var],
							f->neg_occurences + f->neg_occurences_index[var+1],
							s,v,var);
		}
		else // s->info[var] == False
		{
			//turn off negative occurences and test unitness in positive occurences
			TurnOffClauses(f, f->neg_occurences + f->neg_occurences_index[var], 
							f->neg_occurences + f->neg_occurences_index[var+1], 
							s, v);
			sat = TestUnit(f, f->pos_occurences + f->pos_occurences_index[var],
							f->pos_occurences + f->pos_occurences_index[var+1],
							s, v, var);
		}
	}
	return sat;
}