#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>

#define   ROW    19     // ��Ϸ���������
#define   COL    12     // ��Ϸ���������
#define    NR    4  // �������ݴ�С
#define    TYPE  7  // ����������
/* ����ö�� */
enum key {
   DOWN,    			// ��
   LEFT,    			// ��
   RIGHT,   			// ��
   CHANGE,  			// �仯
   STOP,    			// ֹͣ
   EXIT,    			// �˳�
   UNKNOW,  			// δ֪
};

/***** ������������ ******/
void initalGameArea(void);                  // ��ʼ����Ϸ����
void drawBlock(char bl[NR][NR]);            // ������
void cleanBlock(char bl[NR][NR]);           // �������
void turnBlock(char bl[NR][NR]);            // ��ת����
void gameEnd(void);                         // ������Ϸ
void gameStop(void);                        // ��ͣ��Ϸ
void showGame(void);                        // ��ʾ��Ϸ
void gameSelf(int signo);                   // ��Ϸ�Զ�����
void checkDeleteLine(void);                 // ����Ƿ���һ��
void checkGameOver(char bl[NR][NR]);        // ����Ƿ���Ϸ����
int  checkMove(char bl[NR][NR], int flag);  // ��鷽���Ƿ���ƶ�
void  setBufferedInput(bool enable);                        // ��ȡ����

/* ȫ�ֱ������� */
static char gameArea[ROW][COL] = {0};   	// ��Ϸ��������
static int startX = 4, startY = 6;      	// ������ֵ���ʼλ��
static int type = 0;                    	// ���鵱ǰ����
static int nextType = 0;                	// �������һ������
static int diret = 0;                   	// ����ķ���
char *state = "\033[32m��Ϸ��...\033[0m";	// ��Ϸ����״̬
static unsigned int level = 0;          	// ��Ϸ�ȼ�
static unsigned int score = 0;          	// ��Ϸ����
static unsigned int maxScore = 0;       	// ��Ϸ��߼�¼
static FILE *fp = NULL;                 	// ���ڰѼ�¼���浽�ļ�

/* �������� */
char bl[TYPE][NR][NR][NR] = {
    /* ��һ�ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �ڶ��ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
  	{ /* �����ַ��� */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {3,0,0,0},
  	 {3,3,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,3,3,0},
  	 {0,3,0,0},
  	 {0,3,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {3,3,3,0},
  	 {0,0,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,3,0},
  	 {0,0,3,0},
  	 {0,3,3,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,0,4,0},
  	 {4,4,4,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,4,0,0},
  	 {0,4,0,0},
  	 {0,4,4,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,4,4,4},
  	 {0,4,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,4,4,0},
  	 {0,0,4,0},
  	 {0,0,4,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,5,0,0},
  	 {5,5,5,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,5,0,0},
  	 {0,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {5,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,5,0,0},
  	 {5,5,0,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,7,7,0},
  	 {7,7,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,7,7},
  	 {0,7,7,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  },
};



/*
 * ������������ȫ������
*/
int main(void)
{
    /*
     * �������ӣ�
     * ��ǰʱ����Ϊ0.7�룬��һ��ʱ����Ϊ0.7��
    */
    struct itimerval  timer = {{0,700000},{0,700000}};
    setitimer(ITIMER_REAL, &timer,NULL);

    /* ��ʼ����Ϸ���� */
    initalGameArea();

    /* ������Ϸ�ź� */
    signal(SIGALRM, gameSelf);

    /* ��ʼ���������� */
    srand(time(NULL));
    type     = rand()%7;
    nextType = rand()%7;

    /* ��ȡ�ļ�����߼�¼ */
    fp = fopen("./record","r+");
    if (NULL == fp)
    {
        /*
         * �ļ��������򴴽����� 
         * "w"��ʽ�򿪻��Զ����������ڵ���
         */
        fp = fopen("./record","w");
    }
    fscanf(fp,"%u",&maxScore);

    /* �û����� */
	char c;
    int key;
	setBufferedInput(false);
    while (1)
    {
        c=getchar();
		switch(c) {
			case 97:	// 'a' key
			case 104:	// 'h' key
			case 68:	// left arrow
			case 52:	// 4 arrow
				key = LEFT;  break;
			case 100:	// 'd' key
			case 108:	// 'l' key
			case 67:	// right arrow
			case 54:	// 6 arrow
				key = RIGHT; break;
			case 119:	// 'w' key
			case 107:	// 'k' key
			case 65:	// up arrow
			case 50:	// 2 arrow
				key = CHANGE;    break;
			case 115:	// 's' key
			case 106:	// 'j' key
			case 66:	// down arrow
			case 56:	// 8 arrow
				key = DOWN;  break;
			case 32:	//space
				key=STOP;break;
			default: key = UNKNOW;
		}
		
        switch (key)
    	{
    	    case RIGHT : checkMove(bl[type][diret],RIGHT);
    	                 break;
    	    case LEFT  : checkMove(bl[type][diret],LEFT);
    	                 break;
    	    case DOWN  : checkMove(bl[type][diret],DOWN);
    	                 break;
    	    case CHANGE: turnBlock(bl[type][(diret+1)%4]);
    	                 break;
    	    case STOP  : gameStop();
    	                 break;
    	    case EXIT  : gameEnd();
    	                 break;
    	    case UNKNOW: continue;
    	}

        /* ������ */
        drawBlock(bl[type][diret]);

        /* ��ʾ��Ϸ */
        showGame();

        /* ������� */
        cleanBlock(bl[type][diret]);
    }

    return 0;
}

void setBufferedInput(bool enable) {
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled) {
		// restore the former settings
		tcsetattr(STDIN_FILENO,TCSANOW,&old);
		// set the new state
		enabled = true;
	} else if (!enable && enabled) {
		// get the terminal settings for standard input
		tcgetattr(STDIN_FILENO,&new);
		// we want to keep the old setting to restore them at the end
		old = new;
		// disable canonical mode (buffered i/o) and local echo
		new.c_lflag &=(~ICANON & ~ECHO);
		// set the new settings immediately
		tcsetattr(STDIN_FILENO,TCSANOW,&new);
		// set the new state
		enabled = false;
	}
}
/*
 * ��������initalGameArea
 * �������ܣ���ʼ����Ϸ����
 * ��������
 * ����ֵ����
*/
void initalGameArea(void)
{
    int i;

	/* ��Ļ���� */
	printf("\033[2J");			  // ����
    system("stty -icanon");		  // �ػ���
    system("stty -echo");		  // �ػ���
    fprintf(stdout,"\033[?25l");  // �ر������ʾ

    /* ��ʼ���� */
    for (i = 0; i < COL; i++)
    {
        gameArea[0][i]     = 8;   // ��0��
        gameArea[5][i]     = 8;   // ��5��
        gameArea[ROW-1][i] = 8;   // ���һ��
    }

    /* ��ʼ���� */
    for (i = 0; i < ROW; i++)
    {
        gameArea[i][0]     = 8;  // ��0��
        gameArea[i][COL-1] = 8;  // ���һ��
    }

    /* �м�һС�� */
    for (i = 1; i < 5; i++)
    {
        gameArea[i][6] = 8;
    }
}


/*
 * ��������gameSelf
 * �������ܣ���Ϊ�źź���������ʱ��һ�����Զ�����
 * �������ź�
 * ����ֵ����
*/
void gameSelf(int signo)
{
    /* ������ */
    drawBlock(bl[type][diret]);

    /* ��ʾ��Ϸ */
    showGame();

    /* ������� */
    cleanBlock(bl[type][diret]);

    /* ��������Ѿ����� */
    if (!checkMove(bl[type][diret],DOWN))
    {
    	/* ����Ƿ���Ϸ���� */
    	checkGameOver(bl[type][diret]);

    	/* �����Ѿ����׵ķ��� */
    	drawBlock(bl[type][diret]);

    	/* ��ʾ��Ϸ��� */
    	showGame();

    	/* ����߽�����Ƿ������ */
    	checkDeleteLine();

    	/* ���¿�ʼ��һ������ */
    	startY = 6;
    	startX = 4;
    	type = nextType;
    	nextType = rand()%7;
    	diret = 0;
    }
}

