#include <windows.h>
#include <gl/glut.h>

void draw_triangle() {

    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.50, 0.75, 0.0);
    glVertex3f (0.50, 0.75, 0.0);

    glEnd();
    glFlush ();
}

void init_draw() {

    glClearColor (1.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, -1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (300, 300);
    glutCreateWindow ("Triangle");

    init_draw ();

    glutDisplayFunc(draw_triangle);

    glutMainLoop();

    return 0;
}
