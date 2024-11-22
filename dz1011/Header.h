#pragma once
#include<iostream>
#include<fstream>
#include<windows.h>
#include<math.h>
#include<memory>
using namespace std;

void moveTo(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

class Shape
{
public:
    Shape() {}

    Shape(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    virtual ~Shape() {}

    friend void moveTo(int x, int y);

    virtual void Show() = 0;
    virtual void Save() = 0;
    virtual void Load() = 0;

protected:
    int x = 0;
    int y = 0;
    string fileName = "";
};

class Square : public Shape
{
public:
    int length = 0;

    Square(int xPos, int yPos, int side) : Shape(xPos, yPos)
    {
        length = side;
        fileName = "square.txt";
    }

    void Save() override
    {
        ofstream out(fileName);
        out << x << endl;
        out << y << endl;
        out << length << endl;
        out.close();
    }

    void Load() override
    {
        ifstream inp(fileName);
        inp >> x >> y >> length;
        inp.close();
    }

    void Show() override
    {
        moveTo(x, y);
        for (size_t i = 0; i <= length; i++)
        {
            for (size_t j = 0; j < length; j++)
            {
                cout << "*";
            }
            moveTo(x, y + i);
        }
    }
};

class MyRectangle : public Shape
{
public:
    int width = 0;
    int height = 0;

    MyRectangle(int xPos, int yPos, int w, int h) : Shape(xPos, yPos)
    {
        width = w;
        height = h;
        fileName = "rectangle.txt";
    }

    void Save() override
    {
        ofstream out(fileName);
        out << x << endl;
        out << y << endl;
        out << width << endl;
        out << height << endl;
        out.close();
    }

    void Load() override
    {
        ifstream inp(fileName);
        inp >> x >> y >> width >> height;
        inp.close();
    }

    void Show() override
    {
        moveTo(x, y);
        for (size_t i = 0; i <= height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << "*";
            }
            moveTo(x, y + i);
        }
    }
};

class Circle : public Shape
{
public:
    int radius = 0;

    Circle(int xPos, int yPos, int r) : Shape(xPos, yPos)
    {
        radius = r;
        fileName = "circle.txt";
    }

    void Save() override
    {
        ofstream out(fileName);
        out << x << endl;
        out << y << endl;
        out << radius << endl;
        out.close();
    }

    void Load() override
    {
        ifstream inp(fileName);
        inp >> x >> y >> radius;
        inp.close();
    }

    const int pathLength(int deltaX, int deltaY)
    {
        return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    }

    void Show() override
    {
        moveTo(x, y);
        const int circleWidth = radius;
        const int circleLength = radius * 1.5;

        for (int i = circleWidth; i >= -circleWidth; i -= 2)
        {
            for (int j = -circleLength; j <= circleLength; j++)
            {
                if ((int)pathLength(j, i) == radius)
                    cout << "*";
                else
                    cout << " ";
            }
            moveTo(x, y += 1);
        }
    }
};
