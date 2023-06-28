#include <iostream>;
#include <bitset>
#include <Windows.h>;
#include <random>;
#include <string>;
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string reg;
	int number;
	string input;
	int TC = 0;
	int PC = 0;
	bool PS;
	const int BIT_SIZE = 26;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, (1 << BIT_SIZE) - 1);
	unsigned int Op1 = dis(gen);
	unsigned int Op2 = dis(gen);
	unsigned int Op3 = dis(gen);
	unsigned int Op4 = dis(gen);
	string operation;
	while (Op1 == Op2) {
		Op2 = dis(gen);
	}
	while (Op1 == Op3) {
		Op3 = dis(gen);
	}
	while (Op1 == Op4) {
		Op4 = dis(gen);
	}

	bitset<BIT_SIZE> bits(Op1);
	bitset<BIT_SIZE> bits1(Op2);
	bitset<BIT_SIZE> bits2(Op3);
	bitset<BIT_SIZE> bits3(Op4);
	string Op1_length = bits.to_string();
	while (true) {


		cout << "Enter the command (mov (putting the value into the register); sum (the sum of the byte digits of the first operand taken modulo the second operand):" << endl;
		cin >> operation >> reg >> input;
		try {
			number = stoi(input);
			if (number > 67108863) {
				cout << "The value is too large for 26 bits" << endl;
				return 1;
			}
			if (number < -67108863) {
				cout << "The value is too small for 26 bits" << endl;
				return 1;
			}
			if (operation == "mov") {
				PC = 0;
				if (Op1 < 0) {
					PS = false;
				}
				else {
					PS = true;
				}
				bitset<BIT_SIZE> bits(Op1);
				cout << "R1 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				cout << "R2 = ";
				bitset<BIT_SIZE> bits1(Op2);
				for (int i = 0; i < 4; i++) {
					std::cout << bits1.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				bitset<BIT_SIZE> bits2(Op3);
				cout << "R3 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits2.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				bitset<BIT_SIZE> bits3(Op4);
				cout << "R4 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits3.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				PC = PC + 1;
				cout << endl;
				cout << "PS = " << PS << endl;
				cout << "TC = " << TC << endl;
				cout << "PC = " << PC << endl;
				if (reg == "R1") {
					Op1 = number;
					if (Op1 < 0) {
						PS = false;
					}
					else {
						PS = true;
					}
					bitset<BIT_SIZE> bits4(Op1);
					cout << "R1 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits4.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					cout << "R2 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits1.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					cout << "R3 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits2.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					cout << "R4 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits3.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					PC = PC + 1;
					TC = TC + 1;
					cout << endl;
					cout << "PS = " << PS << endl;
					cout << "TC = " << TC << endl;
					cout << "PC = " << PC << endl;
				}
				else if (reg == "R2") {
					Op2 = number;
					if (Op2 < 0) {
						PS = false;
					}
					else {
						PS = true;
					}
					bitset<BIT_SIZE> bits4(Op1);
					cout << "R1 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits4.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits1(Op2);
					cout << "R2 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits1.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits2(Op3);
					cout << "R3 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits2.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits3(Op4);
					cout << "R4 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits3.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					PC = PC + 1;
					TC = TC + 1;
					cout << endl;
					cout << "PS = " << PS << endl;
					cout << "TC = " << TC << endl;
					cout << "PC = " << PC << endl;
				}
				else if (reg == "R3") {
					Op3 = number;
					if (Op3 < 0) {
						PS = false;
					}
					else {
						PS = true;
					}
					bitset<BIT_SIZE> bits4(Op1);
					cout << "R1 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits4.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits1(Op2);
					cout << "R2 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits1.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits2(Op3);
					cout << "R3 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits2.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits3(Op4);
					cout << "R4 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits3.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					PC = PC + 1;
					TC = TC + 1;
					cout << endl;
					cout << "PS = " << PS << endl;
					cout << "TC = " << TC << endl;
					cout << "PC = " << PC << endl;
				}
				else if (reg == "R4") {
					Op4 = number;
					if (Op4 < 0) {
						PS = false;
					}
					else {
						PS = true;
					}
					bitset<BIT_SIZE> bits4(Op1);
					cout << "R1 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits4.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits1(Op2);
					cout << "R2 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits1.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits2(Op3);
					cout << "R3 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits2.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					bitset<BIT_SIZE> bits3(Op4);
					cout << "R4 = ";
					for (int i = 0; i < 4; i++) {
						std::cout << bits3.to_string().substr(i * 8, 8) << " ";
					}
					cout << endl;
					PC = PC + 1;
					TC = TC + 1;
					cout << endl;
					cout << "PS = " << PS << endl;
					cout << "TC = " << TC << endl;
					cout << "PC = " << PC << endl;
				}
				else {
					cout << "There is no such register" << endl;
				}
			}
			else if (operation == "sum") {
				PC = 0;
				if (Op1 < 0) {
					PS = false;
				}
				else {
					PS = true;
				}

				bitset<BIT_SIZE> bits(Op1);
				unsigned int sum = 0;

				if (Op1_length.length() < 32) {
					Op1_length = string(32 - Op1_length.length(), '0') + Op1_length;
				}
				for (int i = 0; i < Op1_length.length(); i += 8) {
					bitset<8> byte(Op1_length.substr(i, 8));
					sum += byte.to_ulong() % Op2;
				}
				bitset <BIT_SIZE> bits5(sum);
				cout << "R1 = ";
				for (int i = 0; i < 4; i++) {
					cout << bits5.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				bitset<BIT_SIZE> bits1(Op2);
				cout << "R2 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits1.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				bitset<BIT_SIZE> bits2(Op3);
				cout << "R3 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits2.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				bitset<BIT_SIZE> bits3(Op4);
				cout << "R4 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits3.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				PC = PC + 1;
				cout << endl;
				cout << "PS = " << PS << endl;
				cout << "TC = " << TC << endl;
				cout << "PC = " << PC << endl;

				int result = sum % Op2;
				bitset <BIT_SIZE> bits6(result);
				cout << "R1 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits6.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				cout << "R2 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits1.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				cout << "R3 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits2.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				cout << "R4 = ";
				for (int i = 0; i < 4; i++) {
					std::cout << bits3.to_string().substr(i * 8, 8) << " ";
				}
				cout << endl;
				PC = PC + 1;
				TC = TC + 1;
				cout << endl;
				cout << "PS = " << PS << endl;
				cout << "TC = " << TC << endl;
				cout << "PC = " << PC << endl;
			}
		}
		catch (const invalid_argument& ia) {
			cerr << "Input is not a number" << endl;
			return 1;
		}
		catch (const out_of_range& oor) {
			cerr << "Input is too large or too small for int type" << endl;
			return 1;
		}
		
	}
}