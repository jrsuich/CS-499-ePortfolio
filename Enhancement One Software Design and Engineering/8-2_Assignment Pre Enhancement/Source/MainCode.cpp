#include <GLFW\glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;

const float DEG2RAD = 3.14159f / 180;

enum BRICKTYPE { REFLECTIVE, DESTRUCTABLE };
enum ONOFF { ON, OFF };

class Brick {
public:
    float red, green, blue;
    float x, y, width;
    BRICKTYPE brick_type;
    ONOFF onoff;
    int hitCounter;

    Brick(BRICKTYPE bt, float xx, float yy, float ww, float rr, float gg, float bb, int hits = 1)
        : brick_type(bt), x(xx), y(yy), width(ww), red(rr), green(gg), blue(bb), onoff(ON), hitCounter(hits) {}

    void drawBrick() {
        if (onoff == ON) {
            glColor3f(red, green, blue);
            glBegin(GL_QUADS);
            glVertex2f(x - width / 2, y + width / 2);
            glVertex2f(x + width / 2, y + width / 2);
            glVertex2f(x + width / 2, y - width / 2);
            glVertex2f(x - width / 2, y - width / 2);
            glEnd();
        }
    }

    void reduceHit() {
        hitCounter--;
        if (hitCounter <= 0) {
            onoff = OFF;
        }
    }
};

class Circle {
public:
    float red, green, blue;
    float radius;
    float x, y;
    float speed;
    int direction;

    Circle(float xx, float yy, float rad, int dir, float r, float g, float b)
        : x(xx), y(yy), radius(rad), direction(dir), red(r), green(g), blue(b), speed(0.03) {}

    void MoveOneStep() {
        float dx = speed * cos(direction * DEG2RAD);
        float dy = speed * sin(direction * DEG2RAD);
        x += dx;
        y += dy;
        if (x + radius > 1 || x - radius < -1) {
            direction = 180 - direction;
        }
        if (y + radius > 1 || y - radius < -1) {
            direction = -direction;
        }
    }

    void DrawCircle() {
        glColor3f(red, green, blue);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= 360; i++) {
            float degInRad = i * DEG2RAD;
            glVertex2f(cos(degInRad) * radius + x, sin(degInRad) * radius + y);
        }
        glEnd();
    }

    void CheckCollision(Brick* brk) {
        float distX = fabs(x - brk->x);
        float distY = fabs(y - brk->y);

        if (distX > (brk->width / 2 + radius) || distY > (brk->width / 2 + radius)) {
            return;
        }

        if (distX <= (brk->width / 2) || distY <= (brk->width / 2)) {
            direction = (x > brk->x) ? 180 - direction : -direction;
            brk->reduceHit();
            return;
        }

        float cornerDistance_sq = (distX - brk->width / 2) * (distX - brk->width / 2) +
            (distY - brk->width / 2) * (distY - brk->width / 2);

        if (cornerDistance_sq <= (radius * radius)) {
            direction = (x > brk->x) ? 180 - direction : -direction;
            brk->reduceHit();
        }
    }
};

class Paddle : public Brick {
public:
    Paddle(float xx, float yy, float ww, float rr, float gg, float bb)
        : Brick(REFLECTIVE, xx, yy, ww, rr, gg, bb) {}

    void MoveLeft() {
        if (x > -1 + width / 2) {
            x -= 0.05f;
        }
    }

    void MoveRight() {
        if (x < 1 - width / 2) {
            x += 0.05f;
        }
    }
};

vector<Circle> circles;
Paddle paddle(0, -0.9, 0.3, 0.5, 0.5, 0.5);

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        paddle.MoveLeft();
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        paddle.MoveRight();
    }
}

int main(void) {
    srand(time(NULL)); // Initialize random seed
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Brick Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Brick brick1(REFLECTIVE, -0.8, 0.8, 0.2, 1, 0, 0, 1);
    Brick brick2(DESTRUCTABLE, 0.8, 0.8, 0.2, 0, 1, 0, 1);
    circles.push_back(Circle(0.0, 0.0, 0.05, 45, 1, 0, 0));

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        for (auto& circle : circles) {
            circle.CheckCollision(&brick1);
            circle.CheckCollision(&brick2);
            circle.MoveOneStep();
            circle.DrawCircle();
        }

        if (brick1.onoff == ON) brick1.drawBrick();
        if (brick2.onoff == ON) brick2.drawBrick();
        paddle.drawBrick();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}