#pragma once
#include"Header.h"
#include<vector>

int main()
{
    vector<shared_ptr<Shape>> v;
    v.push_back(make_shared<Square>(2, 1, 3));
    v.push_back(make_shared<Circle>(6, 6, 6));
    v.push_back(make_shared<MyRectangle>(13, 5, 9, 2));
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->Show();
    }
    Circle cir(27, 7, 11);
}
