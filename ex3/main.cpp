#include <windows.h>
#include <GL/glut.h>

void drawOneLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {

    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
}

void init() {

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void draw_lines() {

    glClear(GL_COLOR_BUFFER_BIT);

    glEnable (GL_LINE_STIPPLE);
    glLineStipple (1, 0x0101);
    drawOneLine (50.0, 125.0, 90.0, 3.0);
    glLineStipple (1, 0x00FF);
    drawOneLine (12.0, 43.0, 250.0, 125.0);
    glLineStipple (1, 0x1C47);
    drawOneLine (250.0, 125.0, 350.0, 125.0);

    glLineWidth (5.0);
    glLineStipple (1, 0x0101);
    drawOneLine (98.0, 100.0, 89.0, 54.0);
    glLineStipple (1, 0x00FF);
    drawOneLine (150.0, 654.0, 250.0, 65.0);
    glLineStipple (1, 0x1C47);
    drawOneLine (87.0, 321.0, 654.0, 12.0);
    glLineWidth (3.0);

    glLineStipple (1, 0x1C47);
    glBegin (GL_LINE_STRIP);

    for (int i = 0; i < 7; i++)
        glVertex2f (50.0 + ((GLfloat) i * 50.0), 75.0);

    glEnd ();

    for (int i = 0; i < 6; i++) {
        drawOneLine (50.0 + ((GLfloat) i * 50.0), 50.0,
        50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
    }

    glLineStipple (5, 0x1C47);
    drawOneLine (50.0, 98.0, 350.0, 25.0);
    glDisable (GL_LINE_STIPPLE);
    glFlush ();
}

void reshape (int w, int h) {

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize (400, 150);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(draw_lines);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
