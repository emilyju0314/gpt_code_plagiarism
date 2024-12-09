void initOLD(void)
{
	// Define a cor do fundo da tela (AZUL)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    // Leitura do arquivo
    Mapa.insere_vertice(Ponto(0,0));
    Mapa.insere_vertice(Ponto(-3,5));
    Mapa.insere_vertice(Ponto(5,5));
    Mapa.insere_vertice(Ponto(8,-3));
    Mapa.insere_vertice(Ponto(-4,-3));

    // Seta os limites da �rea de desenho
    Min = Ponto(-10, -10, 0);
    Max = Ponto( 10,  10, 1);
}