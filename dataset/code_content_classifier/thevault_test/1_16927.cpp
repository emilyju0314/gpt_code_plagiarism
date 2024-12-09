void achar_campos(char *registro, struct leitura *campos)//recebe o ponteiro do registro que vamos separar
{
	//coloca os dados em uma struct
	//lendo o registro em partes separadas por '|'
	strcpy(campos->ID,strtok(registro, "#"));
	strcpy(campos->sigla,strtok(NULL, "#"));
	strcpy(campos->nome,strtok(NULL, "#"));
	strcpy(campos->disciplina,strtok(NULL, "#"));
	strcpy(campos->media,strtok(NULL, "#"));
	strcpy(campos->frequencia,strtok(NULL, "#"));
}