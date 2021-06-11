#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));
	int iNum[25] = {};	//5 * 5 크기

	//1~25까지 숫자 넣어줌
	for (int i = 0; i < 25; i++) {
		iNum[i] = i + 1;
	}
	//숫자를 섞어줌
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
		system("cls"); //화면을 깨끗하게 지움

		//숫자를 5 * 5로 출력
		for (int i = 0; i < 5; i++)
		{ 
			for (int j = 0; j < 5; j++) {
				if (iNum[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNum[i * 5 + j] << "\t";	//이차원 배열이 아니기 때문에 가로줄이 바뀔 때마다 줄바꿈해주는걸 *5로 표현
			}
			cout << endl; 
		}

		cout << "Bingo Line : " << Bingo << endl;

		//줄수가 5 이상일 경우 게임 종료
		if (Bingo >= 5) {
			cout << "Bingo finsh" << endl;
			break;
		}

		//수를 입력받음
		cout << "숫자 입력(0 : 종료) : ";
		int Input;
		cin >> Input;

		if (Input == 0) break;
		else if (Input < 1 || Input >25) continue;

		//중복 체크, 기본적으로 중복으로 인식함
		bool Acc = true;

		//모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 찾아냄
		for (int i = 0; i < 25; i++) {

			//같은 숫자가 있을 경우
			if (Input == iNum[i]) {

				//숫자를 찾았을 경우 중복된 숫자가 아니므로 false로 바꿔줌
				Acc = false;

				//숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNum[i] = INT_MAX;

				//더이상 다른 숫자를 찾아볼 필요가 없으므로 for문을 빠져나감
				break;
			}
		}
		//Acc 변수가 true일 경우 *로 바꾸지 못했으므로 다시 입력 받음
		if (Acc) continue; //기본값이 true임

		//빙고줄 수를 체크하는 것은 매번 숫자를 입력할 때마다 처음부터 새로 카운트, Bingo변수를 매번 0으로 초기화
		Bingo = 0;

		//가로 세로 줄 수를 구해줌
		int check1 = 0, check2 = 0;
		for (int i = 0; i < 5; i++) {

			//한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화
			check1 = 0, check2 = 0;

			for (int j = 0; j < 5; j++) {
				//가로 별 개수를 구해줌
				if (iNum[i * 5 + j] == INT_MAX)
					++check1;

				//세로 별 개수를 구해줌
				if (iNum[j * 5 + i] == INT_MAX)
					++check2;
			}

			//j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지 check1 변수에 들어감
			//check1의 값이 5이면 한줄이 모두 *이라는 것이기 때문에 빙고 한줄이 생김
			if (check1 == 5) Bingo++;
			if (check2 == 5) Bingo++;
		}

		//왼쪽 상단에서 오른쪽 하단 대각선 체크
		check1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNum[i] == INT_MAX)
				check1++;
		}
		if (check1 == 5) Bingo++;

		//오른쪽 상단에서 왼쪽 하단 대각선 체크
		check1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNum[i] == INT_MAX)
				check1++;
		}
		if (check1 == 5) Bingo++;
	}
	return 0;
}