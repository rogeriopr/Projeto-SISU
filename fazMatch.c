void fazMatch(tMatch match[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[],int nMatch)
{
    int i,j,k; //contadores
    /*Match da lista de escolhas*/
    for(i=0;i<nMatch;i++)
    {
        printf("Processando: %d ",i);
        if(candidato[match[i].idCandidato].classificado!=-2) //-2 significa aprovado na 1 opcao
        {
            if (nSelecionados[match[i].idCurso][match[i].grupo-1]<curso[match[i].idCurso].vagas[match[i].grupo]) //verifica se ja nao foi completado a quantidade de candidatos para cada cota de cada curso
            {
                printf("Entrou: %s -> %s",candidato[match[i].idCandidato].nome,curso[match[i].idCurso].nome);
                if(match[i].opcao==1 && candidato[match[i].idCandidato].classificado!=-1) //se o candidato ja havia passado na 2º chamada, chama o trocaEscola, que vai reoferecer a vaga
                {
                    trocaEscolha(match[i].idCandidato,i,match,nSelecionados,candidato,curso);
                }
                nSelecionados[match[i].idCurso][match[i].grupo-1]++;//aumenta 1 no numero de selecionados
                match[i].classificado=1;//marca verdadeiro em escolhido no controle do match
                if(match[i].opcao==1)//verifica se a opcao de curso é a 1º
                    candidato[match[i].idCandidato].classificado=-2;//marca -2 caso seja a primeira opcao
                else
                    candidato[match[i].idCandidato].classificado=i;//marca o id na lista em que esta localizada a opcao(caso tenha passado na 2 opcao)
                    //esse id sera usado futuramente usado na trocaEscola caso o candidato passe na 1 opcao
            }
        }
        printf("\n");
    }
}
