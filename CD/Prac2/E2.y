%{
#include<stdio.h>
#include<stdlib.h>

%}
%token ZERO ONE
%%
  
stmt : s {printf("\nString Accepted\n");}
;
  
s : c
| ZERO a
| ONE b
;
  
a : c a
| ZERO
;
  
b : c b
| ONE
;
  
c : ZERO
| ONE
;
  
%%
int yyerror(char *msg)
{
printf("Invalid string \n");
exit(0);
}

main() 
 {
    printf("\nEnter String: ");
    yyparse();
    printf("\n");
    return 0;
 }
int yywrap(){return 1;}
