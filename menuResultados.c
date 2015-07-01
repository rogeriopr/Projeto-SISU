void menuResultados(tMatch match[],int nMatch,tCandidato candidato[], int nCandidatos, tCurso curso[],int nCursos)
{
	int opcao;	//declaracao de variavael local

	do {
		printf("Escolha a opcao:\n\n\t1. Exportar Aprovados Geral\n\t2. Exportar Aprovados por curso\n\t3. Exportar Aprovados por curso e grupo\n\t4. Busca por candidato\n\t5. Busca por curso\n\n\t0. Sair\n\nOpcao: ");
		while (scanf("%d", &opcao) != 1);
		switch (opcao) {
		case 1:
			system("cls");
			aprovadosTodos(match, nMatch, candidato, curso);	//Exibir a lista de aprovados ordenados por media (decrescente)
			break;
		case 2:
			system("cls");
			aprovadosCurso(match, nMatch, candidato, curso, nCursos);	//Exibicao dos aprovados separados por cursos
			break;
		case 3:
			system("cls");
			aprovadosGrupo(match, nMatch, candidato, curso, nCursos);	//Exibicao da lista de aprovados separados por cursos e grupos
			break;
		case 4:
			system("cls");
			procuraCandidatos(candidato, nCandidatos, curso);	//Opcao para procurar candidatos pelo nome
			break;
        case 5:
			system("cls");
			procuraCurso(match, nMatch, candidato, curso, nCursos);	//Opcao para procurar candidatos pelo nome
			break;
		}
		printf("\n\n");
	} while (opcao != 0);	//criterio de parada

	system("cls");	//limpa a tela
}
