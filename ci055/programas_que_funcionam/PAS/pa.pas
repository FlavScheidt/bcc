
program pa;
 var
  i, a1, r, soma, termo: integer;

begin

write ('Digite o primeiro termo e a razão');

 read (a1, r);
 i:=1;
 termo:= a1;
 soma:= 0;
 
while (i<=5) do
 begin
  termo:= termo+r;
  soma:= soma+termo;
 i:= 1+i;
 end;

writeln (soma);
 end.
