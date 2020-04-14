 #include "game.h"


Game::Game(int p_step){

    desk.resize(8);
    for(int i = 0; i < 8; i++){
        if(i == 0){
            desk[i].push_back(new Rook(BLACK));
            desk[i].push_back(new Knight(BLACK));
            desk[i].push_back(new Bishop(BLACK));
            desk[i].push_back(new Queen(BLACK));
            desk[i].push_back(new King(BLACK));
            desk[i].push_back(new Bishop(BLACK));
            desk[i].push_back(new Knight(BLACK));
            desk[i].push_back(new Rook(BLACK));
        }
        else if(i == 1|| i == 6){
            for(int j = 0; j < 8; j++){
                desk[i].push_back(new Pawn(i == 1 ? BLACK : WHITE));       
            }
        }
        else if(i == 7){
            desk[i].push_back(new Rook(WHITE));
            desk[i].push_back(new Knight(WHITE));
            desk[i].push_back(new Bishop(WHITE));
            desk[i].push_back(new Queen(WHITE));
            desk[i].push_back(new King(WHITE));
            desk[i].push_back(new Bishop(WHITE));
            desk[i].push_back(new Knight(WHITE));
            desk[i].push_back(new Rook(WHITE));
        }
        else{
            for(int j = 0; j < 8; j++){
                desk[i].push_back(NULL);      
            }
        }
        
    }

    draw_desk(p_step);
}

void Game::restart(vector<vector<Figure *>> &p_desk){

    for(int i = 0; i < p_desk.size(); i++){
        for(int j = 0; j < p_desk[0].size(); j++){
            if(p_desk[i][j] != NULL) {
                delete p_desk[i][j];
            } 
        }
        p_desk[i].clear();
    }
    p_desk.clear();

    p_desk.resize(8);
    for(int i = 0; i < 8; i++){
        if(i == 0){
            p_desk[i].push_back(new Rook(BLACK));
            p_desk[i].push_back(new Knight(BLACK));
            p_desk[i].push_back(new Bishop(BLACK));
            p_desk[i].push_back(new Queen(BLACK));
            p_desk[i].push_back(new King(BLACK));
            p_desk[i].push_back(new Bishop(BLACK));
            p_desk[i].push_back(new Knight(BLACK));
            p_desk[i].push_back(new Rook(BLACK));
        }
        else if(i == 1|| i == 6){
            for(int j = 0; j < 8; j++){
                p_desk[i].push_back(new Pawn(i == 1 ? BLACK : WHITE));       
            }
        }
        else if(i == 7){
            p_desk[i].push_back(new Rook(WHITE));
            p_desk[i].push_back(new Knight(WHITE));
            p_desk[i].push_back(new Bishop(WHITE));
            p_desk[i].push_back(new Queen(WHITE));
            p_desk[i].push_back(new King(WHITE));
            p_desk[i].push_back(new Bishop(WHITE));
            p_desk[i].push_back(new Knight(WHITE));
            p_desk[i].push_back(new Rook(WHITE));
        }
        else{
            for(int j = 0; j < 8; j++){
                p_desk[i].push_back(NULL);      
            }
        }
    }
	
	system("CLS");
	printf("Game restarted\n");
}

bool Game::save(vector<vector<Figure *>> &p_desk, int p_step){

    FILE *File;
    File = fopen("D:\\OneDrive\\Studing\\CPP\\Chess\\save", "w");
    if(File == NULL)
        {return false;}
    fprintf(File, "%d \n", p_step);
    for(int i = 0; i < p_desk.size(); i++){
        for(int j = 0; j < p_desk[0].size(); j++){
            if(p_desk[i][j] != NULL){
                fprintf(File, "%c%c%c ", p_desk[i][j]->color == 0 ? 'b':'w', 
                p_desk[i][j]->name.second, p_desk[i][j]->if_made_move == true ? 't' : 'f');
            }
            else{fprintf(File, "v ");}
        }
        fprintf(File, "\n");
    }
    fclose(File);
    system("CLS");
    printf("Game saved\n");
    return true;
    
}

bool Game::load(vector<vector<Figure *>> &p_desk, int &p_step){

    char color, name, move;
    string str;
    int num;
    Color temp_color;
    pair<string, char> temp_name;
    bool temp_if_move;

    FILE *File;
    File = fopen("D:\\OneDrive\\Studing\\CPP\\Chess\\save", "r");
    if(File == NULL)
        {return false;}
    
    for(int i = 0; i < p_desk.size(); i++){
        for(int j = 0; j < p_desk[0].size(); j++){
            if(p_desk[i][j] != NULL) {
                delete p_desk[i][j];
            } 
        }
        p_desk[i].clear();
    }
    p_desk.clear();
    p_desk.resize(8);

    fscanf(File," %d ", &p_step);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            fscanf(File," %s", str.c_str());
            num = sscanf(str.c_str(), "%c%c%c", &color, &name, &move);
            switch(num)
            {
                case 3:
                    if(color == 'b') temp_color = BLACK;
                    else if(color == 'w') temp_color = WHITE; 
                    else return false;

                    if(move == 't') temp_if_move = true;
                    else if(move == 'f') temp_if_move = false;
                    else return false;

                    switch(name)
                    {
                        case 'P':
                            temp_name.first = "Pawn";
                            temp_name.second = 'P';
                            p_desk[i].push_back(new Pawn(temp_color, temp_name, temp_if_move));
                            break;
                        case 'R':
                            temp_name.first = "Rook";
                            temp_name.second = 'R';
                            p_desk[i].push_back(new Rook(temp_color, temp_name, temp_if_move));
                            break;
                        case 'k':
                            temp_name.first = "Knight";
                            temp_name.second = 'k';
                            p_desk[i].push_back(new Knight(temp_color, temp_name, temp_if_move));
                            break;
                        case 'B':
                            temp_name.first = "Bishop";
                            temp_name.second = 'B';
                            p_desk[i].push_back(new Bishop(temp_color, temp_name, temp_if_move));
                            break;
                        case 'Q':
                            temp_name.first = "Queen";
                            temp_name.second = 'Q';
                            p_desk[i].push_back(new Queen(temp_color, temp_name, temp_if_move));
                            break;
                        case 'K':
                            temp_name.first = "King";
                            temp_name.second = 'K';
                            p_desk[i].push_back(new King(temp_color, temp_name, temp_if_move));
                            break;
                        default:
                            return false;
                    }
                    break;
                case 1:
                    if(!strcmp(str.c_str(), "v")){
                        p_desk[i].push_back(NULL);
                    }else{return false;} 
                    break;
                default:
                    return false;
            }   
        }   
    }
	fclose(File);
	system("CLS");
	printf("Game loaded\n");
    return true;
}

void Game::draw_line(){
    printf("   |---------------------------------------|\n");
}

void Game::draw_letters(){
    printf("      A    B    C    D    E    F    G    H\n");
}

int Game::input(Moving &p_var, vector<vector<Figure *>> &p_desk){

    int from, to;
    char cfrom, cto;
    int num_of_inp;
    string s;

    printf("How you would like to move? (pattern: a,2/a,3)\n"
    "Or you can enter comman like save/load/restart/end.\n");
    scanf("%s", s.data());

    num_of_inp = sscanf(s.c_str(), "%c%*c%d%*c%c%*c%d", &cfrom, &from, &cto, &to); 
    //printf("%d\n\n", num_of_inp);
    if(num_of_inp == 4){  
        p_var.y_from = cfrom - 'a';
        p_var.x_from = 8 - from;
        p_var.y_to = cto - 'a';
        p_var.x_to = 8 - to;
        //printf("%d %d %d %d\n", p_var.y_from, p_var.x_from, p_var.y_to, p_var.x_to);
        if(p_var.x_from < 8 && p_var.x_from > -1 && p_var.y_from < 8 && 
            p_var.y_from > -1 && p_var.x_to < 8 && p_var.x_to > -1 &&
            p_var.y_to < 8 && p_var.y_to > -1 && p_desk[p_var.x_from][p_var.y_from] != NULL){
            return 4;
        }else{ return 6;}   
    }else{

        if(!strcmp(s.c_str(), "save")){ return 0;}
        else if(!strcmp(s.c_str(), "load")){ return 1;}
        else if(!strcmp(s.c_str(), "restart")){ return 2;}
        else if(!strcmp(s.c_str(), "end")){ return 3;}
        else { return 5;}
    }   
}

char Game::input_changing_pawn(){
    string str;
    char symbol;
    //pair<string, char> temp_name;
    //bool temp_if_move = p_desk[p_var.x_from][p_var.y_from]->if_made_move;
    //Color temp_color = p_desk[p_var.x_from][p_var.y_from]->color;

    printf("What do you want to turn the pawn into?\n"
    "(print \"R\" - Rook, \"k\" - Knight, \"B\" - Bishop, \"Q\" - Queen,)\n");
    scanf(" %s", str.c_str());
    int tmp = sscanf(str.c_str(), "%c", &symbol);


    switch(symbol)
    {
        case 'R':
			return 'R';
            break;
        case 'k':  
			return 'k';              
            break;
        case 'B':
			return 'B';
            break;
        case 'Q':
			return 'Q';
            break;
        default:
			return '\0';
    }

}

bool Game::changing_pawn(Moving &p_var, vector<vector<Figure *>> &p_desk, char p_figure) {
	pair<string, char> temp_name;
	bool temp_if_move;
	Color temp_color; 

	temp_if_move = p_desk[p_var.x_from][p_var.y_from]->if_made_move;
	temp_color = p_desk[p_var.x_from][p_var.y_from]->color;


	switch (p_figure)
	{
	case 'R':
		delete p_desk[p_var.x_from][p_var.y_from];
		p_desk[p_var.x_from][p_var.y_from] = NULL;
		delete p_desk[p_var.x_to][p_var.y_to];

		temp_name.first = "Rook";
		temp_name.second = 'R';
		p_desk[p_var.x_to][p_var.y_to] = new Rook(temp_color, temp_name, temp_if_move);
		system("CLS");
		return true;
		break;
	case 'k':
		delete p_desk[p_var.x_from][p_var.y_from];
		p_desk[p_var.x_from][p_var.y_from] = NULL;
		delete p_desk[p_var.x_to][p_var.y_to];

		temp_name.first = "Knight";
		temp_name.second = 'k';
		p_desk[p_var.x_to][p_var.y_to] = new Knight(temp_color, temp_name, temp_if_move);  
		system("CLS");
		return true;
		break;
	case 'B':
		delete p_desk[p_var.x_from][p_var.y_from];
		p_desk[p_var.x_from][p_var.y_from] = NULL;
		delete p_desk[p_var.x_to][p_var.y_to];

		temp_name.first = "Bishop";
		temp_name.second = 'B';
		p_desk[p_var.x_to][p_var.y_to] = new Bishop(temp_color, temp_name, temp_if_move);
		system("CLS");
		return true;
		break;
	case 'Q':
		delete p_desk[p_var.x_from][p_var.y_from];
		p_desk[p_var.x_from][p_var.y_from] = NULL;
		delete p_desk[p_var.x_to][p_var.y_to];

		temp_name.first = "Queen";
		temp_name.second = 'Q';
		p_desk[p_var.x_to][p_var.y_to] = new Queen(temp_color, temp_name, temp_if_move);
		system("CLS");
		return true;
		break;
	default:
		error_changing_pawn();
		return false;
		break;
	}
}


void Game::draw_desk(int p_step){

    Game::print_turn(p_step);
    draw_letters();
    draw_line();
    for(int i = 0; i < 8; i++){
        printf("%d  |", 8 - i);
        for(int j = 0; j < 8; j++){
            if(desk[i][j] == NULL) printf("    ");
            else desk[i][j]->draw();
            printf("|");
        }
        printf("  %d\n", 8 - i);
        draw_line();
    }
    draw_letters();
}

bool Game::check_color(Moving &p_var, vector<vector<Figure *>> &p_desk, int p_step){
    if(p_step % 2 == p_desk[p_var.x_from][p_var.y_from]->color){
        return true;
    }else{
        return false;
    }
}

bool Game::move(Moving &p_var, vector<vector<Figure *>> &p_desk){
    if(p_desk[p_var.x_to][p_var.y_to] != NULL && 
        p_desk[p_var.x_from][p_var.y_from]->color == p_desk[p_var.x_to][p_var.y_to]->color){
        return false;
    }else{
        p_desk[p_var.x_from][p_var.y_from]->if_made_move = true;
        if(p_desk[p_var.x_to][p_var.y_to] != NULL){ 

            system("CLS");
            printf("%s %s is killed!\n", 
            p_desk[p_var.x_to][p_var.y_to]->color == 0 ? "Black" : "White",
            p_desk[p_var.x_to][p_var.y_to]->name.first.c_str());

            delete p_desk[p_var.x_to][p_var.y_to];   
        }
        else system("CLS");
        p_desk[p_var.x_to][p_var.y_to] = p_desk[p_var.x_from][p_var.y_from];
        p_desk[p_var.x_from][p_var.y_from] = NULL;
        return true;
    }
}

void Game::print_turn(int p_step){

    if(p_step % 2 == 1){
        printf("                  White's turn\n");
    }else{
        printf("                  Black's turn\n");
    }
}

void Game::error_color(){
    system("CLS");
    printf("The step cannot be completed, wrong color!\n");
}

void Game::error_input(){
    system("CLS");
    printf("Error occurs while entering, please, follow the pattern!\n");
}

void Game::error_void_input(){
    system("CLS");
    printf("Error occurs while entering, cell is void!\n");
}

void Game::error_kill_yours(){
    system("CLS");
    printf("The step cannot be completed, you can't kill your figures!\n");
}

void Game::error_busy_way(){
    system("CLS");
    printf("The step cannot be completed, the path is busy!\n");
}

void Game::error_behavior(){
    system("CLS");
    printf("The step cannot be completed, the figure cannot walk this way!\n");
}

void Game::error_saving(){
    system("CLS");
    printf("Prolem with saving!\n");
}

void Game::error_loading() {
	system("CLS");
	printf("Prolem with loading!\n");
}

void Game::error_changing_pawn() {
	//system("CLS");
	printf("Error! Enter figure first letter!\n");
}

