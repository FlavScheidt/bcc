program campo_minado;
uses crt, sysutils;

const max = 100;
      min = -2;
type matriza=array [min..max,min..max] of CHAR; 
     matrizi=array [min..max,min..max] of integer;
var aparencia: matriza;
    campo, aux: matrizi;
    ganhou, revela, perdeu: boolean;   
    n, nbombas: integer; 
    
     
    
    procedure cria_campoz (var aux, campo: matrizi; n: integer);
    var i, j: integer;
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
    var i, j: integer;
    begin
    for i:=1 to n do
    begin
    for j:=1 to n do
    aparencia[i,j]:=' ';
    end;
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
    
      
    contavizinhos(campo);
  end;
 
    
   procedure imprimea (*imprime aparencia*) (aparencia:matriza; campo: matrizi; var aux:matrizi; n:integer);
    var i,nmarc, j, k: integer;
    begin 
    nmarc:=0;
    begin
    writeln ('Total de bombas no campo:', nbombas);
    for i:=1 to n do
    for j:=1 to n do 
    if aux[i,j]= 10 then;
    nmarc:=nmarc+1;
    writeln ('Numero de bombas marcadas:', (nmarc-1));
    end;
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
      if aux[i,j] <>1 then
       begin
       if aux[i,j]<> 10 then
       write ('||',aparencia[i,j])     ;
       end;
      if aux[i,j] = 1 then
       begin
       write ('||',campo[i,j]);
       end;
	 if aux[i,j]= 10 then
	 begin
	 write('||B'); 
	 end;
    end;
    write ( '||');
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


   
    procedure revela_pos (var aux: matrizi; var aparencia: matriza; var campo: matrizi; n:integer); 
    var  lin, col: integer;
    begin
    writeln('Digite as coordenadas da posicao que deseja revelar. Dica: inicie pela posicao central do campo');
    writeln ('linha:');
    read(lin);
    writeln ('coluna:');
    read(col);
    aux[lin,col]:=1;
     if campo[lin,col]=9 then
      begin
      perdeu:= true;
      imprimec (campo, n);
      end;               
    if campo[lin,col]= 0 then
    begin
	    expande(campo, aux,lin,col);  
    end;
    imprimea (aparencia, campo, aux, n);
    end;

    procedure marca_bomba (var aparencia: matriza; var aux: matrizi);
    var lin, col: integer;
    begin
    writeln ('Digite as coordenadas que deseja marcar');
    writeln('linha:');
    read(lin);
    writeln('coluna:');
    read (col);
    begin
    if aux[lin,col] <> 10 then
    aux[lin,col]:= 10
    else
    aux[lin,col]:= 0;
    end;
    end;

    procedure menu;
    var option: char;
    begin 
writeln;
writeln;    
writeln ('                         C A M P O    M I N A D O    '); 
writeln;
writeln ('                     _______________________________');
writeln ('                     |           MENU              |');
writeln ('                     |       N - Novo jogo         |');
writeln ('                     |     P - Revelar posicao     |');
writeln ('                     |  M - Marcar/desmarcar bomba |');
writeln ('                     |     R - Revelar campo       |');
writeln ('                     |        S - Sair             |');
writeln ('                     _______________________________');
writeln;
writeln ('Op????o: ');
    readln (option);
    if option= 'n' then
    begin
     cria_campoa (aparencia, n);
     cria_campoc (campo, aux, n, nbombas);
     cria_campoz (aux,campo, n); 
    end;
    if option='p' then
    revela_pos (aux, aparencia, campo, n);  
    if option= 'm' then
    marca_bomba (aparencia, aux);  
    if option= 'r' then
     begin
	imprimec (campo, n);
     revela:= true;
     end;
    if option ='s' then
    perdeu:= true;   
    end;
    
    function checa_vitoria (campo, aux: matrizi; n:integer): boolean;
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
   

    procedure criatxt(var campo: matrizi; n, nbombas: integer);
    var
       arq: text;
       i,j: integer;
       texto: string;
       
begin
        assign(arq,ParamStr(3));
       rewrite(arq);
       texto := inttostr(n) + ' ' + inttostr(nbombas);
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


(* PROGRAMA PRINCIPAL*)
	BEGIN 	
	n:=StrtoInt(ParamStr(1));
	nbombas:=StrtoInt(ParamStr(2));
	
	if( n < 8) or (n > 40) then
	begin
	writeln ('ERRO. Digite um tamanho de campo (n) entre 8 e 40');
	read(n);
        end;
	if nbombas > ((n*n) -9) then 
	begin
	writeln ('ERRO. Numero de bombas maior que o suportado. Digite um novo valor');
        read (nbombas);
        end;
	if (n*n) < nbombas then
	begin
	writeln ('ERRO. Valor invalido, digite um numero de bombas menor que o quadrado do tamanho do campo escolhido');
	read (nbombas);
	end;
	ganhou:= false;
	perdeu:= false;
	revela:= false;
	randomize;
	cria_campoa (aparencia,n);
	cria_campoc (campo, aux, n, nbombas);
	cria_campoz (aux, campo, n);
	criatxt(campo,n,nbombas );
	
    (* while not ganhou and not perdeu and not revela do
	begin
	textcolor(15);
	imprimea(aparencia,campo, aux,n);
	menu;               
	ganhou:=checa_vitoria(campo, aux, n);     
	clrscr;
	end;
	if ganhou then
	begin
	writeln ('Parabens, voce ganhou o jogo!');
	imprimec(campo,n);
        end;
	if perdeu then
	begin
       	writeln ('Voce perdeu, fim de jogo.');
	imprimec (campo, n);
	end;
	if revela then
	imprimec (campo, n); *)
	END.
	
