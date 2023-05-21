#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представлення підручника
struct Textbook {
    string author;
    string title;
    int approvalCount;
    Textbook* prev;
    Textbook* next;
};

// Додати підручник до списку
void addTextbook(Textbook*& head, string author, string title, int approvalCount) {
    Textbook* newBook = new Textbook;
    newBook->author = author;
    newBook->title = title;
    newBook->approvalCount = approvalCount;
    newBook->prev = nullptr;
    newBook->next = nullptr;

    if (head == nullptr) {
        head = newBook;
    }
    else {
        Textbook* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newBook;
        newBook->prev = current;
    }
}

// Створити новий список з даними про підручники, які рекомендовані до розгляду
Textbook* createRecommendedList(Textbook* head, int minApprovalCount) {
    Textbook* recommendedHead = nullptr;

    Textbook* current = head;
    while (current != nullptr) {
        if (current->approvalCount >= minApprovalCount) {
            addTextbook(recommendedHead, current->author, current->title, current->approvalCount);
        }
        current = current->next;
    }

    return recommendedHead;
}

// Вивести список підручників
void printTextbookList(Textbook* head) {
    Textbook* current = head;
    while (current != nullptr) {
        cout << "Author: " << current->author << endl;
        cout << "Name: " << current->title << endl;
        cout << "Number of positive reviews: " << current->approvalCount << endl;
        cout << "-----------------------" << endl;
        current = current->next;
    }
}

// Звільнити пам'ять, виділену під список
void freeTextbookList(Textbook* head) {
    Textbook* current = head;
    while (current != nullptr) {
        Textbook* nextBook = current->next;
        delete current;
        current = nextBook;
    }
}

int main() {
    Textbook* textbookList = nullptr;
    addTextbook(textbookList, "Author 1", "Book 1", 10);
    addTextbook(textbookList, "Author 2", "Book 2", 5);
    addTextbook(textbookList, "Author 3", "Book 3", 12);
    addTextbook(textbookList, "Author 4", "Book 4", 8);
    addTextbook(textbookList, "Author 5", "Book 5", 15);

    cout << "Input list of textbooks: " << endl;
    printTextbookList(textbookList);

    // Запит користувача щодо кількості схвальних відгуків
    int minApprovalCount;
    cout << "Enter the minimum number of positive reviews: ";
    cin >> minApprovalCount;

    // Створення нового списку з рекомендованими підручниками
    Textbook* recommendedList = createRecommendedList(textbookList, minApprovalCount);

    cout << endl;
    cout << "Initial list of recommended textbooks: " << endl;
    printTextbookList(recommendedList);

    // Звільнення пам'яті, виділеної під списки
    freeTextbookList(textbookList);
    freeTextbookList(recommendedList);

    return 0;
}