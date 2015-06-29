void trocaEscolha(int id, int pos,tMatch match[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[])
{
	//declaracao de variaveis
    int i,j,achou=0;
	printf("\n\t Efetua Troca: -", id);
    i=candidato[id].classificado;//candidatos classificados
    nSelecionados[match[i].idCurso][match[i].grupo-1]--; //decrementa em uma unidade os Selecionados
    match[i].classificado=0; //marca falso no controle do match
    j=i+1;
    
    
    while(j<pos&&achou==0)
    {
    	//verifica se candidato passou na segunda opcao
        if(candidato[match[j].idCandidato].classificado!=-2 && match[j].idCurso==match[i].idCurso && match[j].grupo==match[i].grupo){
            printf(" %s -> %s",candidato[match[j].idCandidato].nome,curso[match[j].idCurso].nome);
            achou=1;
            //verifica se o candidato passou na primeira opcao e realiza a troca da segunda com a primeira
            if (candidato[match[j].idCandidato].classificado!=-1){
                trocaEscolha(match[j].idCandidato,j,match,nSelecionados,candidato,curso);
            }
            nSelecionados[match[j].idCurso][match[j].grupo-1]++; //encrementa os nSelecionados 
            match[j].classificado=1;//verifica se esta classificado 
            if(match[j].opcao==1)
                candidato[match[j].idCandidato].classificado=-2; //recebe -2 caso esteja classificado na primeira opcao
            else
                candidato[match[j].idCandidato].classificado=j; //marca o id na lista
        }
        j++;
    }
}
