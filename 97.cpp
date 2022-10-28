#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>

#define   ROW    19     // 游戏区域的行数
#define   COL    12     // 游戏区域的列数
#define    NR    4  // 方块数据大小
#define    TYPE  7  // 方块类型数
/* 按键枚举 */
enum key {
   DOWN,    			// 上
   LEFT,    			// 左
   RIGHT,   			// 右
   CHANGE,  			// 变化
   STOP,    			// 停止
   EXIT,    			// 退出
   UNKNOW,  			// 未知
};

/***** 函数声明区域 ******/
void initalGameArea(void);                  // 初始化游戏区域
void drawBlock(char bl[NR][NR]);            // 画方块
void cleanBlock(char bl[NR][NR]);           // 清除方块
void turnBlock(char bl[NR][NR]);            // 旋转方块
void gameEnd(void);                         // 结束游戏
void gameStop(void);                        // 暂停游戏
void showGame(void);                        // 显示游戏
void gameSelf(int signo);                   // 游戏自动运行
void checkDeleteLine(void);                 // 检查是否满一行
void checkGameOver(char bl[NR][NR]);        // 检查是否游戏结束
int  checkMove(char bl[NR][NR], int flag);  // 检查方块是否可移动
void  setBufferedInput(bool enable);                        // 获取输入

/* 全局变量区域 */
static char gameArea[ROW][COL] = {0};   	// 游戏区域数据
static int startX = 4, startY = 6;      	// 方块出现的起始位置
static int type = 0;                    	// 方块当前类型
static int nextType = 0;                	// 方块的下一种类型
static int diret = 0;                   	// 方块的方向
char *state = "\033[32m游戏中...\033[0m";	// 游戏运行状态
static unsigned int level = 0;          	// 游戏等级
static unsigned int score = 0;          	// 游戏分数
static unsigned int maxScore = 0;       	// 游戏最高记录
static FILE *fp = NULL;                 	// 用于把记录保存到文件

/* 方块数据 */
char bl[TYPE][NR][NR][NR] = {
    /* 第一种方块 */
 {
  	{ /* 第一种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第二种方块 */
 {
  	{ /* 第一种方向 */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
  	{ /* 第三种方向 */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
 },

 /* 第三种方块 */
 {
  	{ /* 第一种方向 */
  	 {3,0,0,0},
  	 {3,3,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,3,3,0},
  	 {0,3,0,0},
  	 {0,3,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {3,3,3,0},
  	 {0,0,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,0,3,0},
  	 {0,0,3,0},
  	 {0,3,3,0},
  	 {0,0,0,0},
  	},
 },

 /* 第四种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,0,4,0},
  	 {4,4,4,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,4,0,0},
  	 {0,4,0,0},
  	 {0,4,4,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {0,4,4,4},
  	 {0,4,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,4,4,0},
  	 {0,0,4,0},
  	 {0,0,4,0},
  	 {0,0,0,0},
  	},
 },

 /* 第五种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,5,0,0},
  	 {5,5,5,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,5,0,0},
  	 {0,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {5,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,5,0,0},
  	 {5,5,0,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第六种方块 */
 {
  	{ /* 第一种方向 */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第七种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,7,7,0},
  	 {7,7,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {0,0,7,7},
  	 {0,7,7,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  },
};



/*
 * 主函数：控制全局流程
*/
int main(void)
{
    /*
     * 设置闹钟：
     * 当前时间间隔为0.7秒，下一次时间间隔为0.7秒
    */
    struct itimerval  timer = {{0,700000},{0,700000}};
    setitimer(ITIMER_REAL, &timer,NULL);

    /* 初始化游戏区域 */
    initalGameArea();

    /* 设置游戏信号 */
    signal(SIGALRM, gameSelf);

    /* 初始化方块类型 */
    srand(time(NULL));
    type     = rand()%7;
    nextType = rand()%7;

    /* 读取文件的最高记录 */
    fp = fopen("./record","r+");
    if (NULL == fp)
    {
        /*
         * 文件不存在则创建并打开 
         * "w"方式打开会自动创建不存在的文
         */
        fp = fopen("./record","w");
    }
    fscanf(fp,"%u",&maxScore);

    /* 用户操作 */
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

        /* 画方块 */
        drawBlock(bl[type][diret]);

        /* 显示游戏 */
        showGame();

        /* 清除方块 */
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
 * 函数名：initalGameArea
 * 函数功能：初始化游戏区域
 * 参数：无
 * 返回值：无
*/
void initalGameArea(void)
{
    int i;

	/* 屏幕设置 */
	printf("\033[2J");			  // 清屏
    system("stty -icanon");		  // 关缓冲
    system("stty -echo");		  // 关回显
    fprintf(stdout,"\033[?25l");  // 关闭鼠标显示

    /* 初始化行 */
    for (i = 0; i < COL; i++)
    {
        gameArea[0][i]     = 8;   // 第0行
        gameArea[5][i]     = 8;   // 第5行
        gameArea[ROW-1][i] = 8;   // 最后一行
    }

    /* 初始化列 */
    for (i = 0; i < ROW; i++)
    {
        gameArea[i][0]     = 8;  // 第0列
        gameArea[i][COL-1] = 8;  // 最后一列
    }

    /* 中间一小列 */
    for (i = 1; i < 5; i++)
    {
        gameArea[i][6] = 8;
    }
}


/*
 * 函数名：gameSelf
 * 函数功能：作为信号函数，闹钟时间一到就自动下落
 * 参数：信号
 * 返回值：无
*/
void gameSelf(int signo)
{
    /* 画方块 */
    drawBlock(bl[type][diret]);

    /* 显示游戏 */
    showGame();

    /* 清除方块 */
    cleanBlock(bl[type][diret]);

    /* 如果方块已经到底 */
    if (!checkMove(bl[type][diret],DOWN))
    {
    	/* 检查是否游戏结束 */
    	checkGameOver(bl[type][diret]);

    	/* 保留已经到底的方块 */
    	drawBlock(bl[type][diret]);

    	/* 显示游戏结果 */
    	showGame();

    	/* 到达边界后检查是否可消行 */
    	checkDeleteLine();

    	/* 重新开始下一个方块 */
    	startY = 6;
    	startX = 4;
    	type = nextType;
    	nextType = rand()%7;
    	diret = 0;
    }
}

