void ordenaLista(tMatch match[],int nMatch){
    int i; //contador de laço
    printf("Ordenando Lista...\n");
    /*Ordenação da lista pelo algoritmo qsort*/
    qsort((void *) &match[0], nMatch, sizeof(tMatch),(compfn)compare );
}
