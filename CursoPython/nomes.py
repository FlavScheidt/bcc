l= []
d= {}

d['nome']=raw_input('Nome:')
d['sobrenome']=raw_input('Sobrenome:')

while d['nome']!='':
	l.append (d)
	d={}
	d['nome']=raw_input('Nome:')
	d['sobrenome']=raw_input('Sobrenome:')

print l	
