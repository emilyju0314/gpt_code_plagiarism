void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita)
{
	if (arvore== NULL)
		return;
	depth++;
	desenha_arvore_horiz(arvore->right, depth, path, 1);
	path[depth-2] = 0;
	if(direita)
		path[depth-2] = 1;
		if(arvore->left)
			path[depth-1] = 1;
		printf("\n");
		for(int i=0; i<depth-1; i++)
		{
			if(i == depth-2)
				printf("+");
			else if(path[i])
				printf("|");
			else
				printf(" ");
			
			for(int j=1; j< espaco; j++)
				if(i < depth-2)
					printf(" ");
				else
					printf("-");
		}
		printf("%d\n", arvore->info);
		for(int i=0; i<depth; i++)
		{
			if(path[i])
				printf("|");
			else
				printf(" ");
				for(int j=1; j< espaco; j++)
					printf(" ");
		}
		desenha_arvore_horiz(arvore->left, depth, path, 0);
		
}