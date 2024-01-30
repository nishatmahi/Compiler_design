%{
 /* C declaration-contains header, functions and other c variables.*/
	#include<stdio.h>
	#include<stdlib.h>
	#include<conio.h>
	#include<string.h>
	#include<math.h>

    /* structure for storing variables.*/ 
    typedef struct variable{
        char *name; // this is for the name of the variable
        int type; /* indicates data type- 0:int,1:double,2:char* */
        int* ival;  // this is a integer pointer for storing array element
        double* dval;   // this is a double pointer for storing double array element
        char** sval; // this is string pointer for storing string type value array
        int size;   // this is for geting the size of that array
        int isArray;    // 1 for array and 0 for normal variable
    }tmp;

    int temporay = -1; // this is check the expression will return a integer type value or a real type value

    struct variable var[2000];
    int varCnt = 0;


    int *temporayIntegerArray;
    int temporayArrayLength = 0;
    double *temporaryDoubleArray;
    char **temporaryCharArray;

    int temporaryInteger = -1;
    double temporaryDouble = -1.0;
    char* temporaryChar;
    double choiceValue; /* stores the value of choice to check in options. */

    int ifelseCondtionMatchNumber = 0; // this is for checking which conditon has been matched

    typedef struct functionStruct{
        char *FuncName;
        tmp *varPtr; 
        int varCnt ;
        int retType ; 
    }pre;

    struct functionStruct fvar[200];
    int fvarCnt = 0;
    int functionNotCorrect = 0;
    char* temporaryFunctionName;
    int temporaryFunctionReturnType = 0;

    struct variable* temVarPointer;
    int temVarPointerCount  = 0;

    int currentFunction = 0;
    int functionRejected = 0;
  

     /* Print value of a varible  */
        void showValueOfTheVariable (int id){
            if (var[id].isArray) {
       
    } else {
        // Print the value based on the variable type
        if (var[id].type == 0){
            printf("%d\n", var[id].ival[0]);
        }
        else if (var[id].type == 1){
            printf("%lf\n", var[id].dval[0]);
        }
        else {
            printf("%s\n", var[id].sval[0]);
        }
    }
        }

    // this is checking it is an real type expression or double type k = 1 mean int k = 2 mean real
        void setTemporaryValue(int k){
            temporay = k;
        }
        int getTemporaryValue(){
            return temporay;
        } 

    /* Checks if a variable is already declared. */
        int checkExistance(char *varName){
            for(int i = 0 ; i<varCnt; i++){
                if(strcmp(var[i].name,varName)==0){
                    return 1;
                }
            }
            return 0;
        }
    
    /* Get the index of variable that is called. If not found return -1. */
        int getVariableIndex(char *varName){
            for(int i = 0 ; i<varCnt; i++){
                if(strcmp(var[i].name,varName)==0){
                    return i;
                }
            }
            return -1;
        }
    
    // this will return function variable index
        int getFunctionIndex(char *varName){
            for(int i = 0 ; i<fvarCnt; i++){
                if(strcmp(fvar[i].FuncName,varName)==0){
                    return i;
                }
            }
            return -1;
        }

    

    // create a new integer type variable or array varibale of integer type
         void createNewIntegerTypeVarible (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            int *x = ((int*)value);
            var[id].ival = malloc(size*sizeof(int));
            for(int i=0;i<size;i++){
                var[id].ival[i] = x[i];
            }
            var[id].type = 0;
        }
    
    // create a new real type variable or array varibale of real type
        void createNewRealTypeVarible (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            double* x = ((double*)value);
            var[id].dval = malloc(size*sizeof(double));
            for(int i=0;i<size;i++){
                var[id].dval[i] = x[i];
            }
            var[id].type = 1;
        }
    
    // create a new string type variable or array variable of string type
        void createNewStringTypeVariable (char *varname,void* value,int type,int id,int size,int isArray){
            var[id].name = varname;
            var[id].size = size;
            var[id].isArray = isArray;
            
            char **s =((char**)value);
            var[id].sval = malloc(size*sizeof(char**));
            for(int i=0;i<size;i++){
                var[id].sval[i] = s[i];
            }
            var[id].type = 2;
        }
    
   

    // take input form the user 
        void takeInputFromUser (int id){
            if (var[id].type==0){
                scanf("%d",&var[id].ival[0]);
                printf("Scanned Integer value is: %d\n",var[id].ival[0]);
            }
            else if (var[id].type==1){
                scanf("%lf",&var[id].dval[0]);
                printf("Scanned Double value is: %lf\n",var[id].dval[0]);
            }
            else {
                char demoStr[2000];
                scanf("%s",&var[id].sval[0]);
                printf("Scanned String value is: %s\n",var[id].sval);
            }
        }
    

    // Error Handleing function

    void assignmentError (char *varName){
        printf("Your are trying to assign wrong value type in wrong type of varibale\n");
    }

   
   
    /* Flex handling */
    extern FILE *yyin, *yyout;
	int yylex();
	int yyparse();
	int yyerror(char *s);

%}

/* Bison Declaration */
%union{
	int integer;
    double real;
    char* string;
}



%token INTEGER REAL STRING INT_ARRAY DOUBLE_ARRAY STRING_ARRAY EOL VARIABLE INPUT EQL NOTEQL LESSEQL GREATEREQL SHOW APPEND
%token AND OR MXOR MAND MOR NOT MNOT SIN COS TAN SQRT LOG LOG2 LN DOUBLEMINUS DOUBLEPLUS VOID
%token IF ELIF ELSE FOR IN SCOPE WHILE SWITCH CASE DEFAULT DEFINE CALL ARROW COMMENT POP SORT

%type <string> VARIABLE STRING
%type <integer> INTEGER 
%type <real> expression REAL starting mainRules

%nonassoc ELIF 
%nonassoc ELSE

%left DOUBLEPLUS DOUBLEMINUS
%left AND OR NOT
%left MAND MOR MXOR MNOT
%left LOG LOG2 SQRT 
%left '<' '>' EQL NOTEQL LESSEQL GREATEREQL
%left  '+' '-'
%left  '*' '/' '%'
%left SIN COS TAN

%%

program:
            starting                                 {}
    ;

starting:
            {/*this is for nothing*/}
            | starting mainRules
    ;

mainRules:
            EOL                                     {}
            | COMMENT                               {}
            | input                                 {}
            | show                                  {}
            | declaration                           {}
            
            | if_blocks          
                {ifelseCondtionMatchNumber=0;}
            | for_block                             {}
            | while_block                           {}
            | switch_block                          {}
            | function_block                        {}
            | function_call                         {}
    ;




show:
    SHOW '(' showExpression ')'                      {}
    ;

showExpression:
            showExpression ',' VARIABLE
                {
                    int id = getVariableIndex($3);
                    if (id!=-1){
                        showValueOfTheVariable(id);
                    }
                    else {
                        printf("Variable is not declared yet\n");
                    }
                }
            | VARIABLE
                {
                    int id = getVariableIndex($1);
                    if (id!=-1){
                        showValueOfTheVariable(id);
                    }
                    else {
                        printf("Variable is not declared yet\n");
                    }
                }
            | showExpression ',' STRING
                {
                    printf("%s\n",$3);
                }
            | STRING 
                {
                    printf("%s\n",$1);
                }
            
    ;


input:
    INPUT '(' inputExpression ')'               {}
    ;

inputExpression:
             inputExpression ',' VARIABLE 
    {
        int ch = checkExistance($3);
        if (ch){
            int id = getVariableIndex($3);
            takeInputFromUser(id);
        }
        else {
           char value[2000]="\n";
           createNewStringTypeVariable($3,&value,2,varCnt,1,0);
            printf("Automatically defined as a string. The variable is %s\n", var[varCnt - 1].name);
            takeInputFromUser(varCnt - 1);
        }
    }
    | VARIABLE 
    {
        int ch = checkExistance($1);
        if (ch){
            int id = getVariableIndex($1);
            takeInputFromUser(id);
        }
        else {
           char value[2000]="\n";
            createNewStringTypeVariable($1,&value,2,varCnt,1,0);
            printf("Automatically defined as a string. The variable is %s\n", var[varCnt - 1].name);
            takeInputFromUser(varCnt - 1);
        }
    }
    ;

declaration: /* Variable Declaration */
            VARIABLE '=' expression
                {
                    int k = checkExistance($1);
                    if (k){
                        // this variable has been declared already
                        if (getTemporaryValue()==1){
                            // this is integer
                            int id = getVariableIndex($1);
                            if (var[id].type==2 || var[id].isArray){
                                assignmentError($1);
                            }
                            else {
                                if (var[id].type==1){
                                    printf("Implicitly convert the value into real type and assign the value\n");
                                    var[id].dval[0] = $3;
                                }
                                else {
                                    var[id].ival[0] = $3;
                                }
                            }
                        }
                        else {
                            // this is real type
                            int id = getVariableIndex($1);
                            if (var[id].type==2 || var[id].isArray){
                                assignmentError($1);
                            }
                            else {
                                if (var[id].type==0){
                                    printf("Implicitly convert the integer type variable into real type and assign the value\n");
                                    var[id].dval = malloc(1*sizeof(double));
                                    var[id].dval[0] = $3;
                                    var[id].type = 1;
                                    var[id].ival = NULL;
                                }
                                else {
                                    var[id].dval[0] = $3;
                                }
                            }
                        }
                        setTemporaryValue(-1);
                    }
                    else {
                        // this is a new variable
                        if (getTemporaryValue()==1){
                            // this is interger
                            int value = $3;
                            createNewIntegerTypeVarible($1,&value,0,varCnt,1,0);
                            printf("New Integer type variable has been declared\n");
                            varCnt++;
                        }
                        else {
                            // this is real type
                            double value = $3;
                            createNewRealTypeVarible($1,&value,1,varCnt,1,0);
                            printf("New Double type variable has been declared\n");
                            varCnt++;
                        }
                        setTemporaryValue(-1);
                    }
                }
            | VARIABLE '[' INTEGER ']' '=' expression
                {
                    int id = getVariableIndex($1);
                    int t = getTemporaryValue();
                    int idx = $3;
                    if (t==1){
                        if (var[id].type==0){
                            if (var[id].size<=idx){
                                printf("Index out of bound\n");
                            }
                            else {
                                var[id].ival[idx] = $6;
                            }
                        }
                        else {
                            printf("Type does not matched\n");
                        }
                    }
                    else if (t==2){
                        if (var[id].type==2){
                            printf("Type does not matched\n");
                        }
                        else {
                            if (var[id].size<=idx){
                                printf("Index out of bound\n");
                            }
                            else {
                                var[id].dval[idx] = $6;
                            }
                        }
                    }

                    setTemporaryValue(-1);
                }
            | VARIABLE '[' INTEGER ']' '=' STRING
                {
                    int id = getVariableIndex($1);
                    int idx = $3;
                    if (var[id].type!=2){
                        printf("Type does not matched\n");
                    }
                    else {
                        if (var[id].size<=idx){
                            printf("Out of bound\n");
                        }
                        else {
                            var[id].sval[idx] = $6;
                        }
                    }
                }
            | VARIABLE '=' STRING 
                {
                    int k = checkExistance($1);
                    if (k){
                        int id = getVariableIndex($1);
                        if (var[id].type!=2){
                            assignmentError($1);
                        }
                        else {
                            var[id].sval[0] = $3;
                        }
                    }
                    else{
                        char *value = $3;
                        createNewStringTypeVariable($1,&value,2,varCnt,1,0);
                        varCnt++;
                        printf("New string type variable has been declared\n");
                    }
                }

           
            
    ;


function_block:
            module_declare
                {
                    if (!functionNotCorrect){
                        printf("New Function Declared-\n");
                        // for (int i=0;i<fvar[fvarCnt-1].varCnt;i++){
                        //     printf("%s\n", fvar[fvarCnt-1].varPtr[i].name);
                        // }
                    }
                }
    ;

module_declare:
            DEFINE funtion_name '(' function_variable ')' ARROW return_type '{' mainRules '}'
                {
                    
                    fvar[fvarCnt].FuncName = temporaryFunctionName;
                    fvar[fvarCnt].varCnt = temVarPointerCount;

                    fvar[fvarCnt].varPtr = realloc(fvar[fvarCnt].varPtr, temVarPointerCount*sizeof(var[0]));
                    for (int i=0;i<temVarPointerCount; i++){
                        fvar[fvarCnt].varPtr[i] = temVarPointer[i];
                    }
                    fvar[fvarCnt].retType = temporaryFunctionReturnType;
                    

                    temVarPointerCount = 0;

                    fvarCnt++;
                }
    ;
funtion_name:
            VARIABLE
                {
                    int id = getFunctionIndex($1);
                    if (id!=-1){
                        printf("Function is already decared\n");
                        functionNotCorrect = 1;
                    }
                    else {
                        temporaryFunctionName = $1;
                    }
                }
    ;
function_variable:
            function_variable ',' single_var
            | single_var
    ;
single_var: 
            VARIABLE ':' INT_ARRAY
                {
                    int id = getVariableIndex($1);
                    if (id!=-1) {
                        printf("this variable is already declared\n");
                    }
                    else {
                        int value = 0;
                        createNewIntegerTypeVarible($1,&value,0,varCnt,1,0);
                         
                        temVarPointerCount++;

                        temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                        temVarPointer[temVarPointerCount-1] = var[varCnt];
                        varCnt++;

                    }
                }
            | VARIABLE ':' DOUBLE_ARRAY
                {
                    int id = getVariableIndex($1);
                    if (id!=-1) {
                        printf("this variable is already declared\n");
                    }
                    else {
                        double value = 0;
                        createNewRealTypeVarible ($1,&value,1,varCnt,1,0);
                        temVarPointerCount++;

                        temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                        temVarPointer[temVarPointerCount-1] = var[varCnt];
                        varCnt++;
                        
                    }
                }
          
    ; 

return_type:
        INT_ARRAY
            {
               temporaryFunctionReturnType = 1;
            }
        | DOUBLE_ARRAY
            {
                temporaryFunctionReturnType = 2;
            }
       
        | VOID 
            {
                temporaryFunctionReturnType = 0;
            }
    ;

function_call:
            CALL user_module_name '(' user_parameters ')'
                {
                    functionRejected = 0;
                    int id = currentFunction;
                    if (fvar[id].varCnt!=temVarPointerCount){
                        functionRejected = 1;
                    }
                    else {
                        for (int i=0;i<temVarPointerCount;i++){
                            if (fvar[id].varPtr[i].type!=temVarPointer[i].type){
                                functionRejected = 1;
                                break;
                            }
                        }
                    }
                    
                    if(functionRejected){
                        printf("Function was not called as declared\n");
                    }
                    else{
                        printf("Function called Successfully.\n");
                    }
                }
    ;
user_module_name:
            VARIABLE
                {
                    int id = getFunctionIndex($1);
                    if(id==-1){printf(" No Function Exist with this name.");}
                    else{
                        currentFunction = id;
                    }
                }
    ;
user_parameters:
            user_parameters ',' single_param
            | single_param
    ;
single_param: 
            VARIABLE
                {
                    int id = getVariableIndex($1);
                    // printf("%d\n",id);
                    temVarPointerCount++;
                    temVarPointer = realloc(temVarPointer,temVarPointerCount*sizeof(var[0]));
                    temVarPointer[temVarPointerCount-1] = var[getVariableIndex($1)];
                }
    ;



if_blocks: // starting of if block
            IF if_block else_block   {}
    ;
if_block:
            '(' expression ')' '{' starting '}' 
                {
                    int isTrue = (fabs($2)>1e-9);
                    if(isTrue){
                        printf("Condition in if block is true.\n");
                        ifelseCondtionMatchNumber = 1;
                    }
                    else{
                        printf("Condition in if block is false.\n");
                    }
                }
    ;
else_block:
            | elif_block
            | elif_block  single_else
            | single_else
    ;
single_else: ELSE '{' starting '}' 
                {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring else block.\n");
                    }
                    else{
                        int isTrue =1;
                        if(isTrue){
                            printf("Condition in else block is true.\n");
                            ifelseCondtionMatchNumber = 1;
                        }
                        else{
                            printf("Condition in else block is false.\n");
                        }
                    }  
                }
    ;
elif_block:
            elif_block  single_elif
            | single_elif 
    ;
single_elif:
            ELIF '(' expression ')' '{' starting '}' 
                {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring elif block.\n");
                    }
                    else{
                            int isTrue = (fabs($3)>1e-9);
                            if(isTrue){
                                printf("Condition in elif block is true.\n");
                                ifelseCondtionMatchNumber = 1;
                            }
                            else{
                                printf("Condition in elif block is false.\n");
                            }
                        }
                }
    ;

for_block:
        FOR VARIABLE IN SCOPE '(' INTEGER ':' INTEGER ')' '{' starting '}' 
            {
                int s = $6;
                int e = $8;
                int len = (e-s);
                printf("The inner block will iterate :%d times\n",len);
            }
        | FOR VARIABLE IN SCOPE '(' INTEGER ':' INTEGER ':' INTEGER ')' '{' starting '}' 
            {
                int s = $6;
                int e = $8;
                int len = 0;
                int inc = $10;
                for (int i=s;i<e;i+=inc){
                    len++;
                }
                printf("The inner block will iterate :%d times\n",len);
            }
    ;
while_block:
        WHILE '(' expression ')' '{' starting '}'
            {
                int val = $3;
                if (val){
                    printf("The expression given inside while is True\n");
                }
                else {
                    printf("The expression given inside while is false\n");
                }
            }
    ;

switch_block: 
            SWITCH '(' choice_variable ')' '{' options '}'
                {
                    ifelseCondtionMatchNumber = 0;
                }
    ;
choice_variable: 
            VARIABLE
                {
                    int id = getVariableIndex($1);
                    if(id==-1) printf("No such variable");
                    else if(var[id].type==2){
                        printf("can't assign string in choices.");
                    }
                    else if(var[id].type==0) choiceValue = var[id].ival[0];
                    else choiceValue = var[id].dval[0];
                }

    ;

options:    
            optionlist default
            | default
    ;
default: 
            DEFAULT '{' starting '}' 
                {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring default option.\n");
                        }
                    else{
                        printf("Executing Default Option.No match found.\n");
                    }
                }
    ;
optionlist:
            optionlist option
            | option
    ;
option: 
            CASE '(' expression ')' '{' starting '}' 
                {
                    if(ifelseCondtionMatchNumber){
                        printf("Condition already fulfilled.Ignoring current option\n");
                        }
                    else{
                        int isTrue = (fabs($3-choiceValue)<1e-9);
                            if(isTrue){
                                printf("Option matched.\n");
                                ifelseCondtionMatchNumber = 1;
                            }
                            else{
                                printf("Condition of current option doesn't match.\n");
                            }
                    }
                }
    ;





expression: /*this is every expression*/
            INTEGER
                {
                    $$ = $1;
                    if(getTemporaryValue()==-1)
                        setTemporaryValue(1);
                }
            | REAL
                {
                    $$ = $1;
                    setTemporaryValue(2);
                }
            | VARIABLE             
                {
                    int id = getVariableIndex($1);
                    if(id==-1) {
                        printf("Varibale does not exits\n");
                    }
                    else if(var[id].type==2){
                        printf("It is not a numaric variable\n");
                    }
                    else if(var[id].type==0) {
                        $$ = var[id].ival[0];
                        setTemporaryValue(1);
                    }
                    else{
                        $$ = var[id].dval[0];
                        setTemporaryValue(2);
                    }
                }
            | '+' expression
                {
                    $$ = $2;
                }
            | '-' expression
                {
                    $$ = -$2;
                }
            | expression '+' expression         
                {
                    $$ = $1 + $3;
                }
            | expression '-' expression         
                {
                    $$ = $1 - $3;
                }
            | expression '*' expression
                {
                    $$ = $1 * $3;
                } 
            | expression '/' expression         
                {
                    $$ = $1 / $3;
                }
            | expression '%' expression         
                {

                    $$ = (int)$1 % (int)$3;
                }
            | expression '<' expression         
                {
                    $$ = ($1 < $3);
                }
            | expression '>' expression         
                {
                    $$ = ($1 > $3);
                }
            | expression LESSEQL expression        
                {
                    $$ = ($1 <= $3);
                }
            | expression GREATEREQL expression     
                {
                    $$ = ($1 >= $3);
                }
            | expression EQL expression        
                {
                    $$ = ($1 == $3);
                }
            | expression NOTEQL expression        
                {
                    $$ = ($1 != $3);
                }
            | expression AND expression         
                {
                    $$ = ( $1 && $3);
                }
            | expression OR expression          
                {
                    $$ = ($1 || $3);
                }
            | expression MXOR expression      
                {
                    $$ = ((int)$1 ^ (int)$3);
                }
            | NOT expression             
                {
                    $$ = !$2;
                }
            | '(' expression ')'          
                {
                    $$ = $2;
                }
            | SIN '(' expression ')'      
                {
                    $$ = sin($3);

                }
            | COS '(' expression ')'      
                {
                    $$ = cos($3);
                }
            | TAN '(' expression ')'      
                {
                    $$ = tan($3);
                }
            | LOG '(' expression ')'      
                {
                    $$ = log10($3);
                }
            | LOG2 '(' expression ')'     
                {
                    $$ = log2($3);
                }
            | SQRT '(' expression ')'     
                {
                    $$ = sqrt($3);
                }
            | VARIABLE DOUBLEPLUS        
                {
                    int id = getVariableIndex($1);
                    if(id==-1) {
                        printf("Variable Does not exit\n");
                    }
                    else if(var[id].type==2) {
                        printf("This is not a numeric variable\n");
                    }
                    else if(var[id].type==1) printf("can't increment real.\n");
                    else {
                        var[id].ival[0]++;
                        $$ = var[id].ival[0];
                        if (getTemporaryValue()==-1){
                            setTemporaryValue(1);
                        }
                    }
                
                }
            | VARIABLE DOUBLEMINUS       
                {
                    int id = getVariableIndex($1);
                    if(id==-1) {
                        printf("Variable Does not exit\n");
                    }
                    else if(var[id].type==2) {
                        printf("This is not a numeric variable\n");
                    }
                    else if(var[id].type==1) printf("can't decrement real.\n");
                    else {
                        var[id].ival[0]--;
                        $$ = var[id].ival[0];
                        if (getTemporaryValue()==-1){
                            setTemporaryValue(1);
                        }
                    }
                }
    ;


%%




int main(int argc, char **argv){

    FILE *fpt;
	fpt=freopen("input.txt","r", stdin);
	yyin = fpt;
	yyout=freopen("output.txt", "w", stdout);
    printf("\n\nProgram completed\n\n\n");
	yyparse();
	return 0;
} 
