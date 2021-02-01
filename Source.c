﻿// File: exercise10.c
// Author: Dmitrii Zmerzlov
/* Description: Реализация Упражнения 10 из книги Стивена Прата 
   "Язык программирования C. Лекции и упражнения" 5-е издание */

/* Описание задачи:
 Напишите программу, которая читает строки и прекращает чтение на десятой
строке включительно или при появлении с имвола EOF , в зависимости от того,
какое из этих событий произойдет первым. Функция должна предложить поль·
зователю меню с пятью вариантами: печать исходного списка строк, печать
строк в виде упорядоченной последовательности в кодировке ASCII, печать
строк в порядке возрастания их длины, печать строк в порядке возрастания
длины первого слова строки и выход из программы. Меню должно выводиться
на экран после выполнения каждой операции, указанной меню , пока пользова·
тель не выберет вариант выхода из программы. Разумеется , программа должна
выполнять все указанные в меню задачи.
*/
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Header.h"

int main() {
	SetConsoleOutputCP(1251);

	char arrOfStrings[MAX][STRING_LEN];
	int choice, counter;
	int state = TRUE;

	printf("Введите максимум 10 строк c длиною не больше 50 на латинице\n");
	printf("Слова, отличные от латиницы, будут заменятся на пробел: ");
	for (counter = 0; state == TRUE && counter < MAX; counter++)
		ownfgets(&arrOfStrings[counter], STRING_LEN, &state);

	while ((choice = get_choice()) != 'e')
		sortingAndPrint(arrOfStrings, counter, choice);

	printf("До свидания!\n");

	return 0;
}