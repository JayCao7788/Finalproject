char AI()
{
	int a, b;
	char c1, c2;

	srand(time(NULL));

	a = rand() % 3;
	b = rand() % 3;

	switch (a)
	{
	case 0:
		c1 = '1';
		break;
	case 1:
		c1 = '2';
		break;
	case 2:
		c1 = '3';
		break;
	}

	switch (b)
	{
	case 0:
		c2 = 'A';
		break;
	case 1:
		c2 = 'B';
		break;
	case 2:
		c2 = 'C';
		break;
	}

	buf[0] = c1;
	buf[1] = c2;
}

int AI_check(void)
{
	int x, y;

	x = buf[0] - '1';
	y = buf[1] - 'A';

	if (a[x][y] == 1 || a[x][y] == 2)
	{
		return 1;
	}
	else if (a[x][y] == 0)
	{
		return 0;
	}
}