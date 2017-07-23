
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
	//��Ϸ���̵Ĺ�ģ��[0..19]*[0..19]����
	Piecesize = 4,
	//����Ĺ�ģ��[0..4]*[0..4]����
	Piecenum = 20,
	//����ĸ������������Ϊ0, 1, ... , 20����

	Blankcolour = 4,
	//��Ϸ�����Ͽհ׸��ӵ���ɫ��
	Mycolour = 5;
	//�Լ��������ɫ��


struct board {
		int
			b[Length + 1][Length + 1];
	};
	//��Ϸ���̡���[i][j]������ֵ����ʾ��i�С���j�еĸ��ӵ���ɫ��
	//�������е����������ꡱ[x][y]��Ҳ����ʾ��x�С���y�С�
struct piece {
		int
			p[Piecesize + 1][Piecesize + 1];
		//���飬�������ֵΪ1��0����ʾ�ø����Ƿ�ռ��

	};
	
const piece
	Iron[Piecenum + 1] =
	//��Ϸ�����и�����21�ַ��顣
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
	//����Ĵ�С����ÿ������ķ�ֵ��
		{
			1, 2, 3, 4, 5, 3, 4,
			5, 5, 4, 5, 4, 5, 5,
			5, 5, 5, 4, 5, 5, 5
		};
board
	cur;
	//��ǰ����Ϸ���̡�
piece
	diamond[Piecenum + 1][8];
	//��[i][d]��������ʾ��i�ַ��龭��d�ַ�ʽ��ת�󣬵õ��ķ��顣
bool
	used[Piecenum + 1];
	//��[i]������ʾ��i�������Ƿ��ѱ�ʹ�á�
int
	fx, fy;
	//��һ��������븲�ǵĸ������ꡣ

bool
	meetend;
	//�Ƿ��յ�[end]ָ�

void turn(int d, piece oir, piece & res);
//����oir����d�ַ�ʽ��ת�󣬵õ�����res��
void forge();
//����diamond���顣

void start(board & cur);
//ִ��[start]ָ�
bool putable(board cur, int x, int y, int i, int d);
//�ж���(x, y)Ϊ���Ͻ�����ĵ�i�ַ��飬����d�ַ�ʽ��ת��õ��ķ��飬�ܷ񱻷�����
//��ǰ�����ϡ�
bool putablefirst(int x, int y, int i, int d);
//�ж�����ϲ���ķ�ʽ�ŵķ����Ƿ��ܹ���Ϊ��һ��ŵ�������

void putsingle(board & cur, int x, int y, int p, int i, int d);
//����(x, y)Ϊ���Ͻ�����ĵ�i�ַ��飬����d�ַ�ʽ��ת��õ��ķ��飬����ɫp������
//�����ϡ�
void putothers(board & cur);
//ִ��[put]ָ������������������������õķ��飬������Ϸ���̸������ӵ���ɫ��


const int Passedcolour=6;
//�ж���չ�ռ��ʱ���߹��ĸ����ɫ
int step=0;
//��¼�߹��˶��ٲ���

const int dx[8]={-1,-1,1,1,0,0,-1,1};
const int dy[8]={-1,1,-1,1,-1,1,0,0};
//һ����İ˸��������ϣ����ϣ����£�����
int otherspoint[4]={};
//�����˵ķ�
int rank[4]={};
//�����˵ĵ�ǰ������Խ������Խ��
bool enteruncontrolled;
//�жϷ����������Ƿ������δ���Ƶ�����

void clean(board & cur);
//��ʼ����Ϸ���̡�

void putmine(board & cur);
//����ѡ��ö�٣���������ࡢ��ת��ʽ��λ�ã�ֱ�����ܹ������ڵ�ǰ������Ϊֹ����
//��������

void putminefirst(board & cur);
//������ϲ���ķ�ʽ���µ�һ��

board copies;
//���̵Ŀ���������spread��valid����
board iscorner;
//������ÿ�������Ƿ��ǿ��еĽǿ��������ڼ���Ȩֵ
board isrealcorner;
//������ÿ�������Ƿ��ǿ��еĽ�
board controlled;
//��չʱ�ж�������Ƿ���ܱ�����
board realcontrolled;
//ʵ��������Ƿ񱻿���

float powervalue[Piecesize+Length+1][Piecesize+Length+1][Piecenum+1][8]={};
//ÿ��״̬��Ȩֵ
int spread(int x,int y);
//����Ӹ÷��������������ٿռ䣨����������

bool pointvalid(int x,int y);
//�жϸ÷����Ƿ��ǿ��еķ���
bool spreadvalid(int x,int y);
//�жϸø��Ƿ��ǿ���չ�ķ���
bool valid(int x,int y);
//�жϸ÷����Ƿ�Ӵ���������ı߻����



void calculate(board & cur,int u,int v,int i,int d);
//����÷������ࡢ��ת��ʽ��λ������״̬��Ȩֵ

/*--------------------------------�����Ǻ����Ķ���------------------------*/
int main()
{
	forge();
	start(cur);
	//��ʼ����Ϸ���̣���������Ϸ���跽�顣
	putothers(cur);
	putminefirst(cur);
	//���õ�һ�����顣
	meetend = false;
	for (;;) {
		putothers(cur);
		if (meetend == true)
			break;
		putmine(cur);
	}
	//���ϸ���������µ�ǰ��Ϸ���̣�������Լ��ķ�����Ϣ��ֱ�����յ�[end]ָ�
	return 0;
}

void turn(int d, piece oir, piece & res)
//����oir����d����ת��ʽ�󣬵õ�����res��
{
	int
		u, v;

	switch (d) {
		case 0 :
		//ԭ״��
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[u            ][v            ];
		break;

		case 1 :
		//����90�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - v][u            ];
		break;

		case 2 :
		//����180�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - u][Piecesize - v];
		break;

		case 3 :
		//����270�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[v            ][Piecesize - u];
		break;

		case 4 :
		//ˮƽ��ת��
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[u            ][Piecesize - v];
		break;

		case 5 :
		//ˮƽ��ת������90�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - v][Piecesize - u];
		break;

		case 6 :
		//ˮƽ��ת������180�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[Piecesize - u][v            ];
		break;

		case 7 :
		//ˮƽ��ת������270�ȡ�
		for (u = 0; u <= Piecesize; u++)
		for (v = 0; v <= Piecesize; v++)
			res.p[u][v] = oir.p[v            ][u            ];
	}
}

void forge()
//����diamond���顣
{
	int
		i, d;

	for (i = 0; i <= Piecenum; i++)
	for (d = 0; d <= 7; d++)
		turn(d, Iron[i], diamond[i][d]);
	//����i�ַ��飨Iron[i]������d����ת��ʽ��õ��ķ��飬��¼��diamond���顣
}

void clean(board & cur)
//��ʼ����Ϸ���̡�
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
	//����Ϸ���̳�ʼ��Ϊδ���÷���ĸ��ӵ���ɫ��
}

void start(board & cur)
//ִ��[start]ָ�
{
	string
		command;

	getline(cin, command);
	cin>>fx>>fy;
	cin.get();
	//�����һ��������븲�ǵĸ��ӡ�
	clean(cur);
	memset(used, 0, sizeof(used));
	//��ʼ����Ϸ���̣��������з�����Ϊ��δʹ�ù���״̬��
}

bool putablefirst(board & cur,int x, int y, int i, int d,int fx,int fy)
//�ж�����ϲ���ķ�ʽ�ŵķ����Ƿ��ܹ���Ϊ��һ��ŵ�������
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
					//�ұߡ�
				) ||
				(
					((x + u + 1) <= Length) &&
					(cur.b[x + u + 1][y + v    ] == Mycolour)
					//�±ߡ�
				) ||
				(
					((y + v - 1) >= 0) &&
					(cur.b[x + u    ][y + v - 1] == Mycolour)
					//��ߡ�
				) ||
				(
					((x + u - 1) >= 0) &&
					(cur.b[x + u - 1][y + v	   ] == Mycolour)
					//�ϱߡ�
				)
				)
			//�Ƿ��и��ӳ�����Ϸ���̵ķ�Χ�����Լ��ĸ���
			//�����ڵıߡ�
			)
			return false;
		if (
			(diamond[i][d].p[u][v] == 1) &&
			((x + u) == fx) &&
			((y + v) == fy)
			//�Ƿ��ܸ��Ǹ���(fx, fy)��
		)
			filled = true;
	}
	if (filled == true)
		return true;
	else
		return false;
	//�������(fx, fy)�����ǣ�����Ϊ���ܡ���
}

void putminefirst(board & cur)
//������ϲ���ķ�ʽ���µ�һ��
{
	int
		u, v,i, d;
	int finalu,finalv,finali,finald;
	float max=INT_MIN;
	for (i=0;i<Piecenum;i++)
	for (u = (- Piecesize); u <= Length; u++)
	for (v = (- Piecesize); v <= Length; v++)
	for (d = 0; d <= 7; d++)
	//ö����ת��ʽ��
		if (putablefirst(cur,u, v, i, d,fx,fy) == true)
		{
			//����������Ϊ��һ�����飬�������������ϡ�
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
			//���ݸ÷�������ࡢ��ת��ʽ��λ�ã��������Ϸ��ø÷��鲢��������
			return;

}

void putsingle(board & cur, int x, int y, int p, int i, int d)

//����(x, y)Ϊ���Ͻ�����ĵ�i�ַ��飬����d�ַ�ʽ��ת��õ��ķ��飬����ɫp������
//�����ϡ�
{
	int
		u, v;

	for (u = 0; u <= Piecesize; u++)
	for (v = 0; v <= Piecesize; v++)
		if (diamond[i][d].p[u][v] == 1)
			cur.b[x + u][y + v] = p;
		//��Ϊ(x, y)�����Ͻ����꣬���Ը÷����(u, v)λ�ã���Ӧ����Ϸ�����ϵ�
		//(x + u, y + v)λ�á�
}



void putothers(board & cur)
//ִ��[put]ָ������������������������õķ��飬������Ϸ���̸������ӵ���ɫ��
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
	//�������[end]ָ�����Ϸ�������Զ��˳���

	cin>>n;
	cin.get();
	for (ni = 1; ni <= n; ni++) 
	{
		cin>>x>>y>>c>>i>>d;
		cin.get();
		putsingle(cur, x, y, c, i, d);
		otherspoint[c]+=Ironsize[i];
		//ÿ����һ��������������õķ��飬��������һ�Ρ�
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
//�ж���(x, y)Ϊ���Ͻ�����ĵ�i�ַ��飬����d�ַ�ʽ��ת��õ��ķ��飬�ܷ񱻷�����
//��ǰ�����ϡ�
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
				//�Ƿ��и��ӳ�����Ϸ���̵ķ�Χ��
				(cur.b[x + u][y + v] != Blankcolour) ||
				(
					((y + v + 1) <= Length) &&
					(cur.b[x + u    ][y + v + 1] == Mycolour)
					//�ұߡ�
				) ||
				(
					((x + u + 1) <= Length) &&
					(cur.b[x + u + 1][y + v    ] == Mycolour)
					//�±ߡ�
				) ||
				(
					((y + v - 1) >= 0) &&
					(cur.b[x + u    ][y + v - 1] == Mycolour)
					//��ߡ�
				) ||
				(
					((x + u - 1) >= 0) &&
					(cur.b[x + u - 1][y + v	   ] == Mycolour)
					//�ϱߡ�
				)
				//�Ƿ����Լ��ĸ��������ڵıߡ�
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
					//���Ͻǡ�
				) ||
				(
					((x + u + 1) <= Length) &&
					((y + v + 1) <= Length) &&
					(cur.b[x + u + 1][y + v + 1] == Mycolour)
					//���½ǡ�
				) ||
				(
					((x + u + 1) <= Length) &&
					((y + v - 1) >= 0     ) &&
					(cur.b[x + u + 1][y + v - 1] == Mycolour)
					//���½ǡ�
				) ||
				(
					((x + u - 1) >= 0     ) &&
					((y + v - 1) >= 0     ) &&
					(cur.b[x + u - 1][y + v - 1] == Mycolour)
					//���Ͻǡ�
				)
			)
			//�Ƿ��������Ķ��㡣
		)
			corner = true;
	}
	if (corner == true)
		return true;
	else
		return false;
	//��������������Ķ��㣬����Ϊ���ܡ���
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
			//�ұߡ�
		) ||
		(
			((x  + 1) <= Length) &&
			(copies.b[x  + 1][y      ] == Mycolour)
			//�±ߡ�
		) ||
		(
			((y - 1) >= 0) &&
			(copies.b[x     ][y   - 1] == Mycolour)
			//��ߡ�
		) ||
		(
			((x - 1) >= 0) &&
			(copies.b[x  - 1][y      ] == Mycolour)
			//�ϱߡ�
		)
		)
		return 0;
	return 1;
}

void calculate(board & cur,int u,int v,int i,int d)
{
	powervalue[u+Piecesize][v+Piecesize][i][d]+=Ironsize[i]*20;
	//Ȩֵ��һ�������

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
	//Ȩֵ�ڶ�������ĵľ��룬Ȩֵ�������չ�������õĽ�����Ȩֵ�������չ���¿ռ��С(��������ԭ�����ɿ�������ļӷ֣�
	
	return ;
}

void putmine(board & cur)
//����ѡ��ö�٣���������ࡢ��ת��ʽ��λ�ã�ֱ�����ܹ������ڵ�ǰ������Ϊֹ����
//��������
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
	//ö�ٷ������ࡣ
	{
		if (used[i]) continue;
	for (u = (- Piecesize); u <= Length; u++)
	for (v = (- Piecesize); v <= Length; v++)
	//ö�ٷ������Ͻǵĸ��ӵ����ꡣ
	for (d = 0; d <= 7; d++)
	//ö����ת��ʽ��
		if (		
			(putable(cur, u, v, i, d) == true)
			//�����δ��ʹ�ã��ҿ��Է����ڵ�ǰ��Ϸ�����ϡ�
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
			//���ݸ÷�������ࡢ��ת��ʽ��λ�ã��������Ϸ��ø÷��鲢��������

			return;

}

