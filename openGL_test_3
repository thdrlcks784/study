#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void initail_display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 1200, 300);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void drawing_Line() {
    glBegin(GL_LINES);
    glVertex3f(4.0, 0.0, 0.0);
    glVertex3f(-4.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-2.0, 1.0, 0.0);
    glVertex3f(-2.0, -1.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(2.0, 1.0, 0.0);
    glVertex3f(2.0, -1.0, 0.0);
    glEnd();
      
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glEnd();
}
void Left_display() {
    glPushMatrix();
    glTranslatef(-2, 0.0, 0.0);
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(0.3);
    glPopMatrix();
}
void Right_display() {
    glPushMatrix();
    glTranslatef(2, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(0.3);
    glPopMatrix();
}


void MyDisplay() {
    initail_display();
    drawing_Line();

    Left_display();

    Right_display();

    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(1200, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
