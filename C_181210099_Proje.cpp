#include <iostream>
#include <Windows.h> //sleep komutunu kullanmak eklenmesi gerekli
#include<time.h> //random sayý üretmek için eklenmesi gerekli

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
int i, j, k, þ = 0;
dusmanYolu Dusman[1000];
mermiYolu Mermi[1000];


void gotoxy(int x, int y) // kursörü istediðimiz yere koyabilmemiz için kullandýðýmýz komut
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursoruGizle()  // kursörü sahneden yok eden fonksiyon
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO		cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void tusOku(char yonler[]) // klavye tuþlarýna bastýðýmýzda algýlanmasý için gerekli olan fonksiyon
{
	for (int x = 0; x < 256; x++)
		yonler[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void randomsayiüret() //1 ile 20 arasýnda random sayý üreten fonksiyon
{
	srand(time(NULL));
	k = (rand() % 20 + 1);
	
}

void sahneCiz()  // ekrana sürekli sahneyi çizdiren  ve yerleþtirdiðimiz kordinatlarada uçak parçalarýný yerleþtiren fonksiyon 
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
void oyunAlaný() // üst , alt , sað ve sola çerçeveyi yerleþtiren fonksiyon
{
	for (int a = 0; a < 80; a++) //üst ve alta yerleþtiren döngü
	{
		Sahne[a][0] = 219; 
		Sahne[a][19] = 219;
	}
	for (int b = 0; b < 20; b++) // sað ve sola yerleþtiren döngü
	{
		Sahne[0][b] = 219;
		Sahne[79][b] = 219;
	}
}
void sahneSil() // sahneyi sildiren fonksiyon
{
	for (int b = 0; b < 20; b++) // 20 kere dönen döngü
	{
		for (int a = 0; a < 80; a++) // 80 kere dönen döngü
		{
			Sahne[a][b] = ' '; //döngüde ki her kordinata boþluk ata
		}
	}
}


void mermiyiOluþtur() 
{

	Mermi[j].x = 3;	 // tuþa basýldýðýnda mermi x=3 kordinatýndan harekete baþlar
	Mermi[j].y = 3 + i; // uçaðýn konumuna göre belirlenen i ile mermi y=3+i kordinatýndan  harekete baþlar
	Mermi[j].yon = YON_SAG; // merminin yönünü belirler
	Mermi[j].karakter = 220; // belirlenen kordinata  ascii kodlaarýnda 220 ye denk gelen karakteri atar
}
void mermiyiSahneyeYerlestir() 
{
	for (int i = 0; i < 80; i++) // 80 kere dönen döngü
	{
		int x = Mermi[i].x; // merminin x kordinatýný alýyor
		int y = Mermi[i].y; //  merminin y kordinatýný alýyor
		Sahne[x][y] = Mermi[i].karakter; // alýnan kordinatlarda mermiyi sahneye yerleþtiriyor
	}
}
void mermiyiHareketEttir() 
{ 
	for (int i = 0; i < 80; i++) // 80 kere dönen döngü
	{
		switch (Mermi[i].yon) // mermini yönünü alýyor
		{
		case YON_SAG: // sað olduðu zaman
			if (Mermi[i].x == 80) // alan doldu hatasý almamak için  merminin x i 80 olunca orda duruyor
			{

			}
			else // eðer x=80 olmamýþ ise x i arttýrarak devam ediyor
				Mermi[i].x++;
			break; // döngüden çýk
		}
	}
}

void dusmanOlustur()
{

	randomsayiüret(); // random sayý üreten fonksiyonu çaðýrdýk düþmanlar farklý y kordinatlarýndan gelsin diye
	Dusman[þ*5].x = 78; // düþman x = 78 kordinatýndan harekete baþlar
	Dusman[þ].y = k;   // o anki üretelen random sayýya göre düþmanýn y kordinatý belirleniyor
	Dusman[þ].yon = YON_SOL; // düþmanýn yönünü belirler 
	Dusman[þ].karakter = 178; // belirlenen kordinata  ascii kodlaarýnda ki 178 ye denk gelen karakteri atar
}
void dusmaniSahneyeYerlestir()
{
	for (int i = 0; i < 1000; i++) // 1000 kere dönen döngü
	{
		int x = Dusman[i].x; // merminin x kordinatýný alýyor
		int y = Dusman[i].y; // merminin y kordinatýný alýyor
		Sahne[x][y] = Dusman[i].karakter;  // alýnan kordinatlarda düþmaný sahneye yerleþtiriyor
	}
}
void dusmaniHareketEttir()
{
	for (int i = 0; i < 1000; i++) // 1000 kere dönen döngü
	{
		switch (Dusman[i].yon) // düþmanýn yönünü alýyor
		{
		case YON_SOL: // sol olduðu zaman
			if (Dusman[i].x == 0) // alan doldu hatasý almamak için  düþmanýn x i sýfýr olunca orda duruyor
			{

			}
			else // eðer x = 0 olmamýþ ise x i azaltarak devam ediyor
				Dusman[i].x--;
			break; // döngüden çýk
		}
	}
}
void dusmanYokEt()
{
	for (int i = 0; i < 80; i++) // 80 kere dönen döngü
	{
		for (int j = 0; j < 80; j++) // 80 kere dönen döngü
		{
			if (Mermi[i].y == Dusman[j].y && Mermi[i].x == Dusman[j].x) // düþman ve merminin x ile y si eþit olduðu takdirde
			{
				Dusman[j].x = NULL; // düþmanýn x ine null ata 
				Dusman[j].y = NULL; // düþmanýn y sine null ata 
				Mermi[i].x = NULL; // merminin x ine null ata 
				Mermi[i].y = NULL; // merminin y sine null ata 
			}
		}
	}
}

void tusKontrol()
{
	tusOku(tus); // basýlan tuþu kontrol et
	if (tus['W'] != 0) // eðer W ise 
	{ 
		i -= 1; //y kordinatýný bir azalt

	}
	if (tus['S'] != 0)  // eðer S ise 
	{
		i += 1; // y kordinatýný bir arttýr
	}
	if (tus['E'] != 0)  // eðer E ise 
	{
		mermiyiOluþtur(); // mermi oluþtur fonksiyonunu çaðýr
		j++; // her basýldýðýnda bir sonraki mermiye geç
		if (j == 80) // eðer 80 mermi basýlýrsa
			j = 0; // ilk atýlan mermiyi baþtan almaya baþla
	}
}


int main()
{

	kursoruGizle(); // kursörü gizle fonksiyonunu çaðýr



	while (true) // while döngüsü daima doðru
	{


		sahneSil(); // sahneyi sil fonksiyonunu çaðýr

		tusKontrol(); // basýlan tuþlarý kontrol eden fonksiyonu çaðýr

		mermiyiHareketEttir(); // mermiyi hareket ettiren fonksiyonu çaðýr
		mermiyiSahneyeYerlestir(); // mermiyi sahneye yerleþtiren fonksiyonu çaðýr


		dusmanOlustur(); // düþmaný oluþturan fonksiyonu çaðýr
		dusmaniSahneyeYerlestir(); // düþmaný sahneye yerleþtiren fonksiyonu çaðýr
		dusmaniHareketEttir(); // düþmaný hareket ettiren fonksiyonu çaðýr
		dusmanYokEt(); // düþmaný yok et fonksiyonunu çaðýr



		gotoxy(0, 0); // kursörü sýfýra sýfýr noktasýna getir

		oyunAlaný(); // oyun sýnýrlarýný çizen  fonksiyonu çaðýr

		sahneCiz(); // sahneyi çizen fonksiyonu çaðýr


		Sleep(10); // döngüyü 10 mili saniye uyut

		þ++; // her döngüden sonra yeni düþman oluþtur
	}





	cin.get(); 
	system("pause");
	return 0;
}