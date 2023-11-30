#include "GL/gl.h"
#include "GLFW/glfw3.h"
#include "stdio.h"

int main() {
  GLFWwindow *window;

  if (!glfwInit()) {
    printf("Failed to init GLFW\n");
    return -1;
  }

  window = glfwCreateWindow(1080, 720, "Hello, world!", NULL, NULL);

  if (!window) {
    printf("Failed to create window.\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  do {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();

  } while (!glfwWindowShouldClose(window));

  glfwTerminate();
  return 0;
}

