int strfunc (char *st)
{
  char *pst = st;

  while (*pst)
    ++pst;

  return (pst - st);

}
/* Retorna o tamanho da string */
/* Pega o endereço de st (vetor, utilizando notação de ponteiro) e joga em pst
	Enquanto houver elementos referenciados em pst, incrementa pst */
