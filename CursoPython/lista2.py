l= range(0,15)
maior=0
for x in l:
	l[x]=int(raw_input())
for x in l:
	if l[x]>maior:
		maior=l[x]
print maior
