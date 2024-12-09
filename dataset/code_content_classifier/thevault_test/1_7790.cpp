int NFAMatch::match(string str){
	int score = 0;
    buildGraph(str);
    score = dynamicProg(str);
    //printMatr(str);
    return score;
}