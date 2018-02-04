#pragma once

glm::ivec2 screenSize;
GLuint modelViewUniform;
GLuint vertexShader;
GLuint fragmentShader;
Shader* shader;
float rotation;
int lastTime;

void init();
void display();
void reshape(int newWidth, int newHeight);
void keyboard(unsigned char key, int x, int y);
void update();


