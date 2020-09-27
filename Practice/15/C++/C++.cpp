#include <iostream>
#include <time.h> 
#include "Windows.h"

const char* msg_hello = "\n"\
						"  ╔══════════════════════════════════════════════════════╗\n"\
						"  ║                                                      ║\n"\
						"  ║    ~ Угадай число ~                                  ║\n"\
						"  ║                                                      ║\n"\
						"  ║    • Компьютер загадывает случайное целое число N    ║\n"\
						"  ║      в диапазоне (0 <= N <= 100)                     ║\n"\
						"  ║    • Вам даётся 5 попыток угадать это число          ║\n"\
						"  ║                                                      ║\n"\
						"  ╚══════════════════════════════════════════════════════╝\n";
const char* msg_not_enough = "Загаданное число больше";
const char* msg_too_many   = "Загаданное число меньше";
const char* msg_win        = "Поздравляю! Вы угадали";
const char* msg_fail       = "Вы проиграли. Было загадано: ";
const char* msg_second_try = "Хотите начать сначала? (1 - ДА )";

const int min_random  = 0;
const int max_random  = 100;
const int attempt_lim = 5;

bool TryingGuess(int x, int n) {
	if (x == n)
		return true; //Guessed
	else if (x < n)
		std::cout << msg_not_enough << std::endl;
	else if (x > n)
		std::cout << msg_too_many << std::endl;
	return false; //Not guessed
}

void UserGuess(int n) {
	bool isGuessed = false;
	int attempt = 0;
	while ((!isGuessed) & (attempt < attempt_lim)) {
		int x;
		std::cout << "\n> ";
		std::cin >> x;
		isGuessed = TryingGuess(x, n);
		attempt++;
	}
	if (isGuessed)
		std::cout << "\n" << msg_win << std::endl;
	else
		std::cout << "\n" << msg_fail << n << std::endl;
}

bool UserRestart() {
	int answer;
	std::cout << msg_second_try << std::endl;
	std::cout << "\n> ";
	std::cin >> answer;
	return answer == 1;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::cout << msg_hello << std::endl;
	while (true) {
		SYSTEMTIME systime;
		GetSystemTime(&systime);
		int n = (systime.wMilliseconds % (max_random + 1)) + min_random;
		UserGuess(n);
		if (!UserRestart())
			break;
	}
}