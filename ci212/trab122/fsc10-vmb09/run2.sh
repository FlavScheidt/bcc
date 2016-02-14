#!/bin/bash

## ------------------------------------------------------------------------
## UFPR, BCC, ci212 2012-2 trabalho semestral, autor: Roberto Hexsel, 24jan
## ------------------------------------------------------------------------

## ESTE ARQUIVO NAO PODE SER ALTERADO


# set -x

# se passar um argumento para script, executa gtkwave
if [ $# = 1 ] ; then WAVE="sim"
else WAVE=
fi

src="packageWires aux filtro tb_filtro"
sim=filtro
simulador=tb_${sim}
visual=v_${sim}.vcd


# compila simulador
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
rm -f log.txt
ghdl --clean
for F in ${src} ; do
    ghdl -a --ieee=standard -fexplicit ${F}.vhd 2>>log.txt || cat log.txt
done

if [[ $? == 0 ]]; then
    ghdl -e --ieee=standard -fexplicit ${simulador} 2>>log.txt || cat log.txt
    if [[ $? == 0 ]] && [ -x ./${simulador} ] ; then
	./${simulador} --ieee-asserts=disable --stop-time=4us \
            --vcd=${visual}
        # executa gtkwave sob demanda
	test -z $WAVE  ||  gtkwave -O /dev/null ${visual} v.sav 
    else
	cat log.txt
    fi
else
    cat log.txt
fi

