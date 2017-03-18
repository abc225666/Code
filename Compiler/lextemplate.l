%{
#define LIST                { strncat(buf, yytext, sizeof(buf) - strlen(buf) - 1); }
#define token(t)            { LIST; if (Opt_Token) printf("<%s>\n", t); }
#define tokenString(t, s)   { LIST; if (Opt_Token) printf("<%s:%s>\n", t, s); }
#define MAX_LINE_LENGTH 257
#define MAX_ID_LENGTH 257
int Opt_Source = 1;
int Opt_Token = 1;
int Opt_Statistic = 1;
int linenum = 1;
char buf[MAX_LINE_LENGTH];
char strCheck[MAX_LINE_LENGTH];

typedef struct identifier
{
    struct identifier* next;
    char id_name[MAX_LINE_LENGTH];
    int id_count;
}identifier;

identifier* id_head;

void st();
void pragmaset();
void idCount();
void ShowId();
void finallize();


%}

delim [\(\)\{\}\[\];,]
op [+\-*/%!=<>]|(<=)|(>=)|(&&)|(\|\|)|(!=)|(==)
KW (while|do|if|else|true|false|for|int|print|const|read|boolean|bool|void|float|double|string|continue|break|return)
letter [a-zA-Z_]
number [0-9]
pragma (^[ \t]*(#pragma)([ \t])+(token|source|statistic)([ \t])+(on|off))

%x comment
%x pragmacomment
%x morepragmacomment


%%

<comment>\n {
    LIST;
    if (Opt_Source)
        printf("%d:%s\n", linenum, buf);
    ++linenum;
    buf[0] = '\0';
}

<comment>. {
    LIST;
}
<comment>"*/" {
    LIST;
    BEGIN 0;
}

<pragmacomment>\n {
    LIST;
    if (Opt_Source)
        printf("%d:%s\n", linenum, buf);
    ++linenum;
    buf[0] = '\0';
}

<pragmacomment>. {
    LIST;
}

<pragmacomment>"*/" {
    LIST;
    BEGIN morepragmacomment;
}

<morepragmacomment>\n {
    LIST;
    if (Opt_Source)
        printf("%d:%s\n", linenum, buf);
    ++linenum;
    buf[0] = '\0';
    BEGIN 0;
}

<morepragmacomment>[ \t] {
    LIST;
}

<morepragmacomment>"/*" {
    LIST;
    BEGIN pragmacomment;
}

<morepragmacomment>. {
    fprintf(stderr, "Error at line %d: %s\n", linenum, yytext);
    exit(1);
}



"/*" {
    LIST;
    BEGIN comment;
}

[ \t] {
    LIST;
}

{pragma}([ \t])*$ {
    pragmaset();
    //printf("normal pragma\n");
    LIST;
}

{pragma}([ \t])*\/\/.*$ {
    pragmaset();
    //printf("// pragma\n");
    LIST;
}

{pragma}([ \t])*"/*" {
    pragmaset();
    //printf("/* pragma\n");
    LIST;
    BEGIN pragmacomment;
}

{delim} {
    
    tokenString("delim",yytext);
}

{op} {
    char tt[strlen(yytext)+5];
    tt[0]='"';
    tt[1]='\0';
    strcat(tt,yytext);
    strcat(tt,"\"\0");
    token(tt);
}

{KW} {
    tokenString("KW",yytext);
}

{letter}({letter}|{number})* {
    idCount();
    tokenString("id",yytext);
}

([1-9]{number}*)|0 {
    tokenString("integer",yytext);
}

{number}+\.{number}+ {
    tokenString("float",yytext);
}

{number}+(\.{number}+)?[Ee][+\-]?{number}+ {
    tokenString("scientific",yytext);
}

\"(\\.|[^\\"\n])*\" {
    
    st();
    tokenString("string",strCheck);
}

\/\/.*$ {
    LIST
}

\n {
    LIST;
    if (Opt_Source)
        printf("%d:%s\n", linenum, buf);
    ++linenum;
    buf[0] = '\0';
}

<INITIAL>. { // Unrecognized character
    fprintf(stderr, "Error at line %d: %s\n", linenum, yytext);
    exit(1);
}

%%

int main( int argc, char **argv )
{
    if (argc >= 2)
    {
        yyin = fopen( argv[1], "r" );
        if ( NULL == yyin ) {
            fprintf( stderr, "Cannot open: %s\n", argv[1] );
            exit(-1);
        }
    }
    else
    {
        yyin = stdin;
    }

    yylex();

    if (Opt_Statistic)
    {
        ShowId();
        // Print frequency table
    }


    free(id_head);

    exit(0);
}

void st()
{
    int index=0;
    int t;
    char ou[MAX_LINE_LENGTH];
    int len=0;
    for(t=0;yytext[t];t++)
    {
        len++;
    }
    for(t=1;t<len-1;t++)
    {
        if(yytext[t]!='\\')
        {
            ou[index++]=yytext[t];
        }
        else
        {
            if(t+1<len-1)
            {
                if(yytext[t+1]=='"' || yytext[t+1]=='\\')
                {
                    ou[index++]=yytext[t+1];
                    t++;
                }
                else
                {
                    ou[index++]=yytext[t];
                    ou[index++]=yytext[t+1];
                    t++;
                }
            }
            else
            {
                ou[index++]=yytext[t];
            }
        }
    }
    ou[index++]='\0';

    for(t=0;t<index;t++)
    {
        strCheck[t]=ou[t];
    }


    return;
}

void pragmaset()
{
    char temp[MAX_LINE_LENGTH];
    char *i;
    char *setting;
    strcpy(temp,yytext);
    strtok(temp," ");
    i=strtok(NULL," ");
    setting=strtok(NULL," ");

    if(strcmp(setting,"on")==0)
    {
        if(!strcmp(i,"token"))
            Opt_Token=1;
        if(!strcmp(i,"source"))
            Opt_Source=1;
        if(!strcmp(i,"statistic"))
            Opt_Statistic=1;
    }
    if(strcmp(setting,"off")==0)
    {
        if(!strcmp(i,"token"))
            Opt_Token=0;
        if(!strcmp(i,"source"))
            Opt_Source=0;
        if(!strcmp(i,"statistic"))
            Opt_Statistic=0;
    }
}

void idCount()
{
    int isFind=0;
    identifier* parser=id_head;
    identifier* pre=NULL;
    while(parser!=NULL && !isFind)
    {
        if(!strcmp(yytext,parser->id_name))
        {
            parser->id_count++;
            isFind=1;
        }
        pre=parser;
        parser=parser->next;
    }
    if(!isFind)
    {
        identifier* p=(identifier*)malloc(sizeof(identifier));
        strcpy(p->id_name,yytext);
        p->id_count=1;
        if(id_head==NULL)
            id_head=p;
        else
            pre->next=p;
    }
    return;
}

void ShowId()
{
    printf("frequencies of identifiers:\n");
    identifier* parser=id_head;
    while(parser!=NULL)
    {
        printf("%s\t%d\n",parser->id_name,parser->id_count);
        parser=parser->next;
    }
    return;
}
