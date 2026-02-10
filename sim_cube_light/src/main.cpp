// #include <iostream>
//
// using std::cout;
// using std::endl;
//
// int main(int argc, char* argv[]) {
//     Cube cube(64, 64, 64);
//
//     return EXIT_SUCCESS;
// }

// https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    // Initialisierung
    if (!glfwInit())
        return -1;

    // OpenGL Version festlegen --> 4.6 Core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Fenster erstellen
    GLFWwindow *window =
        glfwCreateWindow(800, 600, "Sim Cube Light", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD laden
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Fehler beim Laden von GLAD!" << std::endl;
        return -1;
    }

    // Main Loop
    while (!glfwWindowShouldClose(window)) {
        // Hintergrundfarbe --> Dunkelgrau
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}