#include <stdlib.h>
#include <GL/glut.h>

GLfloat angle, fAspect;

void defineIluminacao(){
    GLfloat diffuseLight[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat specularLight[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat spectre[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat lightPos[] = { 600.0, 10.0, 200.0, 1.0 };

    glMaterialfv( GL_FRONT, GL_SPECULAR, spectre );
    glMateriali( GL_FRONT, GL_SHININESS, 128 );
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

    glLightfv( GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv( GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv( GL_LIGHT0, GL_POSITION, lightPos );

    glShadeModel(GL_SMOOTH);
}

void drawPlane(){
     glTranslatef(-0.5,0,-0.5);
     glColor3f(0,0.5,1);
     glBegin(GL_POLYGON);
     glNormal3f( 0, 1, 0 );
     glVertex3f(1,0,1);
     glVertex3f(1,0,0);
     glVertex3f(0,0,0);
     glVertex3f(0,0,1);
     glEnd();
 }

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    // Draw plane
     glPushMatrix();
     glScalef(100,100,100);
     drawPlane();
     glPopMatrix();

    // Draw teapot
     glColor3f(1.0,0.5,0.5);
     glPushMatrix();
     glTranslated( 0, 15, 0 );
     glScaled(20,20,20);
     glutSolidTeapot(1.0);
     glPopMatrix();

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=50;
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );
 }

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	defineIluminacao();

	// Especifica posição do observador e do alvo
    gluLookAt(0,60,150, 0,0,0, 0,1,0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,00);

	PosicionaObservador();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void setupRC(){
    glEnable(GL_LIGHTING);
}

// Programa Principal
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(450,450);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	setupRC();
	glutMainLoop();
}
