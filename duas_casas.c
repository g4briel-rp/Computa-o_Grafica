// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

GLint tx1, tx2, ty1, ty2, angulo1, angulo2;
GLfloat ex1, ex2, ey1, ey2, casa;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente
    //         R     G     B
    glColor3f(0.0f, 0.0f, 1.0f);

    //Expessura da linha
    glLineWidth(1);

    //desenha a linha horizontal
    glBegin(GL_LINES);
    glVertex2i(0,250);
    glVertex2i(0,-250);
    glEnd();

    //desenha a linha vertical
    glBegin(GL_LINES);
    glVertex2i(250,0);
    glVertex2i(-250,0);
    glEnd();

    //Expessura da linha
    glLineWidth(3);

    glPushMatrix();

    //operações de translação, escala e rotação
    glTranslatef(tx1, ty1, 0);
    glScalef(ex1, ey1, 1);
    glRotatef(angulo1, 0, 0, 1);

    // Desenha uma casa centralizada na origem
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(50,45);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(0,100);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(-50,45);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(50,-44);
    glVertex2i(50,44);
    glVertex2i(-50,44);
    glVertex2i(-50,-44);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    //operações de translação, escala e rotação
    glTranslatef(tx2, ty2, 0);
    glScalef(ex2, ey2, 1);
    glRotatef(angulo2, 0, 0, 1);

    // Desenha uma casa centralizada na origem
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(60,110);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(110,150);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(160,110);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(60,10);
    glVertex2i(60,109);
    glVertex2i(160,109);
    glVertex2i(160,10);
    glEnd();

    glPopMatrix();

    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1.0f, 1.0f, 1.f, 1.0f);

    tx1 = tx2 = ty1 = ty2 = angulo1 = angulo2 = 0;
    ex1 = ey1 = ex2 = ey2 = casa = 1;
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    gluOrtho2D (-250.0f, 250.0f, -250.0f, 250.0f);
}

void TeclasEspeciais(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_PAGE_UP:
        if (casa==1) angulo1+=5;
        if (casa==2) angulo2+=5;
        break;
    case GLUT_KEY_PAGE_DOWN:
        if (casa==1) angulo1-=5;
        if (casa==2) angulo2-=5;
        break;
    case GLUT_KEY_HOME:
        if (casa==1)
        {
            ex1+=1;
            ey1+=1;
        }
        if (casa==2)
        {
            ex2+=1;
            ey2+=1;
        }
        break;
    case GLUT_KEY_END:
        if (casa==1)
        {
            ex1-=1;
            ey1-=1;
        }
        if (casa==2)
        {
            ex2-=1;
            ey2-=1;
        }
        break;
    case GLUT_KEY_UP:
        if (casa==1) ty1+=2;
        if (casa==2) ty2+=2;
        break;
    case GLUT_KEY_DOWN:
        if (casa==1) ty1-=2;
        if (casa==2) ty2-=2;
        break;
    case GLUT_KEY_LEFT:
        if (casa==1) tx1-=2;
        if (casa==2) tx2-=2;
        break;
    case GLUT_KEY_RIGHT:
        if (casa==1) tx1+=2;
        if (casa==2) tx2+=2;
        break;
    case GLUT_KEY_F1:
        casa = 1;
        break;
    case GLUT_KEY_F2:
        casa = 2;
        break;
    }
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char ** argv)

{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(500, 200);
    glutCreateWindow("Quadrado preto e branco");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutSpecialFunc(TeclasEspeciais);
    Inicializa();
    glutMainLoop();
}
