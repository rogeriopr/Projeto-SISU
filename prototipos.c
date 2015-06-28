/*Objetivo: Ler os dados do aluno
Parametros:
    - Aluno : struct tipo tAluno (parametro de entrada)
Valor de retorno: nenhum */
void lerDados (tAluno aluno);

/*Objetivo: Calcular a media de cada aluno
Parametros:
    - Aluno : struct tipo tAluno (parametro de entrada)
Valor de retorno:
    - Media : media de cada aluno*/
double calcularMedia (tAluno aluno);

/*Objetivo: Ordena decrescentemente a lista de alunos pela media
Parametros:
    - Aluno : struct tipo tAluno (parametro de entrada)
Valor de retorno: nenhum */
void ordenarLista (tAluno aluno);

/*Objetivo: Separa os alunos pela escolha dos cursos, campus e politicas afirmativas
Parametros:
    - Aluno : struct tipo tAluno (parametro de entrada)
Valor de retorno: nenhum */
void separarPorEscolha (tAluno aluno);

/*Objetivo: Ler os dados do aluno
Parametros:
    - Aluno : struct tipo tAluno (parametro de entrada)
Valor de retorno: nenhum */
void filtarSegundaOpcao (tAluno aluno);

/*Objetivo: Exibe os alunos que foram aprovados
Parametros:
    - Cursos : struct tipo tCurso (parametro de entrada)
Valor de retorno: nenhum */
void listaAprovados (tCurso cursos);
