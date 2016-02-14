From fhbz10@inf.ufpr.br  Wed Jun 16 21:03:30 2010
Return-Path: <fhbz10@inf.ufpr.br>
X-Spam-Checker-Version: SpamAssassin 3.3.1 (2010-03-16) on urquell.c3sl.ufpr.br
X-Spam-Level: 
X-Spam-Status: No, score=-1.9 required=5.0 tests=BAYES_00 autolearn=ham
	version=3.3.1
X-Original-To: luciano@inf.ufpr.br
Delivered-To: luciano@inf.ufpr.br
Received: from webmail.inf.ufpr.br (cognac.c3sl.ufpr.br [200.17.202.24])
	by urquell.c3sl.ufpr.br (Postfix) with ESMTP id 413EA20006FCB
	for <luciano@inf.ufpr.br>; Wed, 16 Jun 2010 21:03:30 -0300 (BRT)
Received: from 201.86.30.16
        (SquirrelMail authenticated user fhbz10)
        by webmail.inf.ufpr.br with HTTP;
        Wed, 16 Jun 2010 21:03:27 -0300
Message-ID: <b25a3b513a630942336ca3876a5b70f4.squirrel@webmail.inf.ufpr.br>
In-Reply-To: <20100615011524.GI1495@inf.ufpr.br>
References: <c7006753fd8117f42ff4ce5969f747c5.squirrel@webmail.inf.ufpr.br>
    <20100615011524.GI1495@inf.ufpr.br>
Date: Wed, 16 Jun 2010 21:03:27 -0300
Subject: Re: Resolvedor de campo minado
From: fhbz10@inf.ufpr.br
To: "Luciano Silva" <luciano@inf.ufpr.br>
User-Agent: SquirrelMail/1.4.20
MIME-Version: 1.0
Content-Type: text/plain;charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Priority: 3 (Normal)
Importance: Normal
Status: RO
Content-Length: 3045
Lines: 93

> Precisava escrever em pascal... parece que o seu trabalho 1 tambem ta em
> py. Veja se resolve isso ate o final da semana com
> um arquivo com instrucoes para compilar e rodar os programas. Vou ter
> que adaptar os scripts de avaliacao caso rode com .py
>
> []s
> Luciano

Achei que não teria problema pois o enunciado do trabalho não falava
nada de linguagem, tava afim de dar uma treinada e acabei fazendo assim
mesmo.
Não entendi muito bem o que quis dizer, quer que eu reescreva mesmo ou só
faça um manualzinho?
Bom, caso for a segunda opção:

Como python é interpretado, eu deixei os arquivos prontos para serem
executados, só dar um chmod +x ou chamar com o python:
(Foram desenvolvidos para rodar com a versão do python da federal, 2.5,
mas roda no 2.6, só não roda no 3.0)

Gerador:
./generator.py TAMANHO MINAS
ou
python generator.py TAMANHO MINAS
Exemplo:
./generator.py 8 10
Gera um campo com 8x8 com 10 minas e cospe a saída no stdout, fica mais
prático porque eu posso rodar: ./generator.py 8 10 | ./solver.py

Para mandar para um arquivo é só redirecionar a saída, por exemplo:
./generator 8 10 > campo.txt

Resolvedor:
./solver.py < campo.txt
ou
python solver.py < campo.txt

Assim ele vai resolver o campo e dizer quantos movimentos usou, quantos
chutes, se ganhou...
Se quiser ver todas as jogadas, pode rodar com -v, como em:
./solver.py -v < field00569.txt
ou
./generator.py 8 10 | ./solver.py -v

Deixei o -v porque quando rodei com 10 mil campos gerados a saída ficava
imensa, provavelmente vai te ser útil rodar sem também.

E eis aqui o scriptzinho que fiz para rodar os dez mil
cd fields
for i in *
do
        ../solver.py < $i
done

Eu estava rodando o script assim:
./rodacampos > cases.txt

Para que eu pudesse analizar os resultados depois.

Campos de tamanho aleatório e quantidade de bombas até 50% do campo,
gerados com outro scriptzinho chamando o generator.

O problema é que meus campos são todos começando a contar as coordenadas a
partir do zero. Eu modifiquei antes de entregar e esta funcionando a
partir do 1, mas praticamente joguei fora os dez mil


O seguinte comando releva que ganhei 27,43% dos jogos:
fhbz10@macalan:~/python$ cat cases.txt | grep won | wc -l
2743

E o seguinte, quantos jogos ganhei usando movimento complexo:

fhbz10@macalan:~/python$ cat cases.txt | grep -B 1 "[123456789][0-9]*
complex" | grep won | wc -l
62

Só com jogadas simples e chute simples consegue-se 26,xx% em média, o
melhor que vi conseguiu 28,8% nos meus campos.

E, finalmente, o jogo mesmo se roda igual ao gerador.
./campominado.py TAMANHO MINAS

E se for rodar numa fornada enorme de campos, é bem provável que demore,
python é um tartaruga, os resultados são, praticamente, instantâneos para
um campo, mas com dez mil demora quase duas horas. Pior ainda se camparado
às versões em pascal, que, mesmo com um resolvedor complexo, não demoram
nem 10 minutos com essa quantidade.

Acho que cobri tudo, mas qualquer problema eu reescrevo até o fim de semana.
Abraços,

Flávio

