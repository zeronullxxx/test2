#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.cpp"
#include "reader.cpp"
#include <stdlib.h>
#include <string>
#include <windows.h>
////menu vubora akaunta
using namespace std;


int n = 5;
book_options* s = new book_options[n]
{

	{ "22","Metro2033", "DmitriiGluhovskiy", "fantezi", "134$", "***", "a1" },
	{ "23", "Poliana", "ElionorPorter", "putishestviya", "54$", "**", "a2" },
	{ "15", "Voin", "RobertSalvator", "fantastika", "250$", "*****", "a3" },
	{ "31","MeinKampf", "Adolf", "aftobiografiya", "150$", "****", "a4" },
	{ "2", "Nevidimuy", "GerbertVells", "skazka", "43$", "***", "a5 "},

	//{ "23", "Poliana", "ElionorPorter", "putishestviya", "54$", "**", "a2" },
	//{ "15", "Voin", "RobertSalvator", "fantastika", "250$", "*****", "a3" },
	//{ "31","MeinKampf", "Adolf", "aftobiografiya", "150$", "****", "a4" },
	//{ "2", "Nevidimuy", "GerbertVells", "skazka", "43$", "***", "a5 "},

	


};
///////////////////
///////////////////
int n1 = 5;
read_options* s1 = new read_options[n1]
{


	{ "Ovdiy","Dima", "yriyovuch", "10/24/2004", "0689845084", "309", "2","0" },
	{ "Lebid", "Oleg", "Olegovich", "4/27/2003", "HZ", "228", "1","1" },
	{ "Leventov", "Ivan", "Dmitrivich", "8/15/2005", "55055456", "455", "0","0" },
	{ "Maroko","Alex", "Adolfovich", "9/31/2004", "2334555534", "45", "3","2" },
	{ "Lixackiy", "Artem", "Valentinovich", "11/15/2005", "66666555", "23", "1","0"}


};

////////////////////////////////
////////////////////////////////
void remove(book_options*& s);
void SetConsWinSize(int XSize = 40, int YSize = 25) {
	HWND hWnd = GetForegroundWindow();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = YSize;
	windowSize.Left = 0;
	windowSize.Right = XSize;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { XSize + 1, YSize + 1 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}
void SetColorBgTex(int Bg = 0, int Tex = 2) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}
////////////////////////////////
////////////////////////////////
void readN(const char* file_path);
void writeN(const char* file_path);
void write(const char* file_path, book_options* s);
void read(const char* file_path, book_options* s);
////////////////////////////////////////
////////////////////////////////////////
void newArr(book_options*& s);
void push_back(book_options*& s, int& n);
////////////////////////////////////////
////////////////////////////////////////
void menu1();
void readN1(const char* file_path);
void writeN1(const char* file_path);
void write1(const char* file_path, read_options* s);
void read1(const char* file_path, read_options* s);
void vudachabook(read_options* s1, int n1);
void poisk1(read_options* s1, int n1);
int get_variant1(int count);
void dobavleniye_reader(read_options* s1, int n1);
int menu_instrumetov_reader();
////////////////////////////////////////
////////////////////////////////////////
//txt menu 
void menu();

//poisk knig
void poisk(book_options* s);
void push_back1(read_options*& s1, int& n1);
int get_variant(int count1);
//add book
void dobavleniye_book(book_options* s, int n);
//menu_vubora_akaunta
void menu_vubora_akaunta(int a);
int menu_instrumetov_bibliotekarya();
////////////////////
////////////////////

int main()

{
	
	
	SetColorBgTex();
	SetConsWinSize();
	setlocale(LC_ALL, "Russian");
	int vubor_akaunta;
	printf(" Дадова програма библиотека\n 1.Выбирете акаунт::\n 2.1Библеотекарь::2Читатель\nВвод::");

	scanf("%d", &vubor_akaunta);
	bool vubor = true;
	menu_vubora_akaunta(vubor_akaunta);





	delete[] s;
	delete[] s1;
}
//book









void remove(book_options*& s)
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	
printf("Уаление книги\n--");
int  pos;
cout << "Введите индекс: ";
cin >> pos;
for (int i = pos; i < n - 1; i++) //Двигаемся слева направо с заданной позиции
{
	s[i] = s[i + 1]; //Сдвигаем элементы
}

 //Обнуляем последний элемент (часто в целях безопасности)
book_options* new2Arr = new book_options[n - 1];


s[n - 1] = { 0 };
n--;
cout << "Массив после удаления элемента:" << endl;
for (int i = 0; i < n - 1; i++) //Уменьшаем размер массива на единицу
{
	printf("Дата издания::%s\n Название::%s\n Автор::%s\n Жанр::%s\nСтоимость::%s\nРейтинг::%s\nID::%s\n\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book); //Выводим массив после удаления элемента
}
cout << endl;



}

void newArr(book_options*& s)
{
	book_options* new1Arr = new book_options[n];
	
	
	
	
	delete[] s;
	
	s = new1Arr;
	

}
void newArr1(book_options*& s1)
{
	book_options* new1Arr = new book_options[n1];




	delete[] s1;

	s1 = new1Arr;


}
//dobavlenie elementa v masiv
void push_back(book_options *&s, int &n)
{
	book_options* newArr = new book_options[n + 1];

	for ( int i = 0;  i < n;  i++)
	{
		newArr[i] = s[i];

	}
	
	n++;
	delete[] s;
	s = newArr;
		
}
//add book
void dobavleniye_book(book_options* s, int n)
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	int g = 1;
	printf("Добавте книгу в библиотеку?\n--");
	//scanf("%d", &g);
	int a,b;
	
	
	a = n;
	b = n;
	a--;
	
	printf("-Пример\n  Дата издания::\n  Название::\n  Автор::\n  Жанр::\n  Стоимость::\n  Рейтинг::\n  ID::\n\nВвод::");
	for (int i = 0; i < g; i++)
	{

		for (int j = a; j < b; j++)
		{
			//cin >> s[j].data_izdniya >> s[j].nazvanie >> s[j].avtor >> s[j].janr >> s[j].stoemost >> s[j].raiting >> s[j].id_book;
			  scanf(" %s \n %s \n %s\n%s \n %s \n %s \n %s \n", s[j].data_izdniya, s[j].nazvanie, s[j].avtor, s[j].janr, s[j].stoemost, s[j].raiting, s[j].id_book);
			
		}


		//scanf("vedite daty nazvaniya::%s\nvedite nazvanie::%s\nvedite avtorra::%s\nvedite janr::%s\nvedite stoemost::%s\nvedite raiting::%s\nvedite id::%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, &s[i].stoemost, s[i].raiting, &s[i].id_book);




	}

	
	for (int j = a; j < b; j++)
	{
		printf("Дата издания::%s\n Название::%s\n Автор::%s\n Жанр::%s\nСтоимость::%s\nРейтинг::%s\nID::%s\n\n", s[1].data_izdniya, s[1].nazvanie, s[1].avtor, s[1].janr, s[1].stoemost, s[1].raiting, s[1].id_book);


	}

		




}
//menu_vubora_akaunta
void menu_vubora_akaunta(int a)
{
	setlocale(LC_ALL, "Russian");

	if (a == 1)
	{
		printf("Вход в акаунт библиотекар успешин");
		menu_instrumetov_bibliotekarya();
	}
	else if (a == 2)
	{
		printf("Вход в акаунт ридер успешин");
		menu_instrumetov_reader();
	}
	else

		while (a != 1 || a != 1)
		{
			system("cls");
			printf("Дадова програма библиотека\n");
			printf("* Ошибка входа 1.билиотекар\n2.читатель\nВвод::");
			scanf("%d", &a);
			if (a == 1)
			{
				printf("Вход в акаунт библиотекар успешин");
				menu_instrumetov_bibliotekarya();
			}
			else if (a == 2)
			{
				printf("Вход в акаунт ридер успешин");
				menu_instrumetov_reader();
			}

		}
}
//menu_instrumetov_bibliotekarya
int menu_instrumetov_bibliotekarya()
{
	int variant; // выбранный пункт меню

	do {
		menu(); // выводим меню на экран

		variant = get_variant(10); // получаем номер выбранного пункта меню

		switch (variant) {
		case 1:
			push_back(s, n);
			dobavleniye_book(s, n);
			break;

		case 2:
			remove(s);
			break;

		case 3:
			//редактиравание
			break;


		case 4:
			poisk(s);
			break;

		case 5:
			vudachabook(s1, n1);
			break;
		case 6:
			//вивод о самых активных читателях;
			break;
		case 7:
			writeN("n.txt");
			write("bd.txt", s);
			break;
		case 8:
			//newArr(s);
			newArr(s);
			readN("n.txt");
			cout << n;
			read("bd.txt", s);
			
			//newArr(s);
			
			break;
		case 10:
			system("cls");
			main();
			break;
		}

		if (variant != 10)
			system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
	} while (variant != 10);




	return 0;
}
//get_variant
int get_variant(int count)
{
	int variant;
	char s[100]; // строка для считывания введённых данных
	scanf("%s", s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
		printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
		scanf("%s", s); // считываем строку повторно
	}

	return variant;
}
//txt menu 
void menu()
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	printf("Меню управления Admin book\n");
	printf("1. Добавление\n");
	printf("2. Удаление\n");
	printf("3. Поиск по Дата издания,названию,Автор,Жанр,Стоимость,Рейтинг,ID,самых популярных книгах в своем жанре\n");
	printf("4. Выдача книги \n");
	printf("5. возврат книги \n");
	printf("6. Вывод информации о книгах находящихся на руках у читателей \n");
	printf("7. сохранить библиотеку \n");
	printf("8.  библиотеку \n");
	printf("10. загрузить Exit\n");
	printf(">");
}
//poisk knig
void poisk(book_options* s)
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	printf(" * Поиск по Дата издания \n * Поиск по Название \n * Поиск по Автор \n * Поиск по Жанр \n * Поиск по Стоимость \n * Поиск по Рейтинг \n * Поиск по ID \n * Поиск по самых популярных книгах в своем жанре \n");
	int vubor = 0;
	printf("Ведите параметр:: ");
	scanf(" %d", &vubor);
	char user[250];
	int user1 = 0;

	//поиск по названию


	if (vubor == 1)
	{

		system("cls");
		printf("Ведиите дату издания:: ");

		scanf(" %s", user);


		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].data_izdniya, user) == 0)
			{
				printf(" Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\n Стоимость:: %s\n Рейтинг:: %s\n ID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
				//cout << s[i].data_izdniya << s[i].nazvanie << s[i].avtor << s[i].janr << s[i].stoemost << s[i].raiting << s[i].id_book;
			}

		}

	}
	else if (vubor == 2)
	{
		system("cls");
		printf("Ведиите название:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].nazvanie, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}
	////поиск по режисеру
	else if (vubor == 3)
	{
		system("cls");
		printf("Ведиите автор:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].avtor, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}
		}
	}

	// поиск по жанру
	else if (vubor == 4)
	{
		system("cls");
		printf("Ведиите жанр:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].janr, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}
	else if (vubor == 5)
	{
		system("cls");
		printf("Ведиите стоимость:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].stoemost, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}
	else if (vubor == 6)
	{
		system("cls");
		printf("Ведиите Рейтинг:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].raiting, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}
	else if (vubor == 7)
	{
		system("cls");
		printf("Ведиите ID:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].id_book, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}
	else if (vubor == 8)
	{
		system("cls");
		printf("Ведиите жанр для вывода самой популярной книги в жанре:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].janr, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
			}

		}
	}

}
//zapis blioteki
void write(const char* file_path, book_options* s)
{
	
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen(file_path, "wt");
	for (auto i = 0; i < n; i++)
	{
		//fprintf(file, " %s#%s#%s#%s#%s#%s#%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
		fprintf(file, " %s" " %s" " %s" " %s " " %s" " %s" " %s" "\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);

	}
	fclose(file);
}
//zagruzka sohranenoy biblioteki

 /*void read(const char* file_path, book_options* s)
{
	
	setlocale(LC_ALL, "Russian");
	readN("n.txt", n);
	int i = 0;
	FILE* file = fopen("dima.txt", "rt");
	while (!feof(file))
	{
		
		fprintf(file, "%s\n %s\n %s\n %s\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);


		i++;
	}
	fclose(file);

  }*/
void read(const char* file_path, book_options* s)
{

	setlocale(LC_ALL, "Russian");
	
	
	FILE* file = fopen(file_path, "rt");
	if (file == NULL)
	{
		printf("Error!!! File not found\n\n");
		getchar();

	}
	for (auto i = 0; i < n; i++)
	{
		
		//fprintf(file, " %s%s#%s#%s#%s#%s#%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
		fscanf(file, " %s" "%s" "%s" "%s" "%s" "%s" "%s" "\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);

	}
	fclose(file);

}
//zapis n odelno ot osnovdoy zapisi eto normalno dlya bezapasnosti!TAK NADO !!!
void writeN(const char* file_path)
{

	FILE* file = fopen(file_path, "w"); 
	fprintf(file, "%d", n);
	fclose(file);
	
}
//chteniye iz faila n.txt 
void readN(const char* file_path)
{

	FILE* file = fopen(file_path, "r"); 
	if (file == NULL)
	{
		printf("Error!!! File not found\n\n");
		getchar();

	}

	fscanf(file, "%d", &n);
	fclose(file);
}


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void remove1(read_options*& s1)
{
	setlocale(LC_ALL, "Russian");
	system("cls");

	printf("Уаление читателя\n--");
	int  pos;
	cout << "Введите индекс: ";
	cin >> pos;
	for (int i = pos; i < n1 - 1; i++) //Двигаемся слева направо с заданной позиции
	{
		s1[i] = s1[i + 1]; //Сдвигаем элементы
	}

	//Обнуляем последний элемент (часто в целях безопасности)
	


	s[n1 - 1] = { 0 };
	n1--;
	cout << "Массив после удаления элемента:" << endl;
	for (int i = 0; i < n1 - 1; i++) //Уменьшаем размер массива на единицу
	{
		printf("  Фамилия:: % s\n  имя:: % s\n  отчество:: % s\n дата рождения:: % s\n номеру паспорт:: % s \n  ID:: % s\n количеству прочитанных книг:: % s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook); //Выводим массив после удаления элемента
	}
	cout << endl;



}
void write1(const char* file_path, read_options* s1)
{

	setlocale(LC_ALL, "Russian");
	FILE* file = fopen(file_path, "wt");

	
	for (auto i = 0; i < n1; i++)
	{
		
		//fprintf(file, " %s#%s#%s#%s#%s#%s#%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
		fprintf(file, "%s" " %s" " %s" " %s " " %s" " %s" " %s" "\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);

	}
	fclose(file);
}
//zagruzka sohranenoy biblioteki

 /*void read(const char* file_path, book_options* s)
{

	setlocale(LC_ALL, "Russian");
	readN("n.txt", n);
	int i = 0;
	FILE* file = fopen("dima.txt", "rt");
	while (!feof(file))
	{

		fprintf(file, "%s\n %s\n %s\n %s\n", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);


		i++;
	}
	fclose(file);

  }*/
void read1(const char* file_path, read_options* s1)
{

	setlocale(LC_ALL, "Russian");


	FILE* file = fopen(file_path, "rt");

	if (file == NULL)
	{
		printf("Error!!! File not found\n\n");
		getchar();

	}
	for (auto i = 0; i < n1; i++)
	{

		//fprintf(file, " %s#%s#%s#%s#%s#%s#%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, s[i].stoemost, s[i].raiting, s[i].id_book);
		fscanf(file, " %s" " %s" " %s" " %s " " %s" " %s" " %s""\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);

	}
	fclose(file);

}
//zapis n odelno ot osnovdoy zapisi eto normalno dlya bezapasnosti!TAK NADO !!!
void writeN1(const char* file_path)
{


	FILE* file = fopen(file_path, "wt");
	fprintf(file, "%d", n1);
	fclose(file);

}
//chteniye iz faila n.txt 
void readN1(const char* file_path)
{
	FILE* file = fopen(file_path, "r");

	if (file == NULL)
	{
		printf("Error!!! File not found\n\n");
		getchar();

	}
	fscanf(file, "%d", &n1);
	fclose(file);
}
void poisk1(read_options* s1, int n1)
{

	setlocale(LC_ALL, "Russian");
	system("cls");
	printf("* Поиск и сортировка по Фамилия,имя,отчество\n,* количеству прочитанных книг\n,* ID\n,* номеру паспорта\n,* Вывод информации на экран о самых активных читателях\n\n");
	int vubor = 0;
	printf("Ведите параметр:: ");
	scanf("%d", &vubor);
	char user[250];
	int user1 = 0;

	//поиск по названию


	if (vubor == 1)
	{

		system("cls");
		printf("Ведиите  Фвмилию:: ");

		scanf("%s", user);


		for (auto i = 0; i < n1; i++)
		{
			if (strcmp(s1[i].firstname, user) == 0)
			{
				printf("  Фамилия::%s\n  имя::%s\n  отчество::%s\n дата рождения::%s\n номеру паспорт::%s \n  ID::%s\n количеству прочитанных книг::%s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);

			}

		}

	}
	else if (vubor == 2)
	{
		system("cls");
		printf("Ведиите имя:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s1[i].name, user) == 0)
			{
				printf(" Фамилия::%s\n  имя::%s\n  отчество::%s\n дата рождения::%s\n номеру паспорт::%s \n  ID::%s\n количеству прочитанных книг::%s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);
			}

		}
	}
	////поиск по режисеру
	else if (vubor == 3)
	{
		system("cls");
		printf("Ведиите отчество:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s1[i].otchestvo, user) == 0)
			{
				printf("  Фамилия::%s\n  имя::%s\n  отчество::%s\n дата рождения::%s\n номеру паспорт::%s \n  ID::%s\n количеству прочитанных книг::%s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);
			}
		}
	}

	// поиск по жанру
   /* else if (vubor == 4)
	{
		system("cls");
		printf("Ведиите количеству прочитанных книг:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s[i].janr, user) == 0)
			{
				printf("Дата издания:: %s\n Название:: %s\n Автор:: %s\n Жанр:: %s\nСтоимость:: %s\nРейтинг:: %s\nID:: %s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);
			}

		}
	}*/
	else if (vubor == 5)
	{
		system("cls");
		printf("Ведиите  ID:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s1[i].idnomer, user) == 0)
			{
				printf("  Фамилия::%s\n  имя::%s\n  отчество::%s\n дата рождения::%s\n номеру паспорт::%s \n  ID::%s\n количеству прочитанных книг::%s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);
			}

		}
	}
	else if (vubor == 6)
	{
		system("cls");
		printf("Ведиите номеру паспорта:: ");

		scanf("%s", user);
		for (auto i = 0; i < n; i++)
		{
			if (strcmp(s1[i].nomerpasporta, user) == 0)
			{
				printf("  Фамилия::%s\n  имя::%s\n  отчество::%s\n дата рождения::%s\n номеру паспорт::%s \n  ID::%s\n количеству прочитанных книг::%s\t\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Narmbook);
			}

		}
	}


}
int get_variant1(int count1)
{
	int variant;
	char s[100];
	scanf("%s", s);


	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count1) {
		printf("Incorrect input. Try again: ");
		scanf("%s", s);
	}

	return variant;
}
void dobavleniye_reader(read_options* s1, int n1)
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	int g = 1;
	printf("Добавте читателя?\n--");
	//scanf("%d", &g);
	int a;
	a = n1;
	a--;
	printf("-Пример\n  Фамилия::\n  Имя::\n  Отчество::\n  Дата рождения::\n  Номер паспорта::\n  ID номер читателя::\n  Количество прочитанных книг::\n  Список книг находящихся на руках у читателя \n Ввод::\n\n");
	for (int i = 0; i < g; i++)
	{

		for (int j = a; j < n1; j++)
		{
			//cin >> s[j].data_izdniya >> s[j].nazvanie >> s[j].avtor >> s[j].janr >> s[j].stoemost >> s[j].raiting >> s[j].id_book;
			scanf(" %s \n %s \n %s\n%s \n %s \n %s \n %s \n %s\n\n", s1[j].firstname, s1[j].name, s1[j].otchestvo, s1[j].dataspawn, s1[j].nomerpasporta, s1[j].idnomer, s1[j].Nreadbook, s1[j].Narmbook);
		}


		//scanf("vedite daty nazvaniya::%s\nvedite nazvanie::%s\nvedite avtorra::%s\nvedite janr::%s\nvedite stoemost::%s\nvedite raiting::%s\nvedite id::%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, &s[i].stoemost, s[i].raiting, &s[i].id_book);




	}

	for (auto i = 0; i < n1; i++)
	{

		printf("Фамилия::%s\n  Имя::%s\n  Отчество::%s\n  Дата рождения::%s\n  Номер паспорта::%s\n  ID номер читателя::%s\n  Количество прочитанных книг::%s\n  Список книг находящихся на руках у читателя %s\n\n", s1[i].firstname, s1[i].name, s1[i].otchestvo, s1[i].dataspawn, s1[i].nomerpasporta, s1[i].idnomer, s1[i].Nreadbook, s1[i].Narmbook);



	}

}
int menu_instrumetov_reader()
{
	setlocale(LC_ALL, "Russian");
	int variant; // выбранный пункт меню

	do {
		menu1(); // выводим меню на экран

		variant = get_variant(10); // получаем номер выбранного пункта меню

		switch (variant) {
		case 1:
			push_back1(s1, n1);
			dobavleniye_reader(s1, n1);
			break;

		case 2:
			remove1(s1);
			break;

		case 3:
			poisk1(s1, n1);
			break;

		case 4:
			vudachabook(s1, n1);
			break;
		case 5:
			writeN1("n1.txt");
			write1("bd1.txt", s1);
			break;
		case 6:
			//newArr(s);
			newArr1(s);
			readN1("n1.txt");
			
			read1("bd1.txt", s1);
		case 10:
			system("cls");
			main();
			break;
		}

		if (variant != 10)
			system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
	} while (variant != 10);




	return 0;
}
void menu1()
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	printf("1. Добавление\n");
	printf("2. Удаление\n");
	printf("3. Поиск по ФИО, количеству прочитанных книг, ID,номеру паспортасамых популярных книгах в своем жанре,Вывод информации на экран о самых активных читателях.\n");
	printf("4. Вывод информации о читателях с просроченной датой возврата книги \n");
	printf("5. сохранить  \n");
	printf("6. вывести  \n");
	printf("10. Exit\n");
	printf(">");
}
void vudachabook(read_options* s1, int n1)
{
	setlocale(LC_ALL, "Russian");
	system("cls");
	int g = 1;
	printf("Видать  книгb!\nВыбирите кому выдадите книги\n");
	//scanf("%d", &g);
	int a;
	a = n1;
	a--;
	char user[60];
	for (auto i = 0; i < n1; i++)
	{

		printf("Фамилия:: %s\n", s1[i].firstname);



	}

	scanf(" %s\n", user);


	for (auto i = 0; i < n1; i++)
	{
		if (strcmp(s1[i].firstname, user) == 0)
		{
			scanf(" %s\n", s1[i].Narmbook);

		}

	}


	//for (int i = 0; i < g; i++)
	//{

	   // for (int j = a; j < 6; j++)
	   // {
	   //	 //cin >> s[j].data_izdniya >> s[j].nazvanie >> s[j].avtor >> s[j].janr >> s[j].stoemost >> s[j].raiting >> s[j].id_book;
	   //	 scanf(" %s \n %s \n %s\n%s \n %s \n %s \n %s \n\n", s1[j].firstname, s1[j].name, s1[j].otchestvo, s1[j].dataspawn, s1[j].nomerpasporta, s1[j].idnomer, s1[j].Nreadbook, s1[j].Narmbook);
	   // }


	   // //scanf("vedite daty nazvaniya::%s\nvedite nazvanie::%s\nvedite avtorra::%s\nvedite janr::%s\nvedite stoemost::%s\nvedite raiting::%s\nvedite id::%s", s[i].data_izdniya, s[i].nazvanie, s[i].avtor, s[i].janr, &s[i].stoemost, s[i].raiting, &s[i].id_book);




	//}



}
void push_back1(read_options*& s1, int& n1)
{
	read_options* newArr1 = new read_options[n1 + 1];

	for (int i = 0; i < n1; i++)
	{
		newArr1[i] = s1[i];

	}

	n1++;
	delete[] s1;
	s1 = newArr1;

}
///////////////////////////
///////////////////////////
