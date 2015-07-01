/*
   Nome da função: mostraCursoGrupo
   Objetivos: imprime os resultados de um curso especifico separados por cota
   Parâmetros Formais:
       -match[]: Vetor com os aprovados (Entrada de dados)
       -candidato[]: Vetor com os dados dos candidatos (Entrada de dados)
       -curso[]: Vetor com os dados dos cursos (Entrada de dados)
       -nMatch: Número de aprovados (Entrada de dados)
       -nCursos (int): Quantidade de cursos cadastrados (Entrada de dados)
       -nome(char): nome do curso a pesquisar(Entrada de dados)
   Retorno: Nenhum (procedimento)
*/
void mostraCursoGrupo(tMatch match[],int nMatch,tCandidato candidato[],tCurso curso[],int nCursos,char nome[TAM_NOME])
{
    //declaracao das variaveis
    char temp[TAM_NOME];
    int i,j,c,k=0,l=0;

    system("cls");
    //pesquisa para cursos com nome parecido
    for(i=0;i<nCursos;i++) {
        strcpy(temp,curso[i].nome);
        toUpperStr(temp);

        if(strstr(temp,nome)!=NULL) { // Compara o nome do teclado com os nomes dos candidatos dentro do vetor candidato.
					        // Requer a biblioteca <string.h>.
            //impressao dos alunos aprovados
            printf("-%s-\n",curso[i].nome);
            for(c=1;c<6;c++){
                k=1;
                l=0;
                printf("    -GRUPO %d-\n\n",c);
                for(j=0; j<nMatch; j++){
                    if(match[j].idCurso==i && match[j].grupo==c){
                        l++;
                        if(match[j].classificado==1){
                            printf("\t%3d. %s %*s %d Media: %.2Lf\n", k++, candidato[match[j].idCandidato].nome,abs(35-strlen(candidato[match[j].idCandidato].nome)) , "Opcao:" , match[j].opcao, match[j].media);
                        }
                    }
                }
                //estatisticas
                printf("\nVagas Preenchidas: %d\nTotal de vagas: %d\nTotal de candidatos(1. e 2. Opcao): %d\n\n",k-1,curso[i].vagas[c],l);
            }
        }
    }

    //impressao em caso de nenhuma curso possuir o nome
    if(k==0)
        printf("Nenhum Curso com esse nome encontrado.\n");

    system("pause");
    system("cls");
}
