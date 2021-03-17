#include <GL/glut.h>///使用glut外掛
int N=0,vx[3000],vy[3000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清空
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);///減一半 再除一半  ,加負號 減一半 再除一半
    }
    glEnd();

    glutSwapBuffers();///交換兩倍的buffers
}
void motion(int x,int y)///x座標,y座標
{
    vx[N]=x,vy[N]=y;///把vx vy值存起來
    N++;
    display();///邊動mouse motion 邊畫display
}
int main(int argc,char**argv)///glut初始設定
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);///顯示模式
    glutCreateWindow("WEEK04");///視窗
    glutDisplayFunc(display);///顯示的函示
    glutMotionFunc(motion);///mouse motion在動
    glutMainLoop();///主要迴圈
}

