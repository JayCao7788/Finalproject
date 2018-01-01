#include <stdio.h> 
#include <stdlib.h> 

int a[3][3];
char buf[3] = { 0 };
void show_position(void);
int check(void);
char AI(void);
int AI_check(void);

int main()
{
	int i, j, player, pp, done, mode, w;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = 0;
		}
	}

	pp = 0;
	done = 0;
	player = 0;

	printf("�п�ܼҦ� : <1> ���aVS���a  <2> ���aVS�q��  <3> (----->>���}) \n\n");
	printf("�z�n���Ҧ���: ");
	scanf("%d", &mode);
	if (mode == 1)
		printf("\n\n�z�n���Ҧ���: ���aVS���a\n\n");
	if (mode == 2)
		printf("\n\n�z�n���Ҧ���: ���aVS�q��\n\n");
	system("pause");

	/* ���aVS���a */

	while (mode == 1)
	{
		do
		{
			show_position();

			printf("\n���a %d ��ܤ@�Ӧ�l (�Ҧp: 1A; �� E ���}~): ", player);
			scanf("%s", &buf);/* ��J���ȷ|�H buf[]={1,A,0} �o�˪��覡�x�s */

			if (buf[0] == 'E')
			{
				printf("\n��������!\n");
				system("pause");
				return;
			}

			i = buf[0] - '1';  /* ��i���ȥu�� 0, 1, 2 ���ܤ� */
			j = buf[1] - 'A';  /* ��j���ȥu�� 0, 1, 2 ���ܤ� */

			/* ���J���~���ȮɡA��������U�@�Ӱj�� Ex: 4A,2D,3x... */
			/* �� */
			if ((i < 0) || (2 < i) || (j < 0) || (2 < j)) 
			{
				continue;
			}

			if (a[i][j] > 0) 
			{               
				continue;   
			}
			/* �� */

			a[i][j] = player + 1;  /* �p�G i=0, j=0(1A) player=0 ���ܴN�b1A����m�[ 1 */
			player = 1 - player;   /* �������a 0 1 0 1 ���� */
			done = check();        /* �P�_�j��O�_�n�~�� */
			pp++;                  /* �̦h�[��9�N���X�j��(9��) */

		} while ((done == 0) && (pp < 9)); /* pp�N����(�̦h9��) */

		printf("\n");
		show_position();
		player = 1 - player;

		if (done == 2)
			printf("\n���a %d Ĺ!\n\n", player);
		else if (done == 1)
			printf("\n���a %d Ĺ!\n\n", player);
		else
			printf("��������!\n");

		system("pause");
		return;
	}

}

