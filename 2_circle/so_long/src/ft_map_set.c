#include "./so_long.h"

static void	ft_open_file(int argc, char **argv, int *fd)
{
	char	*ptr;

	if (argc != 2)
	{
		ft_printfd(2, "Error\nusage: ./so_long [filename.ber]\n");
		exit(EXIT_FAILURE);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		perror("so_long");
		exit(EXIT_FAILURE);
	}
	if (ft_strrchr(argv[1], '.') == NULL)
	{
		ft_printfd(2, "Error\nso_long: Check filename extension is \"*.ber\"\n");
		exit(EXIT_FAILURE);
	}
	ptr = ft_strrchr(argv[1], '.') + 1;
	if (ptr[0] != 'b' || ptr[1] != 'e' || ptr[2] != 'r' || ptr[3] != 0)
	{
		ft_printfd(2, "Error\nso_long: Check filename extension is \"*.ber\"\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_setting_map(int fd, t_tools *tools)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		line = ft_strjoin(line, temp);
		if (temp != NULL)
			free(temp);
		if (line == NULL)
			exit (FTERROR);
		temp = NULL;
		temp = get_next_line(fd);
	}
	if (line == NULL)
	{
		ft_printfd(2, "Error\nso_long: file is empty\n");
		exit(EXIT_FAILURE);
	}
	tools->map = ft_split(line, '\n');
	free(line);
	close(fd);
	if (tools->map == NULL)
		exit(FTERROR);
}

static void	ft_checking_map1(t_tools *tools, int temp, int i, int j)
{
	int	pec[128];

	pec['P'] = 0;
	pec['E'] = 0;
	pec['C'] = 0;
	while ((tools->map)[++i] != NULL)
	{
		j = -1;
		while ((tools->map)[i][++j] != 0)
		{
			if ((tools->map)[i][j] == 'P' || (tools->map)[i][j] == 'E'
				|| (tools->map)[i][j] == 'C')
				pec[(int)(tools->map)[i][j]]++;
			else if ((tools->map)[i][j] != '0' && (tools->map)[i][j] != '1')
				temp = -1;
		}
	}
	if (pec['P'] != 1 || pec['E'] == 0 || pec['C'] == 0 || temp == -1)
	{
		ft_printfd(2, "Error\nso_long: map must contain only");
		ft_printfd(2, " 0(Empty), 1(Wall), P(Player), E(Exit), C(Item)");
		ft_printfd(2, " at least one E, C and just one P\n");
		exit(ft_free(EXIT_FAILURE, tools));
	}
	tools->all_item = pec['C'];
}

static void	ft_checking_map2(t_tools *tools, int i, int j, int flag)
{
	i = -1;
	flag = 0;
	while ((tools->map)[++i] != NULL)
	{
		j = -1;
		while ((i == 0 || (tools->map)[i + 1] == NULL)
			&& (tools->map)[i][++j] != 0)
			if ((tools->map)[i][j] != '1')
				flag = 2;
		while (i != 0 && (tools->map)[i + 1] != NULL
			&& (tools->map)[i][++j] != 0)
			if ((tools->map)[i][0] != '1'
				|| ((tools->map)[i][j + 1] == 0 && (tools->map)[i][j] != '1'))
				flag = 2;
		if (j != tools->width)
			flag = 1;
		if (flag == 1)
			ft_printfd(2, "Error\nso_long: map is not square\n");
		if (flag == 2)
			ft_printfd(2, "Error\nso_long: map is not surrounded by 1(Wall)\n");
		if (flag != 0)
			exit(ft_free(EXIT_FAILURE, tools));
	}
	tools->height = i;
}

void	ft_map_set(int argc, char **argv, t_tools *tools)
{
	int	i;
	int	j;
	int	fd;

	tools->map = NULL;
	tools->item_cnt = 0;
	tools->move_cnt = 0;
	ft_open_file(argc, argv, &fd);
	ft_setting_map(fd, tools);
	tools->width = (int)ft_strlen((tools->map)[0]);
	ft_checking_map1(tools, 0, -1, -1);
	ft_checking_map2(tools, 0, -1, -1);
	i = 0;
	while (i < tools->height && (tools->map)[i][j] != 'P')
	{
		j = 0;
		while (j < tools->width && (tools->map)[i][j] != 'P')
			j++;
		if ((tools->map)[i][j] != 'P')
			i++;
	}
	(tools->p_index)[0] = i;
	(tools->p_index)[1] = j;
	tools->flag = FTNORMAL;
}
