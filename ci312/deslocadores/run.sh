#!/bin/bash

## ------------------------------------------------------------------------
## UFPR, BCC, ci210 2013-1 trabalho semestral, autor: Roberto Hexsel, 01jul
## ------------------------------------------------------------------------

## ESTE ARQUIVO NAO PODE SER ALTERADO


# set -x

# se passar um argumento para script, executa gtkwave
if [ $# = 1 ] ; then WAVE="sim"
else WAVE=
fi

sim=deslocador
src="packageWires aux ${sim} tb_${sim}"
simulador=tb_${sim}
visual=v_${sim}.vcd


ghdl --clean
rm -rf log.txt $simulador $visual

# compila simulador
for F in ${src} ; do
    ghdl -a --ieee=standard -fexplicit ${F}.vhd 2>>log.txt || cat log.txt
done

if [[ $? == 0 ]]; then
    ghdl -e --ieee=standard -fexplicit ${simulador} 2>>log.txt || cat log.txt
    if [[ $? == 0 ]] && [ -x ./${simulador} ] ; then
	./${simulador} --ieee-asserts=disable --stop-time=80us \
            --vcd=${visual}
        # executa gtkwave sob demanda
	test -z $WAVE  ||  gtkwave -O /dev/null ${visual} v.sav 
    else
	cat log.txt
    fi
else
    cat log.txt
fi

