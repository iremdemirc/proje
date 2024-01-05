#include <stdio.h>

struct Account {
    int accountNumber;
    char name[50];
    double balance;
};

void createAccount(struct Account accounts[], int *accountCount);
void listAccounts(struct Account accounts[], int accountCount);
void deposit(struct Account accounts[], int accountCount, int accountNumber, double amount);
void withdraw(struct Account accounts[], int accountCount, int accountNumber, double amount);

int main() {
    struct Account accounts[100];
    int accountCount = 0;
    int choice;

    do {
        printf("\n1. Create Account\n");
        printf("2. List Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                listAccounts(accounts, accountCount);
                break;
            case 3:
                {
                    int accountNumber;
                    double amount;
                    printf("Account Number: ");
                    scanf("%d", &accountNumber);
                    printf("Amount to Deposit: ");
                    scanf("%lf", &amount);
                    deposit(accounts, accountCount, accountNumber, amount);
                }
                break;
            case 4:
                {
                    int accountNumber;
                    double amount;
                    printf("Account Number: ");
                    scanf("%d", &accountNumber);
                    printf("Amount to Withdraw: ");
                    scanf("%lf", &amount);
                    withdraw(accounts, accountCount, accountNumber, amount);
                }
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void createAccount(struct Account accounts[], int *accountCount) {
    if (*accountCount < 100) {
        printf("Name: ");
        scanf("%s", accounts[*accountCount].name);
        accounts[*accountCount].accountNumber = *accountCount + 1;
        accounts[*accountCount].balance = 0.0;
        (*accountCount)++;
        printf("Account created.\n");
    } else {
        printf("Maximum account limit reached.\n");
    }
}

void listAccounts(struct Account accounts[], int accountCount) {
    printf("\nAccount List:\n");
    printf("-------------------------------------------------\n");
    printf("| Account No | Name          | Balance          |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < accountCount; i++) {
        printf("| %-11d | %-13s | %-16.2f |\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }

    printf("-------------------------------------------------\n");
}

void deposit(struct Account accounts[], int accountCount, int accountNumber, double amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("%.2f deposited. New balance: %.2f\n", amount, accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(struct Account accounts[], int accountCount, int accountNumber, double amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("%.2f withdrawn. New balance: %.2f\n", amount, accounts[i].balance);
            } else {
                printf("Insufficient balance. Transaction canceled.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}
