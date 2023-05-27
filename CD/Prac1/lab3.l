 /*definition*/ 
%{ 
int n,n1,n2,n3,n4,n5,n6,n7,n8,n9 = 0 ;  
%} 
  
/* rules section*/
%% 
  
([A-Z][a-z]+)+" "+([A-Z][a-z]*)    {printf("\n Name of student is : %s", yytext);} 
[0-9]"."[0-9]+ {printf("\tCGPA : %s", yytext);} 
[1-9][0-9]{9}   {printf("\t Mobile Number:%s", yytext);}  
[0-9]+  {printf("\t Package : %s", yytext);}  
[a-zA-Z0-9+_]+[@][a-z]+".edu"  {printf("\t Email id:%s", yytext);} 
"TCS" {n++;}
"Infosys" {n1++;}
"Wipro" {n2++;}
"Accenture" {n3++;}
"Informatica" {n4++;}
"M" {n5++;}
"F" {n6++;}
"CSE" {n7++;}
"IT" {n8++;}
"EC" {n9++;}                      
  

%% 
int yywrap(void){}   
   
int main() 
  
{ 
    yyin = fopen("lab3.txt","r");  
    yylex();
    printf("\n Number of students placed in TCS:%d\n",n);
    printf("\n Number of students placed in Infosys:%d\n",n1);
    printf("\n Number of students placed in Wipro:%d\n",n2);
    printf("\n Number of students placed in Accenture:%d\n",n3);
    printf("\n Number of students placed in Informatica:%d\n",n4);
    printf("\n Number of female students: %d\n", n5);   
    printf("\n Number of male students: %d\n", n6);
    printf("\n Number of CSE students: %d\n", n7); 
    printf("\n Number of IT students: %d\n", n8); 
    printf("\n Number of EC students: %d\n", n9);  
} 
