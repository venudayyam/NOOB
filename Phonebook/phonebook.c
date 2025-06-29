/* A program which implements phone book
  *
  * complete exceptional handled program
  * user friendly error messages
  *
*/

#include<stdio.h>
#include<string.h >
#include<stdlib.h>
#include<ctype.h>
#define MAX_NO 15
#define MAX_NAME  26
#define NEW_CONTACT   (pb* ) malloc (sizeof ( pb ) ) ;
#define NEW_NAME  (char * ) malloc ( strlen ( temp_name) +1 )
#define NEW_NUMBER (char * ) malloc ( MAX_NO )


typedef struct phonebook {           /* Heart of the program  */

    char * name ;
    char * no ;
    struct  phonebook * next ;

} pb ;

pb * root = NULL ;  /* head node */

void add_contact( pb * node ) ;    /* To perform various tasks */
void print_book( pb * node ) ;
void delete_contact ( char * ) ;
void edit_contact (pb * ) ;
void get_details () ;
void store_detalis(pb *) ;
void search ( pb * node , char * ) ;
int duplicate_check(char * , char * ) ;

void read_file() ;      /* file operations */
void write_file () ;

int check_name (char *) ;  /* presentation and exception check */
int check_no (char *) ;
void head() ;
void tail() ;
int home() ;

char temp_name[ MAX_NAME ] ;    /*  global variables  */
char temp_no [ MAX_NO ] ;
int count=-1 ;
int file_access =0 ;
int case_flag =0 ;
FILE *ptr ;



int main ( )
{
    read_file() ;

    while (home() ) {

        printf("\n\n\n press any key...... ") ;
        getchar() ;
        fflush(stdin) ;
    }
    write_file( root ) ;
}



void split ( char * ptr )
{
    char name [ 30 ] ;
    char no [ 15 ] ;

    char * ch = name ;

    while ( *ptr )
    {
        if ( *ptr == '=' )
        {
            *ch = '\0' ;
            ch = no ;
        }
        else
        {
            *ch=*ptr ;
            ch++  ;
        }
         ptr ++ ;
    }
    *ch='\0' ;


    strcpy( temp_name , name ) ;
    strcpy( temp_no , no ) ;

}


void read_file () {                 /* read all contacts from file when program starts */

    char out [ 44 ] ;
    file_access=1 ;
    ptr = fopen("contacts.txt" , "r" ) ;
    int ch ;
    char * cptr = out ;

   while ( ( ch = getc (ptr) ) != EOF )
    {
        if ( ch == '\n')
        {
            *cptr ='\0'  , split ( out )  ;
             add_contact(root) ;
             cptr = out ;
        }
        else
        {
            *cptr = ch ;
            cptr++ ;
        }
    }

    fclose(ptr) ;
    remove("contacts.txt") ;
    file_access=0 ;

}

char *  merge ( char * name , char * no )
{
    static char temp[ 44 ] ;

    strcpy ( temp , name ) ;
    strcat ( temp , "=" ) ;
    strcat ( temp , no ) ;
    strcat ( temp , "\n" ) ;
    return temp ;
}

void write_file( pb * node ) {               /* saving all contacts in a file before terminating */

    ptr = fopen("temp.txt" , "w" ) ;
    char temp[ 44 ] ;

    while ( node != NULL ) {

        fputs( strcpy ( temp , merge ( node->name , node->no ) ) , ptr ) ;
        node=node->next ;
    }
    getchar() ;
    fclose( ptr ) ;
    rename("temp.txt" , "contacts.txt" ) ;

}

void format (pb * temp ) {

    if (temp==NULL) {

        root=NULL ;
        return ;
    }

    format( temp->next ) ;
    free(temp) ;
 }

int duplicate_check(char * name , char * no ) {        /* checks for duplicate contact name/no */

        pb * temp = root ;

        char *ptr = (char *) malloc (40) ;
        strcpy(ptr , name ) ;
        if(islower(*ptr) )
            strupr(ptr) ;
        else
            strlwr(ptr) ;

        while (temp!=NULL) {

            if (strcmp(temp->name , temp_name )==0  || strcmp(temp->name , ptr )==0  ) {

                printf("\n\nError : contact already exists.....!! " ) ;
                return 1 ;
            }
            if ( strcmp(temp->no , temp_no ) ==0 ) {

                printf("\n\n Error : Number already exists with different name ....!! " ) ;
                return 2 ;
            }
            temp=temp->next ;
        }
        return 0 ;
}


void delete_contact(char * name ) {

    pb* temp = root ;
    pb* node ;

    if (root==NULL) {
        printf("\n Error : Phone Book Empty..!! ") ;
        return ;
    }

    if ( strcmp ( root->name , temp_name ) ==0 ) {

        node =root->next ;
        free( root )  ;
        root= node ;
        printf("\n Contact deleted successfully...!! ") ;
        return ;
    }

    while ( temp->next != NULL ) {

        if (strcmp(temp->next->name , temp_name ) ==0 )  {

            node = temp->next->next ;
            free(temp->next) ;
            temp->next = node ;
            printf("\n Contact deleted successfully...!! ") ;
            return ;
        }
        temp=temp->next ;
    }
    printf("\nError : contact not found...!! ") ;
}






int  home () {                    /* home page */

        system("cls") ;
        char ch ;
        int i , j ;
        printf("\n\n\t\t  WELCOME TO PHONEBOOK DATABASE " ) ;

        printf("\n\n\n FUNCTIONS " ) ;
        printf("\n\n\n 1 . Add single contact " ) ;
        printf("\n\n 2 . Add multiple contacts " ) ;
        printf("\n\n 3 . Edit contact   " ) ;
        printf("\n\n 4 . Delete contact   " ) ;
        printf("\n\n 5 . Search contact " ) ;
        printf("\n\n 6 . Format DataBase  " ) ;
        printf("\n\n 7 . Print Entire Phone Book " ) ;


        printf ("\n\n\n\n\n\n Enter your choice  : " ) ;
        ch = getchar() ;

        fflush(stdin) ;
        system("cls" ) ;

        switch (ch) {

        case '1' : add_contact(root) ;
                        break ;
        case '2' : printf("\nEnter the no.of contacts you wish to add : " ) ;
                        scanf("%d" , &i)  ;
                        for (; i>0 ; i--)
                            add_contact(root) ;
                        break ;

        case '5' : do {
                              printf("\n\n Enter Contact Name or Number  : " ) ;
                              gets(temp_name) ;
                        } while (strlen(temp_name)==0 ) ;

                        search(root , temp_name ) ;
                        break ;

        case '4' : do {
                              printf("\n\n Enter Contact Name   : " ) ;
                              gets(temp_name) ;
                        } while (strlen(temp_name)==0 ) ;

                       delete_contact( temp_name ) ;
                        break ;

        case '3' :  edit_contact ( root ) ;
                        break ;

        case '7' :  print_book(root) ;
                        break;
        case '6'  : printf("\n Caution : Entire data will be formated . Is that ok ???  ( press Y / any other key )  : " ) ;
                        ch= getchar() ;
                        if(ch=='Y' || ch=='y' ) {
                                format( root) ;
                                printf("\n Successful....!!! ") ;
                        } else
                        printf("\n\n Process aborted  " ) ;
                        break ;
        default :  printf("\n\n\nThank You ....!! \n\n") ;
                       return 0;

        }

        return 1 ;

}

void  search( pb * node , char * temp_str ) {                     /* search contact */

        int found=0 ;

        char * t_str = (char * ) malloc (40) ;
        strcpy ( t_str , temp_str ) ;
        if (isupper(*t_str))
            strlwr(t_str) ;

         head() ;
        while (node!=NULL) {

            if ( strstr( node->name , temp_str )  || strstr(node->no , temp_str )  ||  strstr(node->name , t_str ) )
                    printf("\n %4d     %-30s %-11s" , ++found , node->name , node->no ) ;

            node= node->next ;
        }

        if (!found)
            printf("\n\n\t\t No results found \n")  , tail() ;
        else
            tail() , printf ("\n\n %d result%c found " , found ,  found==1? ' ': 's' ) ;

}


void store_detalis (pb * temp ) {             /* allocate memory dynamically for  node , contact name , number  */

    temp->name = NEW_NAME ;
    temp->no = NEW_NUMBER ;
    strcpy ( temp->name , temp_name ) ;
    strcpy ( temp->no , temp_no ) ;
    count++ ;
    printf("\n\n Successful !! \n") ;
}




void add_contact ( pb * node ) {

    pb * ptr = node ;                     /* temp pointer variable */

     if ( !file_access ) {

        get_details( ) ;           /* function asks for contact details */

        if ( duplicate_check(temp_name , temp_no)  )
        return ;

     }


    if (root == NULL ) {

         root = NEW_CONTACT ;
         store_detalis( root )  ;
         root ->next = NULL ;
         return ;
    }

    if ( strcmp ( temp_name , node->name ) == -1 ) {

        root =NEW_CONTACT ;
        store_detalis(root) ;    /* modifying root node */
        root ->next = ptr ;
        return ;
    }

    while ( node -> next != NULL ) {

        if (strcmp( temp_name , node->name ) ==1  &&  strcmp ( temp_name ,  node->next->name ) <=0 )
            break ;
        node = node->next ;
     }

    ptr = node->next ;           /*  storing the  next address in ptr (temporarily) */
    node->next = NEW_CONTACT ;
    store_detalis(node->next ) ;
    node= node->next ;
    node ->next = ptr ;    /* re linking to the next node */

}

int check_name (char * ptr  ) {                 /* exception check for name */

    if ( strlen (ptr) > MAX_NAME ||  strlen(ptr) <1 ) {
        printf(" Error : Length exceeded or No input ( max 25 ) ") ;
        return 1 ;
    }

    for ( ;  *ptr ; ptr++)

        if ( !isalpha (*ptr ) && *ptr != ' ' ) {

            printf( " Error : Invalid characters used ( only alphabets allowed ) " ) ;
            return 1 ;
        }

    return 0 ;
}


int check_no (char * ptr  ) {                     /* exception check for number  */

    if ( strlen (ptr)!=10  ||   ( *ptr !='7'  && *ptr !='8'  &&  *ptr !='9'  )   )  {
        printf(" Error : Invalid Number  ( enter a ten digit number , starting with 9 or 8 or 7 )\n") ;
        return 1 ;
    }

    for ( ;  *ptr ; ptr++)

        if ( ! isdigit (*ptr ) ) {

            printf( " Error : Invalid characters used ( only digits allowed ) \n" ) ;
            return 1 ;
        }

    return 0 ;
}

void get_details() {                                 /* prompts user for name,number */

    fflush(stdin) ;

    do {
            printf("\n\n Enter Contact Name   : " ) ;
            gets(temp_name) ;      /* global variables */

    } while ( check_name (temp_name) ) ;

    strlwr(temp_name) ;

    do {
            printf("\n Enter Mobile Number  : " ) ;
            gets(temp_no) ;      /* global variables */

    } while ( check_no (temp_no) ) ;

}


void head() {

    system("cls" ) ;
    printf("\n%-50s" , "------------------------------------------------------- " ) ;
    printf("\n %-8s %-29s %-11s" , "SL.NO" ,"CONTACT NAME " , "MOBILE NUMBER " ) ;
    printf("\n%-50s" , "------------------------------------------------------- " ) ;

}

void tail() {

    printf("\n%-50s" , "------------------------------------------------------- \n\n" ) ;

}

void print_book ( pb * node ) {                    /* print entire phone book */

    int i =0 ;

    head();
    if (node==NULL)
        printf("\n\n\t    \t List is Empty \n" ) ;
    else
    while (node!=NULL) {

        printf("\n %4d     %-30s %-11s" , ++i , node->name , node->no ) ;
        node=node->next;
    }
    tail() ;
}



void edit_contact(pb * node ) {            /* considered all possible outcomes  */

        int i ;
        pb * gptr ;

        do {
                printf("\n\n Enter Contact Name   : " ) ;
                gets(temp_name) ;

        } while ( check_name (temp_name) ) ;

        while (node!=NULL) {

            if ( strcmp(node->name , temp_name ) == 0 ) {

                system("cls") ;
                printf("\n Contact Found \n Enter New Details " ) ;
                get_details() ;

                if ( strcmp( node->no , temp_no ) ==0  && strcmp (temp_name, node->name  )==0) {
                        printf("\n\n No Changes Made ...!! ") ;
                        return ;
                }
                else if ( strcmp (node->name , temp_name ) ==0 ) {

                    gptr = root ;
                    while ( gptr!=NULL ) {
                            if ( strcmp (gptr->no , temp_no ) == 0 )  {
                                printf("\n Error : Trying to add duplicate number....!! ") ;
                                return ;
                            }
                            gptr=gptr->next ;
                    }
                    strcpy ( node->no , temp_no  ) ;
                    printf("\n Number Changed...!! " ) ;
                    return ;

                }
                 else if ( strcmp( node->no , temp_no ) ==0 ) {

                        printf("\n\n Name changed...!! ") ;
                        return ;
                }
                else {

                    i = duplicate_check( temp_name , temp_no ) ;
                    if ( !i ) {
                        strcpy(node->name , temp_name ) ;
                        strcpy(node->no , temp_no  ) ;
                        printf("\n Successfully Edited....!! \n") ;
                        return ;
                    }
                    return ;
                }
            }
            node= node->next ;
        }
        printf("\n\n Error : contact found \n\n" ) ;
}
