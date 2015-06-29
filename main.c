#include <stdio.h>
#include <string.h>

//includes das estruturas e funções
#include "estruturaDados_Prototipos.c"
#include "lerCurso.c"
#include "mediaCandidato_lerCandidato.c"
#include "inicializaLista.c"
#include "compare.c"
#include "ordenaLista.c"
#include "fazMatch.c"
#include "trocaEscolha.c"
#include "aprovadosCurso.c"
#include "aprovadosGrupo.c"
#include "aprovadosTodos.c"
#include "procuraCandidatos.c"
#include "menuResultados.c"

int main()
{
    //declarações de variaveis

    //nCursos:quantidade de cursos
    //nCandidatos: quantidade de candidatos
    //nMatch: quantidade de escolhas no vetor match
    //nSelecionados[CURSO][GRUPO]: quantidade de candidatos ja elecionados pra cada curso e grupo
    int nCursos, nCandidatos, nMatch, nSelecionados[MAX_CURSOS][5]={0};

    //VETORES
    tCurso curso[MAX_CURSOS];//vetor de cursos
    tCandidato candidato[MAX_CANDIDATOS];//vetor de candidatos
    tMatch match[MAX_MATCH]; //vetor de classificação dos candidatos - GERAL

    /**PROCESSO DE LEITURA DE DADOS DO ARQUIVO**/
    nCursos=lerCursos(curso);
    nCandidatos=lerCandidatos(candidato,curso);
    /**ORGANIZAÇÂO DE DADOS**/
    nMatch = inicializaLista(match,nSelecionados,candidato,nCandidatos,nCursos);
    ordenaLista(match,nMatch);
    /**MATCH**/
    fazMatch(match,nSelecionados,candidato,curso,nMatch);

    system("cls");//limpeza da tela

    /**OUTPUT DOS RESULTADOS**/
    menuResultados(match, nMatch, candidato, nCandidatos, curso,nCursos);

    return 0;
}
