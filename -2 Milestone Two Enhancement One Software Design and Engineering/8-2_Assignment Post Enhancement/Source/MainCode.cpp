#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

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
    float direction;

    Circle(float xx, float yy, float rad, float dir, float r, float g, float b)
        : x(xx), y(yy), radius(rad), direction(dir), red(r), green(g), blue(b), speed(0.01) {}

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

    void DrawCircle() const {
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
        if (brk->onoff == OFF) return;

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

    void CheckPaddleCollision(Circle* circle) {
        if (circle->y - circle->radius <= y + width / 2 && circle->x >= x - width / 2 && circle->x <= x + width / 2) {

            float relativeHitPosition = (circle->x - x) / (width / 2); // Normalized [-1, 1]
            circle->direction = 90 - relativeHitPosition * 60; // Adjust direction within a range
        }
    }
};

class Game {
public:
    vector<Brick> bricks;
    vector<Circle> circles;
    Paddle paddle;
    int score;

    Game() : paddle(0, -1.0, 0.5, 0.5, 0.5, 0.5), score(0) {}

    void initialize() {
        createBrickGrid(5, 7); // Create a grid of bricks (5 rows, 7 columns)
        circles.push_back(Circle(0.0, 0.0, 0.05, 45, 1, 0, 0));
    }

    void createBrickGrid(int rows, int cols) {
        float startX = -0.9, startY = 0.8;
        float brickWidth = 0.2;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                float x = startX + j * (brickWidth + 0.02);
                float y = startY - i * (brickWidth + 0.02);
                bricks.push_back(Brick(DESTRUCTABLE, x, y, brickWidth,
                    static_cast<float>(rand() % 100) / 100.0f,
                    static_cast<float>(rand() % 100) / 100.0f,
                    static_cast<float>(rand() % 100) / 100.0f,
                    rand() % 3 + 1));
            }
        }
    }

    void processCollisions() {
        for (auto& circle : circles) {
            circle.MoveOneStep();
            for (auto& brick : bricks) {
                circle.CheckCollision(&brick);
                if (brick.onoff == OFF) {
                    score += 10;
                }
            }
            paddle.CheckPaddleCollision(&circle);
        }
    }

    void draw() {
        for (auto& brick : bricks) {
            if (brick.onoff == ON) brick.drawBrick();
        }
        for (auto& circle : circles) {
            circle.DrawCircle();
        }
        paddle.drawBrick();
    }

};

void processInput(GLFWwindow* window, Paddle& paddle) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        paddle.MoveLeft();
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        paddle.MoveRight();
    }
}

int main() {
    srand(time(NULL));
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window = glfwCreateWindow(1280, 960, "Enhanced Brick Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Game game;
    game.initialize();

    while (!glfwWindowShouldClose(window)) {
        processInput(window, game.paddle);

        glClear(GL_COLOR_BUFFER_BIT);
        game.processCollisions();
        game.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
