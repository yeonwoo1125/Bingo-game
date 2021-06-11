#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));
	int iNum[25] = {};	//5 * 5 ũ��

	//1~25���� ���� �־���
	for (int i = 0; i < 25; i++) {
		iNum[i] = i + 1;
	}
	//���ڸ� ������
	int tmp, dx1, dx2;
	for (int i = 0; i < 100; i++) {
		dx1 = rand() % 25;
		dx2 = rand() % 25;

		tmp = iNum[dx1];
		iNum[dx1] = iNum[dx2];
		iNum[dx2] = tmp;
	} 

	int Bingo = 0;

	while (true) {
		system("cls"); //ȭ���� �����ϰ� ����

		//���ڸ� 5 * 5�� ���
		for (int i = 0; i < 5; i++)
		{ 
			for (int j = 0; j < 5; j++) {
				if (iNum[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNum[i * 5 + j] << "\t";	//������ �迭�� �ƴϱ� ������ �������� �ٲ� ������ �ٹٲ����ִ°� *5�� ǥ��
			}
			cout << endl; 
		}

		cout << "Bingo Line : " << Bingo << endl;

		//�ټ��� 5 �̻��� ��� ���� ����
		if (Bingo >= 5) {
			cout << "Bingo finsh" << endl;
			break;
		}

		//���� �Է¹���
		cout << "���� �Է�(0 : ����) : ";
		int Input;
		cin >> Input;

		if (Input == 0) break;
		else if (Input < 1 || Input >25) continue;

		//�ߺ� üũ, �⺻������ �ߺ����� �ν���
		bool Acc = true;

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ��� ã�Ƴ�
		for (int i = 0; i < 25; i++) {

			//���� ���ڰ� ���� ���
			if (Input == iNum[i]) {

				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ� false�� �ٲ���
				Acc = false;

				//���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNum[i] = INT_MAX;

				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ��������
				break;
			}
		}
		//Acc ������ true�� ��� *�� �ٲ��� �������Ƿ� �ٽ� �Է� ����
		if (Acc) continue; //�⺻���� true��

		//������ ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� ������ ó������ ���� ī��Ʈ, Bingo������ �Ź� 0���� �ʱ�ȭ
		Bingo = 0;

		//���� ���� �� ���� ������
		int check1 = 0, check2 = 0;
		for (int i = 0; i < 5; i++) {

			//������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ
			check1 = 0, check2 = 0;

			for (int j = 0; j < 5; j++) {
				//���� �� ������ ������
				if (iNum[i * 5 + j] == INT_MAX)
					++check1;

				//���� �� ������ ������
				if (iNum[j * 5 + i] == INT_MAX)
					++check2;
			}

			//j for���� ���������� ���� ���� ���� ���� �� ������ ����� check1 ������ ��
			//check1�� ���� 5�̸� ������ ��� *�̶�� ���̱� ������ ���� ������ ����
			if (check1 == 5) Bingo++;
			if (check2 == 5) Bingo++;
		}

		//���� ��ܿ��� ������ �ϴ� �밢�� üũ
		check1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNum[i] == INT_MAX)
				check1++;
		}
		if (check1 == 5) Bingo++;

		//������ ��ܿ��� ���� �ϴ� �밢�� üũ
		check1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNum[i] == INT_MAX)
				check1++;
		}
		if (check1 == 5) Bingo++;
	}
	return 0;
}