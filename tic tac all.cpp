#include<conio.h>

#include<iostream>

#include<stdio.h>

#include<stdlib.h>

using namespace std;
class usser {
  private:
    char x[20], y[20];
  char a[9];
  int i, d, j, k;
  int s[9];
  inline void intro() {
    fflush(stdin);
    printf("\nenter player name\nplayer A:  ");
    gets(x);
    printf("player B:  ");
    fflush(stdin);
    gets(y);
    printf("\ncontinue:");
    getch();
    system("cls");
    char ch[9] = {
      'L',
      'O',
      'D',
      'I',
      'N',
      'G',
      '.',
      '.',
      '.'
    };
    for (i = 0; i <= 8; i++) {
      printf("%c", ch[i]);
      for (j = 0; j <= 10; j++) {
        system("color 2");
      }
    }
    system("color 07");
    system("cls");
    printf("INSTRUCTION:\n>>Make straight line shape in square using 'X' and 'O'.\n>>The player who make recognized line first will win.\n>>You must press the location block number where you want to enter 'X' and 'O'.\n");
    printf("\nLOCATION OF BLOCK\t\t FILL LIKE THIS");
    printf("\n_______________\t\t\t________________\n| 1  | 2  | 3  |\t\t|  X |  O |    |\n|____|____|____|\t\t|____|____|____|\n| 4  | 5  | 6  |\t\t|    |  X | O  |\n|____|____|____|\t\t|____|____|____|\n| 7  | 8  | 9  |\t\t|  O |    |  X |\n|____|____|____|\t\t|____|____|____|\n");
    printf("**************************************************************\n%s your key is 'X' and  %s your key is 'O'.\nENTER to play:", x, y);
    getch();
    system("cls");
    start();
  }

  inline void start() {
    for (k = 0; k <= 8; k++) {
      a[k] = ' ';
    }
    for (k = 0; k <= 8; k++) {
      s[k] = 60;
    }
    for (k = 0; k <= 3; k++) {
      user1();
      user2();
    }
    user1();
    system("cls");
    print();
    printf("\nDRAW!");
    repeat();
  }

  inline void check() {
    if (s[0] + s[1] + s[2] == 3 || s[3] + s[4] + s[5] == 3 || s[6] + s[7] + s[8] == 3 || s[0] + s[3] + s[6] == 3 || s[1] + s[4] + s[7] == 3 || s[2] + s[5] + s[8] == 3 || s[0] + s[4] + s[8] == 3 || s[2] + s[4] + s[6] == 3) {
      system("cls");
      print();
      printf("congratulation!, %s you won.\npress any key to continue:\n", x);
      getch();
      system("cls");
      repeat();
    }
    if (s[0] + s[1] + s[2] == 6 || s[3] + s[4] + s[5] == 6 || s[6] + s[7] + s[8] == 6 || s[0] + s[3] + s[6] == 6 || s[1] + s[4] + s[7] == 6 || s[2] + s[5] + s[8] == 6 || s[0] + s[4] + s[8] == 6 || s[2] + s[4] + s[6] == 6) {
      system("cls");
      print();
      printf("congratulation!, %s you won.\npress any key to continue:\n", y);
      getch();
      system("cls");
      repeat();
    }
  }

  inline void repeat() {
    char c;
    printf("\npress r to restart:\npress q to quit:\npress m to main menu:\n");
    c = getch();
    switch (c) {
    case 'r':
      system("cls");
      start();
      break;
    case 'm':
      system("cls");
      intro();
      break;
    case 'q':
      exit(0);
    default:
      system("cls");
      printf("invalid entry$$\n");
      repeat();
    }
  }

  inline void user1() {
    system("cls");
    i = 11;
    print();
    printf("\n%s your term,enter block number:  ", x);
    scanf("%d", & i);
    if (i == 0) {
      exit(0);
    }
    j = i - 1;
    ic1();
    check();
  }

  inline void user2() {
    system("cls");
    i = 11;
    print();
    printf("\n%s your term,enter block number:  ", y);
    scanf("%d", & i);
    if (i == 0) {
      exit(0);
    }
    j = i - 1;
    ic2();
    check();
  }

  inline void print() {
    printf("\n_____________\n| %c | %c | %c |\n|___|___|___|\n| %c | %c | %c |\n|___|___|___|\n| %c | %c | %c |\n|___|___|___|\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
  }

  inline void ic1() {
    if (s[j] == 60) {
      a[j] = 'X';
      s[j] = 1;
    } else {
      if (i >= 1 && i <= 9) {
        system("cls");
        print();
        printf("\nAllready filled,try again with another block:");
        for (d = 0; d <= 30; d++) {
          system("color 07");
        }
        fflush(stdin);
        user1();
      } else {
        system("cls");
        print();
        printf("\nInvalid entry");
        for (d = 0; d <= 15; d++) {
          system("color 07");
        }
        fflush(stdin);
        user1();
      }
    }
  }

  inline void ic2() {
    if (s[j] == 60) {
      a[j] = 'O';
      s[j] = 2;
    } else {
      if (i >= 1 && i <= 9) {
        system("cls");
        print();
        printf("\nAllready filled,try again with another block:");
        for (d = 0; d <= 30; d++) {
          system("color 07");
        }
        fflush(stdin);
        user2();
      } else {
        system("cls");
        print();
        printf("\nInvalid entry");
        for (d = 0; d <= 15; d++) {
          system("color 07");
        }
        fflush(stdin);
        user2();
      }
    }
  }

  public:
    void mainn() {
      intro();
    }
};

class commputer {
  private: char a[9];
  int i, d, j, k, x, v, o;
  int s[9];
  inline void intro() {
    system("cls");
    char ch[9] = {
      'L',
      'O',
      'D',
      'I',
      'N',
      'G',
      '.',
      '.',
      '.'
    };
    for (i = 0; i <= 8; i++) {
      printf("%c", ch[i]);
      for (j = 0; j <= 10; j++) {
        system("color 2");
      }
    }
    system("color 07");
    system("cls");
    printf("INSTRUCTION:\n>>Make straight line shape in square using 'X'.\n>>If you make line before computer,you will win.\n>>You must press the location block number where you want to enter 'X'.\n");
    printf("\nLOCATION OF BLOCK\t\t FILL LIKE THIS");
    printf("\n_______________\t\t\t________________\n| 1  | 2  | 3  |\t\t|  X |  O |    |\n|____|____|____|\t\t|____|____|____|\n| 4  | 5  | 6  |\t\t|    |  X | O  |\n|____|____|____|\t\t|____|____|____|\n| 7  | 8  | 9  |\t\t|  O |    |  X |\n|____|____|____|\t\t|____|____|____|\n");
    printf("**************************************************************\nyou got 'X'.\nENTER to play:");
    getch();
    system("cls");
    start();
  }

  void start() {
    for (k = 0; k <= 8; k++) {
      a[k] = ' ';
    }
    for (k = 0; k <= 8; k++) {
      s[k] = 10;
    }
    v = 1;
    user();
    computer();
  }

  void user() {
    check();
    delay();
    system("cls");
    i = 11;
    print();
    printf("\nyour term,enter block number:  ");
    scanf("%d", & i);
    if (i == 0) {
      exit(0);
    }
    j = i - 1;
    ic();
    check();
  }

  void compfix() {
    system("cls");
    print();
    j = i - 1;
    a[j] = 'O';
    s[j] = 2;
    check();
  }

  void check() {
    if (s[0] + s[1] + s[2] == 3 || s[3] + s[4] + s[5] == 3 || s[6] + s[7] + s[8] == 3 || s[0] + s[3] + s[6] == 3 || s[1] + s[4] + s[7] == 3 || s[2] + s[5] + s[8] == 3 || s[0] + s[4] + s[8] == 3 || s[2] + s[4] + s[6] == 3) {
      system("cls");
      print();
      printf("congratulation!,you won.\npress any key to continue:\n");
      getch();
      system("cls");
      repeat();
    }
    if (s[0] + s[1] + s[2] == 6 || s[3] + s[4] + s[5] == 6 || s[6] + s[7] + s[8] == 6 || s[0] + s[3] + s[6] == 6 || s[1] + s[4] + s[7] == 6 || s[2] + s[5] + s[8] == 6 || s[0] + s[4] + s[8] == 6 || s[2] + s[4] + s[6] == 6) {
      system("cls");
      print();
      printf("you lose.\npress any key to continue:\n");
      getch();
      system("cls");
      repeat();
    }
  }

  void repeat() {
    char c;
    printf("\npress r to restart:\npress q to quit:\npress m to main menu:\n");
    c = getch();
    switch (c) {
    case 'r':
      system("cls");
      start();
      break;
    case 'm':
      system("cls");
      intro();
      break;
    case 'q':
      exit(0);
    default:
      system("cls");
      printf("invalid entry$$\n");
      repeat();
    }
  }

  void computer() {
    if (s[4] == 1) {
      i = 3;
      compfix();
      user();
      bstmove();
      bstmove();
      bstmove();
    }
    if (s[0] == 1 || s[1] == 1 || s[2] == 1 || s[3] == 1 || s[5] == 1 || s[6] == 1 || s[7] == 1 || s[8] == 1) {
      i = 5;
      compfix();
      user();
      bstmove();
      bstmove();
      bstmove();
    }
  }

  void draw() {
    system("cls");
    print();
    printf("\nDRAW !");
    repeat();
  }

  void delay() {
    for (x = 0; x <= 30; x++) {
      system("color 07");
    }
  }

  void print() {
    printf("\n_____________\n| %c | %c | %c |\n|___|___|___|\n| %c | %c | %c |\n|___|___|___|\n| %c | %c | %c |\n|___|___|___|\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
  }

  void ic() {
    if (s[j] == 10) {
      a[j] = 'X';
      s[j] = 1;
    } else {
      if (i > 0 && i < 10) {
        system("cls");
        print();
        printf("\nAllready filled,try again with another block:");
        for (x = 0; x <= 3; x++) {
          system("color 07");
        }
        fflush(stdin);
        user();
      } else {
        system("cls");
        print();
        printf("\nInvalid entry");
        delay();
        fflush(stdin);
        user();
      }
    }
  }

  void bstmove() {
    o = 10;
    for (d = 0; d <= 8; d++) {
      if (s[d] == 10) {
        s[d] = 2;
        if (s[0] + s[1] + s[2] == 6 || s[3] + s[4] + s[5] == 6 || s[6] + s[7] + s[8] == 6 || s[0] + s[3] + s[6] == 6 || s[1] + s[4] + s[7] == 6 || s[2] + s[5] + s[8] == 6 || s[0] + s[4] + s[8] == 6 || s[2] + s[4] + s[6] == 6) {
          a[d] = 'O';
          o = 0;
          v++;
          break;
        } else {
          s[d] = 10;
          o = 1;
        }
      }
    }
    if (o == 1) {
      for (d = 0; d <= 8; d++) {
        if (s[d] == 10) {
          s[d] = 1;
          if (s[0] + s[1] + s[2] == 3 || s[3] + s[4] + s[5] == 3 || s[6] + s[7] + s[8] == 3 || s[0] + s[3] + s[6] == 3 || s[1] + s[4] + s[7] == 3 || s[2] + s[5] + s[8] == 3 || s[0] + s[4] + s[8] == 3 || s[2] + s[4] + s[6] == 3) {
            s[d] = 2;
            a[d] = 'O';
            o = 0;
            v++;
            break;
          } else {
            s[d] = 10;
            o = 1;
          }
        }
      }
    }
    if (o == 1) {
      if (s[2] + s[5] + s[8] == 21 && s[6] + s[7] + s[8] == 21) {
        if (s[5] == 1 && s[7] == 1 && s[8] == 10) {
          s[8] = 2;
          a[8] = 'O';
          o = 0;
          v++;
        } else {
          o = 1;
        }
      }
    }
    if (o == 1) {
      if (s[0] + s[4] + s[8] < 15 || s[2] + s[4] + s[6] < 15) {
        if (s[1] + s[4] + s[7] == 22 || s[3] + s[4] + s[5] == 22) {
          for (d = 1; d <= 7; d += 2) {
            if (s[d] == 10) {
              s[d] = 2;
              a[d] = 'O';
              o = 0;
              v++;
              break;
            } else {
              o = 1;
            }
          }
        }
      }
    }
    if (o == 1) {
      if (s[0] + s[4] + s[8] == 22 || s[2] + s[4] + s[6] == 22) {
        for (d = 0; d <= 8; d += 2) {
          if (d == 0 || d == 2 || d == 6 || d == 8) {
            if (s[d] == 10) {
              s[d] = 2;
              a[d] = 'O';
              o = 0;
              v++;
              break;
            } else {
              o = 1;
            }
          }
        }
      }
    }
    if (o == 1) {
      if (s[0] + s[1] + s[2] == 21 && s[2] + s[5] + s[8] == 21) {
        if (s[2] == 10) {
          s[2] = 2;
          a[2] = 'O';
          o = 0;
          v++;
        } else {
          o = 1;
        }
      }
    }
    if (o == 1) {
      if (s[6] + s[7] + s[8] == 21 && s[0] + s[3] + s[6] == 21) {
        if (s[6] == 10) {
          s[6] = 2;
          a[6] = 'O';
          o = 0;
          v++;
        } else {
          o = 1;
        }
      }
    }
    if (o == 1) {
      if (s[0] + s[1] + s[2] == 21 && s[0] + s[3] + s[6] == 21) {
        if (s[0] == 10) {
          s[0] = 2;
          a[0] = 'O';
          o = 0;
          v++;
        } else {
          o = 1;
        }
      }
    }
    if (o == 1) {
      for (d = 0; d <= 8; d++) {
        if (s[d] == 10) {
          s[d] = 2;
          a[d] = 'O';
          o = 0;
          v++;
          break;
        } else {
          o = 1;
        }
      }
    }
    if (v == 4) {
      check();
      draw();
    }
    user();
  }

  public:
    void cmainn() {
      intro();
    }
};

int main() {
  char a;
  printf("\nWELCOME TO TIC TAC TOE GAME:");
  printf("\n***************************************************************");
  printf("\nselect mode\nTwo player mode::press p.\nSingle player mode::press s.\n");
  a = getch();
  switch (a) {
  case 'p':
    usser p;
    p.mainn();
    break;
  case 's':
    commputer s;
    s.cmainn();
    break;
  default:
    system("cls");
    printf("\nInvalid entry");
    main();
  }
}
