#include <stdio.h>
#include <string.h>

float balance = 10000.0;
char transactionHistory[100][100];
int transactionCount = 0;

void addTransaction(char transaction[]) {
    strcpy(transactionHistory[transactionCount], transaction);
    transactionCount++;
}

void checkBalance() {
    printf("\nCurrent Balance: ₹%.2f\n", balance);

    addTransaction("Checked Balance");
}

void depositMoney() {
    float amount;

    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if(amount > 0) {
        balance += amount;

        char trans[100];
        sprintf(trans, "Deposited ₹%.2f", amount);
        addTransaction(trans);

        printf("Deposit Successful!\n");
        printf("Updated Balance: ₹%.2f\n", balance);
    }
    else {
        printf("Invalid Amount!\n");
    }
}

void withdrawMoney() {
    float amount;

    printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &amount);

    if(amount <= 0) {
        printf("Invalid Amount!\n");
        return;
    }

    if(amount > balance) {
        printf("Insufficient Balance!\n");
    }
    else {
        balance -= amount;

        char trans[100];
        sprintf(trans, "Withdrawn ₹%.2f", amount);
        addTransaction(trans);

        printf("Withdrawal Successful!\n");
        printf("Remaining Balance: ₹%.2f\n", balance);
    }
}

void transferMoney() {
    float amount;
    char account[20];

    printf("\nEnter Receiver Account Number: ");
    scanf("%s", account);

    printf("Enter Amount to Transfer: ₹");
    scanf("%f", &amount);

    if(amount <= 0) {
        printf("Invalid Amount!\n");
        return;
    }

    if(amount > balance) {
        printf("Insufficient Balance!\n");
    }
    else {
        balance -= amount;

        char trans[100];
        sprintf(trans,
                "Transferred ₹%.2f to Account %s",
                amount,
                account);

        addTransaction(trans);

        printf("Transfer Successful!\n");
        printf("Remaining Balance: ₹%.2f\n", balance);
    }
}

void showTransactionHistory() {
    printf("\n========== TRANSACTION HISTORY ==========\n");

    if(transactionCount == 0) {
        printf("No Transactions Found!\n");
        return;
    }

    for(int i = 0; i < transactionCount; i++) {
        printf("%d. %s\n", i + 1, transactionHistory[i]);
    }
}

int main() {
    int choice;
    int pin;
    int correctPin = 1234;

    printf("====================================\n");
    printf("      ATM SIMULATOR SYSTEM\n");
    printf("====================================\n");

    printf("Enter 4-Digit PIN: ");
    scanf("%d", &pin);

    if(pin != correctPin) {
        printf("\nAccess Denied! Incorrect PIN.\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    do {
        printf("\n====================================\n");
        printf("            ATM MENU\n");
        printf("====================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("====================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                transferMoney();
                break;

            case 5:
                showTransactionHistory();
                break;

            case 6:
                printf("\nThank You For Using ATM Simulator!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}