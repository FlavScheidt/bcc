#!/usr/bin/env python
#-.- coding: utf-8 -*-
mult=100
def calcula_moedas(valor, moedas=[1, 0.5, 0.25, 0.1, 0.05, 0.01]):
	valor = valor*mult
	num_moedas = 0
	for i in moedas:
		i= int(i*mult)
		while valor>=i:	
			num_moedas+= valor/i
			valor = valor%i
	
	return int(num_moedas)


valor = raw_input ('valor: ')
moedas = raw_input ('moedas: ')

if moedas:
	moedas = map(float, moedas.split(', '))
	moedas.sort(reverse=True)
	resultado = calcula_moedas (float(valor),moedas)
else:
	resultado = calcula_moedas (float(valor))

print resultado
