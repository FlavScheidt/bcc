#!/usr/bin/env Python
# coding: utf-8
class Pessoa(object):
	def __init__(self, nome=" ", idade=0):
		self.nome = nome
		self.idade = idade
	def apresente_se(self):
		print 'Olá, meu nome é', +self.nome, 'e minha idade é', self.idade

p1 = Pessoa('Fulano', 25)
p2 = Pessoa()

p1.apresente_se()
p2.apresente_se()
