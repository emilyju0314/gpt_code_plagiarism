bool game::readRule(const string& arqName){
	ifstream 	arq;
	string 		line;
	
	printf("Reading file named \"%s\"\n", arqName.c_str());
	arq.open("./rules/" + arqName + ".rule");
	if(! arq.is_open()){
		fprintf(stderr, "Erro ao ler arquivo \"%s\".\n", arqName.c_str());
		return false;
	}
	
	getline(arq,line);
	pJogo->rS = pJogo->ruleStringToInt(line);
	getline(arq,line);
	pJogo->rB = pJogo->ruleStringToInt(line);
	arq.close();
	printf("Arquivo lido com sucesso.\n");
	usleep(20000);
	
	return true;
}