#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>

#define WIDTH 500
#define HEIGHT 500
#define GRID_SIZE 30
#define NUM_ESTRELAS 50

int tamanhoCobra = 3;
int cobra[100][2];
int controle = 0; // 0: direita, 1: esquerda, 2: cima, 3: baixo
int pontos = 0;
int bateu = 0;
int sapo[2];

typedef struct {
    float x, y;
    float velocidade;
} Estrela;

Estrela estrelas[NUM_ESTRELAS];

float r, g, b;

void gerarNumeroCor() {
    r = (float)rand() / RAND_MAX;  
    g = (float)rand() / RAND_MAX;  
    b = (float)rand() / RAND_MAX;  
}

void desenhaCobra(int x, int y){
	glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}

void desenhaSapo(int x, int y) {
    float r = (float)rand() / RAND_MAX; 
    float g = (float)rand() / RAND_MAX;  
    float b = (float)rand() / RAND_MAX;
    
	glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}


void desenhaTexto(float x, float y, const char* string) {
    glColor3f(1.0, 1.0, 1.0); // Cor do texto
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
    }
}

void InicializarCobra(){
    //incrementa x
    cobra[0][0] = 3;
    cobra[1][0] = 2;
    cobra[2][0] = 1;
    
    //incrementa y;
    cobra[0][1] = 15;
    cobra[1][1] = 15;
    cobra[2][1] = 15;
    
    sapo[0] = rand() % GRID_SIZE;
    sapo[1] = rand() % GRID_SIZE;
    
    for (int i = 0; i < NUM_ESTRELAS; i++) {
        estrelas[i].x = rand() % GRID_SIZE;
        estrelas[i].y = rand() % GRID_SIZE;
        estrelas[i].velocidade = (rand() % 10 + 1) / 100.0f; 
    }
    
    gerarNumeroCor();
}

void desenhaEstrelas() {
    glColor3f(1.0, 1.0, 1.0); 
    for (int i = 0; i < NUM_ESTRELAS; i++) {
        glBegin(GL_POINTS);
        glVertex2f(estrelas[i].x, estrelas[i].y);
        glEnd();
    }
}

void atualizarEstrelas() {
    for (int i = 0; i < NUM_ESTRELAS; i++) {
        estrelas[i].x -= estrelas[i].velocidade; 

        
        if (estrelas[i].x < 0) {
            estrelas[i].x = GRID_SIZE;
            estrelas[i].y = rand() % GRID_SIZE;
        }
    }
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    desenhaEstrelas();
    
    for(int i = 0; i < tamanhoCobra; i++){
        desenhaCobra(cobra[i][0], cobra[i][1]);
    }
    
    desenhaSapo(sapo[0], sapo[1]); 
    
    if (bateu) {
        desenhaTexto(12, GRID_SIZE - 20, "Perdeu!");
        char pontosTexto[50];
        sprintf(pontosTexto, "Pontos: %d", pontos);
        desenhaTexto(12, GRID_SIZE - 22.5, pontosTexto);
    } else {
    	char pontosTexto[50];
        sprintf(pontosTexto, "Pontos: %d", pontos);
        desenhaTexto(1, GRID_SIZE - 1, pontosTexto);
	}
    
    glutSwapBuffers();
}

int verificaColisaoComSapo() {
    if (cobra[0][0] == sapo[0] && cobra[0][1] == sapo[1]) {
        return 1; // Colidiu
    }
    return 0; // Não colidiu
}

int Colisao(){
    for (int i = 1; i < tamanhoCobra; i++) { 
        if (cobra[0][0] == cobra[i][0] && cobra[0][1] == cobra[i][1]) {
            return 1; // Colidiu com o corpo
        }
    }

    if (cobra[0][0] < 0 || cobra[0][0] >= GRID_SIZE || cobra[0][1] < 0 || cobra[0][1] >= GRID_SIZE) {
        return 1; // Colidiu com a parede
    }

    return 0; // Não colidiu
}



void atualizarCobra(){
	if (bateu) return;
	
    for(int i = tamanhoCobra - 1; i > 0; i--){
        cobra[i][0] = cobra[i - 1][0];
        cobra[i][1] = cobra[i - 1][1];
    }
    if(controle == 0){
    	cobra[0][0]++;
	}
	if(controle == 1){
		cobra[0][0]--;
	}
	if(controle == 2){
		cobra[0][1]++;
	}
	if(controle == 3){
		cobra[0][1]--;
	}
	
    if (Colisao()) {
        bateu = 1;
    } else if (verificaColisaoComSapo()) {
      
        pontos += 10; 
        tamanhoCobra++; 
        sapo[0] = rand() % GRID_SIZE;
        sapo[1] = rand() % GRID_SIZE;
    }
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'W':
            if (controle != 3) controle = 2; 
            break;
        case 's':
        case 'S':
            if (controle != 2) controle = 3; 
            break;
        case 'a':
        case 'A':
            if (controle != 0) controle = 1;
            break;
        case 'd':
        case 'D':
            if (controle != 1) controle = 0; 
            break;
    }
}

void timer(int value) {
    atualizarCobra();
    atualizarEstrelas();
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor de fundo branca
    gluOrtho2D(0, GRID_SIZE, 0, GRID_SIZE);
}

// Função principal
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Jogo da Cobra");

    
    init(); 
    InicializarCobra();
    glutDisplayFunc(desenha);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(100, timer, 0);


    glutMainLoop();
    return 0;
}


