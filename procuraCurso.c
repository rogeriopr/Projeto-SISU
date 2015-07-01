/*
   Nome da função: procuraCurso
   Objetivos: imprime os resultados de um curso especifico
   Parâmetros Formais:
       -match[]: Vetor com os aprovados (Entrada de dados)
       -candidato[]: Vetor com os dados dos candidatos (Entrada de dados)
       -curso[]: Vetor com os dados dos cursos (Entrada de dados)
       -nMatch: Número de aprovados (Entrada de dados)
       -nCursos (int): Quantidade de cursos cadastrados (Entrada de dados)
   Retorno: Nenhum (procedimento)
*/
void procuraCurso(tMatch match[],int nMatch,tCandidato candidato[],tCurso curso[],int nCursos)
{
    //declaracao das variaveis
    char nome[TAM_NOME];
    char temp[TAM_NOME];
    int i,j,k=0,l=0;

    //leitura do nome do curso
    printf("Nome do Curso: ");
    fflush(stdin);
    while(strlen(gets(nome))<3)
    {
        system("cls");
        printf("Digite pelo menos 3 caracteres!\n\nNome do Curso: ");
    }
    toUpperStr(nome);

    system("cls");
    //pesquisa para cursos com nome parecido
    for(i=0;i<nCursos;i++) {
        strcpy(temp,curso[i].nome);
        toUpperStr(temp);

        if(strstr(temp,nome)!=NULL) { // Compara o nome do teclado com os nomes dos candidatos dentro do vetor candidato.
					        // Requer a biblioteca <string.h>.
            k=1;
            l=0;
            //impressao dos alunos aprovados
            printf("-%s-\n\n",curso[i].nome);
            for(j=0; j<nMatch; j++){
                if(match[j].idCurso==i){
                    l++;
                    if(match[j].classificado==1){
                        printf("\t%3d. %s %*s %d Grupo: %d Media: %.2Lf\n", k++, candidato[match[j].idCandidato].nome,abs(35-strlen(candidato[match[j].idCandidato].nome)) , "Opcao:" , match[j].opcao, match[j].grupo, match[j].media);
                    }
                }
            }
            //estatisticas
            printf("\nConsiderando candidatos e vagas de todas as cotas:\nVagas Preenchidas: %d\nTotal de vagas: %d\nTotal de candidatos: %d\n\n",k-1,curso[i].vagas[1]+curso[i].vagas[2]+curso[i].vagas[3]+curso[i].vagas[4]+curso[i].vagas[5],l);

        }
    }

    //impressao em caso de nenhuma curso possuir o nome
    if(k==0){
        printf("Nenhum Curso com esse nome encontrado.\n");
        system("pause");
        system("cls");
    }else{
        printf("Relatorio dos cursos por grupos:\n");
        system("pause");
        system("cls");
        mostraCursoGrupo(match,nMatch,candidato,curso,nCursos,nome);
    }
}
