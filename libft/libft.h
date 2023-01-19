/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:47:32 by alevra            #+#    #+#             */
/*   Updated: 2023/01/17 19:50:54 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BASE_HEXA
#  define BASE_HEXA "0123456789abcdef"
# endif

# ifndef BASE_DEC
#  define BASE_DEC "0123456789"
# endif

# ifndef BASE_HEXA_MAJ
#  define BASE_HEXA_MAJ "0123456789ABCDEF"
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_putstr(char *str);
void				ft_putnbr(int n);
int					ft_putnbr_base(long nbr, char *base);
int					ft_put_u_nbr_base(unsigned long nbr, char *base,
						int padding);
int					ft_put_u_nbr(unsigned int n);
int					ft_itoa_printf(int n);
size_t				ft_putchar(char c);
int					ft_printf(const char *str, ...);
void				ft_freetab(void **tab, int position);
long long			ft_atoll(const char *a);
int					ft_isnumber(const char *str);
int					ft_strequ(char *str1, char *str2);
size_t				ft_max(size_t a, size_t b);
int					ft_overflow_int(long long nb);
int					how_many_splits(const char *str, char c, int *res);
int					ft_sqrt(int nb);
int					ft_min(int a, int b);
#endif
