void procuraCurso(tMatch match[],int nMatch,tCandidato candidato[],tCurso curso[],int nCursos)
{
    //declaracao das variaveis
    char nome[TAM_NOME];
    int i,j,k=0;

    //leitura do nome do curso
    printf("Nome do Curso: ");
    fflush(stdin);
    gets(nome);
    toUpperStr(nome);

    //pesquisa para cursos com nome parecido
    for(i=0;i<nCursos;i++) {

        toUpperStr(curso[i].nome);
        if(strstr(curso[i].nome,nome)!=NULL) { // Compara o nome do teclado com os nomes dos candidatos dentro do vetor candidato.
					        // Requer a biblioteca <string.h>.
            k++;

            //impressao dos alunos aprovados
            printf("-%s-\n\n",curso[i].nome);
            for(j=0; j<nMatch; j++){
                if(match[j].classificado==1 && match[j].idCurso==i){
                    printf("\t%s %*s %d Grupo: %d Media: %.2Lf\n", candidato[match[j].idCandidato].nome,abs(35-strlen(candidato[match[j].idCandidato].nome)) , "Opcao:" , match[j].opcao, match[j].grupo, match[j].media);
                }
            }

            printf("\n\n");

        }
    }

    //impressao em caso de nenhuma curso possuir o nome
    if(k==0)
        printf("Nenhum Curso com esse nome encontrado.\n");
}
