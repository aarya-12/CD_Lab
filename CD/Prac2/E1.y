%{
    #include <stdio.h>
    #include <stdlib.h>
    int answer = 0;
%}

%token NUMBER ID NL
%left '+' '-'
%left '*' '/'

%%

stmt : 
    exp NL {    
                printf("\nValid Expression\n");
                printf("\nAnswer = %d\n", $1);
                exit(0);
            }

|   exp1 NL {   
                printf("\nValid Expression, but Calculation cannot be performed on variables.\n");
                exit(0);
            };

exp:
    exp '+' exp {$$ = $1 + $3; printf("+");}
|   exp '-' exp {$$ = $1 - $3;printf("-");}
|   exp '*' exp {$$ = $1 * $3; printf("*");}
|   exp '/' exp {$$ = $1 / $3; printf("/");}
|   '(' exp ')' {$$ = $2;}
|   NUMBER {$$ = $1; printf("%d",$$);};
    
exp1: 
    exp1 '+' exp1 {$$ = $1 - $3; printf("+");}
|   exp1 '-' exp1 {$$ = $1 * $3; printf("-");}	
|   exp1 '*' exp1 {$$ = $1 / $3; printf("*");}
|   exp1 '/' exp1 {$$ = $1 / $3; printf("/");}	
|    '(' exp1 ')'
|   ID {$$=$1; printf("%s", $1);};


%%

int yyerror(char *msg)
{
    printf("Invalid Expression\n");
    exit(0);
}

main()
{
    printf("Enter the expression: \n");
    yyparse();
}

int yywrap()
{
    return 1;
}
