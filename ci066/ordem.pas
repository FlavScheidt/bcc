program ordem;
var
type vetor=array [1,5]: integer;
const max=5;

function ler (var i: integer; var num: vetor;);
begin

for i=0 to max do
read (num[i]);

end;

function maior (var num, v: vetor);
var	maior, i, j: integer;	
	begin

         if num[i]>num[i+1] then
            m1:= num[i]
         else 
            m1:= num[i+1];
        
         if num[i+2]>num[i+3] then
            m2:= num[i+2]
         else
            m2:= num[i+3];

         if m1>m2 then
            m3:= m1;
         else
            m3:= m2;

         if m3>num[i+4] then
            v[1]:= m3;
         else
            v[1]:= num[i+4];


