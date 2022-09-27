// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *str)
// {
// 	int		len;
// 	int		i;
// 	char	*dup;

// 	len = ft_strlen(str);
// 	i = -1;
// 	dup = malloc(len + 1);
// 	if (!dup)
// 		return (NULL);
// 	while (str[++i])
// 		dup[i] = str[i];
// 	dup[i] = 0;
// 	return (dup);
// }

// char	*get_next_line(int fd)
// {
// 	char	buffer;
// 	char	rtn[7000000];
// 	int		n;
// 	int		i;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	i = 0;
// 	n = read(fd, &buffer, 1);
// 	while (n > 0)
// 	{
// 		rtn[i++] = buffer;
// 		if (buffer == '\n')
// 			break ;
// 		n = read(fd, &buffer, 1);
// 	}
// 	rtn[i] = 0;
// 	if (n <= 0 && i == 0)
// 		return (0);
// 	return (ft_strdup(rtn));
// }


///////////////////////////////////////////////////


#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

char *ft_strdup(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    char *new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (0);
    int i = -1;
    while (++i < len)
        new_str[i] = str[i];
    new_str[i] = 0;
    return (new_str);
}

char *get_next_line(int fd)
{
	char heap[6000000] = {0};
	char buff;
	int nbyte = 0;
	int i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while ((nbyte = read(fd, &buff, 1)) && nbyte > 0)
	{
		heap[i++] = buff;
		if (buff == '\n')
			break;
	}
	heap[i] = '\0';
	if (nbyte <= 0 && i == 0)
		return (0);
	return ft_strdup(heap);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("t", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	//system("leaks out");
	close(fd);
	return (0);
}