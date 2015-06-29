/* ----- ESTRUTURA DE DADOS PROJETO SISU - CAP ----- */

#include <stdio.h>
#define MAX_NOME 64     // Todos os chars que caracterizam nomes tem no máximo 64 caracteres
#define MAX_VETOR 128   // Os vetores principais manipulados no código tem no máximo 128 posições

/// ----------------------------------------------------------------------------------------
/// Desenvolvimento das tipagens utilizadas para entrada e saída de dados
// tNotas: referente as notas de cada candidato
// USADA EM tCandidato
typedef struct {
    double redacao;     // Referente a nota do candidato na prova de redação
    double linguagens;  // Referente a nota do candidato na prova de Linguagens, Códigos e suas tecnologias
    double matematica;  // Referente a nota do candidato na prova de Matemática e suas tecnologias
    double natureza;    // Referente a nota do candidato na prova de Ciências da Natureza e suas tecnologias
    double humanas;     // Referente a nota do candidato na prova de Ciências Humanas e suas tecnologias
} tNotas;


// tVaga: referente as vagas de cada curso
// USADA EM tCurso
typedef struct {
    int total;      // Numero total de vagas que são disponibilizadas em um curso
    int grupo1;     // Cota: pretos, pardos e indígenas com renda inferior a 1,5 salário mínimo per capita
    int grupo2;     // Cota: escola pública com renda inferior a 1,5 salário mínimo per capita
    int grupo3;     // Cota: pretos, pardos e indígenas independente da renda
    int grupo4;     // Cota: egressos de escola pública independente da renda
    int grupo5;     // Ampla concorrência
} tVaga;


// tCurso: referente a cada curso
typedef struct {
    int id;                   // ID de cada curso
    char nome[MAX_NOME];      // Nome do curso
    // char categoria[MAX_NOME]; // para busca por rea de cursos
    tVaga vagas;              // Total de vagas disponibilizadas
    tNotas pesos;             // Armazena os pesos de cada prova
    int aprovados[MAX_VETOR]; // Vetor que controla os aprovados no curso
} tCurso;


// tInscricao: referente a inscrição de cada candidato
typedef struct {
    int idCurso;         // Armazena o ID do curso que o candidato colocou na opção
    int grupo;           // Referente ao grupo que o candidato se inscreveu
    double media;      // Nota média
} tInscricao;


// tCandidato: referente a cada candidato
typedef struct {
    int numeroInsc;         // Referente ao número de inscrição do candidato
    char nome[MAX_NOME];    // Nome do candidato
    tNotas notas;           // Referente as notas das provas do candidato
    tInscricao opcao1;
    tInscricao opcao2;
    int classificado;           // 1 - Aprovado na vaga; 0 - Não aprovado; Imita tipo boolean
} tCandidato;



/// ----------------------------------------------------------------------------------------
/// Criação dos protótipos de funções básicas
// FUNÇÕES DE INSERÇÃO
void getNome (char *nome[MAX_NOME]);    // Função útil para todas as entradas de nomes
void getUniversidade (char *nome[][MAX_NOME]);    // Leitura de nomes de universidades
void getCPF (char *cpf[15]);            // Leitura de CPF
void getVagas (tVaga *vagas);


// FUNÇÕES DE BUSCA
// O usuário do Sisu pode realizar buscas por nome do curso, nome da universidade e por cidade
void buscaTermo(char vetorBusca[][MAX_NOME], int tamanhoVetor);
/* Objetivo: encontrar a cadeia de char em forma de substring inserida pelo usuário em um vetor. */


/// ----------------------------------------------------------------------------------------
tCurso cursos[MAX_VETOR];
tCandidato concorrentes[MAX_VETOR];
// tem que ter estruturas de dados para o processamento intermedirio dos candidato
// tem que ter estruturas de dados para armazenar os candidatos aprovados por curso
