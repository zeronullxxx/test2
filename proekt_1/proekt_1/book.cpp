// структура характеристики книги
struct book_options
{
	char data_izdniya[60];
	char nazvanie[60];
	char avtor[60];
	char janr[60];
	char stoemost[60];
	char raiting[60];
	char id_book[60];
	
	
};


//struct book
//{
//
//	book_options* book_arr = new book_options[count_arr];
//	int count_arr = 1;
//};
//Название.Автор.Жанр.
//Стоимость.Рейтинг.ID номер книги.