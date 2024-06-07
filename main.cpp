#include <GL/glut.h>
#include <vector>
#include <iostream>

struct Point {
    float x, y;
};

std::vector<Point> points;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    

    glBegin(GL_POINTS);
    for (const auto& point : points) {
        glVertex2f(point.x, point.y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (size_t i = 0; i + 1 < points.size(); i += 2) {
        glVertex2f(points[i].x, points[i].y);
        glVertex2f(points[i + 1].x, points[i + 1].y);
    }
    glEnd();
    
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        std::cout << x << " " << y << std::endl;
        float worldX = (float)x / (windowWidth / 2) - 1.0f;
        float worldY = 1.0f - (float)y / (windowHeight / 2);
        std::cout << worldX << " " << worldY << std::endl;
        
        points.push_back({worldX, worldY});
        
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(500, 500);
    
    glutCreateWindow("OpenGL Mouse Click Points");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glPointSize(5.0);
    
    glutDisplayFunc(display);
    
    glutMouseFunc(mouse);
    
    glutMainLoop();
    return 0;
}
