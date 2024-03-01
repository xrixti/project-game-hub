#include<iostream>
#include<ctime>

using namespace std;

void goBackToMain();




//tiktactoe
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
int row, column;
bool draw = false;

void display_board() {
    system("cls");
    cout << endl;
    cout << "\t\tT I C   T A C   T O E" << endl;
    cout << endl;
    cout << "\tPLAYER1[X]\n \tPLAYER2[O]" << endl;
    cout << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "\t\t     |     |     " << endl;
    cout << endl;

}
void player_turn() {
    int choise;

    if (turn == 'X') {
        cout << "\tPLAYER 1[X] TURN :";
        cin >> choise;
    }
    if (turn == 'O') {
        cout << "\tPLAYER 2[O] TURN :";
        cin >> choise;
    }
    switch (choise)
    {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "invalid choice..!!" << endl;
        break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "BOX ALREADYY FILLED...!!\n PLEASE TRYY AGAIN" << endl;
        player_turn();
    }
display_board();
}
bool gameover() {
    // check win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    //game playing
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        if (board[i][j] != 'X' && board[i][j] != 'O') {
            return true;
        }
    //game draw
    draw = true;
    return false;
}

void playtik();

//hangman
int tries=3;
string message="You have 3 chances!";
 void hang(char);
 int checkguess(char,string,string&);
void playHangman()
{
    char letter;
    string month;
    string months[] = {
    "january",
    "february",
    "march",
    "april",
    "may",
    "june",
    "july",
    "august",
    "september",
    "october",
    "november",
    "december",

    };
    srand (time(NULL));
    int month_number = rand()%12;
    month=months[month_number];
    string hide_month(month.length(),'*');

    system("cls");

    while(tries!=0){
       hang('n');
       cout<<"\t\t\t\tLife:"<<tries<<endl;
       cout<<hide_month<<endl;
       cout<<"\t\t\tGuess a letter: ";
       cin>>letter;
       system("cls");

       if(checkguess(letter,month,hide_month)==0){
          message="Incorrect letter!";
          tries--;

       }
       else{

         message="Nice! Correct Guess";
       }

       if(hide_month==month){

        message="You are free!";
        hang('f');
        cout<<"\t\t\t\tLife:"<<tries<<endl;
        cout<<"\t\t\t\tThe month is: "<<month<<endl;
        break;

       }
    }

    if(tries==0)
    {
        message="You are Hanged!";
        hang('h');
         cout<<"\t\t\t\tLife:"<<tries<<endl;
           cout<<"\t\t\t\tThe month is: "<<month<<endl;




    }


  //goBackToMain();

}



int main()
{
    int choice;

    cout << "======================    " << endl;
    cout<<"                     GAME HUB" << endl;
    cout << "                        ========================" << endl;




        cout<<" choose a game to play\n";
        cout<<"Press 1  for Tic Tac Toe \n";
        cout<<"Press 2 for Hangman \n";
        cout<<"Press 3 for Exist\n";
        cin>>choice;

        switch(choice)
        {

        case 1:
            playtik();

        break;
        case 2:
             playHangman();

        break;
        case 3:
            cout<<" Bye......\n";
            return 0;

        default:
            cout<<" Invalid choice!:( Try again"<<endl;



        }



}

//hangman

int checkguess(char guess,string real_month,string& hidden_month)
    {
        int matches=0;
        int len=real_month.length();
         int i;
        for(i=0;i<len;i++)
        {
            if(guess==hidden_month[i]){

                return 0;
            }
            if(guess==real_month[i]){

                hidden_month[i]=guess;
                matches++;
            }
        }
        return matches;
    }
void hang(char state){
    string head_string = "|";
    string stage = "=";
    string handle = "|";
    if(state == 'f'){
        head_string = " ";
        handle = "\\";
    }
    else if(state == 'h'){
        stage = " ";
        handle = "/";
    }cout << "\t\t\t\t________" << endl;
    cout << "\t\t\t\t        "<< head_string <<"       |" << endl;
    cout << "\t\t\t\t        O       |" << endl;
    cout << "\t\t\t\t       / \\      |" << "\t    " << message << endl;
    cout << "\t\t\t\t        |       |" << "\t    /" << endl;
    cout << "\t\t\t\t       / \\      |          O  " << endl;
    cout << "\t\t\t\t    =="<< stage << stage << stage << stage << stage << "==   |         / \\" << endl;
    cout << "\t\t\t\t    |       |   |     "<< handle <<"    |" << endl;
    cout << "\t\t\t\t    |       |   |    ===  / \\" << endl;
    cout << "\t\t\t\t=====================|=|==============" << endl;

    }

 //tiktactoe

  void   playtik() {
    while (gameover()) {
        display_board();
        player_turn();
        gameover();

    }
    if (turn == 'X' && draw == false) {
        cout << "player 2[O] WINS!!!" << endl;
    }
    else if (turn == 'O'  && draw == false) {
        cout << "player 1[X] WINS!!!" << endl;
    }
    else {
        cout << "GAME DRAW!!" << endl;

    }

      goBackToMain();
}



void goBackToMain() {
    char choice;
    cout << "Do you want to go back to the main menu? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        main(); // Call the main function to return to the main menu
    }
    else {
        cout << "Thank you for playing. Goodbye!" << endl;
    }
}
