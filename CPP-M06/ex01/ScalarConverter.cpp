#include "ScalarConverter.hpp"

using namespace std;

static	int	find_entry(long &array, long entry, unsigned int size)
{
	for (int i = 0; i < (int)size; i++)
		if (array[i] == entry)
			return (i);
	return (-1);
}

static unsigned int	get_last_entry_index(long &array, long entry, unsigned int size)
{
	for (int i = 0; i < (int)size; i++)
		if (array[i] == 0)
			return (i);
	return (-1);
}

static	int	str_nchar(string &exp, char c)
{
	static long current_addr_pos = 0;
	static long	str_addresses[128];
	static int	last_positions[128];
	int			k;
	if (!current_addr_pos)
	{
		bzero(str_addresses, 128 * sizeof(long));
		current_addr_pos = 0;
		last_positions[0] = -1;
	}
	else if (exp != str_addresses[current_addr_pos])
	{
		if ((k = find_entry((long &)str_addresses, (long)&exp, 128)) == -1)
		{
			current_addr_pos = get_last_entry_index((long &)str_addresses, (long)&exp, 128);
			last_positions[current_addr_pos] = -1;
		}
		else
			current_addr_pos = find_entry((long &)str_addresses, (long)&exp, 128);
	}
	str_addresses[current_addr_pos] = (long)&exp;
	for (int i = last_positions[current_addr_pos] + 1;
		((last_positions[current_addr_pos] > -1 && exp[last_positions[current_addr_pos]] != 0)
			|| last_positions[current_addr_pos] == -1) && exp[i];
		i++)
	{
		if (exp[i] == c)
		{
			last_positions[current_addr_pos] = i;
			return (i);
		}
	}
	return (-1);
}

static	int	str_char(string &exp, char c)
{
	for (int i = 0; exp[i]; i++)
		if (exp[i] == c)
			return (i);
	return (-1);
}

static	int	is_char(string &exp, char c, unsigned int position)
{
	int i;
	while ((i = str_nchar(exp, c)) != -1 && i < (int)position)
		if (i == (int)position)
			return (1);
	return (0);
}

void	ScalarConverter::converter(string &exp)
{
	cout << exp.compare(0, 3, "inf") << endl;
	str_char(exp, 'c');
	is_char(exp, 'c', 0);
	
}