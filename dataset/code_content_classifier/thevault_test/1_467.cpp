bool game::saveArq(const string &arqName){
	ofstream	arq;
	
	
	printf("Saving to file named \"%s\"\n", arqName.c_str());
	arq.open("./patterns/" + arqName + ".life");
	
	if (! arq.is_open()){
		fprintf(stderr, "Erro ao ler arquivo \"%s\".\n", arqName.c_str());
		return false;
	}
	
	
	arq << board.lar << " " << board.alt << "\n#\n";
	FOR(j,board.alt){
		FOR(i,board.lar){
			if(board.v[i][j])arq << "#";
			else			 arq << "-";
		}
		arq << endl;
	}
	
	arq.close();
	printf("Arquivo salvo com sucesso.\n");
	usleep(20000);
	
	return true;
}