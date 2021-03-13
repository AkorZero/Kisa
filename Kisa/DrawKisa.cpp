#include <math.h>
#include "glut.h"

// Прототипы глобальных функций
void RenderScene(void);								//вызывается при перерисовке экрана
void SetupRC(void);									//начальные установки
void ChangeSize(int, int);							//вызывается при изменении размеров окна
//  void TimerFunction(int); //работа с таймером
//	void keyboardFunc(unsigned char , int , int );		//обработка клавиатуры
//  void SkeyboardFunc(int , int , int );				//обработка клавиатуры - функциональные клавиши
//	void Mouse(int button, int state, int x, int y);	//обработка мыши
// Глобальные переменные:

void DrawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
}
/* функция отображает окружность*/
void DrawCircle(float x, float y, float R, int FillFlag) {
    int N = 360;
    glBegin(FillFlag ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
    for (int i = 1; i <= N; i++) {
        glVertex2f(x + R * cos(2 * 3.14 / N * i), y + R * sin(2 * 3.14 / N * i));
    }
    glEnd();

}

  // Текущие ширина и высота клиентской области окна приложения
GLfloat windowWidth = 10;
GLfloat windowHeight = 10;
//**********************************************************
// Точка входа приложения
void main(int argc, char* argv[])
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glEnable(GLUT_MULTISAMPLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kisa");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    //	 glutKeyboardFunc(keyboardFunc);
    //	 glutSpecialFunc(SkeyboardFunc);
    //   glutMouseFunc(Mouse);
    //	 glutTimerFunc(33, TimerFunction, 1);

    SetupRC();

    glutMainLoop();
}

//**********************************************************
// Рисование сцены
void RenderScene(void)
{

    // Очистка окна текущим цветом
    glClear(GL_COLOR_BUFFER_BIT);

    // Установка цвета рисования в модели RGB (красный)
    glColor3f(0.917, 0.396, 0.0);

    //glPointSize(4);
    gluOrtho2D(-0.1, 0.1, -0.1, 0.1);
    glLineWidth(1.6969);
    
    glColor3f(1.0, 0.654, 0.239);
    glBegin(GL_POLYGON);
    glVertex2f(2, -2);
    glVertex2f(6, 2);
    glVertex2f(4, -1);
    glVertex2f(2, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3, 0);
    glVertex2f(6, 2);
    glVertex2f(4, 0);
    glVertex2f(3, 0);
    glEnd();

    glColor3f(0.917, 0.396, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1, 5);
    glVertex2f(-2, 7);
    glVertex2f(-2, 5);

    glVertex2f(1, 5);
    glVertex2f(2, 7);
    glVertex2f(2, 5);

    glVertex2f(-3, -2);
    glVertex2f(3, -2);
    glVertex2f(0, 4);
    glEnd();

    glColor3f(0.997, 0.596, 0.0);
    DrawCircle(0, 4, 2.5, 1);

    glColor3f(0.298, 0.737, 0.258);
    DrawCircle(-1, 5, 0.3, 1);
    DrawCircle(1, 5, 0.3, 1);

    glColor3f(0.0, 0.0, 0.0);
    DrawCircle(-0.9, 5, 0.16, 1);
    DrawCircle(1.1, 5, 0.16, 1);


    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex2f(0, 3.75);
    glVertex2f(0, 3.25);
    glVertex2f(-0.3, 2.75);
    glVertex2f(0, 3.25);
    glVertex2f(0.3, 2.75);
    glVertex2f(0, 3.25);
    glVertex2f(-2, 4);
    glVertex2f(-4, 5);
    glVertex2f(-2, 3.5);
    glVertex2f(-5, 3.5);
    glVertex2f(-2, 3);
    glVertex2f(-4, 2);



    glVertex2f(2, 4);
    glVertex2f(4, 5);
    glVertex2f(2, 3.5);
    glVertex2f(5, 3.5);
    glVertex2f(2, 3);
    glVertex2f(4, 2);
    glEnd();

    glColor3f(0.788, 0.188, 0.678);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 3.75);
    glVertex2f(-0.3, 4.19);
    glVertex2f(0.3, 4.19);
    glEnd();

    // Переключение буфера с очисткой очереди команд
    glutSwapBuffers();
}

//**********************************************************
// Вызывается по таймеру библиотекой GLUT в спокойном состоянии,
// когда не меняются размеры окна приложения и нет перемещений параметр - номер таймера
//void TimerFunction(int value)
//{
//
//   Перерисовываем сцену с новыми координатами
//  glutPostRedisplay();
//   Запускаем новый таймер
//  glutTimerFunc(33,TimerFunction, 1);
//  
//}

//**********************************************************
// Установка состояния рендеринга (визуализации)
void SetupRC(void)
{
    // Устанавливаем синий цвет очистки 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

//**********************************************************
// Вызывается библиотекой GLUT при изменении размеров окна
// приложения. Осталась такой же, как в примере GLRect,
// только в вызовы glOrtho() поставили переменные
void ChangeSize(int width, int height)
{
    GLfloat aspectRatio;

    // Предотвращаем деление на нуль
    if (height == 0)
        height = 1;

    // Устанавливаем поле просмотра с размерами окна
    glViewport(0, 0, width, height);

    // Устанавливает матрицу преобразования в режим проецирования
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Устанавливаем размеры перспективы (отсекающего объема)
    // (left, right, bottom, top, near, far)
    aspectRatio = (GLfloat)width / (GLfloat)height;
    if (width <= height)
    {
        windowWidth = 100;
        windowHeight = 100 / aspectRatio;
        glOrtho(-100.0, 100.0,
            -windowHeight, windowHeight, 1.0, -1.0);
    }
    else
    {
        windowWidth = 100 * aspectRatio;
        windowHeight = 100;
        glOrtho(-windowWidth, windowWidth,
            -100.0, 100.0, 1.0, -1.0);
    }

    // Восстановливает матрицу преобразования в исходный режим вида
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

