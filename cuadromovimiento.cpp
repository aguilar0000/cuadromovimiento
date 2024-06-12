#include <GL/glut.h>

// Variables para la posición y color del cuadro
float posX = 0.0f;
float posY = 0.0f;
float colorR = 1.0f; // Componente rojo del color
float colorG = 0.0f; // Componente verde del color
float colorB = 0.0f; // Componente azul del color (en este caso, rojo)

// Función para dibujar el cuadro
void draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiar la pantalla

    // Dibujar el cuadro con el color actual
    glColor3f(colorR, colorG, colorB);
    glBegin(GL_QUADS);
    glVertex2f(posX - 0.1f, posY - 0.1f); // Esquina inferior izquierda
    glVertex2f(posX + 0.1f, posY - 0.1f); // Esquina inferior derecha
    glVertex2f(posX + 0.1f, posY + 0.1f); // Esquina superior derecha
    glVertex2f(posX - 0.1f, posY + 0.1f); // Esquina superior izquierda
    glEnd();

    glFlush(); // Finalizar el dibujo
}

// Función para manejar las teclas
void keyboard(unsigned char key, int x, int y) {
    // Cambiar la posición del cuadro
    switch (key) {
    case 'w': // Mover hacia arriba
        posY += 0.1f;
        break;
    case 's': // Mover hacia abajo
        posY -= 0.1f;
        break;
    case 'a': // Mover hacia la izquierda
        posX -= 0.1f;
        break;
    case 'd': // Mover hacia la derecha
        posX += 0.1f;
        break;
    }

    // Cambiar el color del cuadro dependiendo de la dirección del movimiento
    if (key == 'w') { // Si se mueve hacia arriba
        colorR = 1.0f; // Rojo
        colorG = 0.0f; // Verde
        colorB = 0.0f; // Azul
    }
    else if (key == 's') { // Si se mueve hacia abajo
        colorR = 0.0f; // Rojo
        colorG = 1.0f; // Verde
        colorB = 0.0f; // Azul
    }
    else if (key == 'a') { // Si se mueve hacia la izquierda
        colorR = 0.0f; // Rojo
        colorG = 0.0f; // Verde
        colorB = 1.0f; // Azul
    }
    else if (key == 'd') { // Si se mueve hacia la derecha
        colorR = 1.0f; // Rojo
        colorG = 1.0f; // Verde
        colorB = 0.0f; // Azul
    }

    glutPostRedisplay(); // Volver a dibujar la escena
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cuadro Primitivo con Movimiento");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Color de fondo blanco
    gluOrtho2D(-1.2, 1.2, -1.2, 1.2); // Ampliar el sistema de coordenadas
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard); // Registrar la función de teclado
    glutMainLoop();
    return 0;
}