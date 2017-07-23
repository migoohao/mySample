
/*
	Blokus  

*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
const int
	Length = 19,
	//游戏棋盘的规模（[0..19]*[0..19]）。
	Piecesize = 4,
	//方块的规模（[0..4]*[0..4]）。
	Piecenum = 20,
	//方块的个数（编号依次为0, 1, ... , 20）。

	Blankcolour = 4,
	//游戏棋盘上空白格子的颜色。
	Mycolour = 5;
	//自己方块的颜色。


struct board {
		int
			b[Length + 1][Length + 1];
	};
	//游戏棋盘。其[i][j]分量的值，表示第i行、第j列的格子的颜色。
	//本程序中的其它“坐标”[x][y]，也都表示第x行、第y列。
struct piece {
		int
			p[Piecesize + 1][Piecesize + 1];
		//方块，其分量的值为1或0，表示该格子是否被占。

	};
	
const piece
	Iron[Piecenum + 1] =
	//游戏描述中给出的21种方块。
		{
			//No.0
			{
				{1, 0, 0, 0, 0,				
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.1
			{
				{1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.2
			{
				{1, 1, 1, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.3
			{
				{1, 1, 1, 1, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.4
			{
				{1, 1, 1, 1, 1,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.5
			{
				{1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.6
			{
				{1, 1, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.7
			{
				{1, 1, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.8
			{
				{1, 1, 0, 0, 0,
				 0, 1, 1, 0, 0,
				 0, 0, 1, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.9
			{
				{1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.10
			{
				{1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.11
			{
				{1, 0, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.12
			{
				{1, 0, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.13
			{
				{1, 1, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.14
			{
				{0, 1, 0, 0, 0,
				 1, 1, 1, 0, 0,
				 0, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.15
			{
				{1, 0, 0, 0, 0,
				 1, 1, 1, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.16
			{
				{1, 1, 1, 0, 0,
				 1, 0, 0, 0, 0,
				 1, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.17
			{
				{0, 1, 1, 0, 0,
				 1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.18
			{
				{0, 1, 1, 0, 0,
				 1, 1, 0, 0, 0,
				 0, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.19
			{
				{0, 1, 1, 0, 0,
				 0, 1, 0, 0, 0,
				 1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			},
			//No.20
			{
				{0, 1, 1, 1, 0,
				 1, 1, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0}
			}
		};
const int
	Ironsize[Piecenum + 1] =
	//方块的大小，即每个方块的分值。
		{
			1, 2, 3, 4, 5, 3, 4,
			5, 5, 4, 5, 4, 5, 5,
			5, 5, 5, 4, 5, 5, 5
		};
board
	cur;
	//当前的游戏棋盘。
piece
	diamond[Piecenum + 1][8];
	//其[i][d]分量，表示第i种方块经第d种方式旋转后，得到的方块。
bool
	used[Piecenum + 1];
	//其[i]分量表示第i个方块是否已被使用。
int
	fx, fy;
	//第一个方块必须覆盖的格子坐标。

bool
	meetend;
	//是否收到[end]指令。

void turn(int d, piece oir, piece & res);
//方块oir经第d种方式旋转后，得到方块res。
void forge();
//生成diamond数组。

void start(board & cur);
//执行[start]指令。
bool putable(board cur, int x, int y, int i, int d);
//判断以(x, y)为左上角坐标的第i种方块，经第d种方式旋转后得到的方块，能否被放置在
//当前棋盘上。
bool putablefirst(int x, int y, int i, int d);
//判断我最喜欢的方式放的方块是否能够作为第一块放到棋盘上

void putsingle(board & cur, int x, int y, int p, int i, int d);
//将以(x, y)为左上角坐标的第i种方块，经第d种方式旋转后得到的方块，以颜色p放置在
//棋盘上。
void putothers(board & cur);
//执行[put]指令——根据输入的其他玩家所放置的方块，更新游戏棋盘各个格子的颜色。


const int Passedcolour=6;
//判断扩展空间的时候走过的格的颜色
int step=0;
//记录走过了多少步了

const int dx[8]={-1,-1,1,1,0,0,-1,1};
const int dy[8]={-1,1,-1,1,-1,1,0,0};
//一个块的八个方向，左上，右上，左下，右下
int otherspoint[4]={};
//其他人的分
int rank[4]={};
//其他人的当前排名，越大排名越高
bool enteruncontrolled;
//判断放上这个块后是否进入了未控制的区域

void clean(board & cur);
//初始化游戏棋盘。

void putmine(board & cur);
//依次选择（枚举）方块的种类、旋转方式、位置，直至其能够放置在当前棋盘上为止，并
//输出结果。

void putminefirst(board & cur);
//以我最喜欢的方式放下第一块

board copies;
//棋盘的拷贝，用于spread和valid函数
board iscorner;
//棋盘上每个方格是否是可行的角拷贝，用于计算权值
board isrealcorner;
//棋盘上每个方格是否是可行的角
board controlled;
//扩展时判断这个格是否可能被控制
board realcontrolled;
//实际这个格是否被控制

float powervalue[Piecesize+Length+1][Piecesize+Length+1][Piecenum+1][8]={};
//每种状态的权值
int spread(int x,int y);
//计算从该方格可以扩充出多少空间（即方格数）

bool pointvalid(int x,int y);
//判断该方格是否是可行的方格
bool spreadvalid(int x,int y);
//判断该格是否是可扩展的方格
bool valid(int x,int y);
//判断该方格是否接触本方方格的边或出界



void calculate(board & cur,int u,int v,int i,int d);
//计算该方块种类、旋转方式、位置这种状态的权值

/*--------------------------------以下是函数的定义------------------------*/
int main()
{
	forge();
	start(cur);
	//初始化游戏棋盘，并生成游戏所需方块。
	putothers(cur);
	putminefirst(cur);
	//放置第一个方块。
	meetend = false;
	for (;;) {
		putothers(cur);
		if (meetend == true)
			break;
		putmine(cur);
	}
	//不断根据输入更新当前游戏棋盘，并输出自己的放置信息，直至接收到[end]指令。
	return 0;
}

void turn(int d, piece oir, piece & res)
//方块oir经第d种旋转方式后，得到方块res。
{
	int
		u, v;

	switch (d) {
		case 0 :
		//原状。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[u            ][v            ];
		break;

		case 1 :
		//向右90度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - v][u            ];
		break;

		case 2 :
		//向右180度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - u][Piecesize - v];
		break;

		case 3 :
		//向右270度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[v            ][Piecesize - u];
		break;

		case 4 :
		//水平翻转。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[u            ][Piecesize - v];
		break;

		case 5 :
		//水平翻转后向右90度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - v][Piecesize - u];
		break;

		case 6 :
		//水平翻转后向右180度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - u][v            ];
		break;

		case 7 :
		//水平翻转后向右270度。
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[v            ][u            ];
	}
}

void forge()
//生成diamond数组。
{
	int
		i, d;

	for (i = 0; i <= Piecenum; i++)
	for (d = 0; d <= 7; d++)
		turn(d, Iron[i], diamond[i][d]);
	//将第i种方块（Iron[i]）经第d种旋转方式后得到的方块，记录入diamond数组。
}

void clean(board & cur)
//初始化游戏棋盘。
{
	int
		u, v;
	memset(otherspoint,0,sizeof(otherspoint));
	memset(&copies,0,sizeof(copies));
	memset(&realcontrolled,0,sizeof(realcontrolled));
	memset(&controlled,0,sizeof(controlled));
	for (u = 0; u <= Length; u++)
	for (v = 0; v <= Length; v++)
	{
		cur.b[u][v] = Blankcolour;
		isrealcorner.b[u][v]=Blankcolour;
	}
	//将游戏棋盘初始化为未放置方块的格子的颜色。
}

void start(board & cur)
//执行[start]指令。
{
	string
		command;

	getline(cin, command);
	cin>>fx>>fy;
	cin.get();
	//输入第一个方块必须覆盖的格子。
	clean(cur);
	memset(used, 0, sizeof(used));
	//初始化游戏棋盘，并将所有方块置为“未使用过”状态。
}

bool putablefirst(board & cur,int x, int y, int i, int d,int fx,int fy)
//判断我最喜欢的方式放的方块是否能够作为第一块放到棋盘上
{
	int
		u, v;
	bool
		filled;

	filled = false;
	for (u = 0; u <= Piecesize; u++)
	for (v = 0; v <= Piecesize; v++) {
		if ( (used[i]==0) &&
			(diamond[i][d].p[u][v] == 1) &&
			(
				((x + u) < 0     ) ||
				((y + v) < 0     ) ||
				((x + u) > Length) ||
				((y + v) > Length) ||
				(cur.b[x + u][y + v] != Blankcolour) ||
				(
					((y + v + 1) <= Length) &&
					(cur.b[x + u    ][y + v + 1] == Mycolour)
					//右边。
				) ||
				(
					((x + u + 1) <= Length) &&
					(cur.b[x + u + 1][y + v    ] == Mycolour)
					//下边。
				) ||
				(
					((y + v - 1) >= 0) &&
					(cur.b[x + u    ][y + v - 1] == Mycolour)
					//左边。
				) ||
				(
					((x + u - 1) >= 0) &&
					(cur.b[x + u - 1][y + v	   ] == Mycolour)
					//上边。
				)
				)
			//是否有格子超出游戏棋盘的范围及与自己的格子
			//有相邻的边。
			)
			return false;
		if (
			(diamond[i][d].p[u][v] == 1) &&
			((x + u) == fx) &&
			((y + v) == fy)
			//是否能覆盖格子(fx, fy)。
		)
			filled = true;
	}
	if (filled == true)
		return true;
	else
		return false;
	//如果格子(fx, fy)被覆盖，则结果为“能”。
}

void putminefirst(board & cur)
//以我最喜欢的方式放下第一块
{
	int
		u, v,i, d;
	int finalu,finalv,finali,finald;
	float max=INT_MIN;
	for (i=0;i<Piecenum;i++)
	for (u = (- Piecesize); u <= Length; u++)
	for (v = (- Piecesize); v <= Length; v++)
	for (d = 0; d <= 7; d++)
	//枚举旋转方式。
		if (putablefirst(cur,u, v, i, d,fx,fy) == true)
		{
			//如果其可以作为第一个方块，被放置在棋盘上。
			calculate(cur,u,v,i,d);
			if (max<powervalue[u+Piecesize][v+Piecesize][i][d])
			{
				finalu=u;
				finalv=v;
				finali=i;
				finald=d;
				max=powervalue[u+Piecesize][v+Piecesize][i][d];
			}
			else if (max==powervalue[u+Piecesize][v+Piecesize][i][d]&&Ironsize[i]>Ironsize[finali])
			{
				finalu=u;
				finalv=v;
				finali=i;
				finald=d;
			}
		}
			putsingle(cur, finalu, finalv, Mycolour, finali, finald);
			copies=cur;
			for (int p1=0;p1<=Piecesize;p1++)
				for (int p2=0;p2<=Piecesize;p2++)
			{
				if (diamond[finali][finald].p[p1][p2])
				{
				if (isrealcorner.b[finalu+p1][finalv+p2]==Mycolour) {isrealcorner.b[finalu+p1][finalv+p2]=Blankcolour;}
				for (int k=0;k<4;k++)
				{
					if (finalu+p1+dx[k]<0||finalu+p1+dx[k]>Length||finalv+p2+dy[k]<0||finalv+p2+dy[k]>Length) continue;
					if (pointvalid(finalu+p1+dx[k],finalv+p2+dy[k]))
					{
						isrealcorner.b[finalu+p1+dx[k]][finalv+p2+dy[k]]=Mycolour;
					}
					if (isrealcorner.b[finalu+p1+dx[k]][finalv+p2+dy[k]]==Mycolour)
						isrealcorner.b[u+p1+dx[k+4]][v+p2+dy[k+4]]=Blankcolour;
				}
				}
			}
			step++;
			used[finali] = true;
			cout<<finalu<<' '<<finalv<<' '<<finali<<' '<<finald<<endl<<flush;
			//根据该方块的种类、旋转方式、位置，在棋盘上放置该方块并输出结果。
			return;

}

void putsingle(board & cur, int x, int y, int p, int i, int d)

//将以(x, y)为左上角坐标的第i种方块，经第d种方式旋转后得到的方块，以颜色p放置在
//棋盘上。
{
	int
		u, v;

	for (u = 0; u <= Piecesize; u++)
	for (v = 0; v <= Piecesize; v++)
		if (diamond[i][d].p[u][v] == 1)
			cur.b[x + u][y + v] = p;
		//因为(x, y)是左上角坐标，所以该方块的(u, v)位置，对应于游戏棋盘上的
		//(x + u, y + v)位置。
}



void putothers(board & cur)
//执行[put]指令——根据输入的其他玩家所放置的方块，更新游戏棋盘各个格子的颜色。
{
	string
		command;
	int
		n, ni, x, y, c, i, d;

	getline(cin, command);
	if (command == "[end]") {
		meetend = true;
		return;
	}
	//如果遇到[end]指令，则游戏结束，自动退出。

	cin>>n;
	cin.get();
	for (ni = 1; ni <= n; ni++) 
	{
		cin>>x>>y>>c>>i>>d;
		cin.get();
		putsingle(cur, x, y, c, i, d);
		otherspoint[c]+=Ironsize[i];
		//每输入一个其他玩家所放置的方块，更新棋盘一次。
		for (int p1=0;p1<=Piecesize;p1++)
			for (int p2=0;p2<=Piecesize;p2++)
		    {
				if (diamond[i][d].p[p1][p2])
				{					
					isrealcorner.b[x+p1][y+p2]=Blankcolour;	
					for (int k=0;k<4;k++)
					{
						if (pointvalid(x+p1+dx[k],y+p2+dy[k]))
							isrealcorner.b[x+p1+dx[k]][y+p2+dy[k]]=c;
						if (iscorner.b[x+p1+dx[k+4]][y+p2+dy[k+4]]==c)
						{
							iscorner.b[x+p1+dx[k+4]][y+p2+dy[k+4]]=Blankcolour;
						}
					}
				}
			}
	}
	memset(&controlled,0,sizeof(controlled));
	copies=cur;
	for(int u=0;u<=Length;u++)
		for (int v=0;v<=Length;v++)
			if (isrealcorner.b[u][v]==Mycolour)
				spread(u,v);
	realcontrolled=controlled;
}

bool putable(board cur, int x, int y, int i, int d)
//判断以(x, y)为左上角坐标的第i种方块，经第d种方式旋转后得到的方块，能否被放置在
//当前棋盘上。
{
	int
		u, v;
	bool
		corner;
	
	corner = false;
	for (u = 0; u <= Piecesize; u++)
	for (v = 0; v <= Piecesize; v++) {
		if (
			(diamond[i][d].p[u][v] == 1) &&
			(
				((x + u) < 0     ) ||
				((y + v) < 0     ) ||
				((x + u) > Length) ||
				((y + v) > Length) ||
				//是否有格子超出游戏棋盘的范围。
				(cur.b[x + u][y + v] != Blankcolour) ||
				(
					((y + v + 1) <= Length) &&
					(cur.b[x + u    ][y + v + 1] == Mycolour)
					//右边。
				) ||
				(
					((x + u + 1) <= Length) &&
					(cur.b[x + u + 1][y + v    ] == Mycolour)
					//下边。
				) ||
				(
					((y + v - 1) >= 0) &&
					(cur.b[x + u    ][y + v - 1] == Mycolour)
					//左边。
				) ||
				(
					((x + u - 1) >= 0) &&
					(cur.b[x + u - 1][y + v	   ] == Mycolour)
					//上边。
				)
				//是否与自己的格子有相邻的边。
			)
		)
			return false;
		if (
			(corner == false) &&
			(diamond[i][d].p[u][v] == 1) &&
			(
				(
					((x + u - 1) >= 0     ) &&
					((y + v + 1) <= Length) &&
					(cur.b[x + u - 1][y + v + 1] == Mycolour)
					//右上角。
				) ||
				(
					((x + u + 1) <= Length) &&
					((y + v + 1) <= Length) &&
					(cur.b[x + u + 1][y + v + 1] == Mycolour)
					//右下角。
				) ||
				(
					((x + u + 1) <= Length) &&
					((y + v - 1) >= 0     ) &&
					(cur.b[x + u + 1][y + v - 1] == Mycolour)
					//左下角。
				) ||
				(
					((x + u - 1) >= 0     ) &&
					((y + v - 1) >= 0     ) &&
					(cur.b[x + u - 1][y + v - 1] == Mycolour)
					//左上角。
				)
			)
			//是否有相连的顶点。
		)
			corner = true;
	}
	if (corner == true)
		return true;
	else
		return false;
	//如果遇到过相连的顶点，则结果为“能”。
}





int spread(int x,int y)
{
	if (!spreadvalid(x,y)) return 0;
	controlled.b[x][y]=1;
	copies.b[x][y]=Passedcolour;
	return 1+spread(x,y-1)+spread(x,y+1)+spread(x-1,y)+spread(x+1,y);
}

bool spreadvalid(int x,int y)
{
	if (copies.b[x][y]!=Blankcolour) return 0;
	if (!valid(x,y)) return 0;
	return 1;
}

bool pointvalid(int x,int y)
{
	if (copies.b[x][y]!=Blankcolour&&copies.b[x][y]!=Passedcolour) return 0;
	if (!valid(x,y)) return 0;
	if (!realcontrolled.b[x][y]) enteruncontrolled=1;
	return 1;
}

bool valid(int x,int y)
{
	if (x<0||x>Length||y<0||y>Length) return 0;
	if  (
		(
			((y  + 1) <= Length) &&
			(copies.b[x     ][y  +  1] == Mycolour)
			//右边。
		) ||
		(
			((x  + 1) <= Length) &&
			(copies.b[x  + 1][y      ] == Mycolour)
			//下边。
		) ||
		(
			((y - 1) >= 0) &&
			(copies.b[x     ][y   - 1] == Mycolour)
			//左边。
		) ||
		(
			((x - 1) >= 0) &&
			(copies.b[x  - 1][y      ] == Mycolour)
			//上边。
		)
		)
		return 0;
	return 1;
}

void calculate(board & cur,int u,int v,int i,int d)
{
	powervalue[u+Piecesize][v+Piecesize][i][d]+=Ironsize[i]*20;
	//权值第一项：方格数

	int middlex=9,middley=9;
	int sum,dif;
	int minsum=100,mindif=100;
	float nspread;
	float nmaxspread=-1;
	int nnewspace=0;
	if (fx) middlex++;
	if (fy) middley++;
	int newcorners=0;
	memset(&controlled,0,sizeof(controlled));
	copies=cur;
	iscorner=isrealcorner;
	putsingle(copies,u,v,Mycolour,i,d);
	for (int p1=0;p1<=Piecesize;p1++)
		for (int p2=0;p2<=Piecesize;p2++)
		{			
			if (diamond[i][d].p[p1][p2])
			{
				sum=abs(middlex-u-p1)+abs(middley-v-p2);
				dif=abs(abs(middlex-u-p1)-abs(middley-v-p2));
				if (minsum>sum)
				{
					minsum=sum;
					mindif=dif;
				}
				else if (minsum==sum&&mindif>dif)
				{
					mindif=dif;
				}
				if (iscorner.b[u+p1][v+p2]==Mycolour) {iscorner.b[u+p1][v+p2]=Blankcolour;newcorners--;}
				for (int l=0;l<4;l++)
					if (iscorner.b[u+p1][v+p2]==l)
						powervalue[u+Piecesize][v+Piecesize][i][d]+=rank[l];
				for (int k=0;k<4;k++)
				{
					enteruncontrolled=0;
					if (pointvalid(u+p1+dx[k],v+p2+dy[k]))
					{
						if (step>18)
							for (int j=0;j<Piecenum;j++)
							{
								if (used[j]) continue;
								for (int m= (- Piecesize); m <= Length; m++)
									for (int n = (- Piecesize); n <= Length; n++)
										for (int l=0;l<7;l++)
											if (putablefirst(copies,m,n,j,l,u+p1+dx[k],v+p2+dy[k]))
												powervalue[u+Piecesize][v+Piecesize][i][d]+=Ironsize[j]*10;
							}
							
						iscorner.b[u+p1+dx[k]][v+p2+dy[k]]=Mycolour;
						newcorners++;
						nspread=spread(u+p1+dx[k],v+p2+dy[k]);
						if (enteruncontrolled) nspread*=1.3;
						nmaxspread=nmaxspread>nspread?nmaxspread:nspread;
						nnewspace++;
					}
					if (iscorner.b[u+p1+dx[k+4]][v+p2+dy[k+4]]==Mycolour)
					{
						iscorner.b[u+p1+dx[k+4]][v+p2+dy[k+4]]=Blankcolour;
						newcorners--;
					}
				}
			}			
		}
	if (step>4) powervalue[u+Piecesize][v+Piecesize][i][d]+=(float)(nmaxspread/10.0)*2;
	if (step<12) powervalue[u+Piecesize][v+Piecesize][i][d]+=(float)(minsum*(-6+0.5*step)+mindif*(-1+0.08*step));
	powervalue[u+Piecesize][v+Piecesize][i][d]+=newcorners*(-step*step+21*step)/14.0;
	//权值第二项：距中心的距离，权值第三项：扩展出的有用的角数，权值第四项：扩展的新空间大小(包含进入原来不可控制区域的加分）
	
	return ;
}

void putmine(board & cur)
//依次选择（枚举）方块的种类、旋转方式、位置，直至其能够放置在当前棋盘上为止，并
//输出结果。
{
	int
		u, v, i, d;
	int finalu,finalv,finali,finald;
	float max=INT_MIN;
	memset(powervalue,0,sizeof(powervalue));
	memset(rank,0,sizeof(rank));
	for (int m=0;m<4;m++)
		for (int n=0;n<4;n++)
			if (otherspoint[n]>otherspoint[m]) rank[n]++;
	for (i = Piecenum; i >=0; i--)
	//枚举方块种类。
	{
		if (used[i]) continue;
	for (u = (- Piecesize); u <= Length; u++)
	for (v = (- Piecesize); v <= Length; v++)
	//枚举方块左上角的格子的坐标。
	for (d = 0; d <= 7; d++)
	//枚举旋转方式。
		if (		
			(putable(cur, u, v, i, d) == true)
			//如果其未被使用，且可以放置在当前游戏棋盘上。
		)
		{
			powervalue[u+Piecesize][v+Piecesize][i][d]+=100;
			calculate(cur,u,v,i,d);
			if (max<powervalue[u+Piecesize][v+Piecesize][i][d])
			{
				finalu=u;
				finalv=v;
				finali=i;
				finald=d;
				max=powervalue[u+Piecesize][v+Piecesize][i][d];
			}
			else if (max==powervalue[u+Piecesize][v+Piecesize][i][d]&&Ironsize[i]>Ironsize[finali])
			{
				finalu=u;
				finalv=v;
				finali=i;
				finald=d;
			}
		}
	}
			putsingle(cur, finalu, finalv, Mycolour, finali, finald);
			copies=cur;
			for (int p1=0;p1<=Piecesize;p1++)
				for (int p2=0;p2<=Piecesize;p2++)
			{
				if (diamond[finali][finald].p[p1][p2])
				{
				if (isrealcorner.b[finalu+p1][finalv+p2]==Mycolour) {isrealcorner.b[finalu+p1][finalv+p2]=Blankcolour;}
				for (int k=0;k<4;k++)
				{
					if (finalu+p1+dx[k]<0||finalu+p1+dx[k]>Length||finalv+p2+dy[k]<0||finalv+p2+dy[k]>Length) continue;
					if (pointvalid(finalu+p1+dx[k],finalv+p2+dy[k]))
					{
						isrealcorner.b[finalu+p1+dx[k]][finalv+p2+dy[k]]=Mycolour;
					}
					if (isrealcorner.b[finalu+p1+dx[k]][finalv+p2+dy[k]]==Mycolour)
						isrealcorner.b[u+p1+dx[k+4]][v+p2+dy[k+4]]=Blankcolour;
				}
				}
			}
	
			step++;
			used[finali] = true;
			cout<<finalu<<' '<<finalv<<' '<<finali<<' '<<finald<<endl<<flush;
			//根据该方块的种类、旋转方式、位置，在棋盘上放置该方块并输出结果。

			return;

}

