#include "test.h"

int			main()
{
	printf("\n\t/*=======================*/");
	printf("\n\t/*       LIBASM 42       */");
	printf("\n\t/*         test.c        */");
	printf("\n\t/*=======================*/\n");

	printf("\n--------------- TESTS FT_STRCMP.S ---------------\n");
	ft_strcmp_test();

	printf("\n--------------- TESTS FT_STRCPY.S ---------------\n");
	ft_strcpy_test();

	printf("\n--------------- TESTS FT_STRDUP.S ---------------\n");
	ft_strdup_test();

	printf("\n--------------- TESTS FT_STRLEN.S ---------------\n");
	ft_strlen_test();

	printf("\n--------------- TESTS FT_WRITE.S ----------------\n");
	ft_write_test();

	printf("\n--------------- TESTS FT_READ.S -----------------\n");
	ft_read_test();

	return (0);
}

/*
** FONCTIONS TESTS
*/

void		ft_read_test(void)
{
	int		fd;
	int		ret;
	char	buffer[256];

	fd = open("utils/tst_poem.txt", O_RDONLY);
	ret = read(fd, buffer, 100);
	buffer[ret] = 0;
	printf("\n\tREAD: Number of bytes: %d\n%s|\n", ret, buffer);
	close(fd);

	fd = open("utils/tst_poem.txt", O_RDONLY);
	ret = ft_read(fd, buffer, 100);
	buffer[ret] = 0;
	printf("\tFT_READ: Number of bytes: %d\n%s|\n\n", ret, buffer);
	close(fd);

	fd = open("utils/tst_poem.txt", O_RDONLY);
	ret = read(fd, buffer, 2);
	buffer[ret] = 0;
	printf("\tREAD: Number of bytes: %d\n%s|\n", ret, buffer);
	close(fd);

	fd = open("utils/tst_poem.txt", O_RDONLY);
	ret = ft_read(fd, buffer, 2);
	buffer[ret] = 0;
	printf("\tFT_READ: Number of bytes: %d\n%s|\n\n", ret, buffer);
	close(fd);

	printf("\tTest READ: negative fd:\n");
	fprintf(stderr, "read return: %ld | errno num %i = %s\n", read(-42, "Hello World!", 13), errno, strerror(errno));
	printf("\tTest FT_READ: negative fd:\n");
	fprintf(stderr, "ft_read return: %ld | errno num %i = %s\n\n\n", ft_read(-42, "Hello World!", 13), errno, strerror(errno));

	printf("\tTest READ: invalid argument:\n");
	fprintf(stderr, "read return: %ld | errno num %i = %s\n", read(2, "lol.txt", -7), errno, strerror(errno));
	printf("\tTest FT_READ: invalid argument:\n");
	fprintf(stderr, "ft_read return: %ld | errno num %i = %s\n\n\n", ft_read(2, "lol.txt", -7), errno, strerror(errno));

	printf("\tFT_READ from standard stream:\n");
	printf("Enter some characters (max 255):\n");
	ret = ft_read(1, buffer, 256);
	buffer[ret] = 0;
	printf("You wrote (+1 enter): %s\nNumber of bytes: %d\n\n", buffer, ret);

	printf("-----------------\n");
}

void		ft_write_test(void)
{
	int		fd_write;
	int		fd_read;
	char	*buff;

	fd_write = open("utils/tst_write.txt", O_CREAT | O_RDWR, 0644);
	fd_read = open("utils/tst_write.txt", O_CREAT | O_RDWR, 0644);

	printf("\nTest WRITE: write something in stdout:\n");
	write(1, "\tHello world\n", 13);
	printf("Test FT_WRITE: write something in stdout:\n");
	ft_write(1, "\tHello world\n\n\n", 15);

	write(fd_write, "\tHello world from utils/tst_write.txt\n", 38);
	get_next_line(fd_read, &buff);
	printf("Test: something that was write in utils/tst_write.txt with WRITE:\n%s\n", buff);
	free(buff);
	close(fd_read);
	close(fd_write);
	remove("utils/tst_write.txt");
	fd_write = open("utils/tst_write.txt", O_CREAT | O_RDWR, 0644);
	fd_read = open("utils/tst_write.txt", O_CREAT | O_RDWR, 0644);
	ft_write(fd_write, "\tHello world from utils/tst_write.txt, a little bit different :)\n", 66);
	get_next_line(fd_read, &buff);
	printf("Test: something that was write in utils/tst_write.txt with FT_WRITE:\n%s\n\n\n", buff);
	free(buff);
	close(fd_read);
	close(fd_write);
	printf("Test WRITE: negative fd:\n");
	fprintf(stderr, "write return: %ld | errno num %i = %s\n", write(-42, "Hello World!", 13), errno, strerror(errno));
	printf("Test FT_WRITE: negative fd:\n");
	fprintf(stderr, "ft_write return: %ld | errno num %i = %s\n\n\n", ft_write(-42, "Hello World!", 13), errno, strerror(errno));

	printf("Test WRITE: str = NULL:\n");
	fprintf(stderr, "write return: %ld | errno num %i = %s\n", write(1, NULL, 13), errno, strerror(errno));
	printf("Test FT_WRITE: str = NULL:\n");
	fprintf(stderr, "ft_write return: %ld | errno num %i = %s\n", ft_write(1, NULL, 13), errno, strerror(errno));

	remove("utils/tst_write.txt");

	printf("\n-----------------\n");
}

void		ft_strcmp_test(void)
{
	printf("The strcmp() and strncmp() functions return an integer less than, equal to, or  greater  than \
zero  if s1 (or the first n bytes thereof) is found, respectively, to be less than, to match,\
or be greater than s2. man 3 strcmp\n");
	printf("\nBASIC: strcmp: %d  | ft_strcmp: %d\n", strcmp("Hello", "Hello"), ft_strcmp("Hello", "Hello"));
	printf("BASIC: strcmp: %d | ft_strcmp: %d\n", strcmp("Hello", "Mello"), ft_strcmp("Hello", "Mello"));
	printf("BASIC: strcmp: %d  | ft_strcmp: %d\n\n", strcmp("Hello", "Cello"), ft_strcmp("Hello", "Cello"));

	printf("EMPTY S1: strcmp:   %d | ft_strcmp: %d\n", strcmp("", "Mello"), ft_strcmp("", "Mello"));
	printf("EMPTY S2: strcmp:    %d | ft_strcmp: %d\n", strcmp("Hello", ""), ft_strcmp("Hello", ""));
	printf("EMPTY S1&S2: strcmp: %d | ft_strcmp: %d\n\n", strcmp("", ""), ft_strcmp("", ""));

	printf("(below in the main (in comments), test to see if it's segfault if NULL:)\n");
	// ft_strcmp(NULL, "Hello World!");
	// ft_strcmp("Hello World!", NULL);

	printf("\n-----------------\n");
}

void		ft_strdup_test(void)
{
	char	*s11 = strdup("Hello world!");;
	char	*s12 = ft_strdup("Hello world!");
	char	*s21 = strdup("");
	char	*s22 = ft_strdup("");
	char	*s31 = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	char    *s32 = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

	printf("\nBASIC TEST    strdup: %s|", s11);
	printf("\nBASIC TEST ft_strdup: %s|", s12);

	printf("\n\nEMPTY TEST    strdup: %s|", s21);
	printf("\nEMPTY TEST ft_strdup: %s|", s22);

	printf("\n\nLONG TEST    strdup: %s|\n", s31);
	printf("\nLONG TEST ft_strdup: %s|\n", s32);

	printf("\n(below in the main (in comments), test to see if it's segfault if NULL:)\n");
	//    ft_strdup(NULL);

	free(s11);
	free(s12);
	free(s21);
	free(s22);
	free(s31);
	free(s32);

	printf("\n-----------------\n");
}

void		ft_strcpy_test()
{
	char	*s = "hello hello";
	char	*dst = malloc(sizeof(char) * 12);
	char	*my_dst = malloc(sizeof(char) * 12);

	char	*src = "Hello";
	char	*dst_over = malloc(sizeof(char) * 12);
	char	*my_dst_over = malloc(sizeof(char) * 12);

	char	*longer_src = "Hellooooooooooo";
	char	*dst_smaller = malloc(sizeof(char) * 10);
	char	*mydst_smaller = malloc(sizeof(char) * 10);

	char	*smaller_src = "Helloooooo";
	char	*dst_longer = malloc(sizeof(char) * 15);
	char	*mydst_longer = malloc(sizeof(char) * 15);

	char	*dst_emptys = malloc(sizeof(char) * 15);
	char	*mydst_emptys = malloc(sizeof(char) * 15);

	printf("\nBASIC TEST:    STRCPY: dst = %s|\n", strcpy(dst, s));
	printf("BASIC TEST: FT_STRCPY: dst = %s|\n", ft_strcpy(my_dst, s));

	dst_over = strcpy(dst_over, "hello hello");
	my_dst_over = ft_strcpy(my_dst_over, "hello hello");
	printf("\nOVERWRITE TEST:    STRCPY: dst = %s|\n", strcpy(dst, src));
	printf("OVERWRITE TEST: FT_STRCPY: dst = %s|\n", ft_strcpy(my_dst, src));

	printf("\nLONGER SRC TEST:    STRCPY: dst = %s|\n", strcpy(dst_smaller, longer_src));
	printf("LONGER SRC TEST: FT_STRCPY: dst = %s|\n", ft_strcpy(mydst_smaller, longer_src));

	printf("\nLONGER DST TEST:    STRCPY: dst = %s|\n", strcpy(dst_longer, smaller_src));
	printf("LONGER DST TEST: FT_STRCPY: dst = %s|\n", ft_strcpy(mydst_longer, smaller_src));

	printf("\nEMPTY SRC TEST:    STRCPY: dst = %s|\n", strcpy(dst_emptys, ""));
	printf("EMPTY SRC TEST: FT_STRCPY: dst = %s|\n\n", ft_strcpy(mydst_emptys, ""));

	printf("\n(below in the main (in comments), test to see if it's segfault if NULL:)\n");

	free(dst);
	free(my_dst);
	free(dst_over);
	free(my_dst_over);
	free(dst_smaller);
	free(mydst_smaller);
	free(dst_longer);
	free(mydst_longer);
	free(dst_emptys);
	free(mydst_emptys);

	printf("\n-----------------\n");
}

void		ft_strlen_test()
{
	char	*basic = "Hello world!";
	char	*empty = "";
	char	*longstr = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

	printf("\n   STRLEN: 'Hello world!' %lu\n", strlen(basic));
	printf("FT_STRLEN: 'Hello world!' %lu\n", ft_strlen(basic));
	printf("\n   STRLEN: empty %lu\n", strlen(empty));
	printf("FT_STRLEN: empty %lu\n", ft_strlen(empty));
	printf("\n   STRLEN: very long string %lu\n", strlen(longstr));
	printf("FT_STRLEN: very long string %lu\n", ft_strlen(longstr));
	printf("\n(below in the main (in comments), test to see if it's segfault if NULL:)\n");
	//printf("%lu\n", ft_strlen(NULL));
	printf("\n-----------------\n");
}

/*
** UTILS
*/

char    *ft_strdup_libc(const char *s)
{
    char    *copy;
    size_t  i;

    if ((copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(*copy))) == NULL)
        return (NULL);
    i = 0;
    while (s[i] != 0)
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    i = strlen(s1) + strlen(s2);
    if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        new[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        new[j + i] = s2[i];
        i++;
    }
    new[j + i] = '\0';
    return (new);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	buffer[1];

	if (!line)
		return (-1);
	*line = ft_strdup_libc("");
	while ((ret = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			return (1);
		if ((*line = ft_strjoin(*line, buffer)) == NULL)
			return (-1);
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

