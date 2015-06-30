void procuraCandidatos(tCandidato candidato[],int nCandidatos,tCurso curso[])
{
    char nome[TAM_NOME];
    int i,k=0;

    printf("Nome do Candidato: ");
    fflush(stdin);
    gets(nome);

    for(i=0;i<nCandidatos;i++) {
        if(strstr(candidato[i].nome,nome)!=NULL) { // Compara o nome do teclado com os nomes dos candidatos dentro do vetor candidato.
					        // Requer a biblioteca <string.h>.
            k++;
            printf("ID: %d\nNome: %s\n",i,candidato[i].nome);
            printf("1. Opcao:\nCurso: %s\nGrupo: %d\nNota: %.2Lf\n",curso[candidato[i].opcao1.idCurso].nome,candidato[i].opcao1.grupo,candidato[i].opcao1.media);
            if(candidato[i].classificado == -2) {
                printf("Candidato aprovado na 1. Opcao\n");
            }else{
                printf("Candidato não aprovado na 1. Opcao\n");
            }
            printf("\n2. Opcao:\nCurso: %s\nGrupo: %d\nNota: %.2Lf\n",curso[candidato[i].opcao2.idCurso].nome,candidato[i].opcao2.grupo,candidato[i].opcao2.media);
            if(candidato[i].classificado >=0) {
                printf("Candidato aprovado na 2. Opcao\n");
            }
            else if (candidato[i].classificado == -1)
            {
                printf("Candidato nao aprovado na 2. Opcao\n");
            }
            printf("\n");
        }
    }

    if(k==0)
        printf("Nenhum Candidato com esse nome encontrado.\n");
}
