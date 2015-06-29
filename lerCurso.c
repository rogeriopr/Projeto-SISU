//
//  Arquivo: lerCurso.c
//  Autor: Marco Aurélio Murbach Teles Machado R.A. 418927
//  Data: 29 de Junho de 2015
//  Objetivos: Função para ler arquivo com os dados dos cursos, retornando o total de cursos lidos e o vetor
//  tCurso com os dados já cadastrados.
//
//


// Objetivos: Leitura do arquvio CURSOS_FILE, com os dados do curso
// Parametros: tCurso curso (Entrada e Saída)
// Retorno: nCursos -> Total de Cursos Cadastrado
int lerCursos(tCurso curso[])
{
    FILE *ifp; //Identificação do Arquivo
    char *mode = "r"; //Modo Leitura (Somente)
    int i,nCursos,j;
    char nomeTemp[TAM_NOME];
    
    ifp = fopen(CURSOS_FILE, mode);
    
    //--> Caso não encontre o Arquivo para o programa
    if (ifp == NULL) {
        exit(1);
    }
    
    //--> Recupera a Quantidade de Cursos
    fscanf(ifp, "%d", &nCursos);
    printf("Lendo %d cursos\n",nCursos);
    
    // Inicia a leitura do Arquivo de Cursos
    for(i=0;i<nCursos;i++){
        
        // --> Leitura do Nome do Curso
        fscanf(ifp,"%s",nomeTemp);
        
        //correcao do nome
        for( j = 0;j < strlen(nomeTemp); j++){
            if(nomeTemp[j]==95){
                nomeTemp[j]=32;
            }
        }
        strcpy(curso[i].nome,nomeTemp);
        
        //--> Após Ler o Nome do Curso recupera a quantidade de Vagas de Cada Grupo
        fscanf(ifp, "%d %d %d %d %d", &curso[i].vagas[1],&curso[i].vagas[2],&curso[i].vagas[3],&curso[i].vagas[4],&curso[i].vagas[5]);
        
        //--> Vaga[0] Grava total de vagas oferecida pelo curso
        curso[i].vagas[0] = curso[i].vagas[1]+curso[i].vagas[2]+curso[i].vagas[3]+curso[i].vagas[4]+curso[i].vagas[5];
        
        //--> Le os Pesos
        fscanf(ifp, "%lf %lf %lf %lf %lf", &curso[i].pesos.humanas,&curso[i].pesos.linguagens,&curso[i].pesos.matematica,&curso[i].pesos.natureza,&curso[i].pesos.redacao);
        
        //--> Imprime os Nomes dos Cursos Lidos
        printf("Curso[%d]: %s\n", i, curso[i].nome);
    }
    
    //--> Informa o Sucesso ao importar todos os cursos
    printf("Sucesso!\n\n");
    
    //--> Fecha o Arquivo
    fclose(ifp);
    
    //--> Retorna Quantidade de Curso Lida
    return nCursos;
}
