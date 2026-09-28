#include <GL/glut.h>

float x = -1.0;
float angle = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* Road */
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1, -0.5);
        glVertex2f(1, -0.5);
        glVertex2f(1, -0.8);
        glVertex2f(-1, -0.8);
    glEnd();

    /* Move car */
    glPushMatrix();
    glTranslatef(x, 0, 0);

    /* Car body */
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.3, -0.4);
        glVertex2f(0.3, -0.4);
        glVertex2f(0.3, -0.2);
        glVertex2f(-0.3, -0.2);
    glEnd();

    /* Wheels */
    glColor3f(0, 0, 0);

    glPushMatrix();
    glTranslatef(-0.2, -0.43, 0);
    glRotatef(angle, 0, 0, 1);
    glutSolidTorus(0.03, 0.07, 10, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.43, 0);
    glRotatef(angle, 0, 0, 1);
    glutSolidTorus(0.03, 0.07, 10, 20);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value)
{
    x += 0.01;
    angle -= 10;

    if (x > 1.3)
        x = -1.3;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Animated Car");

    glClearColor(0.5, 0.8, 1.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);

    glutMainLoop();

    return 0;
}
