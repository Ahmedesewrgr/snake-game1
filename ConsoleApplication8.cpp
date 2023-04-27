

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace std;
bool gameover;
const int width = 20;
const int hight = 20;
int x, y, FruitX, fruity, score;
int tailx[100], taily[100];
int ntail;
enum eDirection{stop=0, LEFT, RIGHT ,UP , DOWN };
eDirection dir;

void Setup()
{
    gameover = false;
    dir = stop;
    x = width / 2;
    y = hight / 2;
    FruitX = rand() % width;
    fruity = rand() % hight;
    score = 0;
}
void Draw()
{
    system("cls");
    for  (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruity && j == FruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                  
                    if (tailx[k] == j && taily[k] == i)
                    {
                        cout << "0";
                        print = true;
                    }
                   
                }
                if (!print)
                    cout << " ";
            }
            if (j == width-1)
                cout << "#";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "score:" << score << endl;

}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
                dir= LEFT;
                break;
        case 'd':
                dir = RIGHT;
                break;
        case 'w':
                 dir = UP;
                 break;
        case 's':
                 dir = DOWN;
                 break;
        case 'x':
                 gameover = true;
                 break;
        }
    }

}
void Logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        prev2x = tailx[i];
        prev2y  =taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x<0 || y> hight || y < 0)
        gameover = true;
    for (int i = 1; i < ntail; i++)
        if (tailx[i] == x && taily[i] == y)
            gameover = true;
    if (x == FruitX && y == fruity)
    {

        score += 10;
        FruitX = rand() % width;
        fruity = rand() % hight;
        ntail++;
    }
}

int main()
{
    Setup();
    while (!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);


    }
    return 0;
}

