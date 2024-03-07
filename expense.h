#pragma once
// Expense "class"
//	day: int
//	amount: int
//	type: string (char[20])
struct Expense {
	int day;
	int amount;
	char type[20];
};

// Expense "class" constructor
//	day: int
//	amount: int
//	type: string (char[])
//	returns struct Expense
struct Expense Expense(int day, int amount, char type[20]);
