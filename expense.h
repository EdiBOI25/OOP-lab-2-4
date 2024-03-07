#pragma once
// Expense "class"
//	day: int
//	amount: int
//	type: string (char[20])
typedef struct{
	int day;
	int amount;
	char* type;
} Expense;

// Expense "class" constructor
//	day: int
//	amount: int
//	type: string (char[])
//	returns struct Expense
Expense* ConstructExpense(int day, int amount, char* type);
