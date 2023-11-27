#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct lnode
{
    int data;
    char pname[50];
    struct lnode *next;
};

typedef struct lnode node;
node *last = NULL;
node *head = NULL;
int winPlayer;
int empty = 0;
void deleteAtPostion(int pos, node *confirm);
node *readPost(node *confirm, int noofposition);
void display1();
void addChairs(int chair, int player)
{
    int countPlayer = player;
    winPlayer = player;
    for (int z = 1; z <= chair; z++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        char dummyName[50];

        // if it is NULL VALUE
        if (head == NULL)
        {
            printf("Enter the Number %d player Name : ", countPlayer);
            scanf("%s", dummyName);
            strcpy(newNode->pname, dummyName);
            newNode->data = countPlayer;
            newNode->next = last;
            last = newNode;
            last->next = newNode->next;
            head = newNode;
            countPlayer--;
        }
        else
        {
            // ADD THE ADD OR EVEN VALUE

            if (z % 2 == 0)
            {
                strcpy(newNode->pname, "No player");
                newNode->data = 0;
            }
            else
            {
                if (countPlayer > 0)
                {
                    printf("Enter the Number %d player Name : ", countPlayer);
                    scanf("%s", dummyName);
                    strcpy(newNode->pname, dummyName);
                    newNode->data = countPlayer;
                    countPlayer--;
                }
            }
            last->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
}

void display()
{
    node *temp = head;
    node *tem = temp;
    int m = 1;
    // IF CHAIR IS EMPTY
    if (temp == NULL)
    {
        printf("_________________________________________________\n");
        printf("|Chairs are Empty ..                             |");
        printf("\n|________________________________________________|");
        return;
    }

    // DISPLAY THE ELEMENTS
    do
    {

        if (temp->data != 0)
        {

            if (m == 1)
            {
                printf("   Player Name is %d       =  %s  \n ", temp->data, temp->pname);
                m++;
            }
            else
            {
                printf("  Player Name is %d       =  %s  \n ", temp->data, temp->pname);
            }
        }
        temp = temp->next;
    } while (temp != last->next);
    display1();
}
void display1()
{
    node *temp = head;
    node *tem = temp;
    int countPlayer = 0;
    int emptyspace = 0;
    int empty = 0;
    int m = 1;

    printf("\n___________________________________________________\n\n");
    do
    {
        if (temp->data == 0)
        {
            printf("         %d\n", temp->data);
            emptyspace++;
        }
        else
        {
            countPlayer++;
            printf("         %d   ->> %s\n", temp->data, temp->pname);
        }
        temp = temp->next;
    } while (temp != last->next);
    if (emptyspace > 0)
    {
        empty = 1;
    }
  //  printf("balance players are %d", countPlayer);
    printf("___________________________________________________\n");
}
void gamestart(int players, int totalChair, int finalPlayer)
{
    int primaryPlayer;
    node *temp = head;
    node *tem1 = head;
    node *pre, *confirm, *reconfirm;
    node *selectPlayer;
    int ran, i = 0;
    int empty;
    node *ref;
    int pla1 = players, tota = totalChair;
    if (winPlayer > 1) // 2
    {
        printf("___________________________________________________\n");
        printf("Enter the number below %d \nthat player will play the game : ", players);
        scanf("%d", &primaryPlayer);
        if (players >= primaryPlayer)
        {
            printf("\n__________________________________________________");
            printf("\nYou have Selected ,the player number is : %d       |", primaryPlayer);
            int count = 1;
            srand(time(NULL));
            ran = rand() % 10;
            printf("\nand The player should move( %d ) Times             |", ran);
            printf("\n__________________________________________________|\n");
            printf("\nScore Board  \n");
            printf("----- -----\n");
            // FIND THE PLAYER
            int con = 0, con1 = -1;
            node *temp3, *temp4 = head, *temp5;
            do
            {

                printf("\n%d", temp->data);
                if (temp->data == primaryPlayer)
                {
                    printf(" --> selected player %s ", temp->pname);
                    confirm = temp;
                    reconfirm = temp;
                    con1 = con;
                    temp3 = temp->next;
                }
                con++;
                temp = temp->next;

            } while (temp != last->next);

            ref = readPost(confirm, con1);

            // SWAP THE PLAYER
            if (con1 != -1)
            {
                selectPlayer = confirm;
                node *selectpl = confirm;
                for (int random = 1; random <= ran; random++)
                {
                    selectPlayer = selectPlayer->next;
                }
                if (selectPlayer->data == 0)
                {
                    printf("\n%d player got empty chair -> %d,                       |\nso the player( %s ) can play the next round ..\n", con1, selectPlayer->data, confirm->pname);
                    selectPlayer->data = confirm->data;
                    strcpy(selectPlayer->pname, confirm->pname);
                    confirm->data = 0;
                    deleteAtPostion(con1, confirm);
                    display1();
                    return;
                }
                else
                {
                    printf("\n\n%d --> player got another player chair -> ( %d ), \n", confirm->data, selectPlayer->data);
                    printf("( %s )cant play the next round ....", confirm->pname);

                    printf("\nplayer %d is out choose another player ..", primaryPlayer);

                    ref->next = confirm->next;
                    winPlayer--;
                    //   printf("Final player : %d", winPlayer);
                    
                    if (winPlayer == 1)
                    {
                        printf("\n____________________________________________________\n");
                        printf("      Congratulation      ");
                        printf("\n      --------------      ");
                        printf("\nplayer %d ( %s ) won the match .\n", selectPlayer->data, selectPlayer->pname);
                        printf("\n____________________________________________________\n");
                        printf("Game Over .... \n");
                        return;
                    }
                    display1();
                    if(empty==1){
                        printf("Match Draw ...");
                        return;
                    }
                }
            }
            else
            {
                printf("\n%d player unavailable\n", primaryPlayer);
                display1();
            }
        }
        else
        {
            printf("\nERROR >>>>>>>>>>    \n");
            printf("\n%d the player has not participated in the game ..\n", primaryPlayer);
            printf("Choose again \n");
            gamestart(pla1, totalChair, finalPlayer);
        }
    }
    else{
        printf("\n_________________________________________________|\n");
        printf("Game Over .. if u wanna continue the game \n press 1 ");
        printf("\n_________________________________________________|\n");
    }
}

node *readPost(node *confirm, int numberofposition)
{
    node *temp = head;
    node *pre;
    printf("\n____________________________________________________");

    if (numberofposition == 0)
    {
        temp = temp->next;
        //   free(temp);
        printf("Deleted ");
        return temp;
    }
    for (int i = 0; i < numberofposition; i++)
    {
        pre = temp;
        temp = temp->next;
    }
    return pre;
}
void deleteAtPostion(int pos, node *confirm)
{
    node *temp = head;
    node *pre;
    // if (pos == 0)
    // {
    //     temp = temp->next;
    //     //  free(temp);
    //     printf("Deleted position ");
    //     return;
    // }
    for (int i = 0; i < pos; i++)
    {
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    free(temp);
}

int main()
{
    int choice, gamePerson, sizeofChair, players;

    int finalplayer;
    while (1)
    {
        printf("_________________________________________________");
        printf("\n                                                 |");
        printf("\nChoose anyone in the below list :                |");
        printf("\n------ ------ -- --- ----- -----                 |");
        printf("\n1.add Chairs and add Participants    2.Display   |");
        printf("\n3.Start the game                     4.exit      |");
        printf("\n_________________________________________________|\n");
        scanf("%d", &choice);
        switch (choice)
        {
        // how many u want to add int this node
        case 1:
        {
            printf("_________________________________________________\n");
            printf("Enter the chair size                : ");
            scanf("%d", &sizeofChair);
            printf("Enter the total num of participants : ");
            scanf("%d", &players); // 3
            printf("_________________________________________________\n");
            int size = sizeofChair / 2;
            finalplayer = players;
            // sizeofChair=size-players;

            if (players <= size || players >= size && sizeofChair > players)
            {
                sizeofChair = players * 2;
                addChairs(sizeofChair, players);
            }
            else
            {
                printf("\n_________________________________________________\n");
                printf("participants are greater then chairs ...           |");
                printf("\n_________________________________________________|\n");
            }
            break;
        }

        case 2:
        {

            display();

            break;
        }
        case 3:
        {

            gamestart(players, sizeofChair, finalplayer);

            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        }
    }

    return 0;
}
