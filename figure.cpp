#include "figure.h"

Figure::Figure(Color p_color, pair<string, char> p_name, bool p_move){
    color = p_color;
    if_made_move = p_move;
    name.first = p_name.first;
    name.second = p_name.second;
}

void Figure::draw(){
       
    printf(" ");
    printf(color == BLACK ? "B" : "W");
    printf("%c ", name.second);
}

int Knight::check_move(Moving &p_var, vector<vector<Figure *>> &p_desk){
    if(abs(p_var.x_to - p_var.x_from) == 1 && abs(p_var.y_to - p_var.y_from) == 2 || 
    abs(p_var.x_to - p_var.x_from) == 2 && abs(p_var.y_to - p_var.y_from) == 1){
        return 0;
    }else{
        return 2;
    }
}

int Bishop::check_move(Moving &p_var, vector<vector<Figure *>> &p_desk){

    int x_step = (p_var.x_to - p_var.x_from)/((p_var.x_to - p_var.x_from) ? abs(p_var.x_to - p_var.x_from) : 1);
    int y_step = (p_var.y_to - p_var.y_from)/((p_var.y_to - p_var.y_from) ? abs(p_var.y_to - p_var.y_from) : 1);
    int x_t_from = p_var.x_from;
    int y_t_from = p_var.y_from;

    if(abs(p_var.x_to - p_var.x_from) == abs(p_var.y_to - p_var.y_from)){
        if(x_t_from + x_step == p_var.x_to && y_t_from + y_step == p_var.y_to){
            return 0;
        }else{
            do{
                x_t_from += x_step;
                y_t_from += y_step;
                printf("1     %d %d\n",x_t_from, y_t_from);
                if(p_desk[x_t_from][y_t_from] != NULL){
                    return 1;
                }
            }while(x_t_from != p_var.x_to-x_step || y_t_from != p_var.y_to-y_step);
        }
    }else{
        return 2;
    }
    return 0;
}

int Rook::check_move(Moving &p_var, vector<vector<Figure *>> &p_desk){

    int x_step = (p_var.x_to - p_var.x_from)/((p_var.x_to - p_var.x_from) ? abs(p_var.x_to - p_var.x_from) : 1);
    int y_step = (p_var.y_to - p_var.y_from)/((p_var.y_to - p_var.y_from) ? abs(p_var.y_to - p_var.y_from) : 1);
    int x_t_from = p_var.x_from;
    int y_t_from = p_var.y_from;// + y_step;

    if(abs(x_step - y_step) == 1){
        if(x_t_from + x_step == p_var.x_to && y_t_from + y_step == p_var.y_to){
            return 0;
        }else{
            //printf("temp     %d %d\n",x_t_from, y_t_from);
            //printf("real from     %d %d\n",p_var.x_from, p_var.y_from);
            //printf("real to     %d %d\n",p_var.x_to, p_var.y_to);
            //printf("while     %d %d\n",p_var.x_to-x_step, p_var.y_to-y_step);
            do{
                x_t_from += x_step;
                y_t_from += y_step;
                printf("1     %d %d\n",x_t_from, y_t_from);
                if(p_desk[x_t_from][y_t_from] != NULL){
                    return 1;
                }
            }while(x_t_from != p_var.x_to-x_step || y_t_from != p_var.y_to-y_step);
        }
    }else{
        return 2;
    }
    return 0;
} 

int Queen::check_move(Moving &p_var, vector<vector<Figure *>> &p_desk){

    int x_step = (p_var.x_to - p_var.x_from)/((p_var.x_to - p_var.x_from) ? abs(p_var.x_to - p_var.x_from) : 1);
    int y_step = (p_var.y_to - p_var.y_from)/((p_var.y_to - p_var.y_from) ? abs(p_var.y_to - p_var.y_from) : 1);
    int x_t_from = p_var.x_from;
    int y_t_from = p_var.y_from;

    if(abs(p_var.x_to - p_var.x_from) == abs(p_var.y_to - p_var.y_from) || abs(x_step - y_step) == 1){   
        if(x_t_from + x_step == p_var.x_to && y_t_from + y_step == p_var.y_to){
            return 0;
        }else{
            do{
                x_t_from += x_step;
                y_t_from += y_step;
                printf("1     %d %d\n",x_t_from, y_t_from);
                if(p_desk[x_t_from][y_t_from] != NULL){
                    return 1;
                }
            }while(x_t_from != p_var.x_to-x_step || y_t_from != p_var.y_to-y_step);
        }
    }else{
        return 2;
    }
    return 0;
}

