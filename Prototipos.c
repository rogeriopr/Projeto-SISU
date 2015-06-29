// Nomes:
// - Bruna Zamith Santos (RA: 628093)
// - Caio Augusto Silva (RA: 628280)
// - Felipe Akira Kimura Gama (RA: 628115)
// - Iuri Bonna Mauricio de Abreu (RA: 628158)
// - Leonardo Tavares Oliveira (RA: 628174)

/*
   Nome da função: lerCursos
   Objetivos: Ler dados dos cursos do arquivo
   Parâmetros Formais:
       -curso[]: Vetor de tCurso (saída)
   Retorno: Número de cursos lidos (int)
*/  
int lerCursos(tCurso curso[]);

/*
   Nome da função: mediaCandidato
   Objetivos: Calcular a media dos candidatos
   Parâmetros Formais:
       - i: ID do candidato (int)
       -opcao: Opção de curso escolhida (int)
   Retorno: Média das notas do candidato (double)
*/ 
double mediaCandidato(int i, int opcao);

/*
   Nome da função: lerCandidatos
   Objetivos: Ler dados dos candidatos do arquivo
   Parâmetros Formais:
       -candidato[]: Vetor de tCandidato (saída)
   Retorno: Número de candidatos lidos (int)
*/
int lerCandidatos(tCandidato candidato[]);

/*
   Nome da função: leitura  
   Objetivos: Chamar as funções de leitura de cursos e candidatos
   Parâmetros Formais:
       -Nenhum
   Retorno: Nenhum (procedimento)
*/ 
void leitura();

/*
   Nome da função: inicializaLista
   Objetivos: Inicializar o vetor lista[] e preencher com os dados dos candidatos
   Parâmetros Formais:
       -lista[] (tLista): Vetor de escolha de cursos
       -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já  
        alocados para cada curso e grupo
       -candidato[] (tCandidato): Vetor de candidatos
      -nCandidatos (int): Quantidade de candidatos cadastrados
   Retorno: Quantidade de escolhas de curso em lista[] (int)
*/
int inicializaLista(tLista lista[], int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],int nCandidatos);

/*
   Nome da função: compare  
   Objetivos: Implementar o quickSort entre candidatos
   Parâmetros Formais:
       - elem1: Primeiro aluno(entrada)
       - elem2: Segundo aluno(entrada)
   Retorno: 1 se a nota de elem1 for maior, -1 se for menor ou 0 se forem iguais
*/ 
int compare(tLista *elem1, tLista *elem2);

/*
   Nome da função: ordenaLista   
   Objetivos: Ordenar a lista de escolhas de curso de acordo com a media
   Parâmetros Formais:
       -lista[]: Vetor de escolha de cursos
       -nLista: Número de candidatos na lista
   Retorno: Nenhum (procedimento)
*/ 
void ordenaLista(tLista lista[],int nLista);

/*
   Nome da função: fazMatch
   Objetivos: Faz o match de cada candidato para o curso escolhido
   Parametros Formais:
       -lista[] (tLista): Vetor de escolha de cursos ordenado pela nota
       -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já 
         alocados para cada curso e grupo
       -candidato[] (tCandidato): Vetor de candidatos
       -curso[] (tCurso): Vetor de cursos
       -nLista (int): Quantidade de escolhas de curso em lista[]
   Retorno: Nenhum (procedimento)
*/
void fazMatch(tLista lista[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[],int nLista);

/*
   Nome da função: trocaEscolha
   Objetivos: Função chamada na fazMatch quando um candidato que ja havia 
   passado em sua 2º opção, passa na 1º opção, a fim de reoferecer a vaga.
   Parametros Formais:
        -id: ID do candidato(int)
        -pos: posição atual do contador de laço na função anterior(determina até que ponto a 
          busca para o reoferecimento da vaga deve ocorrer)(int)
        -lista[]: Vetor contendo os aprovados
        -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já 
          alocados para cada curso e grupo
        -candidato[]: vetor de candidatos
        -curso[]: vetor de cursos
   Retorno: Nenhum (procedimento)
*/
void trocaEscolha(int id, int pos,tLista lista[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[]);

/*
   Nome da função: calculo  
   Objetivos: Chamar todas as funções para calcular o resultado
   Parâmetros Formais:
       -Nenhum
   Retorno: Nenhum (procedimento)
*/ 
void calculo();

/*
   Nome da função: aprovadosTodos
   Objetivos: Imprimir todos os aprovados
   Parâmetros Formais:
       -lista[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nLista: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosTodos(tLista lista[],tCandidato candidato[],tCurso curso[],int nLista);

/*
   Nome da função: aprovadosCurso
   Objetivos: Imprimir os aprovados separados por cursos
   Parâmetros Formais:
       -lista[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nLista: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosCurso(tLista lista[],tCandidato candidato[],tCurso curso[],int nLista);

/*
   Nome da função: aprovadosGrupo 
   Objetivos: Imprimir os aprovados separados por grupos
   Parâmetros Formais:
       -lista[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nLista: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosGrupo(tLista lista[],tCandidato candidato[],tCurso curso[],int nLista);

/*
   Nome da função: impressaoResultados  
   Objetivos: Imprimir resultados obtidos com o match
   Parâmetros Formais:
       -Nenhum
   Retorno: Nenhum (procedimento)
*/  
void impressaoResultados();
