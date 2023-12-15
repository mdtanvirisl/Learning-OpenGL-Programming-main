#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    //light
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.4f, 0.9f);
    glEnd();

    //pole
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.37f, 0.9f);
    glVertex2f(0.52f, 0.9f);
    glVertex2f(0.52f, 0.92f);
    glVertex2f(0.37f, 0.92f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.47f, 0.92f);
    glVertex2f(0.47f, 0.97f);
    glVertex2f(0.43f, 0.97f);
    glVertex2f(0.43f, 0.92f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.47f, 0.93f);
    glVertex2f(0.47f, 0.97f);
    glVertex2f(0.8f, 0.97f);
    glVertex2f(0.8f, 0.93f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.8f, 0.25f);
    glVertex2f(0.85f, 0.25f);
    glVertex2f(0.85f, 0.97f);
    glVertex2f(0.8f, 0.97f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.9f, 0.25f);
    glVertex2f(0.9f, 0.2f);
    glVertex2f(0.75f, 0.2f);
    glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0, 1, 0, 1);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
