/* ���aVS�q�� */

while (mode == 2)
{
	show_position();
	do
	{
		show_position();
		if (player == 1)
		{
			AI();
			w = AI_check();

			while (w == 1)
			{
				AI();
				w = AI_check();
			}

			printf("\n����q�����!!\n\n");
			system("pause");
		}

		if (player == 0)
		{
			printf("\n���a��ܤ@�Ӧ�l (�Ҧp: 1A; �� E ���}~): ");
			scanf("%s", &buf);

			if (buf[0] == 'E')
			{
				printf("\n��������!\n");
				system("pause");
				return;
			}
		}

		i = buf[0] - '1';
		j = buf[1] - 'A';

		if ((i < 0) || (2 < i) || (j < 0) || (2 < j))
		{
			continue;
		}

		if (a[i][j] > 0)
		{
			continue;
		}

		a[i][j] = player + 1;
		player = 1 - player;
		done = check();
		pp++;

	} while ((done == 0) && (pp < 9));

	printf("\n");
	show_position();
	player = 1 - player;

	if (done == 1)
		printf("\n���aĹ!\n\n", player);
	else if (pp == 9 && done == 0)
	{
		printf("\n��������!\n");
		system("pause");
		return;
	}
	else
	{
		printf("\n�q��Ĺ!\n");
	}

	system("pause");
	return;
}