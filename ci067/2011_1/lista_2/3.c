/*************************
	Reescreva as funções strcmp_1() e strcmp_2() (clique aqui) usando APENAS ponteiros. Otimize sua solução ao máximo. 
*************************/
/*************************
	Flaviene Scheidt de Cristo
	FSC10
	GRR20101915
*************************/
int strcmp_1(char *str1, char *str2) {
	int resp;
	while ( *str1 == *str2 && *str1 && *str2 ) {
		*str1 ++;
		*str2 ++;
		resp = 0;
	}
		if ( *str1 != *str2 ) {
			if ( *str1 > *str2 )
				resp = 1;
			else
				resp = -1;
		}
	return (resp);
}
int strcmp_2(char *str1, char *str2) {
	int resp;
	do resp = *str1 - *str2;
	} while ( !resp && *str1 & *str2 ++ );
	return (resp);
}
