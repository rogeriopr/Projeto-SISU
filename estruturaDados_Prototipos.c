#include <stdio.h>
#include <string.h>

#define TAM_NOME 100
#define MAX_CURSOS 100
#define MAX_CANDIDATOS 5000
#define MAX_MATCH 10000
#define N_GRUPOS 5

//ARQUIVOS
#define CURSOS_FILE "cursos.txt"
#define CANDIDATOS_FILE "candidatos.txt"
#define OUTPUT_TODOS_FILE "aprovados_todos.csv"
#define OUTPUT_CURSO_FILE "aprovados_por_curso.csv"
#define OUTPUT_CURSO_GRUPOS_FILE "aprovados_por_curso_grupos.csv"

/***Estutura de Dados***/
// tNotas: referente as notas de cada candidato
// USADA EM tCandidato
typedef struct {
    double redacao;     // Referente a nota do candidato na prova de redação
    double linguagens;  // Referente a nota do candidato na prova de Linguagens, Códigos e suas tecnologias
    double matematica;  // Referente a nota do candidato na prova de Matemática e suas tecnologias
    double natureza;    // Referente a nota do candidato na prova de Ciências da Natureza e suas tecnologias
    double humanas;     // Referente a nota do candidato na prova de Ciências Humanas e suas tecnologias
} tNotas;

// tCurso: referente a cada curso
typedef struct {
    char nome[TAM_NOME];      // Nome do curso
    int vagas[N_GRUPOS+1];             // Total de vagas disponibilizadas
    tNotas pesos;             // Armazena os pesos de cada prova
} tCurso;

// tInscricao: referente a inscrição de cada candidato
typedef struct {
    int idCurso;         // Armazena o ID do curso que o candidato colocou na opção - -1 significa que nao quer usar a opçao (somente valido para 2 opcao)
    int grupo;           // Referente ao grupo que o candidato se inscreveu
    double media;      // Nota média
} tInscricao;

// tCandidato: referente a cada candidato
typedef struct {
    char nome[TAM_NOME];    // Nome do candidato
    tNotas notas;           // Referente as notas das provas do candidato
    tInscricao opcao1;
    tInscricao opcao2;
    int classificado; //-2 = classificado na 1 opcao | -1 = Nao classificado | numeros positivos = id do curso classificado na 2 opcao
} tCandidato;

// tMatch
typedef struct {
    int idCandidato; //id candidato
    int idCurso;
    double media;
    int opcao;
    int grupo;
    int classificado;
} tMatch;

typedef int (*compfn)(const void*, const void*);

// tMatch
typedef struct {
    int idCandidato; //id candidato
    int idCurso; //id do curso
    double media;
    int opcao; //1 opcao ou 2 opcao
    int grupo; //cota
    int classificado; //0 ou 1
} tMatch;

typedef int (*compfn)(const void*, const void*);

//PROTOTIPOS
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
   Nome da função: inicializaLista
   Objetivos: Inicializar o vetor match[] e preencher com os dados dos candidatos
   Parâmetros Formais:
       -match[] (tMatch): Vetor de escolha de cursos
       -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já  
        alocados para cada curso e grupo
       -candidato[] (tCandidato): Vetor de candidatos
      -nCandidatos (int): Quantidade de candidatos cadastrados
   Retorno: Quantidade de escolhas de curso em match[] (int)
*/
int inicializaLista(tMatch match[], int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],int nCandidatos);

/*
   Nome da função: compare  
   Objetivos: Implementar o quickSort entre candidatos
   Parâmetros Formais:
       - elem1: Primeiro aluno(entrada)
       - elem2: Segundo aluno(entrada)
   Retorno: 1 se a nota de elem1 for maior, -1 se for menor ou 0 se forem iguais
*/
int compare(tMatch *elem1, tMatch *elem2);

/*
   Nome da função: ordenaLista   
   Objetivos: Ordenar a lista de escolhas de curso de acordo com a media
   Parâmetros Formais:
       -match[]: Vetor de escolha de cursos
       -nMatch: Número de candidatos na lista
   Retorno: Nenhum (procedimento)
*/
void ordenaLista(tMatch match[],int nMatch);

/*
   Nome da função: fazMatch
   Objetivos: Faz o match de cada candidato para o curso escolhido
   Parametros Formais:
       -match[] (tMatch): Vetor de escolha de cursos ordenado pela nota
       -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já
         alocados para cada curso e grupo
       -candidato[] (tCandidato): Vetor de candidatos
       -curso[] (tCurso): Vetor de cursos
       -nMatch (int): Quantidade de escolhas de curso em match[]
   Retorno: Nenhum (procedimento)
*/
void fazMatch(tMatch match[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[],int nMatch);

/*
   Nome da função: trocaEscolha
   Objetivos: Função chamada na fazMatch quando um candidato que ja havia
   passado em sua 2º opção, passa na 1º opção, a fim de reoferecer a vaga.
   Parametros Formais:
        -id: ID do candidato(int)
        -pos: posição atual do contador de laço na função anterior(determina até que ponto a
          busca para o reoferecimento da vaga deve ocorrer)(int)
        -match[]: Vetor contendo os aprovados
        -nSelecionados[MAX_CURSOS][5] (int): matriz contendo a quantidade de candidatos já
          alocados para cada curso e grupo
        -candidato[]: vetor de candidatos
        -curso[]: vetor de cursos
   Retorno: Nenhum (procedimento)
*/
void trocaEscolha(int id, int pos,tMatch match[],int nSelecionados[MAX_CURSOS][5],tCandidato candidato[],tCurso curso[]);

/*
   Nome da função: aprovadosTodos
   Objetivos: Imprimir todos os aprovados
   Parâmetros Formais:
       -match[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nMatch: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosTodos(tMatch match[],tCandidato candidato[],tCurso curso[],int nMatch);

/*
   Nome da função: aprovadosCurso
   Objetivos: Imprimir os aprovados separados por cursos
   Parâmetros Formais:
       -match[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nMatch: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosCurso(tMatch match[],tCandidato candidato[],tCurso curso[],int nMatch);

/*
   Nome da função: aprovadosGrupo
   Objetivos: Imprimir os aprovados separados por grupos
   Parâmetros Formais:
       -match[]: Vetor com os aprovados (entrada)
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
       -nMatch: Número de aprovados (entrada)
   Retorno: Nenhum (procedimento)
*/
void aprovadosGrupo(tMatch match[],tCandidato candidato[],tCurso curso[],int nMatch);

/*
   Nome da função: procuraCandidatos
   Objetivos: imprime os resultados de um candidato especifico
   Parâmetros Formais:
       -candidato[]: Vetor com os dados dos candidatos (entrada)
       -nCandidatos: Int com a quantidade de candidatos (entrada)
       -curso[]: Vetor com os dados dos cursos (entrada)
   Retorno: Nenhum (procedimento)
*/
void procuraCandidatos(tCandidato candidato[],int nCandidatos,tCurso curso[]);

/*
   Nome da função: menuResultados  
   Objetivos: Imprimir resultados obtidos com o match
   Parâmetros Formais:
       -Nenhum
   Retorno: Nenhum (procedimento)
*/  
void menuResultados();
