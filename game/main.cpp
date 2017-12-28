#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

void criaLogo();
void criaMenu();
void manipulaMenu();
void manipulaOpcao();
void habilitaOpcao1();
void desabilitaOpcao1();
void habilitaOpcao2();
void desabilitaOpcao2();
void habilitaOpcao3();
void desabilitaOpcao3();
void habilitaOpcao4();
void desabilitaOpcao4();
void criaNivel();
void habilitaNivel1();
void desabilitaNivel1();
void habilitaNivel2();
void desabilitaNivel2();
void habilitaNivel3();
void desabilitaNivel3();
void manipulaNivel();
void inicio();
void criaOpcao();
void mostrarManual();
void mostrarSobre();
void campo();
void initialize();
void movebat();
void moveball();
void physics();
void play();
void inicio_campo();
void imprime_vitoria();


struct bat
{
 int length;
 int width;
 int xcoordinate;
 int new_ycoordinate;
 int old_ycoordinate;
}batA, batB; // Cria os dois bastões para cada usuário.

struct ball
{
 int radius;
 int speedx;
 int speedy;
 int old_xcenter;
 int old_ycenter;
 int new_xcenter;
 int new_ycenter;
}ball1;

struct score
{
  int score_A;
  int score_B;
}score_game;

int tipoCampo = 0;
int vel = 0;
int vel_bar = 0;
main(){
	int i, j = 0, gd = DETECT, gm;
 
   	initgraph(&gd,&gm,"C:\\TC\\BGI");
	inicio();
	closegraph();
	return 0;
}

void inicio(){
	criaLogo();
	criaMenu(); 
	criaNivel();
}

void criaLogo(){
   	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	setcolor(7);
    outtextxy(15,160,"ED1-FUMEC");
   
    settextstyle(BOLD_FONT,HORIZ_DIR,10);
    setcolor(WHITE);
    outtextxy(320,130,"S");
   
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(425,180,"PORTS");   
   
    setlinestyle(SOLID_LINE, 0, 6);
    setcolor(BLUE);
    moveto(0, 220);
    lineto(315, 220);
   
    setlinestyle(SOLID_LINE, 0, 6);
    setcolor(BLUE);
    moveto(425, 170);
    lineto(700, 170);         
}

void criaMenu(){

	/*settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(200,280,"1 PLAYER");*/

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(200,310,"JOGAR");
   
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(200,340,"OPÇÕES");
   
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(200,370,"SAIR"); 
	manipulaMenu();	  	
}

void manipulaMenu(){    
		
	int posAtual = 2;	
	char key;	
	desabilitaOpcao1();
	habilitaOpcao2();
	
    do{   
		key = getch();
		
        if (key == KEY_UP){    
		    	
        	/*if(posAtual==1){ 
				desabilitaOpcao2();             		  		
        		posAtual = 1;
        		habilitaOpcao1(); 
        		
			}else*/ if(posAtual==2){				
				//desabilitaOpcao2();				
				posAtual = 2;
				habilitaOpcao2();
				   					
			}else if(posAtual==3){				
				desabilitaOpcao3();
				posAtual = 2;
				habilitaOpcao2();	
							
			}else if(posAtual==4){	
				desabilitaOpcao4();			
				posAtual = 3;
				habilitaOpcao3();				
			}		        		
		}
		else if(key == KEY_DOWN){
					
		/*	if(posAtual==1){
				desabilitaOpcao1();
        		posAtual = 2;
				habilitaOpcao2();
				           		
			}else*/ if(posAtual==2){
				desabilitaOpcao2();				
				posAtual = 3;
				habilitaOpcao3();
				   					
			}else if(posAtual==3){
				desabilitaOpcao3();		
				posAtual = 4;
				habilitaOpcao4();
			}else if(posAtual==4){		
				posAtual = 4;
				habilitaOpcao4();
			}					
		}
		
	/*	if(key == KEY_ENTER && posAtual==1) {
		 tipoCampo = 1;	
		 	setcolor(4);
		 	outtextxy(200,280,"1 PLAYER");	
			criaNivel();
		}*/
		
		if(key == KEY_ENTER && posAtual==2) {
			tipoCampo = 2;	
			setcolor(4);
			outtextxy(200,310,"JOGAR");	
			criaNivel();
		}
		
		if(key == KEY_ENTER && posAtual==3) {
			setcolor(4);
			outtextxy(200,340,"OPÇÕES");
			criaOpcao();
		}
		if(key == KEY_ENTER && posAtual==4) {			
			exit(1);
		}
    }while(true);	
}

void habilitaOpcao1(){
	setcolor(BLUE);
	circle(170, 293, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
    setcolor(BLUE);
    moveto(500, 320);
    lineto(50, 320); */	
}
void desabilitaOpcao1(){
	setcolor(BLACK);
	circle(170, 293, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
    setcolor(BLACK);
    moveto(150, 320);
    lineto(50, 320);*/ 
}

void habilitaOpcao2(){
	setcolor(BLUE);
	circle(170, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 350);
   	lineto(50, 350);*/
}
void desabilitaOpcao2(){
	setcolor(BLACK);
	circle(170, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 350);
   	lineto(50, 350);*/
}

void habilitaOpcao3(){
	setcolor(BLUE);
	circle(170, 353, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaOpcao3(){
	setcolor(BLACK);
	circle(170, 353, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaOpcao4(){
	setcolor(BLUE);
	circle(170, 383, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaOpcao4(){
	setcolor(BLACK);
	circle(170, 383, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaNivel1(){
	setcolor(BLUE);
	circle(370, 303, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaNivel1(){
	setcolor(BLACK);
	circle(370, 303, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaNivel2(){
	setcolor(BLUE);
	circle(370, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaNivel2(){
	setcolor(BLACK);
	circle(370, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaNivel3(){
	setcolor(BLUE);
	circle(370, 343, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaNivel3(){
	setcolor(BLACK);
	circle(370, 343, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaManual(){
	setcolor(BLUE);
	circle(370, 303, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaManual(){
	setcolor(BLACK);
	circle(370, 303, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void habilitaSobre(){
	setcolor(BLUE);
	circle(370, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLUE);
   	moveto(150, 380);
   	lineto(50, 380);*/	
}
void desabilitaSobre(){
	setcolor(BLACK);
	circle(370, 323, 4);
	/*setlinestyle(SOLID_LINE, 0, 3);
   	setcolor(BLACK);
   	moveto(150, 380);
   	lineto(50, 380);*/
}

void criaNivel(){

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(400,290,"FACIL");
    
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(400,310,"MÉDIO");
    
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(400,330,"DIFICIL");
    
    manipulaNivel();
    
}

void manipulaNivel(){
	printf("nivel");	
	desabilitaOpcao1();  
	desabilitaOpcao2();
	desabilitaOpcao3();  
	desabilitaOpcao4();
	
	int posAtualNivel = 1;	
	char key;	
	habilitaNivel1();
	vel = 2;
	vel_bar = 10;
    do{   
		key = getch();
		
        if (key == KEY_UP){    
		    	printf("up\n");
        	/*if(posAtualNivel==1){ 		  		
        		//posAtualNivel = 1;
        		habilitaNivel1();
        		//vel = 10;
        		printf("10\n");
        		
			}else*/ if(posAtualNivel==2){				
				desabilitaNivel2();				
				posAtualNivel = 1;
				habilitaNivel1();
				vel = 2;
				vel_bar = 15;
				printf("20\n");
				   					
			}else if(posAtualNivel==3){				
				desabilitaNivel3();
				posAtualNivel = 2;
				habilitaNivel2();
				vel = 10;	
				vel_bar = 12;
				printf("30\n");
							
			}else{printf("fim");
			}		        		
		}
		else if(key == KEY_DOWN){
					printf("down\n");
			if(posAtualNivel==1){
				desabilitaNivel1();
        		posAtualNivel = 2;
				habilitaNivel2();
				vel = 10;
				vel_bar = 8;
				          printf("10\n"); 		
			}else if(posAtualNivel==2){
				desabilitaNivel2();				
				posAtualNivel = 3;
				habilitaNivel3();
				vel = 20;
				vel_bar = 2;
				   	printf("20\n");				
			}/*else if(posAtualNivel==3){
				//posAtualNivel = 3;
				habilitaNivel3();
				//vel = 30;
				printf("30\n");
			}*/else{printf("fim");
			}					
		}
		
		if(key == KEY_ENTER && posAtualNivel==1) {
			if(tipoCampo == 1){
					//campo1(int nivel);//passar parametro var nivel
					inicio_campo();
			}else if(tipoCampo == 2){
					//campo2(int nivel);//passar parametro var nivel
					inicio_campo();
			}			
		}
		
		if(key == KEY_ENTER && posAtualNivel==2) {
			if(tipoCampo == 1){
					//campo1(int nivel);//passar parametro var nivel
					inicio_campo();
			}else if(tipoCampo == 2){
					//campo2(int nivel);//passar parametro var nivel
					inicio_campo();
			}	
		}
		
		if(key == KEY_ENTER && posAtualNivel==3) {
				if(tipoCampo == 1){
					//campo1(int nivel);//passar parametro var nivel
					inicio_campo();
			}else if(tipoCampo == 2){
					//campo2(int nivel);//passar parametro var nivel
					inicio_campo();
			}	
		}
		if(key == KEY_ESC) {
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(0);
		    outtextxy(400,290,"FÁCIL");
		    
		    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(0);
		    outtextxy(400,310,"MÉDIO");
		    
		    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(0);
		    outtextxy(400,330,"DIFICIL");
		    desabilitaNivel1();  
			desabilitaNivel2();
			desabilitaNivel3();  
			/*setcolor(7);
		    outtextxy(200,280,"1 PLAYER");*/
		
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(7);
		    outtextxy(200,310,"JOGAR");
			
			manipulaMenu();
		}
    }while(true);
}

void criaOpcao(){
	
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(400,290,"MANUAL");
    
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(400,310,"SOBRE");
    manipulaOpcao();
}

void manipulaOpcao(){
	printf("opcao");	
	desabilitaOpcao1();  
	desabilitaOpcao2();
	desabilitaOpcao3();  
	desabilitaOpcao4();
	
	int posAtualPosicao = 1;	
	char key;	
	int nivel = 0;
	habilitaManual();
	
    do{   
		key = getch();
		
        if (key == KEY_UP){    
		    	
        	if(posAtualPosicao==1){ 
				desabilitaSobre();		  		
        		posAtualPosicao = 2;
        		habilitaManual();
			}else if(posAtualPosicao==2){				
				desabilitaManual();				
				posAtualPosicao = 1;
				habilitaSobre();
			}   		
		}
		else if(key == KEY_DOWN){
					
			if(posAtualPosicao==1){
				desabilitaManual();
        		posAtualPosicao = 2;
				habilitaSobre();	           		
			}else if(posAtualPosicao==2){
				desabilitaSobre();				
				posAtualPosicao = 1;
				habilitaManual();	   					
			}					
		}
		
		if(key == KEY_ENTER && posAtualPosicao==1) {
			mostrarManual();		
		}
		
		if(key == KEY_ENTER && posAtualPosicao==2) {
			mostrarSobre();	
		}
		
		if(key == KEY_ESC) {
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(0);
		    outtextxy(400,290,"MANUAL");
		    
		    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(0);
		    outtextxy(400,310,"SOBRE");
		    desabilitaManual();  
			desabilitaSobre(); 
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		    setcolor(7);
		    outtextxy(200,340,"OPÇÕES"); 
			manipulaMenu();
		}
    }while(true);
}

void mostrarManual(){
	cleardevice();
	char key;
			
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
    setcolor(7);
    outtextxy(60,30,"Manual de Ultilização");
    
    setlinestyle(SOLID_LINE, 0, 4);
    setcolor(BLUE);
    moveto(10, 70);
    lineto(315, 70);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    setcolor(7);
    outtextxy(30,80,"Bem vindo ao ED1-FUMEC SPORTS, o melhor jogo de futebol!");
     outtextxy(30,110,"Instruções:");
     outtextxy(30,130,"O objetivo do jogo é marcar gols em seu adversário.");
     outtextxy(30,160,"Movimente seu goleiro para defender e lançar a bola no gol adversário.");
     outtextxy(30,190,"O primeiro a marcar 10 gols será o vencedor!");
     outtextxy(30,220,"Player 1, CAPS LOCK A (cima) e Z (baixo).");
     outtextxy(30,250,"Player 2, CAPS LOCK J (cima) e M (baixo).");
     outtextxy(30,280,"O jogo possui três níveis de dificuldade: FÁCIL, MÉDIO e DIFÍCIL.");
     outtextxy(30,310,"Quanto maior a dificuldade, maior será a ");
     outtextxy(30,340,"     velocidade da bola e mais ágil será o seu goleiro.");
     outtextxy(30,370,"Escolha o nível de dificuldade que você deseja e bom jogo!");
     
	setcolor(4);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(60,400,"Para voltar pressione ESC.");
    key = getch();
    if (key == KEY_ESC){
    	cleardevice();
		inicio();
	}  
    
}

void mostrarSobre(){
	cleardevice();
	char key;
	int x = 60;
	int y = 50;
			
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setcolor(7);
    outtextxy(x,y+=30,"DESENVOLVIDO POR:");
    
    setlinestyle(SOLID_LINE, 0, 6);
    setcolor(BLUE);
    moveto(10, 120);
    lineto(315, 120);
    
    setcolor(7);
    outtextxy(x,y+=60,"CHRISTIANO HENRIQUE");
	   
	setcolor(4);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(x,y+=50,"Para voltar pressione ESC.");
    key = getch();
    if (key == KEY_ESC){
    	cleardevice();
		inicio();
	}  
}
            
void campo(){

	setlinestyle(0, 0, 2);
	setfillstyle(1 , 0);//forma do interior do campo XHATCH_FILL,CLOSE_DOT_FILL com a cor verde
	setcolor(WHITE);//colocar cor branca nas linhas
	//bar(622, 445, 20, 10);//preencher dentro do campo
	line(310, 460, 310, 5);//linha central
	circle(310, 248, 70);//circulo meio campo
	rectangle(5,150,100,350);//area goleiro Esquerdo
	rectangle(7,200,60,300);//area goleiro Esquerdo
	rectangle(630,360,519,150);//area goleiro direito
	rectangle(630,305,565,205);//area goleiro direito
	rectangle(630,430,5,5);//formato do campo
	
//	rectangle(950-20,260,955-5,320);

line(310, 460, 310, 5);//linha central	
}


void imprime_vitoria_1(){
	cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,8);
    setcolor(WHITE);
    outtextxy(10,130,"PLAYER 1 VENCEU");
}

void imprime_vitoria_2(){
	cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,8);
    setcolor(WHITE);
    outtextxy(10,130,"PLAYER 2 VENCEU");
}

void movebat (char input){
	setcolor(WHITE);
  switch (input){
       case 'A' : 
                  if (batA.new_ycoordinate > 0) // Move somente quando bastão não está tocando o topo para que ele não passar para fora da tela.
                    {
                      batA.old_ycoordinate = batA.new_ycoordinate;
                      batA.new_ycoordinate --;
                      setfillstyle (1,0); // Remove última posição.
                      bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
                      setfillstyle (1,15); // Mostra nova posição.
                      bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
                     }
                   break;
       case 'Z' : 
                  if (batA.new_ycoordinate+batA.length < 430) // Certifique-se de o bastão não irá para abaixo da tela.
                    {
                      batA.old_ycoordinate = batA.new_ycoordinate;
                      batA.new_ycoordinate ++;
                      setfillstyle (1,0); // Remove última posição.
                      bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
                      setfillstyle (1,15); // Mostra nova posição.
                      bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
                    }
                  break;
       case 'J' : 
                  if (batB.new_ycoordinate > 0) 
                     {
                      batB.old_ycoordinate = batB.new_ycoordinate;
                      batB.new_ycoordinate --;
                      setfillstyle (1,0); 
                      bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
                      setfillstyle (1,15); 
                      bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
                     }
                  break;

        case 'M' : 
                  if (batB.new_ycoordinate+batB.length < 430) 
                    {
                      batB.old_ycoordinate = batB.new_ycoordinate;
                      batB.new_ycoordinate ++;
                      setfillstyle (1,0); 
                      bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
                      setfillstyle (1,15); 
                      bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
                    }
                   break;
         }    
}

void moveball (){
	campo();
   ball1.old_xcenter = ball1.new_xcenter;
   ball1.old_ycenter = ball1.new_ycenter;
    setfillstyle (1,0); // Remove última posição.
   ball1.new_xcenter = ball1.new_xcenter + ball1.speedx;
   ball1.new_ycenter = ball1.new_ycenter + ball1.speedy;
   
   setfillstyle (1,0); // Remove última posição.
   	setcolor (0);//COR DA BOLA
   fillellipse (ball1.old_xcenter,ball1.old_ycenter,ball1.radius,ball1.radius);
   setfillstyle (1,15); // Mostra nova posição.
   	setcolor (5);//COR DA BOLA
   fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);
   if ( ball1.new_ycenter - ball1.radius < 5 ) ball1.speedy = -ball1.speedy; // Reflete a partir de topo
   if ( ball1.new_ycenter + ball1.radius > 430 ) ball1.speedy = -ball1.speedy; // Reflete a partir do fundo
   
   
   
	//REFLETE SUPERIOR DIREITO
	if ( ball1.new_xcenter - ball1.radius > 610 ){//DISTANCIA DA LINHA DE FUNDO OK
		if ( ball1.new_ycenter + ball1.radius < 205 ){//TAMANHO DAS TRAVE OK
			ball1.speedx = -ball1.speedx;
		}
	}
	//REFLETE INFERIOR DIREITO
	if ( ball1.new_xcenter - ball1.radius > 610 ){//DISTANCIA DA LINHA DE FUNDO
		if ( ball1.new_ycenter + ball1.radius > 305 ){//TAMANHO DAS TRAVE OK
			ball1.speedx = -ball1.speedx;
		}
	}
	//REFLETE SUPERIOR ESQUERDO
	if ( ball1.new_xcenter - ball1.radius < 25 ){//DISTANCIA DA LINHA DE FUNDO
		if ( ball1.new_ycenter + ball1.radius < 200 ){//TAMANHO DAS TRAVE OK
			ball1.speedx = -ball1.speedx;
		}
	}
	//REFLETE INFERIOR ESQUERDO
	if ( ball1.new_xcenter - ball1.radius < 25 ){//DISTANCIA DA LINHA DE FUNDO
		if ( ball1.new_ycenter + ball1.radius > 310 ){//TAMANHO DAS TRAVE OK
			ball1.speedx = -ball1.speedx;
		}
	}
	

}

void physics (){
  char tempstring [10];
  if ( ball1.new_xcenter - ball1.radius <= 20)
     {
         if (ball1.new_ycenter > batA.new_ycoordinate && ball1.new_ycenter < batA.new_ycoordinate+batA.length)
            {
               ball1.speedx = - ball1.speedx;
               ball1.speedy = rand () % 2;
               if (rand() % 2 == 0) ball1.speedy = - ball1.speedy; 
             }
          else // Reiniciar o jogo com a nova pontuação
             {
               score_game.score_B ++;
                cleardevice();
               initialize ();
             }
          return;
      }
  if ( ball1.new_xcenter +  ball1.radius > 620)
      {
         if (ball1.new_ycenter > batB.new_ycoordinate && ball1.new_ycenter < batB.new_ycoordinate+batB.length)
          {
            ball1.speedx = - ball1.speedx;
            ball1.speedy = rand ()%2;
            if (rand() % 2 == 0) ball1.speedy = - ball1.speedy; 
           }
         else 
          {
           score_game.score_A ++;
           cleardevice();
           initialize ();
          }
           return;
       }
}

void play (){     
      char c;
       do{
    	 	delay (vel_bar); // Reduza a velocidade do jogo para nível jogável humano
	    //Comandos do teclado
       if(kbhit())c= getch();
          switch (c){
                case 'A':    movebat ('A'); break;
                case 'Z':    movebat ('Z'); break;
				case 'J':    movebat ('J'); break;
                case 'M':    movebat ('M'); break;
                default: break;
            }
				moveball ();
				physics ();
    }   while ((c != 'q') && (c != 'Q'));
}
       
void inicio_campo (){
	cleardevice();
  score_game.score_A = 0;// Inicializar pontuação no main
  score_game.score_B = 0;// melhora a eficiência
  initialize ();
  play (); // Game Engine - Motor do jogo
}

void initialize (){ // Inicializa o jogo.

  char tempstring [10]; // Esta String detém controla temporariamente a pontuação no formato char 
  time_t t;// Usado para gerar número aleatório de tempo do sistema.
  // Inicializar bastão A
  batA.length = 40;
  batA.width = 5;
  batA.xcoordinate = 10;
  batA.new_ycoordinate = 237;
  batA.old_ycoordinate = 237;
  
 // Inicializar bastão B
  batB.length = 40;
  batB.width = 5;
  batB.xcoordinate = 620;
  batB.new_ycoordinate = 237;
  batB.old_ycoordinate = 237;
  
   // Inicializar Bola
   ball1.radius = 3;
   ball1.speedx = vel;
//	srand((int) time(&t)); // Seed rand -> um número aleatório
   ball1.speedy = rand ()%1;
   if (rand() % 2 == 0){
    	ball1.speedx = - ball1.speedx; // Gerar direção aleatória X.
    	ball1.speedy = - ball1.speedy; // Gerar direção aleatória Y.
    }
    ball1.old_xcenter = 320;
    ball1.old_ycenter = 250;//
    ball1.new_xcenter = 320;
    ball1.new_ycenter = 240;
    
   // Definir fundo para branco
   setbkcolor (BLACK);
   
   // Desenha Bola em Posição Inicial
   setcolor(0);
   setfillstyle (1,15);
   fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);
  
   // Desenha os bastões na posição inicial
   //setcolor(RED);
   bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
   //setcolor(YELLOW);
   bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
  
   // Exibir pontuação
   setcolor(WHITE);
   sprintf (tempstring,"PLAYER 1 - %d",score_game.score_A);
   outtextxy (10,445,tempstring);
   sprintf (tempstring,"PLAYER 2 - %d",score_game.score_B);  
   outtextxy (500,445,tempstring);
   
   if(score_game.score_A == 10){
   		imprime_vitoria_1();
	}else if(score_game.score_B == 10){
   		imprime_vitoria_2();
   	}
}

