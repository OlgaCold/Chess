#include <iostream>
#include "game.h"
using namespace std;


int main(){

    bool flag = false;
    int num_step = 1;
	
    Game game(num_step);
    while(!flag){

        int inp_tmp = game.input(game.var, game.desk);
        switch (inp_tmp)
        {
            case 0:
                if(!game.save(game.desk, num_step)){
                    game.error_saving();
                }
                break;

            case 1:
				if (!game.load(game.desk, num_step)) {
					game.error_loading();
				}
                break;

            case 2:
                num_step = 1;
                game.restart(game.desk);
                break;

            case 3:
                flag = true;
                continue;
                //end
                break;

            case 4:
                if(game.check_color(game.var, game.desk, num_step)){
                    int check_tmp = game.desk[game.var.x_from][game.var.y_from]->check_move(game.var, game.desk);
                    switch (check_tmp)
                    {
                        case 1:
                            game.error_busy_way();
                            break;
                        case 2:
                            game.error_behavior();
                            break;
                        case 0:
                            if(game.move(game.var, game.desk)){
                                num_step++;    
                            }else{
                                game.error_kill_yours();
                            }
                            break;
                    }          
                }else{
                    game.error_color();
                }
                break;
            case 5:
                game.error_input();
                break;
            case 6:
                game.error_void_input();
                break;
            
        }
        game.draw_desk(num_step);
    } 

    printf("Press any key...\n");
    scanf("%*c");
    return 0;
}

/*1 king
1 queen
2 rooks
2 bishops
2 knights
8 pawns*/












// int inp_tmp = game.input(game.var, game.desk);
//         switch (inp_tmp)
//         {
//             case 0:
//                 if(game.check_color(game.var, game.desk, num_step)){
//                 int check_tmp = game.desk[game.var.x_from][game.var.y_from]->check_move(game.var, game.desk);
//                 switch (check_tmp)
//                 {
//                     case 1:
//                         game.error_busy_way();
//                         game.print_turn(num_step - 1);
//                         break;
//                     case 2:
//                         game.error_behavior();
//                         game.print_turn(num_step - 1);
//                         break;
//                     case 0:
//                         if(game.move(game.var, game.desk)){
//                             game.print_turn(num_step);  
//                             num_step++;
//                         }else{
//                             game.error_kill_yours();
//                             game.print_turn(num_step - 1);
//                         }
//                         break;
//                 }          
//                 }else{
//                     game.error_color();
//                     game.print_turn(num_step - 1);
//                 }
//                 break;
//             case 1:
//                 game.error_input();
//                 game.print_turn(num_step - 1);
//                 break;
//             case 2:
//                 game.error_void_input();
//                 game.print_turn(num_step - 1);
//                 break;
//         }
//         game.draw_desk();