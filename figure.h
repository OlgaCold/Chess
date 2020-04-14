#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <utility> 

using namespace std;

enum Color { 
    BLACK = 0,
    WHITE = 1
};

struct Moving{
    int y_from;
    int y_to;
    int x_from;
    int x_to;
};

class Figure {
    public:
        Color color;
        bool if_made_move;
        pair<string, char> name;

        Figure(){};
        Figure(Color p_color, pair<string, char> p_name, bool p_move);
        Figure(Color p_color) : color(p_color){};
        virtual int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk) = 0;
        void draw();
        
};

class Pawn : public Figure {
    public:
        
        Pawn(Color p_color):Figure(p_color){name.first = "Pawn"; name.second = 'P';};
        Pawn(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);
};

class Rook : public Figure{
    public:
        
        Rook(Color p_color):Figure(p_color){ name.first = "Rook"; name.second = 'R';};
        Rook(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);
        
};

class Knight : public Figure{
    public:
        Knight(Color p_color):Figure(p_color){ name.first = "Knight"; name.second = 'k';};
        Knight(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);

};

class Bishop : public Figure{
    public:
        Bishop(Color p_color):Figure(p_color){name.first = "Bishop"; name.second = 'B';};
        Bishop(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);
};

class Queen : public Figure{
    public:
        Queen(Color p_color):Figure(p_color){name.first = "Queen"; name.second = 'Q';};
        Queen(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);
};

class King : public Figure{
    public:
        King(Color p_color):Figure(p_color){name.first = "King"; name.second = 'K';};
        King(Color p_color, pair<string, char> p_name, bool p_move):Figure(p_color, p_name, p_move){};
        int check_move(Moving &p_var, vector<vector<Figure *>> &p_desk);
};

