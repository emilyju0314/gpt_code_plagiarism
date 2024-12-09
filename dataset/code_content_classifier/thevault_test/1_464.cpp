void tab::print(){
	int terminalSizeX, terminalSizeY;
	int boardSizeX, boardSizeY;
	
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	terminalSizeX=w.ws_col;
	terminalSizeY=w.ws_row;
	
	boardSizeX = pConfig->screenLar;
	boardSizeY = pConfig->screenAlt;
	
	
	int i;
	for(i=0; i< (terminalSizeY - boardSizeY -2)/2; i++)
		printf("\n");
	for(i=0; i< (terminalSizeX - boardSizeX -2)/2; i++)
		printf(" ");
		
	changeBGcolor(COLOR_YELLOW);
	printf("┌");
	for(i=0; i< boardSizeX/2; i++)
		printf("──");
	printf("┐");
	resetColor();
	printf("\n");
	
	
	FOR(j,MIN(boardSizeY,terminalSizeY-12)){
		FOR(i,(terminalSizeX-boardSizeX-2)/2)printf(" ");
		changeBGcolor(COLOR_YELLOW);
		printf("│");
		resetColor();
		FOR(i,MIN(boardSizeX/2,terminalSizeX-20)){
			int xx=(pConfig->curX+i)%lar;
			int yy=(pConfig->curY+j)%alt;
			if     (!xx && yy==alt-1)changeBGcolor(COLOR_BRED);
			else if(!xx || yy==alt-1)changeBGcolor(COLOR_BBLUE);
			else					 changeBGcolor(COLOR_GREEN);

			if(pConfig->editting){
				if(xx == pConfig->cursorX && yy == pConfig->cursorY) invBGcolor();
				changeFGcolor(pConfig->color[0]);
				if(v[xx][yy])	printf("# ");
				else       		printf(". ");
			}
			else{
				changeFGcolor(pConfig->color[(int)(v[xx][yy])%10]);
				if(v[xx][yy]==10)	printf("# ");
				else if(v[xx][yy])	printf("%d ",v[xx][yy]-1);
				else       			printf(". ");
			}
			resetColor();
		}
		changeBGcolor(COLOR_YELLOW);
		printf("│");
		resetColor();
		printf("\n");
	}
	FOR(i,(terminalSizeX-boardSizeX-2)/2)printf(" ");
	changeBGcolor(COLOR_YELLOW);
	printf("└");
	FOR(i,boardSizeX/2)printf("──");
	printf("┘");
	resetColor();
	printf("\n\n");
	FOR(i,(terminalSizeY-boardSizeY-10)/2)printf("\n");
}