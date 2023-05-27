 /*definition*/ 
%{ 
int n = 0 ;  
%} 
  
/* rules section*/
%% 
  

"while"|"if"|"else"|"auto"|"const"|"double"|"float"|"int"|"short"|"struct"|"unsigned"|"break"|"continue"|"for"|"long"|"signed"|"switch"|"void"|"case"|"default"|"enum"|"goto"|"register"|"sizeof"|"typedef"|"volatile"|"char"|"do"|"extern"|"return"|"static"|"union" {n++;printf("\t keywords : %s\n", yytext);}  
  

[a-zA-Z_][a-zA-Z0-9_]* {n++;printf("\t identifier : %s\n", yytext);} 
  

"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;printf("\t operator : %s\n", yytext);}
  

[(){}|, ;]    {n++;printf("\t separator : %s\n", yytext);} 
  
\'.*'\  {n++;printf("\t string : %s\n", yytext);}

[0-9]*"."[0-9]+ {n++;printf("\t float : %s\n", yytext);}  
  

[0-9]+ {n++;printf("\t integer : %s\n", yytext);}                        
  

%% 
int yywrap(void){}   
   
int main() 
  
{ 
    yyin = fopen("lab1.txt","r");  
    yylex();
    printf("\n total no. of token = %d\n", n);   
       
} 
