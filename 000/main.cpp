#include <GL/glut.h>///�ϥ�glut�~��
int N=0,vx[3000],vy[3000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M��
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);///��@�b �A���@�b  ,�[�t�� ��@�b �A���@�b
    }
    glEnd();

    glutSwapBuffers();///�洫�⭿��buffers
}
void motion(int x,int y)///x�y��,y�y��
{
    vx[N]=x,vy[N]=y;///��vx vy�Ȧs�_��
    N++;
    display();///���mouse motion ��edisplay
}
int main(int argc,char**argv)///glut��l�]�w
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("WEEK04");///����
    glutDisplayFunc(display);///��ܪ����
    glutMotionFunc(motion);///mouse motion�b��
    glutMainLoop();///�D�n�j��
}

