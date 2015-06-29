void aprovadosCurso(tMatch match[],int nMatch,tCandidato candidato[],tCurso curso[],int nCursos){

    //declaraçao das variaveis locais
    //i = numero do candidato na lista match, j = id do curso, k = contador de alunos na lista de aprovados de cada curso
    int i, j, k;
    //*ifp = tabela com os aprovados em cada curso
    FILE *ifp;
    //mode = modo de operaçao do arquivo
    char *mode = "w+";

    //inicializaçao do arquivo
    ifp = fopen(OUTPUT_CURSO_FILE, mode);

    //teste para a verificaçao de abertura do arquivo
    if (ifp == NULL){
        exit(1);
    }

    printf("Classificados por curso:\n\n");
    fprintf(ifp, "Classificados por curso:\n\n");

    //Loop para preenchimento da lista de aprovados
    for(j=0; j<nCursos; j++){
         //k = posiçao inicial de alunos em cada curso
        k=1;

        printf("Curso: %s\n",curso[j].nome);
        fprintf(ifp,"Curso:;%s\nPosicao;Nome;Opcao;Grupo;Media\n",curso[j].nome);

        //Escrita dos alunos na lista
        for(i=0; i<nMatch; i++){
            if(match[i].classificado==1 && match[i].idCurso==j){
                printf("%3d. %10s%25s Opcao: %d Grupo: %d Media: %.2Lf\n", k, candidato[match[i].idCandidato].nome, curso[match[i].idCurso].nome, match[i].opcao, match[i].grupo, match[i].media);
                fprintf(ifp, "%d;%s;%d;%d;%.2Lf\n", k++ ,candidato[match[i].idCandidato].nome, match[i].opcao, match[i].grupo, match[i].media);
            }
        }

        printf("\n\n", curso[j].nome);
        fprintf(ifp, "\n\n", curso[j].nome);
    }

    fclose(ifp);
}
