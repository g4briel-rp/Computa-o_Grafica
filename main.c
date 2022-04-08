// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

GLint tx, ty, angulo;
GLfloat ex,ey;

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

     //Rotação no eixo z
     glTranslatef(tx, ty, 0);
     glScalef(ex, ey, 1);
     glRotatef(angulo, 0, 0, 1);

     //Desenha uma casa
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

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1.0f, 1.0f, 1.f, 1.0f);

    tx = 0; ty = 0; angulo = 0; ex = 1; ey = 1;
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
        case GLUT_KEY_PAGE_UP: angulo+=10;
        break;
            case GLUT_KEY_PAGE_DOWN: angulo-=10;
            break;
        case GLUT_KEY_HOME:ex+=1;
            ey+=1;
            break;
        case GLUT_KEY_END: ex-=1;
            ey-=1;
            break;
        case GLUT_KEY_UP:ty+=3;
            break;
        case GLUT_KEY_DOWN: ty-=3;
            break;
        case GLUT_KEY_LEFT: tx-=3;
            break;
        case GLUT_KEY_RIGHT: tx+=3;
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
