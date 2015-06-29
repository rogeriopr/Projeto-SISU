void aprovadosGrupo(tMatch match[],tCandidato candidato[],tCurso curso[],int nMatch){
        //declaraçao das variaveis locais
        //i = numero do candidato na lista match, j = id do curso, k = contador de alunos na lista de aprovados de cada curso, c = grupo
        int i, j, k, c;

        //*ifp = tabela com os aprovados em cada curso por grupo
        FILE *ifp;
        //mode = modo de operaçao do arquivo
        char *mode = "w+";

        //inicializaçao do arquivo
        ifp = fopen(OUTPUT_CURSO_GRUPOS_FILE, mode);

        //teste para a verificaçao de abertura do arquivo
        if (ifp == NULL){
            exit(1);
        }

        printf("Classificados por curso e grupo:\n\n");
        fprintf(ifp,"Classificados por curso e grupo:\n\n");

        //Loop para preenchimento da lista de aprovados
        for(j=0; j < nCursos; j++){

            printf("Curso: %s\n",curso[j].nome);
            fprintf(ifp,"Curso:;%s\nPosicao;Nome;Opcao;Media\n\n",curso[j].nome);

            for(c = 1; c <= N_GRUPOS; c++){

                printf("Grupo %d:\n", c);
                fprintf(ifp,"Grupo %d:\n",c);

                //k = posiçao inicial de alunos em cada grupo
                k = 1;

                //Escrita dos alunos na lista de cada grupo
                for(i=0;i<nMatch;i++){
                if(match[i].classificado==1 && match[i].idCurso==j && match[i].grupo == c){
                    printf("%3d. %10s Opcao: %d Media: %.2Lf\n", k, candidato[match[i].idCandidato].nome, match[i].opcao, match[i].media);
                    fprintf(ifp,"%d;%s;%d;%.2Lf\n", k++, candidato[match[i].idCandidato].nome, match[i].opcao, match[i].media);
                }
            }

        printf("\n\n",curso[j].nome);
        fprintf(ifp,"\n\n",curso[j].nome);
        }
    }
    fclose(ifp);

}
