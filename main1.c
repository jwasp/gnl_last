// #include "get_next_line.h"

// int	main(int argc, char**argv)
// {
// 	char	*line;
// 	int		fd = argc > 1 ? open(argv[1], O_RDONLY) : 0;
// 	int		status;
// 	char buffer[1024];

// 	printf ("argv 1 = %s\n", argv[1]);
// 	printf("fd = %d\n", fd);

// 	while ((status = get_next_line(fd, &line)) == 1)
// 	{
// 		printf("status = %d, line: \"%s\"\n", status, line);
// 		free(line);
// 	}
// 	printf("status = %d\n", status);
// 	close(fd);
// 	return (0);
//  }


// argv: [*, *, NULL]
//        \  \.
//       ./a.out
//             \.
//             first argument

// 0 -- stdin (данные, которые вводим в консоль)
// 1 -- stdout (что печатет и выводит на экран)
// 2 -- stderr (тоже печатается на экран, но сообщает об ошибке)

// char* ptr;
// *ptr == ptr[0]
// ptr[index] --- *(ptr + index)
// index[ptr] --- *(index + ptr)
// *(argv+1) = argv[1]

//*(ft_strchr(buffer, '\n')) = '\0';
//  ~~~~~~~~~~~~~~~~~~~~~~~
//           char*
// char* ptr = buffer;
// ptr++;
// if (*ptr == '1') {...}
// *ptr = 'b';

// char* + int -> char*
// int + char* -> char*


////////////////////////////////////////////////
/// About pointers:
// [0, 1, ..., rmn, (char*)rmn + 1, ...]
// [0, 1, ..., rmn, ..., rmn2, ..., ]
// "Some very. Long string with word"
//  ^        ^
// ptr  end_of_sentence
//
// end_of_sentence - ptr
//
// [----------------------]
//  ^   ^
//     ^   ^
// 1234567
// 123
// 1124567
// int *ptr;
// ptr++; // ptr += sizeof(int);

// char *rmn;
// rmn //сам указатель
// char *rmn;
// *rmn; //значение под адресом разыменование
// char dest;

// dest = *rmn;

// int *num;
// int *rmn;
// int *sum;

// sum = *num + *rmn;
//       ~~~~   ~~~~
//       int     int

//&rmn; //адрес значения // address of `rmn`
////////////////////////////////////////////////


////////////////////////////////////////
//                                                                                   res   tmp
// stack: [main|local vars|get_next_line|local vars get next line|extract_first_line|buffer[]char*|char*| ]
//                                                                                   ^           ^
//                                                                                           <- SP
// res = 77; //
// 55   | mov 77, (SP - 16)
// stack: [main|local vars|get_next_line|local vars get next line|]
/////////////////////////////////////////
