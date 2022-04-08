// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B
     glColor3f(1.0f, 1.0f, 1.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(-50,-50);
               glVertex2i(-50,50);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 0.0f, 0.0f);
               glVertex2i(50,50);
               glVertex2i(50,-50);
     glEnd();

     glBegin(GL_LINES);
                glColor3f(1.0f, 0.0f, 0.0f);
                glVertex2i(0,250);
                glVertex2i(0,-250);
     glEnd();

     //desenha a linha vertical
     glBegin(GL_LINES);
                glVertex2i(250,0);
                glVertex2i(-250,0);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
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
     Inicializa();
     glutMainLoop();
}
