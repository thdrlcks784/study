#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLint test=0;
GLint get_X = 0;
GLint get_Y = 0;
GLfloat vertices[6][3] = {
    {0,0,1},
    {1,0,0},
    {0,1,0},
    {-1,0,0},
    {0,-1,0},
    {0,0,-1}
};
GLfloat colors[8][3] = {
    { 0.0, 0.0, 1.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 1.0, 1.1 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 0.0, 1.0 },
    { 1.0, 1.0, 0.0 },
    { 1.0, 1.0, 1.0 },
    { 0.0, 0.0, 0.0 }
};
GLubyte MyVertexList[24] = {
    0,1,2,     //face indices
    0,2,3,
    0,3,4,
    0,4,1,
    5,1,2,
    5,2,3,
    5,4,1,
    5,3,4
};
void MySpecial(int Keypressed, int x, int y) {      //특수키입력
    switch (Keypressed) {
    case GLUT_KEY_LEFT:
        get_X-=5; break;
    case GLUT_KEY_RIGHT:
        get_X+=5; break;
    case GLUT_KEY_UP:
        get_Y-=5; break;
    case GLUT_KEY_DOWN:
        get_Y+=5; break;
    }
}
int MyListID[4];
void display(GLint Test) {
    MyListID[0] = glGenLists(4);
    MyListID[1] = MyListID[0] + 1;
    MyListID[2] = MyListID[1] + 1;
    MyListID[3] = MyListID[2] + 1;
   /*-------------------------------------------------------------*/
    glNewList(MyListID[0], GL_COMPILE);
    glPushMatrix();
    glTranslatef(-1.0f, -1.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    for (GLint i=0; i < 8; i++) {
        GLint count = i * 3;
        glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glBegin(GL_POLYGON);
        glVertex3fv(vertices[MyVertexList[count]]);
        glVertex3fv(vertices[MyVertexList[count + 1]]);
        glVertex3fv(vertices[MyVertexList[count + 2]]);

        glEnd();// End Drawing The Cube
    }
    glPopMatrix();
    glEndList();
    glCallList(MyListID[0]);
    /*----------------------------------------------------------------*/
    glNewList(MyListID[1], GL_COMPILE);
    /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
    glPushMatrix();
    glTranslatef(1.0f, -1.0f, 0.0f);
    glRotatef(45, 0.0f, 0.0f, 1.0f);

    for (GLint i = 0; i < 8; i++) {
        GLint count = i * 3;
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_POLYGON);
        glVertex3fv(vertices[MyVertexList[count]]);
        glVertex3fv(vertices[MyVertexList[count + 1]]);
        glVertex3fv(vertices[MyVertexList[count + 2]]);

        glEnd();// End Drawing The Cube
    }
    glPopMatrix();
    glEndList();
    glCallList(MyListID[1]);
    /*-----------------------------------------------------------------*/
    glNewList(MyListID[2], GL_COMPILE);
    /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);

    for (GLint i = 0; i < 8; i++) {
        GLint count = i * 3;
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_POLYGON);
        glVertex3fv(vertices[MyVertexList[count]]);
        glVertex3fv(vertices[MyVertexList[count + 1]]);
        glVertex3fv(vertices[MyVertexList[count + 2]]);

        glEnd();// End Drawing The Cube
    }

    glPopMatrix();
    glEndList();
    glCallList(MyListID[2]);
    /*---------------------------------------------------------------------*/
        
        glNewList(MyListID[3], GL_COMPILE);
        
        glPushMatrix();
        /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
        glTranslatef(-1.0f, 1.0f, 0.0f);
        glRotatef(get_X, 0.0f, 1.0f, 0.0f);
        glRotatef(get_Y, 1.0f, 0.0f, 0.0f);
        for (GLint i = 0; i < 8; i++) {
            GLint count = i * 3;
            glColor3f(colors[i][0], colors[i][1], colors[i][2]);
            glBegin(GL_POLYGON);
            glVertex3fv(vertices[MyVertexList[count]]);
            glVertex3fv(vertices[MyVertexList[count + 1]]);
            glVertex3fv(vertices[MyVertexList[count + 2]]);

            glEnd();// End Drawing The Cube
        }

        glPopMatrix();
        glEndList();
        glCallList(MyListID[3]);
        /*---------------------------------------------------------------*/
}

void timer(int value) {
    glutPostRedisplay();      //윈도우를 다시 그리도록 요청
    glutTimerFunc(30, timer, 0); //다음 타이머 이벤트는 30밀리세컨트 후  호출됨.
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러사용
    glFrontFace(GL_CCW);    //시계반대방향 cc = 카운터 클럭
      //백페이스 안그려줌
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);    //벌텍스 명시
    glMatrixMode(GL_MODELVIEW);     //무적권 씀
    glLoadIdentity();   //행렬을 단위행렬로 초기화 무적권씀
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    display(test);
    
                                   /*for (GLint i = 0; i < 6; i++)    //6개의 면을 그림
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);    //정점 4개씩 묶고 시작시점은 4개씩 건너뜀*/
    glFlush();
    test++;
}
void init()
{
    /* Set clear color */
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glClearDepth(1.0);

    /* Enable the depth buffer */
    glEnable(GL_DEPTH_TEST);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    init();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glutSpecialFunc(MySpecial);
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
