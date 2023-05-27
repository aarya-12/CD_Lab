 /*definition*/ 
%{ 
int n,n1,n2,n3 = 0 ;  
%} 
  
/* rules section*/
%% 
  

  
"I"|"II"|"III"|"IV"|"V"|"VI"|"VII"|"VIII"   {n++;printf("\t The semester is : %s\n", yytext);} 

"Question"[1-9]    {n++, n1++;printf("\t The question is : %s\n", yytext);} 
  
[A-Z]*[a-z]+    {n++,n2++;printf("\t Word : %s\n", yytext);} 

[\n] { n++,n3++;} /* no of lines*/

[a-z]    {n++;printf("\t Small letter : %s\n", yytext);} 

[A-Z]     {n++;printf("\t Capital letter : %s\n", yytext);}
  
[(){}|, ;?:]    {n++;printf("\t Symbol : %s\n", yytext);} 
    
[0-9]   {n++;printf("\t Digit : %s\n", yytext);}                        

[0-9]\/[0-9]\/[0-9][0-9][0-9][-0-9]  {n++;printf("\t The date of examination : %s\n", yytext);}    

%% 
int yywrap(void){}   
   
int main() 
  
{ 
    yyin = fopen("lab2.txt","r");  
    yylex();
    printf("\n total no. of token = %d\n", n);   
    printf("\n total no. of questions = %d\n", n1); 
    printf("\n total no. of words = %d\n", n2);
    printf("Number of lines : %d\n",n3);
} 
