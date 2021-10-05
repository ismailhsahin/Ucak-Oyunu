#include <iostream>
#include <Windows.h> //sleep komutunu kullanmak eklenmesi gerekli
#include<time.h> //random say� �retmek i�in eklenmesi gerekli

using namespace std;

enum YON
{
	YON_SAG = 1,
	YON_SOL = 2
};
struct dusmanYolu
{
	int x;
	int y;

	YON yon;
	char karakter;
};
struct mermiYolu
{
	int x;
	int y;

	YON yon;
	char karakter;
};
char Sahne[80][20]; //
char tus[256];
int i, j, k, � = 0;
dusmanYolu Dusman[1000];
mermiYolu Mermi[1000];


void gotoxy(int x, int y) // kurs�r� istedi�imiz yere koyabilmemiz i�in kulland���m�z komut
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursoruGizle()  // kurs�r� sahneden yok eden fonksiyon
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO		cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void tusOku(char yonler[]) // klavye tu�lar�na bast���m�zda alg�lanmas� i�in gerekli olan fonksiyon
{
	for (int x = 0; x < 256; x++)
		yonler[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void randomsayi�ret() //1 ile 20 aras�nda random say� �reten fonksiyon
{
	srand(time(NULL));
	k = (rand() % 20 + 1);
	
}

void sahneCiz()  // ekrana s�rekli sahneyi �izdiren  ve yerle�tirdi�imiz kordinatlarada u�ak par�alar�n� yerle�tiren fonksiyon 
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			cout << Sahne[x][y];
			Sahne[1][1 + i] = 219;
			Sahne[2][2 + i] = 219;
			Sahne[3][3 + i] = 219;
			Sahne[2][4 + i] = 219;
			Sahne[1][5 + i] = 219;
		}
		cout << endl;


	}
}
void oyunAlan�() // �st , alt , sa� ve sola �er�eveyi yerle�tiren fonksiyon
{
	for (int a = 0; a < 80; a++) //�st ve alta yerle�tiren d�ng�
	{
		Sahne[a][0] = 219; 
		Sahne[a][19] = 219;
	}
	for (int b = 0; b < 20; b++) // sa� ve sola yerle�tiren d�ng�
	{
		Sahne[0][b] = 219;
		Sahne[79][b] = 219;
	}
}
void sahneSil() // sahneyi sildiren fonksiyon
{
	for (int b = 0; b < 20; b++) // 20 kere d�nen d�ng�
	{
		for (int a = 0; a < 80; a++) // 80 kere d�nen d�ng�
		{
			Sahne[a][b] = ' '; //d�ng�de ki her kordinata bo�luk ata
		}
	}
}


void mermiyiOlu�tur() 
{

	Mermi[j].x = 3;	 // tu�a bas�ld���nda mermi x=3 kordinat�ndan harekete ba�lar
	Mermi[j].y = 3 + i; // u�a��n konumuna g�re belirlenen i ile mermi y=3+i kordinat�ndan  harekete ba�lar
	Mermi[j].yon = YON_SAG; // merminin y�n�n� belirler
	Mermi[j].karakter = 220; // belirlenen kordinata  ascii kodlaar�nda 220 ye denk gelen karakteri atar
}
void mermiyiSahneyeYerlestir() 
{
	for (int i = 0; i < 80; i++) // 80 kere d�nen d�ng�
	{
		int x = Mermi[i].x; // merminin x kordinat�n� al�yor
		int y = Mermi[i].y; //  merminin y kordinat�n� al�yor
		Sahne[x][y] = Mermi[i].karakter; // al�nan kordinatlarda mermiyi sahneye yerle�tiriyor
	}
}
void mermiyiHareketEttir() 
{ 
	for (int i = 0; i < 80; i++) // 80 kere d�nen d�ng�
	{
		switch (Mermi[i].yon) // mermini y�n�n� al�yor
		{
		case YON_SAG: // sa� oldu�u zaman
			if (Mermi[i].x == 80) // alan doldu hatas� almamak i�in  merminin x i 80 olunca orda duruyor
			{

			}
			else // e�er x=80 olmam�� ise x i artt�rarak devam ediyor
				Mermi[i].x++;
			break; // d�ng�den ��k
		}
	}
}

void dusmanOlustur()
{

	randomsayi�ret(); // random say� �reten fonksiyonu �a��rd�k d��manlar farkl� y kordinatlar�ndan gelsin diye
	Dusman[�*5].x = 78; // d��man x = 78 kordinat�ndan harekete ba�lar
	Dusman[�].y = k;   // o anki �retelen random say�ya g�re d��man�n y kordinat� belirleniyor
	Dusman[�].yon = YON_SOL; // d��man�n y�n�n� belirler 
	Dusman[�].karakter = 178; // belirlenen kordinata  ascii kodlaar�nda ki 178 ye denk gelen karakteri atar
}
void dusmaniSahneyeYerlestir()
{
	for (int i = 0; i < 1000; i++) // 1000 kere d�nen d�ng�
	{
		int x = Dusman[i].x; // merminin x kordinat�n� al�yor
		int y = Dusman[i].y; // merminin y kordinat�n� al�yor
		Sahne[x][y] = Dusman[i].karakter;  // al�nan kordinatlarda d��man� sahneye yerle�tiriyor
	}
}
void dusmaniHareketEttir()
{
	for (int i = 0; i < 1000; i++) // 1000 kere d�nen d�ng�
	{
		switch (Dusman[i].yon) // d��man�n y�n�n� al�yor
		{
		case YON_SOL: // sol oldu�u zaman
			if (Dusman[i].x == 0) // alan doldu hatas� almamak i�in  d��man�n x i s�f�r olunca orda duruyor
			{

			}
			else // e�er x = 0 olmam�� ise x i azaltarak devam ediyor
				Dusman[i].x--;
			break; // d�ng�den ��k
		}
	}
}
void dusmanYokEt()
{
	for (int i = 0; i < 80; i++) // 80 kere d�nen d�ng�
	{
		for (int j = 0; j < 80; j++) // 80 kere d�nen d�ng�
		{
			if (Mermi[i].y == Dusman[j].y && Mermi[i].x == Dusman[j].x) // d��man ve merminin x ile y si e�it oldu�u takdirde
			{
				Dusman[j].x = NULL; // d��man�n x ine null ata 
				Dusman[j].y = NULL; // d��man�n y sine null ata 
				Mermi[i].x = NULL; // merminin x ine null ata 
				Mermi[i].y = NULL; // merminin y sine null ata 
			}
		}
	}
}

void tusKontrol()
{
	tusOku(tus); // bas�lan tu�u kontrol et
	if (tus['W'] != 0) // e�er W ise 
	{ 
		i -= 1; //y kordinat�n� bir azalt

	}
	if (tus['S'] != 0)  // e�er S ise 
	{
		i += 1; // y kordinat�n� bir artt�r
	}
	if (tus['E'] != 0)  // e�er E ise 
	{
		mermiyiOlu�tur(); // mermi olu�tur fonksiyonunu �a��r
		j++; // her bas�ld���nda bir sonraki mermiye ge�
		if (j == 80) // e�er 80 mermi bas�l�rsa
			j = 0; // ilk at�lan mermiyi ba�tan almaya ba�la
	}
}


int main()
{

	kursoruGizle(); // kurs�r� gizle fonksiyonunu �a��r



	while (true) // while d�ng�s� daima do�ru
	{


		sahneSil(); // sahneyi sil fonksiyonunu �a��r

		tusKontrol(); // bas�lan tu�lar� kontrol eden fonksiyonu �a��r

		mermiyiHareketEttir(); // mermiyi hareket ettiren fonksiyonu �a��r
		mermiyiSahneyeYerlestir(); // mermiyi sahneye yerle�tiren fonksiyonu �a��r


		dusmanOlustur(); // d��man� olu�turan fonksiyonu �a��r
		dusmaniSahneyeYerlestir(); // d��man� sahneye yerle�tiren fonksiyonu �a��r
		dusmaniHareketEttir(); // d��man� hareket ettiren fonksiyonu �a��r
		dusmanYokEt(); // d��man� yok et fonksiyonunu �a��r



		gotoxy(0, 0); // kurs�r� s�f�ra s�f�r noktas�na getir

		oyunAlan�(); // oyun s�n�rlar�n� �izen  fonksiyonu �a��r

		sahneCiz(); // sahneyi �izen fonksiyonu �a��r


		Sleep(10); // d�ng�y� 10 mili saniye uyut

		�++; // her d�ng�den sonra yeni d��man olu�tur
	}





	cin.get(); 
	system("pause");
	return 0;
}