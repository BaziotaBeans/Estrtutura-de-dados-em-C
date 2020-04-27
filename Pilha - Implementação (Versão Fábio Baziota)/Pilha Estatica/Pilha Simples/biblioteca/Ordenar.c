int ordenarCrescenteChave (TListaLigadaSimples *lista)
{
	if (vazia (*lista)) return LISTA_VAZIA;
	for (TAtomo *percorrer = lista->primeiro->proximo, *anterior = lista->primeiro; percorrer != NULL; anterior = percorrer, percorrer = percorrer->proximo)
	{
		if (lista->primeiro->info.chave > percorrer->info.chave)
		{
			anterior->proximo = percorrer->proximo;
			percorrer->proximo = lista->primeiro;
			lista->primeiro = percorrer;
		}
		if (percorrer->proximo == NULL) lista->ultimo = percorrer;
	}
	return OPERACAO_EFECTUADA;
}