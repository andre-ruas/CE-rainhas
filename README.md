# CE-rainhas

### Modelo do arquivo "entrada.txt":

COD=int <br>
POP=5 <br>
D=5  <br>
LimiteInferior=1 <br>
LimiteSuperior=10 <br>
RUN=10     
GEN=5 <br>
SEL=1 <br>
ELIT=0 <br>

### Descrição:
COD -> codificação <br> 
POP -> tam da população <br>
D -> dimensão (tamanho do cromossomo) <br>
LimiteInferior -> menor valor que um gene pode assumir <br>
LimiteSuperior -> maior valor que um gene pode assumir <br>
RUN -> número de execuções <br>
GEN -> número de gerações <br>
SEL -> estratégia de seleção, [1,2,3] <br>
ELIT -> elitismo ( 0:false, 1:true ) <br>

### Se, COD=bin ou COD=int-perm: Remover linhas referentes ao limite superior e limite inferior.

Ex de codificação para inteiros permutados: <br>
COD=int-perm <br>
POP=8 <br>
D=8 <br>
RUN=10     
GEN=5 <br>
SEL=1 <br>
ELIT=0 <br>

## Opcões de COD aceitas pelo arquivo: <br>
Binário , inteiro permutado, inteiro, real <br>

COD=bin <br>
COD=int-perm   
COD=int <br>
COD=float <br>

## Opções de SEL aceitas pelo arquivo: <br>
1 -> Roleta Sem Reposição <br>
2 -> Torneio Estocástico. <br>
3 -> Vizinhança Linear (anel). <br>

SEL=1<br>
SEL=2<br>
SEL=3<br>
