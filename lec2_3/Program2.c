#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <unistd.h>
#include <stdlib.h>

extern int errno;


int main() 
{
	int sz; //количество прочитанных байт
	char* c = (char*)calloc(100, sizeof(char)); //динамический массив размером 100 байт
	int fd = open("foo.txt", O_RDONLY | O_CREAT); // открываем файл для чтения и при необходимости создания
	printf("fd = %d/n", fd); // выводим на экран значение дескриптора файла
	
	if (fd == -1) // выводим на экран значение дескриптора файла
	{
		printf("Error Number % d\n", errno); // выводим код ошибки последнего системного вызова

		perror("open file error:"); // выводим на экран текстовое описание ошибки
	}
	//читаем из файла 10 байт
	//в sz хранится количество байт, которое удалось прочитать из файла
	sz = read(fd, c, 10);
	printf("called read(% d, c, 10). returned that"
		" %d bytes were read.\n", fd, sz);
	//записываем в конец массива символ конца строки
	c[sz] = '\0';
	//закрываем файл
	if (close(fd) < 0) 
	{
		perror("close file error:");
		exit(1);
	}
	printf("closed the fd.\n");
	return 0;
}
