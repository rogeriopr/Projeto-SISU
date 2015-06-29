int inicializaLista(tMatch match[], int nSelecionados[MAX_CURSOS][N_GRUPOS],tCandidato candidato[],int nCandidatos){
    int i, j; //variaveis locais contadoras de laco
    // inializacao do vetor lista com cada candidato tendo a variavel inicializada
    
    for(i=0; i<MAX_CANDIDATOS; i++){
        lista[i].media = 0;
    }       
            
    for(i=0; i<nCursos; i++){
            for(j=0, j<N_CURSOS; j++){
                nSelecionados[i][j]=0;
            }
        }
        
    j=0; // reaproveitamento do contador
    
    for(i=0; i<nCandidatos; i++){
        // preenchimento da lista de candidatos
        lista[j].idCandidato = i;
        lista[j].idCurso=candidato[i].opcao1.idCurso;
        lista[j].media=candidato[i].opcao1.media;
        lista[j].opcao1=0;
        lista[j].grupo=candidato[i].opcao.grupo;
        lista[j].classificado=0;
        j++;
        printf("%s - Opcao 1", candidato[i].nome);
        
        if(candidato[i].opcao2.idCurso!=-1){
        lista[j].idCandidato=i;
        lista[j].idCurso=candidato[i].opcao1.idCurso;
        lista[j].media=candidato[i].opcao1.media;
        lista[j].opcao1=0;
        lista[j].grupo=candidato[i].opcao.grupo;
        lista[j].classificado=0;
        j++;
        printf("/Opcao 2");
        }      
    }
    
    return j;//retorna quantos entradas foram colocadas na lista
}
