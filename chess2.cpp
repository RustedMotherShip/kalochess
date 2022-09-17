//2.1
//
#include <iostream>
#include <string>

using namespace std;
class Figure 
{
public:
	//функция возвращает выбранный символ 1 или 2
	char simbolz(string s,int ch)
	{
		string f(s);
		if(ch==0){
			char a = f[0];
			return a;
		}
		else{
			char a = f[1];
			return a;
		}
	}
	//вывод доски с возможными вариантами хода для выбранной фигуры,варианты хода помеченны звёздочками
	void printer(string b[8][8])
	{
		for(int i = 0;i<8;i++)
				{
					for(int j = 0;j<8;j++){
					cout << b[i][j]<< " ";
					}
					cout<<endl;
				}
			};
	//определение цвета фигуры
	void check_color(int x,int y,string now_board[8][8])
	{
	char f_color = simbolz(now_board[x][y],0);
	switch (f_color)
	{
		//выбор функции для нужного цвета.пока так,позже всё будет в одной фукции
		case 'B' :
		check_type_black(x,y,now_board);
		break;
		case 'W' :
		check_type_white(x,y,now_board);
		break;
	}
	}
	void check_type_black(int x,int y,string now_board[8][8])
	{
	char f_type = simbolz(now_board[x][y],1);
	switch (f_type)
	{
		//обработка чёрной пешки,для белой аналогично,только корды другие и цвет противника
		case 'P' :
			switch (x)
				{	
					case 1:
					if(now_board[2][y]=="00" && now_board[3][y]=="00")
					{
						now_board[2][y]="**";
						now_board[3][y]="**";
					}
					if(now_board[2][y]=="00" && now_board[3][y]!="00")
					{
						now_board[2][y]="**";
					}
					if(simbolz(now_board[2][y-1],0) == 'W')
					{
						string s("**");
						s[1] = simbolz(now_board[2][y-1],1);
						now_board[2][y-1] = s;
					}
					if(simbolz(now_board[2][y+1],0) == 'W')
					{
						string s("**");
						s[1] = simbolz(now_board[2][y+1],1);
						now_board[2][y+1] = s;
					}
					break;
					default:
					if(now_board[x+1][y]=="00" )
					{
						now_board[x+1][y]="**";
					}
					if(simbolz(now_board[x+1][y-1],0) == 'W')
					{
						string s("**");
						s[1] = simbolz(now_board[x+1][y-1],1);
						now_board[x+1][y-1] = s;
					}
					if(simbolz(now_board[x+1][y+1],0) == 'W')
					{
						string s("**");
						s[1] = simbolz(now_board[x+1][y+1],1);
						now_board[x+1][y+1] = s;
					}
					 break;
				};
		break;
			case 'E' :
			//обработка чёрного слона,тоже потом всё будет совмещено в один цикл,пока 4 для наглядности
			//позже эта функция будет переписана под ладью и потом будет совмещена с этой функцией для ладьи или слона или пешки
			//для оставших фигур она будет вызываться два раза подряд и таким образом будет работать ферзь и король
			//а вот как быть с конём я пока не придумал
		bool flag;
		int i;
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x+i][y+i]=="00" && y + i <= 7 && x + i <= 7)
			{
				now_board[x+i][y+i]="**";
			}
			else if(simbolz(now_board[x+i][y+i],0)=='W' && y + i <= 7 && x + i <= 7)
			{
				string s("**");
				s[1] = simbolz(now_board[x+i][y+i],1);
				now_board[x+i][y+i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x-i][y-i]=="00" && y - i >= 0 && x - i >= 0)
			{
				now_board[x-i][y-i]="**";
			}
			else if(simbolz(now_board[x-i][y-i],0)=='W' && y - i >= 0 && x - i >= 0)
			{
				flag = true;
				string s("**");
				s[1] = simbolz(now_board[x-i][y-i],1);
				now_board[x-i][y-i] = s;
				
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x+i][y-i]=="00" && x + i <= 7 && y - i >= 0)
			{
				now_board[x+i][y-i]="**";
			}
			else if(simbolz(now_board[x+i][y-i],0)=='W' && x + i <= 7 && y - i >= 0)
			{
				string s("**");
				s[1] = simbolz(now_board[x+i][y-i],1);
				now_board[x+i][y-i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x-i][y+i]=="00" && y + i <= 7 && x - i >= 0)
			{
				now_board[x-i][y+i]="**";
			}
			else if(simbolz(now_board[x-i][y+i],0)=='W' && y + i <= 7 && x - i >= 0)
			{
				string s("**");
				s[1] = simbolz(now_board[x-i][y+i],1);
				now_board[x-i][y+i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		break;
		case 'H' :
		
		break;
		case 'T' :
		bool flag;
		int i;
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x+i][y+i]=="00" && y + i <= 7 && x + i <= 7)
			{
				now_board[x+i][y+i]="**";
			}
			else if(simbolz(now_board[x+i][y+i],0)=='W' && y + i <= 7 && x + i <= 7)
			{
				string s("**");
				s[1] = simbolz(now_board[x+i][y+i],1);
				now_board[x+i][y+i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		break;
		case 'Q' :
		
		break;
		case 'K' :
		
		break;

		default:

		break;
	}

	printer(now_board);};
	void check_type_white(int x,int y,string now_board[8][8])
	{
	char f_type = simbolz(now_board[x][y],1);
	switch (f_type)
	{
		case 'P' :
					switch (x)
				{	
					case 6:
					if(now_board[5][y]=="00" && now_board[4][y]=="00")
					{
						now_board[5][y]="**";
						now_board[4][y]="**";
					}
					if(now_board[5][y]=="00" && now_board[4][y]!="00")
					{
						now_board[5][y]="**";
					}
					if(simbolz(now_board[6][y-1],0) == 'B')
					{
						string s("**");
						s[1] = simbolz(now_board[6][y-1],1);
						now_board[6][y-1] = s;
					}
					if(simbolz(now_board[6][y+1],0) == 'B')
					{
						string s("**");
						s[1] = simbolz(now_board[6][y+1],1);
						now_board[6][y+1] = s;
					}
					break;
					default:
					if(now_board[x-1][y]=="00" )
					{
						now_board[x-1][y]="**";
					}
					if(simbolz(now_board[x+1][y-1],0) == 'B')
					{
						string s("**");
						s[1] = simbolz(now_board[x+1][y-1],1);
						now_board[x+1][y-1] = s;
					}
					if(simbolz(now_board[x+1][y+1],0) == 'B')
					{
						string s("**");
						s[1] = simbolz(now_board[x+1][y+1],1);
						now_board[x+1][y+1] = s;
					}
					 break;
				};
		break;

		// Слон 
		case 'E' :
		bool flag;
		int i;
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x+i][y+i]=="00" && y + i <= 7 && x + i <= 7)
			{
				now_board[x+i][y+i]="**";
			}
			else if(simbolz(now_board[x+i][y+i],0)=='B' && y + i <= 7 && x + i <= 7)
			{
				string s("**");
				s[1] = simbolz(now_board[x+i][y+i],1);
				now_board[x+i][y+i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x-i][y-i]=="00" && y - i >= 0 && x - i >= 0)
			{
				now_board[x-i][y-i]="**";
			}
			else if(simbolz(now_board[x-i][y-i],0)=='B' && y - i >= 0 && x - i >= 0)
			{
				flag = true;
				string s("**");
				s[1] = simbolz(now_board[x-i][y-i],1);
				now_board[x-i][y-i] = s;
				
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x+i][y-i]=="00" && x + i <= 7 && y - i >= 0)
			{
				now_board[x+i][y-i]="**";
			}
			else if(simbolz(now_board[x+i][y-i],0)=='B' && x + i <= 7 && y - i >= 0)
			{
				string s("**");
				s[1] = simbolz(now_board[x+i][y-i],1);
				now_board[x+i][y-i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		flag = false;
		i = 0;
		while(flag==false)
		{ 
			i++;
			if(now_board[x-i][y+i]=="00" && y + i <= 7 && x - i >= 0)
			{
				now_board[x-i][y+i]="**";
			}
			else if(simbolz(now_board[x-i][y+i],0)=='B' && y + i <= 7 && x - i >= 0)
			{
				string s("**");
				s[1] = simbolz(now_board[x-i][y+i],1);
				now_board[x-i][y+i] = s;
				flag = true;
			}
			else{
				flag = true;
			}
		}
		break;

		case 'H' :
		
		break;
		case 'T' :
		
		break;
		case 'Q' :
		
		break;
		case 'K' :
		
		break;

		default:

		break;
	}
	printer(now_board);}
	 	

	 
};
int main()
{					//y 0  y 1  y 2  y 3  y 4  y 5  y 6  y 7
string board[8][8] = {"BT","BH","BE","BQ","BK","BE","BH","BT", // x 0
					  "BP","BP","BP","BP","BP","BP","BP","BP", // x 1
					  "00","00","00","00","00","00","00","00", // x 2
					  "00","00","00","00","00","00","00","00", // x 3
					  "00","00","00","BE","00","00","00","00", // x 4
					  "00","00","00","00","00","00","00","00", // x 5
					  "WP","WP","WP","WP","WP","WP","WP","WP", // x 6
					  "WT","WH","WE","WQ","WK","WE","WH","WT"}; // x 7
					  // шахматное поле,обозначения фигур состоят из двух символов,
					  // первый это цветбвторой обозначает тип фигуры.Два ноля это пустая клетка
Figure gg;
int x = 4; //корды о выбраной фигуре на доске
int y = 3;
cout<<"=========="<< endl;
gg.check_color(x,y,board);//корды передаются в функцию в классе
cout<<"=========="<< endl;
return 0;
}