#include <GL/glew.h>
#define GLEW_STATIC
#include <GLFW/glfw3.h>

#include "stdio.h"
#include "stdbool.h"

int main() {
  if (!glfwInit()) {
    printf("Failed to init GLFW\n");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(1080, 720, "Hello, world!", NULL, NULL);
  glfwMakeContextCurrent(window);

  glewExperimental = true;
  const GLenum initcheck = glewInit();
  if (initcheck != GLEW_OK) {
    printf("Failed to init GLEW. %s\n", glewGetErrorString(initcheck));
    return -1;
  }

  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

  if (!window) {
    printf("Failed to create window.\n");
    glfwTerminate();
    return -1;
  }

  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

  GLuint VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // dealing with vertex shader

  GLuint vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // dealing with fragment shader

  const char *fragementShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\0";
  GLuint fragementShader;
  fragementShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragementShader, 1, &fragementShaderSource, NULL);
  glCompileShader(fragementShader);

  // create shader program

  GLuint shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragementShader);
  glLinkProgram(shaderProgram);

  glUseProgram(shaderProgram);

  do {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();

  } while (!glfwWindowShouldClose(window));

  glDeleteShader(vertexShader);
  glDeleteShader(fragementShader);
  glfwTerminate();
  return 0;
}

