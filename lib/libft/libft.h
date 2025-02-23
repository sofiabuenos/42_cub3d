/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:50 by sheila            #+#    #+#             */
/*   Updated: 2025/02/10 17:24:16 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct 	s_point
{
	int				x;
	int				y;
}			t_point;

typedef struct s_fill_data
{
	char			**tab;
	t_point			size;
	char			c;
}			t_fill_data;

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strrchr(const char *s, int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putendl(char *s);
void		ft_putnbr(int n);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_printf(const char *format, ...);
int			print_format(char specifier, va_list ap);
int			ft_printchar(int c);
int			ft_printstr(char *str);
int			ft_printnbr(int c);
int			ft_printperc(void);
int			ft_nlen(unsigned int n, unsigned int base);
char		*ft_uitoa(unsigned int n);
int			print_uint(unsigned int n);
int			ft_counthex(unsigned long n);
int			ft_printhex(unsigned int n, const char c);
void		ft_puthexa(unsigned long long n);
int			ft_printptr(unsigned long long n);

char		*get_next_line(int fd);
char		*ft_read_line(int fd, char *str);
int			ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *str, char *buffer);
char		*ft_get_line(char *str);
char		*ft_get_newstr(char *str);

int			ft_strnlen(char *str, int n);
char		*ft_strncpy(char *dest, const char *src, int n);
char		*ft_strndup(char *s, size_t n);
char		*ft_appendchar(char const *s1, char c);
void		fill(t_fill_data *data, int x, int y);
void		flood_fill(char **tab, t_point size, t_point begin);
char		**make_area(char **zone, t_point size);


#endif
