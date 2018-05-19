/* easter.c*/
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int eggs_caught=0,missed_eggs=0,level_count=1,points=0;
int p=0;
// for incrementing the points based on color
int d=0; 
// for color selection
float egg_xc,egg_yc;
// for coordinates of egg
int basket_x,basket_y;
// for coordinates of basket
int a=500,b=500; // for default size of the screen
int l=0, q=0;
// for menu option
int dropped_eggs=0;
float speed_1=1.5,speed_2=2.0,speed_3=2.5,speed_4=3.0;
int orange_egg=0,blue_egg=0,pink_egg=0,yellow_egg=0,white_egg=0,green_egg=0;
int w=48,h=48,t=10,e=9,g=12;
void myinit();
void screen1(int,int);
void egg();
void basket(int,int);
void chick(int,int);
void pr_sc();
void estart();
void color();
void score();
void display(void);
void basket_set(int,int);
void myReshape(int,int);
void keys(unsigned char,int,int);
void menu(int);
void screen2(int,int);

void myinit()
{
	glViewport(0,0,a,b);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,(GLdouble)a,0,(GLdouble)b);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


void screen1(int i,int j)
{
	int k;
	char cat[21]="RIGHT CLICK FOR MENU";
	char bor[3]="OR";
	char hatch[17]="Press L to begin";
	char text[7]="EASTER";
	char text2[7]="BASKET";
	glColor3f(0,1,0);
	glRasterPos2i(150,180);
	for(k=0;k<21;k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cat[k]);
	glColor3f(1,1,1);
	glRasterPos2i(250,150);
	for(k=0;k<3;k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,bor[k]);
	glColor3f(1,0,0);
	glRasterPos2i(200,120);
	for(k=0;k<17;k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,hatch[k]);


	glColor3f(0.0,0.3,0.8);
	glRasterPos2i(74,300);
	for(k=0;k<7;k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[k]);

glColor3f(0.0,0.3,0.8);
glRasterPos2i(240,300);
for(k=0;k<7;k++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text2[k]);



glColor3f(1,1,1);
egg_xc=210;
egg_yc=300;
egg();
chick(210,420);
basket(330,0);
}

void screen2(int i, int j)
{
	int a1=i, a2=j;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	int k;
	char n1[12]="Created by:";
	char n2[28]="M.V. SRIVIJAY & KEVIN JACOB";
	char n3[11]="GAME OVER!";	
	glColor3f(0.0,0.3,0.8);
	glRasterPos2i(160,150);
	for(k=0;k<12;k++)
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18,n1[k]);
		
	glColor3f(0.0,0.3,0.8);
	glRasterPos2i(90,110);
	for(k=0;k<28;k++)
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18,n2[k]);
		
	glColor3f(1.0,1.0,0.0);
	glRasterPos2i(150,360);
	for(k=0;k<11;k++)
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,n3[k]);
	
	glColor3f(1,1,0);	
	glBegin(GL_LINE_LOOP);
	glVertex2f(a1,a2);
	glVertex2f(a1+w,a2);
	glVertex2f(a1+w,a2+h/2);
	glVertex2f(a1+w/2-t/2,a2+h/2);
	glVertex2f(a1+w/2-t/2,a2+h/2-3*t/4);
	glVertex2f(a1+w-t,a2+h/2-3*t/4);
	glVertex2f(a1+w-t,a2+t);
	glVertex2f(a1+t,a2+t);
	glVertex2f(a1+t,a2+h-t);
	glVertex2f(a1+w,a2+h-t);
	glVertex2f(a1+w,a2+h);
	glVertex2f(a1,a2+h);
	glEnd();
	glFlush();
	
	a1+=g+w;
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(a1,a2);
	glVertex2f(a1+w,a2);
	glVertex2f(a1+w,a2+h/2);
	glVertex2f(a1+w/2-t/2,a2+h/2);
	glVertex2f(a1+w/2-t/2,a2+h/2-3*t/4);
	glVertex2f(a1+w-t,a2+h/2-3*t/4);
	glVertex2f(a1+w-t,a2+t);
	glVertex2f(a1+t,a2+t);
	glVertex2f(a1+t,a2+h-t);
	glVertex2f(a1+w,a2+h-t);
	glVertex2f(a1+w,a2+h);
	glVertex2f(a1,a2+h);
	glEnd();
	glFlush();

	
	
	
		
}	
void egg()
{
float x,y,z;
int t;
glBegin(GL_POLYGON);
for(t=0;t<=360;t+=1)
{
x = egg_xc+8*(cos(t));
y = egg_yc+16*(sin(t));
z = 0;
glVertex3f(x,y,z);
}
glEnd();
}


void basket(int i,int j)
{
j=10;
if(i>=a-60)i=a-60;
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(0.0+i,30.0+j);
glVertex2f(10.0+i,10.0+j);
glVertex2f(50.0+i,10.0+j);
glVertex2f(60.0+i,30.0+j);
glEnd();
}


void chick(int i,int j)
{
	glColor4f(1.0,1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(i-15,j);
	glVertex2f(i+15,j);
	glVertex2f(i+30,j+15);
	glVertex2f(i+15,j+30);
	glVertex2f(i-15,j+30);
	glVertex2f(i-30,j+15);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(i-15,j);
	glVertex2f(i+15,j);
	glVertex2f(i+60,j-30);
	glVertex2f(i+30,j-60);
	glVertex2f(i-30,j-60);
	glVertex2f(i-60,j-30);
	glEnd();
	
	glColor3f(1.0,0.0,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(i+60,j-30);
	glVertex2f(i-10,j-40);
	glVertex2f(i+75,j-40);
	glEnd();
	
	glColor3f(1.0,0.0,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(i-60,j-30);
	glVertex2f(i+10,j-50);
	glVertex2f(i-75,j-40);
	glEnd();
	
	glPointSize(7.0);
	glBegin(GL_POINTS);
	glVertex2f(i+20,j-65);
	glVertex2f(i-20,j-65);
	glVertex2f(i,j+30);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(i,j);
	glVertex2f(i-10,j+15);
	glVertex2f(i+10,j+15);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2f(i+15,j+20);
	glVertex2f(i-15,j+20);
	glEnd();

glFlush();
}


void pr_sc()
{
	printf("\nLevel reached: %d\n\n",level_count);
	printf("\nNo. of eggs dropped= %d \n",dropped_eggs);
	printf("\nNo. of eggs caught = %d\n",eggs_caught+white_egg);
	printf("\nNo. of eggs missed = %d\n",missed_eggs);
	printf("\nBlue eggs = %d\tpoints gained = %d\n",blue_egg,blue_egg*10);
	printf("\nOrange eggs = %d\tpoints gained = %d\n",orange_egg,orange_egg*10);
	printf("\nGreen eggs = %d\tpoints gained = %d\n",green_egg,green_egg*10);
	printf("\nPink eggs= %d\tpoints gained = %d\n",pink_egg,pink_egg*10);
	printf("\nYellow eggs = %d\tpoints gained = %d\n",yellow_egg,yellow_egg*10);
	printf("\nWhite eggs= %d\tgained = %d\n",white_egg,white_egg*10);
	printf("\n\n\nYour Score=%d\n\n",points);
	printf("\n\n Thank you for playing.\n Created by:\n Kevin & Srivijay\n\n");
	getchar();
	exit(0);
}


void estart()
{
	egg_yc=375;
	if(missed_eggs>=10)
	{
		printf("\n\n\t\t\t\tGAME OVER\n\n");
		pr_sc();
	}
	dropped_eggs++;
	
	switch(rand()%9)
	{
		case 0:egg_xc=105;d=rand()%6; break;
		case 1:egg_xc=245;d=rand()%6; break;
		case 2:egg_xc=380;d=rand()%6; break;
		case 5:egg_xc=105;d=rand()%6; break;
		case 3:egg_xc=245;d=rand()%6; break;
		case 4:egg_xc=380;d=rand()%6; break;
		case 7:egg_xc=105;d=rand()%6; break;
		case 6:egg_xc=245;d=rand()%6; break;
		case 8:egg_xc=380;d=rand()%6; break;
	}
}


void color()
{
	switch(d)
	{
		case 0:glColor3f(1,0,1);p=10;break; //pink
		case 1:glColor3f(1,1,0);p=10;break; //yellow
		case 2:glColor3f(0,1,0);p=10;break; //green
		case 3:glColor3f(1,0.4,0);p=10;break; //orange
		case 4:glColor3f(0,0,1);p=10;break; //white
		case 5:glColor3f(1,1,1);p=10;break; //blue
			
	}
}


void score()
{
	if(egg_yc<=50 && (egg_xc>=basket_x&&egg_xc<=basket_x+60))
	{
		printf("\a");
		eggs_caught++;
		switch(d)
		{
			case 0: pink_egg++;break;
			case 1: yellow_egg++;break;
			case 2: green_egg++;break;
			case 3: orange_egg++;break;
			case 4: white_egg++;break;
			case 5: blue_egg++;break;
		}
		points+=p;
		egg_yc=-10;
	}
	missed_eggs=dropped_eggs-eggs_caught;
}

void display(void)
{
	int i;
	
	char level1[12]="LEVEL 1";
	char level2[12]="LEVEL 2";
	char level3[12]="LEVEL 3";
	char level4[12]="LEVEL 4";
	glClear(GL_COLOR_BUFFER_BIT);
		if(l>=1)
		{
			if(level_count==1)
			{
				glColor3f(1,1,1);
				glRasterPos2i(400,300);
				for(i=0;i<12;i++)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level1[i]);
			}
			else if(level_count==2)
			{
				glColor3f(1,1,1);
				glRasterPos2i(400,300);
				for(i=0;i<12;i++)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level2[i]);
			}
			else if(level_count==3)
			{
				glColor3f(1,1,1);
				glRasterPos2i(400,300);
				for(i=0;i<12;i++)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level3[i]);
			}
			if(level_count==4)
			{
				glColor3f(1,1,1);
				glRasterPos2i(400,300);
				for(i=0;i<12;i++)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level4[i]);
			}
			chick(105,440);
			chick(245,440);
			chick(375,440);
			if(egg_yc<=10)
				estart();
				color();
				egg();
			basket(basket_x,basket_y);
			if(eggs_caught>=10)
			{
				egg_yc-=speed_2;
				level_count=2;
				if(missed_eggs==10)
				{
					screen2(170,400);
					glFlush();
				}
			}
			if(eggs_caught>=20)
			{
				egg_yc-=speed_3;
				level_count=3;
				if(missed_eggs==10)
				{
					screen2(170,400);
					glFlush();
				}
			}
			if(eggs_caught>=30)
			{
				egg_yc-=speed_4;
				level_count=4;
				if(missed_eggs==10)
				{
					screen2(170,400);
					glFlush();
				}
				
			}
			else
			egg_yc-=speed_1;
			score();
			if(missed_eggs==10)
				{
					
					screen2(170,400);
					glFlush();
				}
			
		}
		else  if(q==1)
		{
			screen2(170,400);
			glFlush();
		}
			
		
		else
			screen1(40,300);
		
		glFlush();
	glutSwapBuffers();
	
		
}


void basket_set(int a,int b)
{
basket_x=a;
basket_y=b;
glutPostRedisplay();
}


void myReshape(int w,int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glViewport(0,0,w,h);
a=w;
b=h;
}


void keys(unsigned char key,int x,int y)
{
if(key=='q'||key=='Q')
{
printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
pr_sc();
}
if(key=='l'||key=='L') l=1;
if(key=='a'||key=='A')
{
basket_x-=10;
if(basket_x<=0) basket_x=10;
}
if(key=='d'||key=='D')
{
basket_x+=10;
if(basket_x>=500) basket_x=490;
}
}

void menu(int id)
{
switch(id)
{
case 1: l=1;
break;
case 2:pr_sc();
break;
case 3: printf("\n\n\n\t\tQUIT BY PLAYER\n");
break;
default:exit(0);
}
glutPostRedisplay();
}


int main(int argc,char **argv)
{
printf("******************************************************************");
printf("\n\t\t\t\t EASTER BASKET \n\n");
printf("******************************************************************");
printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");
printf("\n <2> To Start, press key 'l' or 'l' or \n\tClick Right mouse button then click 'Start Game'.\n");
printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");
printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");
printf("\n\n\n SCORE : White Egg = 10 point\n\t ->Green Egg = 10 points\n\t ->Orange Egg= 10 points\n\t ->Pink Egg = 10 points\n\t ->Yellow egg = 10 points\n\t ->Blue Egg = 10 points\n");
printf("\nFor each level, speed increases\n\n");
printf("\n\nBEST OF LUCK\n");
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(a,b);
glutCreateWindow("EASTER BASKET");
myinit();
glutCreateMenu(menu);
glutAddMenuEntry("Start game",1);
glutAddMenuEntry("score",2);
glutAddMenuEntry("Quit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display);
glutKeyboardFunc(keys);
glutPassiveMotionFunc(basket_set);
glutIdleFunc(display);
glutReshapeFunc(myReshape);
glutMainLoop();
}

