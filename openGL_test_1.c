#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
GLfloat Delta_x = 0.0,Delta_y=0.0;
GLint R = 1.0, G = 0.0, B = 1.0;
GLint count = 0;
void MyDisplay() {
    glViewport(0, 0, 1000, 1000);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(R, G, B); //(R,G,B)
    glBegin(GL_POLYGON);
    glVertex3f(TopLeftX / 1000.0 + Delta_x, (1000 - TopLeftY) / 1000.0 - Delta_y, 0.0);
    glVertex3f(TopLeftX / 1000.0 + Delta_x, (1000 - BottomRightY) / 1000.0 - Delta_y, 0.0);
    glVertex3f(BottomRightX / 1000.0 + Delta_x, (1000 - BottomRightY) / 1000.0 - Delta_y, 0.0);
    glVertex3f(BottomRightX / 1000.0 + Delta_x, (1000 - TopLeftY) / 1000.0 - Delta_y, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {     //마우스를(GLUT_UP은 뗏을때)눌렀을때를 왼쪽상단부터 X,Y좌표 설정
        Delta_x = 0.0;
        Delta_y = 0.0;
        TopLeftX = X;
        TopLeftY = Y;

    }
}

void MyMouseMove(GLint X, GLint Y) {
   
    BottomRightX = X;
    BottomRightY = Y;       //마우스를 움직였을때 해당 X,Y좌표를 오른쪽하단에 위치
    glutPostRedisplay();        //다시 MYDISPLAY실행
}

void MyTimer(int Value) {
    printf("---------------\n|%lf  %lf|\n|%lf  %lf|\n---------------\n", (TopLeftX)+(Delta_x * 1000),(TopLeftY) + (Delta_y * 1000),(BottomRightX)+(Delta_x*1000),(BottomRightY)+(Delta_y*1000));
    if ((BottomRightX + (Delta_x*1000) )> 1000) {
        count =1;
    }
    else if ((BottomRightY + (Delta_y * 1000))> 1000) {
        count = 2;
    }
    else if ((TopLeftX + (Delta_x * 1000)) < 0) {
        count = 3;
    }
    else if ((TopLeftY + (Delta_y * 1000)) < 0) {
        count = 0;
    }
    switch (count) {
    case 0:
        Delta_x = Delta_x + 0.001; 
        Delta_y = Delta_y + 0.001;
        break;
    case 1:
        Delta_x = Delta_x - 0.001;
        Delta_y = Delta_y + 0.001;
        break;
    case 2:
        Delta_x = Delta_x - 0.001;
        Delta_y = Delta_y - 0.001;
        break;
    case 3:
        Delta_x = Delta_x + 0.001;
        Delta_y = Delta_y - 0.001;
        break;

    }
    glutPostRedisplay();
    glutTimerFunc(10, MyTimer, 1);
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {       //일반키 입력
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:
        exit(0); break;
    case 'P':
        R = 1.0; G = 0.0; B = 1.0; break;
    case 'p':
        R = 1.0; G = 0.0; B = 1.0; break;
    case 'Y':
        R = 1.0; G = 1.0; B = 0.0; break;
    case 'y':
        R = 1.0; G = 1.0; B = 0.0; break;
    }
}

void MySpecial(int Keypressed, int x, int y) {      //특수키입력
    switch (Keypressed) {
    case GLUT_KEY_F1:
        exit(0); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(500, 0);
    glutCreateWindow("2016305082 한태웅");
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glutTimerFunc(10, MyTimer, 1);
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);        //마우스클릭 함수
    glutMotionFunc(MyMouseMove);        //마우스의 움직임 함수
    glutKeyboardFunc(MyKeyboard);       //키보드를 일반키를 입력받아(unsigned charcter) 함수를 실행시킴
    glutSpecialFunc(MySpecial);
    glutMainLoop();
    return 0;
}
