#include "figure.h"
#include <vector>
#include <regex>
#include <cstdio>
#include <cstring>
//#include <iostream>
//#include <fstream>

using namespace std;


class Game{
    public:
        vector<vector<Figure *>> desk;  
        Moving var;     
        
        Game(int p_step);
        //Game(int p_step, file)
        //~Game();

        void draw_desk(int p_step);
        void draw_line();
        void draw_letters();
        void print_turn(int p_step);
        int input(Moving &p_var, vector<vector<Figure *>> &p_desk);
        bool move(Moving &p_var, vector<vector<Figure *>> &p_desk);
        bool check_color(Moving &p_var, vector<vector<Figure *>> &p_desk, int p_step);
        void error_input();
        void error_void_input();
        void error_color();
        void error_kill_yours();
        void error_busy_way();
        void error_behavior();
        void error_saving();
		void error_loading();
        void restart(vector<vector<Figure *>> &p_desk);
        bool save(vector<vector<Figure *>> &p_desk, int p_step);
        bool load(vector<vector<Figure *>> &p_desk, int &p_step);
        
};