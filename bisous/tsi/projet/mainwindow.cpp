#include "mainwindow.h"
#include "./ui_mainwindow.h"

// A SUPPRIMER ENSUITE
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

void MainWindow::drawTriangle()
{
    // Obtenez le contexte OpenGL
    QOpenGLFunctions* glFunctions = QOpenGLContext::currentContext()->functions();

    // Définissez les coordonnées des sommets du triangle
    GLfloat vertices[] = {
        0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // Créez un objet de tampon OpenGL pour stocker les données des sommets
    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.allocate(vertices, sizeof(vertices));

    // Créez un programme de shaders OpenGL
    QOpenGLShaderProgram shaderProgram;
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                          "attribute vec3 aPosition;"
                                          "void main() {"
                                          "    gl_Position = vec4(aPosition, 1.0);"
                                          "}");
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                          "void main() {"
                                          "    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
                                          "}");
    shaderProgram.link();

    // Configurez le tampon de sommets comme attribut de position
    shaderProgram.bind();
    shaderProgram.enableAttributeArray("aPosition");
    shaderProgram.setAttributeBuffer("aPosition", GL_FLOAT, 0, 3, 0);

    // Effacez l'écran avec une couleur de fond
    glFunctions->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glFunctions->glClear(GL_COLOR_BUFFER_BIT);

    // Dessinez le triangle
    glFunctions->glDrawArrays(GL_TRIANGLES, 0, 3);

    // Libérez les ressources
    shaderProgram.release();
    vbo.release();
}






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QPushButton *button = new QPushButton("Cliquez ici", this);
    button->setObjectName("pushButton");

    connect(button, &QPushButton::clicked, this, &afficherWow);
    */

    QPushButton *button = findChild<QPushButton*>("addLayer");
    if (button) {
        connect(button, &QPushButton::clicked, this, &afficherWow);
    }

    QOpenGLWidget *openGLWidget = findChild<QOpenGLWidget*>("openGLWidget");
    if (openGLWidget) {
        connect(openGLWidget, &QOpenGLWidget::aboutToCompose, this, &MainWindow::drawTriangle);
        openGLWidget->update();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

