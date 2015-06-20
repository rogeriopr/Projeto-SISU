/* ----- ESTRUTURA DE DADOS PROJETO SISU - CAP -----
Autores: Leonardo Utida - 628182
         Rodolfo Asbahr - 628042
         Tiago Marto    - 628522
         Túlio Reis     - 628050

--- CHANGELOG
- 0.1 - estrutura de dados inicial, primitiva e rascunhada
- 0.2 - retirada da tUniversidade
- 0.3 - remoção de valores irrelevantes para as funções básicas (presentes na versão 0.2)
- 0.4 - inserção dos menus enumerados
- 0.5 - inserção dos protótipos de funções de leitura
- 0.6 - inserção dos protótipos de funções de validação e de busca
- 0.7 - tipo enumerado como parâmetro
*/

#include <stdio.h>
#define MAX_NOME 64     // Todos os chars que caracterizam nomes tem no máximo 64 caracteres
#define MAX_VETOR 128   // Os vetores principais manipulados no código tem no máximo 128 posições

/// ----------------------------------------------------------------------------------------
/// Desenvolvimento das tipagens utilizadas para entrada e saída de dados
// tCurso: referente a cada curso
typedef struct {
    int id;                 // ID de cada curso
    char nome[MAX_NOME];    // Nome do curso
    tVaga vagas;            // Total de vagas disponibilizadas
    char universidade[MAX_VETOR][MAX_NOME];   // Vetor de quais as universidades que possuem esse curso
} tCurso;


// tCandidato: referente a cada candidato
typedef struct {
    int numeroInsc;         // Referente ao número de inscrição do candidato
    char nome[MAX_NOME];    // Nome do candidato
    tData dataNasc;         // Data de nascimento do candidato
    tEndereco endereco;     // Endereço do candidato
    char cpf[15];           // CPF do candidato
    char rg[15];            // RG do candidato
    int sexo;               // Código de Sexo do candidato; enum menuDeclara
    char nomeMae[MAX_NOME]; // Nome da mãe do candidato.

    int autodeclaracao;     // 1 - Branco; 2 - Pardo; 3 - Negro; 4 - Indígena; (...)
    tNotas notas;           // Referente as notas das provas do candidato
    int formacaoMedio;          // 1 - Público; 2 - Privado; 3 - Parte privado com bolsa; 4 - Parte privado sem bolsa; (...)
    int classificado;           // 1 - Aprovado na vaga; 0 - Não aprovado; Imita tipo boolean

    int inscricao1;         // Armazena o ID do curso que o candidato colocou na primeira opção
    int inscricao2;         // Armazena o ID do curso que o candidato colocou na segunda opção
} tCandidato;


// tData: referente toda e qualquer data usada no código
// USADA EM tCandidato
typedef struct {
    int dia;
    int mes;
    int ano;
} tData;


// tEndereco: referente a todo e qualquer endereço usado no código
// USADA EM tCandidato
typedef struct {
    char logradouro[MAX_NOME];  // Descrição raiz do endereço (Exemplo: Avenida São Carlos, 2160)
    char bairro[MAX_NOME];      // Nome do bairro do endereço descrito (Exemplo: Centro)
    char cidade[MAX_NOME];      // Nome da cidade (Exemplo: São Carlos)
    char UF[3];                 // Unidade Federativa (Exemplo: SP)
    char CEP[10];               // CEP do endereço descrito
} tEndereco;


// tNotas: referente as notas de cada candidato
// USADA EM tCandidato
typedef struct {
    double redacao;     // Referente a nota do candidato na prova de redação
    double linguagens;  // Referente a nota do candidato na prova de Linguagens, Códigos e suas tecnologias
    double matematica;  // Referente a nota do candidato na prova de Matemática e suas tecnologias
    double natureza;    // Referente a nota do candidato na prova de Ciências da Natureza e suas tecnologias
    double humanas;     // Referente a nota do candidato na prova de Ciências Humanas e suas tecnologias
    double media;       // Média aritmética das 5 notas do aluno (usada em cursos sem pesos definidos nas provas)n
} tNotas;


// tVaga: referente as vagas de cada curso
// USADA EM tCurso
typedef struct {
    int total;      // Numero total de vagas que são disponibilizadas em um curso
    int grupo1;     // Cota: escola pública com renda inferior a 1,5 salário mínimo per capita
    int grupo2;     // Cota: pretos, pardos e indígenas com renda inferior a 1,5 salário mínimo per capita
    int grupo3;     // Cota: egressos de escola pública independente da renda
    int grupo4;     // Cota: pretos, pardos e indígenas independente da renda
    int grupo5;     // Ampla concorrência
} tVaga;









/// ----------------------------------------------------------------------------------------
/// Criação dos menus enumerados dos respectivos elementos
enum optSexo {
    Masculino = 1,
    Feminino
    };
//typedef enum optSexo menuSexo;

enum optDeclara {
    Branco = 1,
    Pardo,
    Negro,
    Indigena
    };
//typedef enum optDeclara menuDeclara;

enum optFormMedio {
    Publica = 1,
    Parte publica,
    Privada
    };
//typedef enum optFormMedio menuFormMedio;













/// ----------------------------------------------------------------------------------------
/// Criação dos protótipos de funções básicas
// FUNÇÕES DE INSERÇÃO
void getNome (char *nome[MAX_NOME]);    // Função útil para todas as entradas de nomes
void getUniversidade (char *nome[][MAX_NOME]);    // Leitura de nomes de universidades
void getData (tData *data);             // Leitura de datas
void getEndereco (tEndereco *endereco); // Leitura de endereços
void getCPF (char *cpf[15]);            // Leitura de CPF
void getRG (char *rg[15]);              // Leitura de RG
void getVagas (tVaga *vagas);

void getEnum (enum tipoDado, char *dado); /// "ENUM" PODE SER UM PARÂMETRO???
/* Objetivo: leitura de dados que são coletados por meio de menus enumerados
   Parametros:
        - tipoDado: menu enumerado a se consultar o número inserido pelo usuário
        - dado: elemento que recebe o valor correspondente à entrada do usuário no menu enumerado */


// FUNÇÕES DE VALIDAÇÃO
int validaData (tData data);
int validaCPF (char cpf[15]);
int validaRG (char rg[15]);


// FUNÇÕES DE BUSCA
// O usuário do Sisu pode realizar buscas por nome do curso, nome da universidade e por cidade
void buscaTermo(char vetorBusca[][MAX_NOME], int tamanhoVetor);
/* Objetivo: encontrar a cadeia de char em forma de substring inserida pelo usuário em um vetor. */

/// FUNÇÕES DE EDIÇÃO? DE REMOÇÃO?

/// ----------------------------------------------------------------------------------------
tCurso cursos[MAX_VETOR];
tCandidato concorrentes[MAX_VETOR];
