program resolve_campo_minado;

uses crt,sysutils;

const min = -2;
      max = 100;

type matrizi= array[min..max,min..max] of integer;
     matriza= array[min..max,min..max] of char;
var aparencia: matriza;
    campo, jogador, aux: matrizi;
    ganhou, perdeu: boolean;   
    n, nbombas: integer; 

 procedure cria_campoz (var aux, campo: matrizi; n: integer);
    var i, j: integer;                (*matriz auxiliar para saber se a casa ja foi aberta*)
    begin
    for i:=1 to n do
    begin
    for j:=1 to n do 
    if campo[i,j] =9 then
    aux[i,j]:=9
    else
    aux[i,j]:= 0; 
    end;
    end;
                                                       
    procedure cria_campoa (var aparencia: matriza; n: integer);
    var i, j: integer;                 (*imprime o tabuleiro para visualizacao do usuario*)
    begin
    for i:=1 to n do
    begin
    for j:=1 to n do
    aparencia[i,j]:=' ';
    end;
    end;
    
    procedure cria_jogador (*matriz em que o resolvedor vai se basear pra jogar*) (var jogador: matrizi; n: integer);
    var i, j: integer;
    begin
     for i:=0 to n+1 do
     for j:=0 to n+1 do
     jogador[i,j]:=0;
    end;

    procedure contavizinhos (var campo: matrizi);
    var lin, col, cont: integer;
    begin
    for lin:=1 to n do
    begin
    for col:=1 to n do
    if campo[lin,col]<>9 then
    begin
    cont:=0; (*conta vizinhos*)
    if campo[lin-1,col-1] = 9 then
    cont:= cont+1;
    if campo[lin-1,col] = 9 then
    cont:= cont+1;
    if campo[lin-1, col+1] = 9 then
    cont:= cont+1;
     if campo[lin, col-1] = 9 then
    cont:= cont+1;
    if campo[lin, col+1] = 9 then
    cont:= cont+1;
    if campo[lin+1, col-1] = 9 then
    cont:= cont+1;
    if campo[lin+1, col] = 9 then
    cont:= cont+1;
     if campo[lin+1, col+1] = 9 then 
    cont:= cont+1;
  
    campo[lin,col]:= cont;
    end;
    end;
    end;
    
    procedure cria_campoc (var campo: matrizi;var aux: matrizi; n, nbombas: integer);
    var i,j,m,t,nbombasusadas:integer;
    begin
      nbombasusadas:=0;   
      while nbombasusadas < nbombas do
      begin
      nbombasusadas:=0;
      i:=random(n)+1;
      j:=random(n)+1;
      if campo[i,j]<>9 then
      campo[i,j]:=9;
      campo[n div 2, n div 2]:= 0;
      campo[(n div 2)-1,(n div 2)-1]:=0;
      campo[(n div 2) -1, n div 2]:=0;
      campo[(n div 2) -1, (n div 2) +1]:=0;
      campo[n div 2, (n div 2) -1]:=0;
      campo[n div 2, (n div 2)+1]:=0;
      campo[(n div 2) +1, (n div 2) -1]:=0;
      campo[(n div 2) +1, n div 2]:=0;
      campo[(n div 2)+1,(n div 2) +1]:=0;
       
       for m:=1 to n do
       for t:=1 to n do
       if campo[m,t]=9 then
       nbombasusadas:= nbombasusadas+1;
      
       end;
       for i:=1 to n do (*sem essa "borda", o resolvedor nao consegue marcar bombas no canto do campo*)
      
      
    contavizinhos(campo);
  end;
 
    
   procedure imprimea (*imprime aparencia*) (aparencia:matriza; campo: matrizi; var aux:matrizi; n:integer);
    var i, j, k: integer;
    begin 
    writeln ('Total de bombas no campo:', nbombas);
   
    for k:=1 to n do
    begin
    textcolor(2);
    if k < 10 then (*numero com 1 digito precisa de 2 espacos para ficar alinhado ao campo*)
    write('  ',k);
    if k > 9 then   (*numero com 2 digitos precisa de 1 espaco para ficar alinhado*)
    write(' ',k);
    textcolor(15);
    end;
    writeln;
    for i:= 1 to n do
     begin       
     for j:=1 to n do
	begin
      if (aux[i,j] <>1) and (aux[i,j]<> 10) then
        write('||',aparencia[i,j])     ;
      if aux[i,j] = 1 then
       begin
       write ('||',campo[i,j]);
       end;
	 if aux[i,j]= 10 then 
	 begin
         write('||');
         textcolor(9);
         write('B');
         textcolor(15); 
	 end;
    end;
    write ('||');
    textcolor(2) ;
    write (i);
    textcolor(15);
    writeln;    
     end;
     end;
     
    
    procedure imprimec (*imprime o campo*) (campo:matrizi; n: integer);
    var i,j,k: integer;
    begin
     for k:=1 to n do
    begin
    textcolor(2);
    if k < 10 then
    write('  ',k);
    if k > 9 then
    write(' ',k);
    textcolor(15);
    end;
    writeln;
    for i:=1 to n do
    begin
    for j:=1 to n do
    if campo[i,j] <> 9 then
    write ('||',campo[i,j])
    else
    begin    
    write('||'); textcolor(4); write('B'); textcolor(15);    
    end;
    write ('||');
    textcolor(2);
    write(i);
    textcolor(15);
    writeln;
    end;
    end;


function recursivo (campo, aux:matrizi):boolean;
var i, j, r,t : integer;
begin
recursivo:=false;
for i:=1 to n do
for j:=1 to n do
if (campo[i,j]=0) and (aux[i,j]<>0) then
begin
for r:=(i-1) to (i+1) do
for t:=(j-1) to (j+1) do	
if (campo[r,t]=0) and (aux[r,t]= 0) then
recursivo:=true;	
end;  
end;

procedure expande (campo:matrizi; var aux:matrizi; lin, col:integer);
var i, j, k, l: integer;
begin
if campo[lin,col]=0 then
aux[lin-1,col-1]:=1;
aux[lin-1,col]:=1;
aux[lin-1,col+1]:=1;
aux[lin,col-1]:=1;
aux[lin,col+1]:=1;
aux[lin+1,col-1]:=1;
aux[lin+1,col]:=1;
aux[lin+1,col+1]:=1;
while recursivo(campo,aux) do
begin
for i:=1 to n do
for j:=1 to n do

if (campo[i,j]= 0) and( aux[i,j] <> 0) then
begin
for k:=(i-1) to (i+1) do
for l:=(j-1) to (j+1) do
aux[k,l]:=1;
end;
end;
end;

procedure le_saida(var campo: matrizi);

var i, j, k : integer;
    arq : text;
   
   begin
     assign(arq, ParamStr(1));  
     reset(arq);
     readln(arq, n, nbombas);
     for k:=1 to nbombas do
        begin
        read(arq,i,j);
        campo[i,j]:=9;
         end;
     close(arq);
   end;


procedure posicao_central (var campo: matrizi; var aux: matrizi; n: integer);
var lin, col: integer;
begin
lin:= (n div 2);
col:= (n div 2);
aux[lin,col]:= 1;
if campo[lin,col]= 0 then
expande(campo,aux,lin,col);
end;

procedure atualiza (aux: matrizi; var jogador: matrizi);
var i, j: integer;
begin
for i:=1 to n do
for j:=1 to n do
if aux[i,j]<> 0 then
jogador[i,j]:= campo[i,j];
end;

procedure joga(var aux: matrizi; var jogador: matrizi; campo: matrizi); 
var lin, col, cont, cont2, i, j: integer;
     jogou: boolean;

begin
jogou:=false; 
cont:=0;
cont2:=0;
for lin:=1 to n do
for col:=1 to n do
       
       if (campo[lin-1,col-1] <>0) and (campo[lin-1,col] <> 0) and (campo[lin-1, col+1] <>0 ) and (campo[lin, col-1] <>0) and (campo[lin, col+1] <>0) and  (campo[lin+1, col-1] <>0) and (campo[lin+1, col] <>0) 
       and (campo[lin+1, col+1] <>0) and (aux[lin-1,col-1] <>0) and (aux[lin-1,col] <>0) and (aux[lin-1, col+1] <>0 ) and (aux[lin, col-1] <>0) and (aux[lin, col+1] <>0) and  (aux[lin+1, col-1] <>0) and (aux[lin+1, col] <>0) and (aux[lin+1, col+1] <>0) then                                                   (*SE TODAS AS CASAS AO REDOR ESTIVEREM ABERTAS E FOREM DIFERENTES DE 0, SIGNIFICA QUE A CASA CENTRAL TEM BOMBA*)
       begin  
       aux[lin,col]:=10; 
       jogou:=true;
       end;
atualiza(aux, jogador);
       
       
     begin
       for lin:=1 to n do
       for col:=1 to n do
       begin
       if (jogador[lin-1,col-1] > 0) and (jogador[lin-1,col-1] < 9)then
       if (jogador[lin-1,col] > 0) and (jogador[lin-1,col] < 9) then                 (* no caso de     1 1                           *)
       if (jogador[lin,col-1] > 0) and (jogador[lin,col-1] < 9) then                (*                 1 x          *)
       if (jogador[lin-2,col-2] = 0) and (aux[lin-2,col-2] <> 0) then
       begin
       aux[lin,col]:=10;
       jogou:=true;
       end;
       end;
atualiza(aux, jogador);      
       
       
       for lin:=1 to n do
       for col:=1 to n do
       begin  
       if (jogador[lin-1,col] > 0) and (jogador[lin-1,col] < 9) then                         (* no caso de       1 1                          *)
       if (jogador[lin-1,col+1] > 0) and (jogador[lin-1,col+1] < 9)  then                    (*                  x 1             x=bomba *)
       if (jogador[lin,col+1] > 0) and (jogador[lin,col+1] < 9) then
       if (jogador[lin-2,col+2] = 0) and (aux[lin-2,col+2] <> 0) then
       begin
       aux[lin,col]:=10;
       jogou:=true;
       end;
       end;
atualiza(aux, jogador);      

       
       for lin:=1 to n do
       for col:=1 to n do
       begin
       if (jogador[lin,col-1] >0) and (jogador[lin,col-1] < 9)  then                      (* no caso de  1 x              *)
       if (jogador[lin+1,col-1]>0) and (jogador[lin+1,col-1] < 9) then                      (*           1 1      x = bomba *)    
       if (jogador[lin+1,col] >0) and (jogador[lin+1,col] < 9) then
       if (jogador[lin+2,col-2] = 0) and (aux[lin+2,col-2] <> 0) then
       begin
       aux[lin,col]:=10;
       jogou:=true;
       end;
       end;
atualiza(aux, jogador);       
    
       
       for lin:=1 to n do
       for col:=1 to n do
       begin
       if (jogador[lin,col+1] >0) and (jogador[lin,col+1] < 9)  then                        (*   no caso de  x 1            *)
       if (jogador[lin+1,col] >0) and  (jogador[lin+1,col] < 9) then                          (*             1 1            x = bomba *)
       if (jogador[lin+1,col+1] >0) and (jogador[lin+1,col+1] < 9)  then
       if (jogador[lin+2,col+2] = 0) and (aux[lin+2,col+2] <> 0)  then
       begin
       aux[lin,col]:=10;
       jogou:=true;
       end;    
       end;
atualiza(aux, jogador);         
     
     end;
 
       
       begin
       for lin:=1 to n do 
       for col:=1 to n do
       if jogador[lin,col]=8 then
       begin
       aux[lin-1,col-1]:=10;
       aux[lin-1,col]:=10;                           (*se a casa tem valor 8, todas em volta tem bombas*)
       aux[lin-1,col+1]:=10;
       aux[lin,col-1]:=10;
       aux[lin,col+1]:=10;
       aux[lin+1,col-1]:=10;
       aux[lin+1,col]:=10;
       aux[lin+1,col+1]:=10;
       jogou:=true;
       end;
       end;
atualiza(aux, jogador);     
      
       
       

       
       
       begin
       cont:=0; cont2:=0;
       for lin:=1 to n do
       for col:=1 to n do
       if aux[col-1,lin-1] =0 then
       cont:=cont+1;
       if aux[col-1,lin] =0 then
       cont:=cont+1;
       if aux[col-1,lin+1] =0 then
       cont:=cont+1;
       if aux[col,lin-1] =0 then
       cont:=cont+1;
       if aux[col,lin+11] =0 then
       cont:=cont+1; 
       if aux[col+1,lin-1] =0 then
       cont:=cont+1;
       if aux[col+1,lin] =0 then
       cont:=cont+1;
       if aux[col+1,lin+1] =0 then
       cont:=cont+1;
       if aux[col-1,lin-1] =10 then
       cont2:=cont2 +1;
       if aux[col-1,lin] =10 then
       cont2:=cont2+1;
       if aux[col-1,lin+1] =10 then
       cont2:=cont2 +1;
       if aux[col,lin-1] =10 then
       cont2:=cont2 +1;
       if aux[col,lin+11] =10 then
       cont2:=cont2 +1; 
       if aux[col+1,lin-1] =10 then
       cont2:=cont2 +1;
       if aux[col+1,lin] =10 then
       cont2:=cont2 +1;
       if aux[col+1,lin+1] =10 then
       cont2:=(cont2) +1;  
       if (cont =1) and (cont2 = (campo[lin,col] -1)) then         (*se apenas uma casa nao foi aberta e falta uma bomba a ser encontrada, a bomba est?? nessa casa fechada*)
       begin
       aux[lin,col]:=10;   
       jogou:=true;
       end;
       end;       
atualiza(aux, jogador);
       
       
       begin
       cont2:=0;
       for lin:=1 to n do
       for col:=1 to n do
       if aux[lin,col]=10 then
       cont2:=cont2 +1;                         (*se todas as bombas foram encontradas, pode abrir tudo*)
       if cont2=nbombas then
       begin
       for lin:=1 to n do
       for col:=1 to n do
       if aux[lin,col]=0 then
       aux[lin,col]:=1;
       end;
       jogou:=true;
       end;
atualiza(aux, jogador);


       if not jogou then
       begin
       lin:= random(n)+1;
       col:= random(n)+1;  
       writeln ('RESOLVEDOR CHUTANDO POSI????O, pressione qualquer tecla.');
       readkey;
       aux[lin,col]:=1;
       if campo[lin,col] = 9 then
       perdeu:=true;
       jogou:=true;
       end;   

end;

function checa_vitoria (aux: matrizi; n: integer): boolean;
var i,casas_fechadas, j: integer;
       
begin     
casas_fechadas:=0 ;
 begin
   for i:=1 to n do
   for j:=1 to n do
     begin
	if aux[i,j] = 0 then
	casas_fechadas:=casas_fechadas +1;
	end;	     
	end;
	if casas_fechadas=0 then
	checa_vitoria:=true
        else
        checa_vitoria:=false;
end;


procedure criatxt(var campo: matrizi; n, nbombas: integer); (*cria arquivo de texto com as coordenadas das bombas para comparar ao passado por parametro no inicio do programa*)
var
arq: text;
i,j: integer;
texto: string;
       
begin
assign(arq,'resolvedor.txt');
rewrite(arq);
texto:= inttostr(n) + ' ' + inttostr(nbombas);
writeln(arq,texto);
for i:=1 to n do
for j:=1 to n do
      
if campo[i,j] = 9 then
       
begin
texto := inttostr(i)+' '+inttostr(j);
writeln(arq,texto);
end;
       
close(arq);
end;	


   (*PROGRAMA PRINCIPAL*)
   BEGIN
    clrscr;
    le_saida (campo);
    cria_campoa (aparencia, n);
    cria_campoc (campo, aux, n, nbombas);
    cria_campoz (aux, campo, n);
    cria_jogador (jogador, n);
    imprimea(aparencia,campo,aux,n);
    delay(1300);
    posicao_central (campo, aux, n);
    ganhou:=false;
    perdeu:=false;
    randomize;
    while not ganhou and not perdeu do
    begin
    clrscr;
    atualiza(aux, jogador);
    imprimea(aparencia,campo,aux,n);
    delay(1300);
    joga (aux, jogador, campo);
    ganhou:=checa_vitoria(aux,n);
    end;
if ganhou then
begin
writeln('FIM DE JOGO');
imprimea(aparencia, campo, aux, n);
imprimec(campo,n);


criatxt(campo,n,nbombas);
end;
if perdeu then
begin
writeln('Chutou uma posi????o com bomba. FIM DE JOGO');
imprimec (campo, n);
end;
   END.
