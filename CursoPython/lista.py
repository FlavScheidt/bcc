l=range(1,10)
i=0
for x in l:
	if x%2!=0:
		y=x*x
		l[i]=y
	i=i+1
print l
