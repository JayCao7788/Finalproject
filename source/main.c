/* 玩家VS電腦 */

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

			printf("\n輪到電腦選擇!!\n\n");
			system("pause");
		}

		if (player == 0)
		{
			printf("\n玩家選擇一個位子 (例如: 1A; 按 E 離開~): ");
			scanf("%s", &buf);

			if (buf[0] == 'E')
			{
				printf("\n本局平手!\n");
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
		printf("\n玩家贏!\n\n", player);
	else if (pp == 9 && done == 0)
	{
		printf("\n本局平手!\n");
		system("pause");
		return;
	}
	else
	{
		printf("\n電腦贏!\n");
	}

	system("pause");
	return;
}