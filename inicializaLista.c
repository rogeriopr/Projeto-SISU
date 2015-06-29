int inicializaLista(tMatch match[], int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],int nCandidatos,int nCursos)
{
    int i,j; //contadores de laço
    // inializacao do vetor lista com cada candidato tendo a variavel inicializada
    printf("Inicializando lista de candidatos:\n");
    for(i=0;i<MAX_CANDIDATOS;i++)
    {
        match[i].media=0;
    }
    for(i=0;i<nCursos;i++)
    {
        for(j=0;j<5;j++)
        {
            nSelecionados[i][j]=0;
        }
    }

    j=0; //reaproveitamento do contador
    for(i=0;i<nCandidatos;i++)
    {
        match[j].idCandidato=i;
        match[j].idCurso=candidato[i].opcao1.idCurso;
        match[j].media=candidato[i].opcao1.media;
        match[j].opcao=1;
        match[j].grupo=candidato[i].opcao1.grupo;
        match[j].classificado=0;
        j++;
        printf("%s - Opcao 1/",candidato[i].nome);
        if(candidato[i].opcao2.idCurso!=-1)
        {
            match[j].idCandidato=i;
            match[j].idCurso=candidato[i].opcao2.idCurso;
            match[j].media=candidato[i].opcao2.media;
            match[j].opcao=2;
            match[j].grupo=candidato[i].opcao2.grupo;
            match[j].classificado=0;
            j++;
            printf("Opcao 2");
        }
        printf(" OK!\n");
    }
    return j;//retorna quantos foram colocados na lista
}
