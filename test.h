#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

void		ft_write_test(void);
void		ft_read_test(void);
void		ft_strcmp_test(void);
void		ft_strdup_test(void);
void		ft_strcpy_test(void);
void		ft_strlen_test(void);

char		*ft_strdup_c(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *dst, const char *src);

#endif
