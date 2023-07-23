#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#pragma comment (lib,"winmm.lib")
using namespace std;
#define MAX 7
bool duongcheochinh(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice);
bool dong(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice);
bool cot(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice);
bool cheophu(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice);
void txtColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void menu1()
{
	while (1)
	{
		for (int i = 2; i < 15; i++)
		{
			system("cls");
			txtColor(i);
			gotoxy(9, 2); cout << " CCCCCCCC                AA                RRRRRRRRRRR           OOOOOOOOOO" << endl;
			gotoxy(9, 3); cout << "CCC                    AA  AA              RR       RRR         OO        OO" << endl;
			gotoxy(9, 4); cout << "CCC                  AAA    AAA            RR        RR         OO        OO" << endl;
			gotoxy(9, 5); cout << "CCC                AAAA      AAAA          RRRRRRRRRRRR         OO        OO" << endl;
			gotoxy(9, 6); cout << "CCC               AAAAAAAAAAAAAAAA         RRRRR                OO        OO" << endl;
			gotoxy(9, 7); cout << "CCC               AAAA        AAAA         RRRRRR               OO        OO" << endl;
			gotoxy(9, 8); cout << "CCC               AAAA        AAAA         RR   RRRR            OO        OO" << endl;
			gotoxy(9, 9); cout << "CCC               AAAA        AAAA         RR    RRRR           OO        OO" << endl;
			gotoxy(9, 10); cout << " CCCCCCCC         AAAA        AAAA         RR     RRRR           OOOOOOOOOO" << endl;

			gotoxy(3, 15); cout << "W      WW      W    EEEEEEEE    LL          CCCCC     OOOOO     MMM       MMM     EEEEEEEE" << endl;
			gotoxy(3, 16); cout << " W    W  W    W     EE          LL         CC        OO   OO    MM M     M MM     EE" << endl;
			gotoxy(3, 17); cout << " WW  W    W  WW     EEEEEE      LL         CC        OO   OO    MM  M   M  MM     EEEEEE" << endl;
			gotoxy(3, 18); cout << "  WWW      WWW      EE          LL         CC        OO   OO    MM   M M   MM     EE" << endl;
			gotoxy(3, 19); cout << "  WWW      WWW      EEEEEEEE    LLLLLLL     CCCCC     OOOOO     MM    M    MM     EEEEEEEE" << endl;
			Sleep(300);
		}
		system("cls");
		break;
	}
}

void menu2(int& c)
{
	txtColor(6);
	gotoxy(40, 3); cout << "1.BAT DAU" << endl;
	gotoxy(39, 5); cout << "2.HUONG DAN" << endl;
	gotoxy(40, 7); cout << "3.CAI DAT" << endl;
	gotoxy(38, 9); cout << "4.LICH SU DAU" << endl;
	gotoxy(41, 11); cout << "5.THOAT" << endl;
	gotoxy(0, 13); cout << "Hay nhap vao muc ban muon chon: "; cin >> c;
	while (c < 1 || c>5)
	{
		gotoxy(0, 14); cout << "Hay nhap lai muc ban muon chon: "; cin >> c;
	}
	system("cls");
}

void huongdan()
{
	txtColor(7);
	cout << char(2) << " CHAO MUNG BAN DA DEN VOI GAME CARO " << char(2) << "\n";
	cout << "SAU DAY LA CACH DE TIEN HANH TRO CHOI\n";
	cout << "\n" << char(16) << " PLAYER vs COMPUTER " << char(17) << "\n"
		<< "Gom 2 che do: DE, KHO.\n";
	cout << "\n\n" << char(16) << " PLAYER vs PLAYER " << char(17) << "\n";
	cout << "Hay nhap ten va chon ki tu (neu ban khong muon mac dinh X O) cua 2 nguoi choi.\n";
	cout << "\n\n\nCO 3 THE LOAI BAN CO: \n";
	cout << "1. Ban co 3x3\n";
	cout << "2. Ban co 5x5\n";
	cout << "3. Ban co 7x7\n";
	cout << "\nBan co the bat tat nhac nen tuy y bang cach an m (bat/tat)\n";
	cout << "\nHAY CHON BAN CO VA CHE DO BAN MUON CHOI TRONG MUC 3.CAI DAT VA BAT DAU TRO CHOI\n\n";
	cout << char(3) << " CHUC BAN CHOI GAME VUI VE! " << char(3) << endl;
	cout << char(16) << " AN PHIM BAT KI DE THOAT " << char(17);
}

void dulieu1(char ten1[], char& kitu1, char& kitu2, int& dulieu)
{
	txtColor(6);
	cout << "Hay nhap ten cua ban: ";
	cin.get();
	cin.get(ten1, 30, '\n');
	cout << "Hay nhao ki tu muon danh cua ban: ";
	cin.get();
	cin >> kitu1;
	cout << "Hay nhap ki tu cua bot: ";
	cin.get();
	cin >> kitu2;

	while (kitu1 == kitu2)
	{
		cout << "Hay nhap lai ki tu cua nguoi choi 1: ";
		cin.get();
		cin >> kitu1;
		cout << "Hay nhap lai ki tu cua nguoi choi 2: ";
		cin.get();
		cin >> kitu2;
	}
	dulieu = 1;
}

void dulieu2(char ten1[], char ten2[], char& kitu1, char& kitu2, int& dulieu)
{
	txtColor(6);
	cout << "Hay nhap ten cua nguoi choi 1: ";
	cin.get();
	cin.get(ten1, 30, '\n');
	cout << "Hay nhap vao 1 ki tu cua nguoi choi 1: ";
	cin.get();
	cin >> kitu1;
	cout << "Hay nhap ten cua nguoi choi 2: ";
	cin.get();
	cin.get(ten2, 30, '\n');
	cout << "Hay nhap vao 1 ki tu cua nguoi choi 2: ";
	cin.get();
	cin >> kitu2;
	while (kitu1 == kitu2)
	{
		cout << "Hay nhap lai ki tu cua nguoi choi 1: ";
		cin.get();
		cin >> kitu1;
		cout << "Hay nhap lai ki tu cua nguoi choi 2: ";
		cin.get();
		cin >> kitu2;
	}
	dulieu = 1;
}

void chonchedo(char& choice, char& kitu1, char& kitu2, char ten1[], char ten2[], int& dulieu)
{
	txtColor(9);
	cout << "Ban muon chon choi voi nguoi hay may?\n";
	cout << "Vui long chon che do PvP hoac PvE (p/c): ";
	cin >> choice;
	if (choice == 'c' || choice == 'C')
	{
		dulieu1(ten1, kitu1, kitu2, dulieu);
	}
	else if (choice == 'p' || choice == 'P')
	{
		dulieu2(ten1, ten2, kitu1, kitu2, dulieu);
	}
	while (choice != 'c' && choice != 'C' && choice != 'p' && choice != 'P')
	{
		cout << "Moi ban nhap lai che do ban muon choi (p/c): ";
		cin >> choice;
		if (choice == 'c' || choice == 'C')
		{
			dulieu1(ten1, kitu1, kitu2, dulieu);
		}
		else if (choice == 'p' || choice == 'P')
		{
			dulieu2(ten1, ten2, kitu1, kitu2, dulieu);
		}
	}
}

void chonbanco(int& t, int& m)
{
	txtColor(12);
	cout << "Hay chon ti le ban co (1/2/3)\n";
	cout << "1. 3x3\n"
		<< "2. 5x5\n"
		<< "3. 7x7\n";
	cin.get();
	cin >> t;
	while (t <= 0 && t >= 4)
	{
		cout << "MOI BAN CHON LAI BAN CO: ";
		cin.get();
		cin >> t;
	}

	if (t == 1)
		m = 3;
	else if (t == 2)
		m = 5;
	else if (t == 3)
		m = 7;
	system("cls");
}

void vebanco(int& m, char a[][MAX], char kitu1, char kitu2)
{
	txtColor(15);
	cout << endl << endl;
	// ve dau 
	cout << char(218);
	for (int i = 0; i < m - 1; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196);
	cout << char(191);
	cout << endl;

	// ve phan than den cuoi
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			a[i][j] = char(32);
			if (j != m)
				cout << char(179) << char(32) << a[i][j] << char(32);

		}
		cout << char(179) << endl;
		if (i == m - 1)
			cout << char(192);
		else
			cout << char(195);
		for (int j = 0; j < m - 1; j++)
		{
			if (i == m - 1)
			{
				cout << char(196) << char(196) << char(196) << char(193);
			}
			else
				cout << char(196) << char(196) << char(196) << char(197);
		}
		if (i == m - 1)
			cout << char(196) << char(196) << char(196) << char(217);
		else
			cout << char(196) << char(196) << char(196) << char(180) << endl;
	}
}

void dichuyen(int& m, char a[][MAX], char& key, int& xdau, int& ydau, char& kitu1, char& kitu2, int& dem, char ten1[], char ten2[], long& win, int& c, char& choice)
{
	txtColor(10);
	xdau = 2;
	ydau = 3;
	dem = 0;
	bool hoa = false;
	int dem1 = 0;
	int dem2 = 0;
	int  nhac = 1;
	gotoxy(40, 3); cout << "W : len" << endl;
	gotoxy(40, 4); cout << "S : xuong" << endl;
	gotoxy(40, 5); cout << "A : trai" << endl;
	gotoxy(40, 6); cout << "D : phai" << endl;
	gotoxy(40, 7); cout << "ENTER : danh" << endl;
	gotoxy(40, 8); cout << "O : BAT/TAT nhac" << endl;
	gotoxy(40, 9); cout << "ESC : thoat" << endl;
	gotoxy(xdau, ydau);
	while (1)
	{
		txtColor(5);
		key = _getch();
		if (_kbhit)
		{
			// sang phai 
			if (key == 68 || key == 100)
			{
				if (m == 3 && xdau == 10)
					xdau = 10;
				else if (m == 5 && xdau == 18)
					xdau = 18;
				else if (m == 7 && xdau == 26)
					xdau = 26;
				else
					gotoxy(xdau += 4, ydau);
			}
			// sang trai 
			if (key == 65 || key == 97)
			{
				gotoxy(xdau -= 4, ydau);
			}
			// di xuong
			if (key == 115 || key == 83)
			{
				if (m == 3 && ydau == 7)
					ydau = 7;
				else if (m == 5 && ydau == 11)
					ydau = 11;
				else if (m == 7 && ydau == 15)
					ydau = 15;
				else
					gotoxy(xdau, ydau += 2);
			}
			// di len
			if (key == 87 || key == 119)
			{
				if (ydau == 3)
					ydau = 3;
				else
					gotoxy(xdau, ydau -= 2);
			}
			//bat/tat nhac
			if ((key == 111 || key == 79) && nhac == 1)
			{
				PlaySound(NULL, NULL, SND_ASYNC);
				nhac = 0;
			}
			else if ((key == 111 || key == 79) && nhac == 0)
			{
				PlaySound(TEXT("nhac.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				nhac = 1;
			}
			//danh
			if (key == 13)
			{
				if (xdau % 4 == 2 && ydau % 2 == 1)
				{

					if (a[xdau / 4][(ydau - 2) / 2] == char(32))
					{
						if (dem % 2 == 0)
						{
							txtColor(4);
							dem1++;
							gotoxy(0, 19); cout << "LUOT THU " << dem1 << " CUA NGUOI CHOI " << ten1 << endl;
							a[xdau / 4][(ydau - 2) / 2] = kitu1;
							gotoxy(xdau, ydau); cout << kitu1;

						}
						else
						{
							if (choice == 'p' || choice == 'P')
							{
								txtColor(9);
								dem2++;
								gotoxy(0, 22); cout << "LUOT THU " << dem2 << " CUA NGUOI CHOI " << ten2 << endl;
								a[xdau / 4][(ydau - 2) / 2] = kitu2;
								gotoxy(xdau, ydau); cout << kitu2;
							}

						}
						dem++;
						bool check1, check2, check3, check4;
						check1 = dong(m, a, kitu1, kitu2, ten1, ten2, choice);
						check2 = cot(m, a, kitu1, kitu2, ten1, ten2, choice);
						check3 = duongcheochinh(m, a, kitu1, kitu2, ten1, ten2, choice);
						check4 = cheophu(m, a, kitu1, kitu2, ten1, ten2, choice);
						if (check1 || check2 || check3 || check4)
						{
							hoa = true;
							win = 1;
							break;
						}
						if (dem == m * m)
						{
							txtColor(15);
							gotoxy(0, 25); cout << "HOA" << endl;
							win = 1;
							break;
						}
					}
				}
			}
			// thoat	
			if (key == 27)
			{
				PlaySound(NULL, NULL, SND_ASYNC);
				system("cls");
				menu2(c);
				break;
			}
		}
		if ((choice == 'c' || choice == 'C') && dem % 2 != 0)
		{
			txtColor(9);
			dem2++;
			dem++;
			gotoxy(0, 22); cout << "LUOT THU " << dem2 << " CUA BOT" << endl;
			int i, j;
			srand(time(NULL));
			i = rand() % m;
			j = rand() % m;
			while (a[i][j] != char(32))
			{
				srand(time(NULL));
				i = rand() % m;
				j = rand() % m;
			}
			a[i][j] = kitu2;
			gotoxy((4 * i) + 2, (j * 2) + 3); cout << kitu2;
			bool check1, check2, check3, check4;
			check1 = dong(m, a, kitu1, kitu2, ten1, ten2, choice);
			check2 = cot(m, a, kitu1, kitu2, ten1, ten2, choice);
			check3 = duongcheochinh(m, a, kitu1, kitu2, ten1, ten2, choice);
			check4 = cheophu(m, a, kitu1, kitu2, ten1, ten2, choice);
			if (check1 || check2 || check3 || check4)
			{
				hoa = true;
				win = 1;
				break;
			}
			if (dem == m * m)
			{
				txtColor(15);
				gotoxy(0, 25); cout << "HOA" << endl;
				win = 1;
				break;
			}
		}
	}
}

bool duongcheochinh(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice)
{
	if (m == 3) // check 3x3
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[0][0] == kitu1 && a[0][0] == a[1][1] && a[0][0] == a[2][2])
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[0][0] == kitu2 && a[0][0] == a[1][1] && a[0][0] == a[2][2])
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}

				}
			}
		}return false;
	}

	else if (m == 5 || m == 7) // check 5x5 || 7x7
	{
		for (int i = 0; i < m - 4; i++)
		{
			for (int j = 0; j < m - 4; j++)
			{
				if (a[i][j] == kitu1 && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] && a[i][j] == a[i + 4][j + 4])
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == kitu2 && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] && a[i][j] == a[i + 4][j + 4])
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}
}

bool dong(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice)
{
	if (m == 3) // check 3x3
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == kitu1 && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == kitu2 && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}
	else if (m == 5 || m == 7) // check 5x5 || 7x7
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m - 4; j++)
			{
				if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4] && a[i][j] == kitu1)
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4] && a[i][j] == kitu2)
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}
}

bool cot(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice)
{
	if (m == 3) // check 3x3
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == kitu1 && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == kitu2 && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}

	else if (m == 5 || m == 7) // check 5x5 || 7x7
	{
		for (int i = 0; i < m - 4; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j] && a[i][j] == kitu1)
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j] && a[i][j] == kitu2)
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}
}

bool cheophu(int& m, char a[][MAX], char& kitu1, char& kitu2, char ten1[], char ten2[], char& choice)
{
	if (m == 5 || m == 7)
	{
		for (int i = 0; i < m - 4; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 2][j - 2] && a[i][j] == a[i + 3][j - 3] && a[i][j] == a[i + 4][j - 4] && a[i][j] == kitu1 && j >= 4 && i <= 3)
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					break;
				}
				else if (a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 2][j - 2] && a[i][j] == a[i + 3][j - 3] && a[i][j] == a[i + 4][j - 4] && a[i][j] == kitu2 && j >= 4 && i <= 3)
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						break;
					}
				}
			}
		}return false;
	}

	else if (m == 3)
	{
		for (int i = 0; i < m - 2; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if ((a[0][2] == kitu1 || a[1][1] == kitu1 || a[2][0] == kitu1) && a[0][2] == a[1][1] && a[0][2] == a[2][0])
				{
					gotoxy(0, 25); cout << "CHUC MUNG " << ten1 << " DA CHIEN THANG" << endl;
					return true;
					//break;
				}
				else if ((a[0][2] == kitu2 || a[1][1] == kitu2 || a[2][0] == kitu2) && a[0][2] == a[1][1] && a[0][2] == a[2][0])
				{
					if (choice == 'p' || choice == 'P')
					{
						gotoxy(0, 25); cout << "CHUC MUNG " << ten2 << " DA CHIEN THANG" << endl;
						return true;
						//break;
					}
					else if (choice == 'c' || choice == 'C')
					{
						gotoxy(0, 25); cout << "BAN DA THUA" << endl;
						return true;
						//break;
					}
				}
			}
		}return false;
	}
}

int main()
{
	resizeConsole(800, 600);
	DisableCtrButton(0, 0, 1);
	PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int t, m, xdau, ydau, dem, dem1, dem2, c, dulieu = 0;
	long win = 0;
	char key, kitu1 = ' ', kitu2 = ' ', choice = ' ', p;
	char ten1[30], ten2[30], a[MAX][MAX];
	menu1();
	menu2(c);
	do {
		if (c == 2)
		{
			huongdan();
			_getch();
			system("cls");
			cin.get();
			menu2(c);
		}
		else if (c == 1)
		{
			system("cls");
			if (dulieu == 0)
			{
				txtColor(12);
				gotoxy(35, 2); cout << "BAN CHUA KHOI TAO DU LIEU";
				gotoxy(20, 3); cout << "MOI BAN VAO MUC 3 DE CAI DAT DU LIEU VA BAT DAU TRO CHOI!\n";
				gotoxy(34, 6); cout << char(16) << " AN PHIM BAT KI DE THOAT " << char(17);
				_getch();
				system("cls");
				cin.get();
				menu2(c);
			}
			else if (dulieu == 1)
			{
				vebanco(m, a, kitu1, kitu2);
				PlaySound(TEXT("nhac.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				dichuyen(m, a, key, xdau, ydau, kitu1, kitu2, dem, ten1, ten2, win, c, choice);
			}

			if (win == 1)
			{
				txtColor(6);
				PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				gotoxy(0, 27); cout << "BAN CO MUON TIEP TUC CHOI KHONG? (y/n): ";
				cin.get();
				cin >> p;
				if (p == 'y' || p == 'Y')
				{
					system("cls");
					PlaySound(NULL, NULL, SND_ASYNC);
					win = 0;
				}
				else if (p == 'n' || p == 'N')
				{
					PlaySound(NULL, NULL, SND_ASYNC);
					system("cls");
					cin.get();
					menu2(c);
				}
				while (p != 'y' && p != 'Y' && p != 'n' && p != 'N')
				{
					cout << "MOI BAN NHAP LAI (y/n)\n";
					cin.get();
					cin >> p;
					if (p == 'n' || p == 'N')
					{
						PlaySound(NULL, NULL, SND_ASYNC);
						system("cls");
						//menu1();
						menu2(c);
					}
				}
			}
		}
		else if (c == 3)
		{
			chonchedo(choice, kitu1, kitu2, ten1, ten2, dulieu);
			chonbanco(t, m);
			gotoxy(35, 5); cout << "Nhan phim bat ki de thoat!\n";
			_getch();
			system("cls");
			cin.get();
			menu2(c);
		}
		else if (c == 4)
		{
			txtColor(3);
			cout << "WELCOME TO CARO GAME!!!!\n";
			cout << "XIN LOI CHUNG TOI KHONG THE TIM THAY DU LIEU NAO CUA BAN!\n";
			cout << "AN PHIM BAT KI DE THOAT\n";
			_getch();
			system("cls");
			cin.get();
			menu2(c);
		}
		else if (c == 5)
		{
			txtColor(4);
			gotoxy(35, 5); cout << "BAN DA THOAT TRO CHOI!\n";
			gotoxy(32, 7); cout << "AN VAO PHIM BAT KI DE THOAT\n";
			break;
		}
	} while (c != 5);
	if (c == 5)
	{
		txtColor(4);
		gotoxy(35, 5); cout << "BAN DA THOAT TRO CHOI!\n";
		gotoxy(32, 7); cout << "AN VAO PHIM BAT KI DE THOAT\n";
	}
	return 0;
}