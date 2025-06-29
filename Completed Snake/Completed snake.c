#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define time_delay  (60-( mul*3))

int tail = 0;
int mul;
char user[30];
int  MAX_X=100 , MAX_Y=25 , MIN_X=10 , MIN_Y=5;
int obj_x , obj_y;
int temp_r=0 , temp_l=0 , temp_b=0 , temp_t=0;
int tail_right=0; tail_bottom=0; tail_left=0 ;  tail_top= 0;
int score=0;
char ch;
int inc;
int queue;
 //==============================QUEUE IMPLEMENTATION ====================================================

struct axis
{
    int x;
    int y;
};
struct data
{

    struct   axis value;
    struct data *next ;
};
typedef struct axis axis ;

typedef struct data data;
data *head=NULL;

void push(axis new1)
{
    data *po;
    if (head==NULL)
    {
        head = (data*) malloc (sizeof(data)) ; queue=1;
        head->value=new1;
        head->next=NULL;
        return ;
    }
        po=head;
        while (po->next!=NULL)
        po=po->next;
        po->next= (data*) malloc (sizeof(data)) ; queue+=1;
        po->next->value=new1;
        po->next->next=NULL;
}

axis pop()
{
        axis res;
        data *que;
        if (head==NULL)
        {
          res.x=0; res.y=0; queue=0;
          return res;
        }
        que=head;
        res= que->value;
        head=head->next; queue-=1;
        free(que) ;
        return res;
  }
//==============================Creating new Fruits ====================================================

new_object()
{
  //  PlaySoundA((HPSTR) "G:\\PARADIGMS\\Programs\\Best Ever -C\\Completed Snake\\sound.wav" , NULL, SND_FILENAME | SND_ASYNC);
    score+=1;
    tail+=1;
    object();
}

object()
{
            int temp_x =wherex();   int temp_y = wherey();
            int x = rand()%90;  int y = rand()%20;
            gotoxy((10+x) , (5+y)) ;

            data * checker = head;
            if (head!=NULL) {
            while (checker->next!=NULL) {
            axis var = checker->value;   while (var.x==wherex() && var.y==wherey()) {
            int x = rand()%90;  int y = rand()%20;
            gotoxy((10+x) , (5+y)) ;
            break;  } ;
            checker=checker->next;
            } }
            obj_x=wherex() ;  obj_y = wherey();
            printf("%c" ,5 ) ; textcolor(1);
            gotoxy(90,3) ;
            printf("SCORE - %2d",score) ;  textcolor(2);
            gotoxy(temp_x, temp_y) ;
}
//=s============================Main Logic ==========================================
go_on(char ch)
{
 switch(ch)
{
          case '2' :  move_bottom();  break;
          case '4' :  move_left();     break;
          case '6' :  move_right();  break;
          case '8' :  move_top();   break;
          default : break;
}
}

char check(char old ,char newer)
{

if (old=='2') { if ( newer == 50 || newer == 56) return old; else {
        if (newer==52) {  fix(wherex(),wherey(), 2 , 4); temp_l=1;  tail_left=0 ;  }
        if (newer==54) {   fix(wherex(),wherey(), 2 , 6); temp_r=1;  tail_right=0; }
        return newer ;} }

if (old=='4') { if ( newer == 54 || newer == 52 ) return old; else{
        if (newer==50) {  fix(wherex(),wherey(), 4 , 2);  temp_b=1;  tail_bottom=0; }
        if (newer==56) {   fix(wherex(),wherey(), 4 , 8); temp_t=1;  tail_top=0; }
  return newer ; } }


if (old=='6') {   if ( newer == 52 || newer ==54 ) return old ; else {
        if (newer==50) { fix(wherex(),wherey(), 6 , 2); temp_b=1;  tail_bottom=0; }
        if (newer==56) {   fix(wherex(),wherey(), 6 , 8); temp_t=1;  tail_top=0; }
     return newer ; }
 }


if (old=='8') { if ( newer == 50 || newer == 56 ) return old; else  {
        if (newer==52) {   fix(wherex(),wherey(), 8 , 4); temp_l=1;  tail_left=0 ; }

        if (newer==54) {  fix(wherex(),wherey(), 8 , 6); temp_r=1;  tail_right=0;

        }
return newer ;} }


}

void fix(int x , int y , int cnst_pre ,int cnst_now)
{
    axis ax;
   switch(cnst_now)
   {
       case  2:
       case  8:
                if (cnst_pre==6) {
                        for (inc=x-tail_right; inc<x ;  inc++) {
                        ax.x=inc; ax.y=y;  push(ax);  } } else
                        if (cnst_pre = 4) {
                        for (inc=x+tail_left; inc>x ;  inc--) {
                        ax.x=inc; ax.y=y; push(ax);  } }  gotoxy(x,y) ;
           break;

            case  6:
            case  4:
                if (cnst_pre==2) {
                        for (inc= y-tail_bottom; inc<y ;  inc++) {
                        ax.x=x ; ax.y=inc;   push(ax);  } } else
                if (cnst_pre = 8 ) {
                        for (inc=y+tail_top; inc >y ;  inc--) {
                        ax.x=x ; ax.y= inc ; push(ax);  } }  gotoxy(x,y) ;
           break;

              }
}

FIX()
{
   while (temp_b )
   {
            if (tail_bottom==tail)
                {   temp_b=0; break; }
            if (tail_bottom<tail)
              ++tail_bottom;
            break;
    }
    while (temp_t )
   {
       if (tail_top==tail)
       {  temp_t=0 ; break; }
       if (tail_top<tail)
       ++tail_top;
       break;
   }
   while (temp_r )
   {
       if (tail_right==tail)
       {  temp_r=0; break; }
       if (tail_right<tail)
        ++tail_right;
       break;
   }
      while (temp_l )
   {
       if (tail_left==tail)
        { temp_l=0; break;}
       if (tail_left<tail)
        ++tail_left;
       break;

    } }


void run ()
{
        int i ;
        char dir ='6';

        while(1)
        {
            if (( (wherex()<=9 || wherex()>=101) ) || (wherey()<=4 || wherey()>=26 ))
            {
               //PlaySoundA((HPSTR) "G:\\PARADIGMS\\Programs\\Best Ever -C\\Completed Snake\\gameover.wav" , NULL, SND_FILENAME | SND_ASYNC);
             return ;  }

                    if (kbhit())
                    {   ch=getch();
                        if (ch=='p' || ch =='P'){
                        printf("%c\b",153); getch(); printf(" \b") ; }
                        if( (ch=='2' || ch == '4' || ch== '6' || ch== '8'))
                        dir =check(dir,ch); else
                        dir=dir;}

                    FIX();
                    axis up;   up=pop();
                    int x_fix=wherex() ;  int y_fix=wherey();
                    while( ! (up.x==0 && up.y==0))
                    {  gotoxy(up.x,up.y);   printf(" "); gotoxy(x_fix,y_fix) ; break; }

                    go_on(dir);

                    data * checker = head;
                    if (head!=NULL) {
                    while (checker->next!=NULL) {
                    axis var = checker->value;
                    if (var.x==wherex() && var.y== wherey()) {
                      //PlaySoundA((HPSTR) "G:\\PARADIGMS\\Programs\\Best Ever -C\\Completed Snake\\gameover.wav" , NULL, SND_FILENAME | SND_ASYNC);
                     return ;  }
                     checker=checker->next;
                    } }

                    if (wherex()==obj_x  && wherey() == obj_y )
                    new_object();

                    if (temp_b==0)  tail_bottom=tail;
                    if (temp_l==0)  tail_left=tail;
                    if (temp_t==0)   tail_top=tail;
                    if (temp_r==0)  tail_right=tail;
        }
//============================================
}

kill (int m , int n , int dir)
{
    gotoxy(m,n);   printf("%c",15);

    switch(dir)
    {
        case 2 :
                            if ( (n-tail_bottom>4) && (!(wherex()-1==obj_x &&  n-tail_bottom==obj_y))  )
                                {  gotoxy(m,n-tail_bottom);  printf(" ");  }
                            gotoxy(m,n+1);
                            break;
        case 4 :       if  ((m+tail_left<101)  && (!(m+tail_left==obj_x &&  wherey()==obj_y))  )
                                {  gotoxy(m+tail_left,n);  printf(" "); }
                            gotoxy(m-1,n);
                            break;
        case 6:         if ( (m-tail_right>9)  && (!(m-tail_right==obj_x &&  wherey()==obj_y))  )
                                {  gotoxy(m-tail_right,n);  printf(" "); }
                            gotoxy(m+1,n) ;
                            break;
        case 8:         if ( (n+tail_top<26)  && (!(wherex()-1==obj_x &&  n+tail_top==obj_y))  )
                                { gotoxy(m,n+tail_top);  printf(" "); }
                            gotoxy(m,n-1);
                            break;
    }
}
//==================================================================================

//==================================================================================

    move_right()
        {
             int xax,yay;
             xax= wherex();  yay=wherey();  printf("%c",153);
             Sleep(time_delay);
             kill(xax,yay,6) ;
        }

    move_left()
        {
             int xax , yay;
             xax= wherex();   yay= wherey();  printf("%c",153);
             Sleep(time_delay);
              kill(xax,yay,4) ;
        }

    move_top()
        {
              int m,n;
              m= wherex();   n= wherey();   printf("%c",153);
               Sleep(time_delay + ((time_delay*36)/100));
               kill(m,n,8) ;
        }

    move_bottom()
        {
             int m,n;
             m= wherex();    n= wherey();   printf("%c",153);
             Sleep(time_delay + ((time_delay*36)/100));
             kill(m,n,2) ;
        }
//==================================================================================

main_outline ()
{
    int i=10;
    gotoxy(9,4);   printf("%c",201);
    for (i=10;i<101;i++)
    printf("%c",120);
    gotoxy(101,4); printf("%c",187);
    for (i=5;i<=26;i++){
    gotoxy(9,i); printf("%c",19);
    gotoxy(101,i); printf("%c",19); }
    gotoxy(9,26);  printf("%c",200);
    for (i=10;i<101;i++)
    printf("%c",120);
    printf("%c",188);

}

board_outline()
{
    int i;
    gotoxy(115,6);
    for (i=115;i<=155;i++)
    printf("%c",120);
    for (i=7;i<=24;i++){
    gotoxy(115,i); printf("%c",19);
    gotoxy(155,i); printf("%c",19); }
    gotoxy(115,25);
    for (i=115;i<=155;i++)
    printf("%c",120);
    gotoxy(119,14);  printf("CONTROL KEYS   ");
    gotoxy(119,16);  printf("   RIGHT     -  num 6 ");
    gotoxy(119,17);  printf("   LEFT      -  num 4 ");
    gotoxy(119,18);  printf("   TOP       -  num 8 ");
    gotoxy(119,19);  printf("   BOTTOM    -  num 2 ");
    gotoxy(119,21);  printf("   PAUSE/PLAY    -   P ");
    textcolor (2);
    gotoxy(119,9);  printf("PLAYER NAME      -- ");
    textcolor (1); fflush(stdin);
    gets(user);
    char muls[4] ; pp:
    gotoxy(119 ,11);      textcolor (2);
    printf("DIFFICULTY(1-10) -- ");    textcolor (1);
    gets(muls);
    mul=atoi(muls) ;  if (mul==0)  goto pp;
    if (mul<1 || mul >10)
    mul=4;
    gotoxy(44,28) ; printf("H U N G R Y   S N A K E ");
    textcolor (2);
    gotoxy(40,15);
     printf ("Press any key to start.....!!!");
  //  PlaySoundA((HPSTR) "G:\\PARADIGMS\\Programs\\Best Ever -C\\Completed Snake\\begin.wav" , NULL, SND_FILENAME | SND_ASYNC);
     getch();
    gotoxy(40,15);
       int ii=0;
       for (ii=0;ii<6;ii++)
        printf("      ");
}

int main ()
{
char high_name[30] ;
 int  high_score;
/* FILE * fp;
fp=fopen("highest_scores.txt" , 'r');
fscanf(fp,"%s %d", &high_name,&high_score) ;
  gotoxy(119,22);  printf("Highest Score :");
 gotoxy(119,23); */
textbackground(15);  textcolor(2);
main_outline();
board_outline();

gotoxy(10,5);   object();
run ();  exit_game();
}
//========game is over==============
void exit_game() {

system("cls");
main_outline();
gotoxy(42,14);  textcolor(12);
printf("Oh "); textcolor(2);
printf("\'%s\'",user);
textcolor(12);   printf(" its Over  !!");
gotoxy(47,16);
printf("You ate "); textcolor(2);
printf("%d ",score); textcolor(12);
score==1?printf("Fruit") : printf("Fruits");
gotoxy(42,22); textcolor(2);
char temp[]="Thank You For Playing....."; int i;
for (i=0;i<strlen(temp);i++)
{
    printf("%c",temp[i]);
    Sleep(45);
}
  getch(); gotoxy(3,28);
}
