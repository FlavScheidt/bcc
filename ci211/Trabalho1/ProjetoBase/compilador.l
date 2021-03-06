%{


#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"

//#define IMPRIME(STR) {};
#define IMPRIME(STR) printf("%s    # %s \n", STR, token);

int nl = 1;  

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zAZ][a-zAZ1-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;} 

{descarte}

{comentario}

program { simbolo  = simb_program;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program ");
          return PROGRAM;
 }

var      { simbolo = simb_var;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var  ");
          return VAR;
 }

begin { simbolo = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin ");
          return T_BEGIN;
 }

end { simbolo = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end  ");
          return T_END;
 }

procedure {	simbolo = simb_proc;
		strncpy(token, yytext, TAM_TOKEN);
		IMPRIME(" procedure ");
		return PROCEDURE;
}

function {	simbolo = simb_func;
		strncpy(token, yytext, TAM_TOKEN);
		IMPRIME(" function ");
		return FUNCTION;
}

while {	simbolo = simb_while;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" while ");
	return WHILE;
}

do    {	simbolo = simb_do;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" do ");
	return DO;
}

if    {	simbolo = simb_if;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" if ");
	return IF;
}

then  {	simbolo = simb_then;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" then ");
	return THEN;
}

else  {	simbolo = simb_else;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" else ");
	return ELSE;
}

label { 
	simbolo = simb_label;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME("label ");
	return LABEL;
}

integer {
	simbolo = simb_integer;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" integer ");
	return INTEGER;
}

:= { simbolo = simb_atribuicao;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" atribuicao  ");
          return ATRIBUICAO;  
 }

\; { simbolo = simb_ponto_e_virgula;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" pt_virgula  ");
          return PONTO_E_VIRGULA;
 }

\: { simbolo = simb_dois_pontos;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" dois pontos ");
          return DOIS_PONTOS;
 }

\, { simbolo = simb_virgula;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" virgula  ");
          return VIRGULA;
 }


\. { simbolo = simb_ponto;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ponto  ");
          return PONTO; 
    }

\(  { simbolo = simb_abre_parenteses;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_parenteses  ");
          return ABRE_PARENTESES;
    }

\)  { simbolo = simb_fecha_parenteses;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_parenteses ");
          return FECHA_PARENTESES;
 }

\+  { 	simbolo = simb_mais;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" mais ");
	return MAIS;
}

\-  {	simbolo = simb_menos;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" menos ");
	return MENOS;
}

\<  { 	simbolo = simb_menor;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" menor ");
	return MENOR;
}

\>  {	simbolo = simb_maior;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" maior ");
	return MAIOR;
}

\<= {	simbolo = simb_menor_igual;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" menor igual ");
	return MENOR_IGUAL;
}

\>= {	simbolo = simb_maior_igual;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" maior igual ");
	return MAIOR_IGUAL;
}

\*  {	simbolo = simb_mult;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" multiplicacao ");
	return MULT;
}

div {	simbolo = simb_div;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" divisão ");
	return DIV;
}

\=  { 	simbolo = simb_igual;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" igual ");
	return IGUAL;
}

\!= {	simbolo = simb_diff;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" diff ");
	return DIFF;
}

and {	simbolo = simb_and;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" and ");
	return AND;
}

or {	simbolo = simb_or;
	strncpy(token, yytext, TAM_TOKEN);
	IMPRIME(" or ");
	return OR;
}
	
{ident} { simbolo = simb_identificador; 
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ident  ");
          return IDENT;
        }

{numero} { 	simbolo = simb_numero; 
          	strncpy (token, yytext, TAM_TOKEN);
	        IMPRIME(" numero  ");
		return NUMERO;
}

%%

