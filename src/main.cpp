#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <DefaultSettings.h>
//#include <InputUtil.h>
#include <string>
#include <cmath>
#include <Scene.h>
#include <ErrorUtility.h>    
#include <FileUtil.h>

int main(void) {
    Scene* scene = new Scene();

    // Create window using glfw
    if (!glfwInit()) {
        LOG_ERROR("Couldn't initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "OpenGL BluePrint", NULL, NULL);
    if (!window)
    {
        LOG_ERROR("Couldn't create GLFW window");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // Loads OpenGL functions using glad
    gladLoadGL();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // Initializes glad
    {
        LOG_ERROR("Failed to initialize GLAD");
    }
    glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
    // Set background color
    glClearColor(0.1f, 0.1f, 0.13f, 1.0f);


    float vertices[] = {
        -0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.2f,
        0.1f, 0.3f, 0.4f
    };
    
    int wahwah = 0;

    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);


    std::string vsSrc = nlib::fileReading::shaderSource("src/shaders/VertexShader.vert");
    const char* vertShaderSrc = vsSrc.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertShaderSrc, NULL);
    glCompileShader(vertexShader);

    std::string fsSrc = nlib::fileReading::shaderSource("src/shaders/FragmentShader.frag");
    const char* fragShaderSrc = fsSrc.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragShaderSrc, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    //unsigned int VAO;



    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    

    //glGenVertexArrays(1, &VAO);
    //glBindVertexArray(VAO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);




    

    //glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);



    // Program loop
    while (!glfwWindowShouldClose(window)) {
        scene->update(window);
         
        glClear(GL_COLOR_BUFFER_BIT);
        
        //glBindVertexArray(VAO

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    //glDeleteBuffers(1, &VBO);
    //glDeleteVertexArrays(1, &VAO);
    
    glDeleteShader(shaderProgram);
    glfwTerminate(); // Closes glfw window 
    return 0;
;}