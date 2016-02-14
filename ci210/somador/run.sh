#!/bin/bash

# set -x

# se passar argumento para script, executa gtkwave
if [ $# = 1 ] ; then WAVE="sim"
else WAVE=
fi

src=adder
out=adder

ghdl --clean

ghdl -a --ieee=synopsys -fexplicit ${src}.vhd 2> log.txt || cat log.txt
if [[ $? == 0 ]]; then
  ghdl -a --ieee=synopsys -fexplicit tb_${src}.vhd 2>> log.txt || cat log.txt
  if [[ $? == 0 ]]; then
    ghdl -e --ieee=synopsys -fexplicit tb_${src} 2>> log.txt || cat log.txt
    if [[ $? == 0 ]]; then
      ./tb_${src} --stop-time=40000ns --vcd=v${out}.vcd 2>> log.txt
      # executa gtkwave sob demanda
      test -z $WAVE  ||  gtkwave -O /dev/null v${out}.vcd g.sav
    else
      cat log.txt
    fi
  else
    cat log.txt
  fi
else
  cat log.txt
fi

egrep -v -i warning log.txt
