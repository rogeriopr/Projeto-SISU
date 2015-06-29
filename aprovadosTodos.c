#include <stdio.h>
#include <string.h>

#define TAM_NOME 100
#define MAX_CURSOS 100
#define MAX_CANDIDATOS 1000
#define MAX_MATCH 2000
#define N_GRUPOS 5

//arquivos
#define OUTPUT_TODOS_FILE "aprovados_todos.csv"

/***Estutura de Dados com Algumas modificações***/

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
    int vagas[6];             // Total de vagas disponibilizadas
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
    int idCurso; //id do curso
    double media;
    int opcao; //1 opcao ou 2 opcao
    int grupo; //cota
    int classificado; //0 ou 1
} tMatch;

int (*compfn)(const void*, const void*);


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
void aprovadosTodos(tMatch match[],tCandidato candidato[],tCurso curso[],int nMatch)
{
    int i,j=1;					//Variáveis para controle de laço
    FILE *ifp;
    char *mode = "w+";			//Cria arquivo vazio para leitura e escrita

    ifp = fopen(OUTPUT_TODOS_FILE, mode);	// OUTPUT_TODOS_FILE = aprovados_todos.csv

    if (ifp == NULL) {						
        exit(1);
    }

	//Impressão dos dados
	
    printf("Classificados:\n\n");								//imprime na tela
    fprintf(ifp,"Posicao;Nome;Curso;Opcao;Grupo;Media\n");		//imprime no arquivo
    for(i=0;i<nMatch;i++)
    {
        if(match[i].classificado==1)
        {
        	//imrpime na tela:
            printf("%3d. %10s%25s Opcao: %d Grupo: %d Media: %.2Lf\n",j,candidato[match[i].idCandidato].nome,curso[match[i].idCurso].nome,match[i].opcao,match[i].grupo,match[i].media);
            //imprime no arquivo:
            fprintf(ifp,"%d;%s;%s;%d;%d;%.2Lf\n",j++,candidato[match[i].idCandidato].nome,curso[match[i].idCurso].nome,match[i].opcao,match[i].grupo,match[i].media);
        }
    }
    fclose(ifp);
}
