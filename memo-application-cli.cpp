#include <iostream>
#include <string>

using namespace std;

const int BOX_WIDTH = 50;  // Width of the content inside the box

// Custom integer to string conversion
string intToString(int n) {
    if (n == 0) return "0";
    bool neg = false;
    if (n < 0) {
        neg = true;
        n = -n;
    }
    string s = "";
    while (n > 0) {
        char digit = '0' + (n % 10);
        s = digit + s;
        n /= 10;
    }
    if (neg) s = "-" + s;
    return s;
}

string createBoxLine(const string &text, int width) {
    string line = text;
    if (line.length() > (size_t)width) {
        line = line.substr(0, width);
    } else {
        line += string(width - line.length(), ' ');
    }
    return "| " + line + " |";
}

void printBoxBorder(int width) {
    cout << "+" << string(width + 2, '-') << "+" << "\n";
}

struct node {
    int id = 0;
    string title = "";
    string description = "";
    node* next = NULL;
} *top = NULL;

void push(string title, string description) {
    node* temp = new node();
    temp->title = title;
    temp->description = description;

    if (top == NULL) {
        temp->id = 0;
        top = temp;
    } else {
        temp->id = top->id + 1;
        temp->next = top;
        top = temp;
    }

    cout << "\nMemo Added Successfully!\n";
}

void pop() {
    if (top == NULL) {
        cout << "\nMemo is already empty!\n";
        return;
    }

    node* q = top;
    top = top->next;
    delete q;
    cout << "\nMemo Removed Successfully!\n";
}

void display() {
    node* q = top;

    if (q == NULL) {
        cout << "\nNo memos available!\n";
    } else {
        cout << "\n======================== MEMOS =======================\n";
        while (q != NULL) {
            string idLine = "ID: " + intToString(q->id);
            string titleLine = "Title: " + q->title;
            string descLine = "Description: " + q->description;

            printBoxBorder(BOX_WIDTH);
            cout << createBoxLine(idLine, BOX_WIDTH) << "\n";
            cout << createBoxLine(titleLine, BOX_WIDTH) << "\n";
            cout << createBoxLine(descLine, BOX_WIDTH) << "\n";
            
            if (q->next==NULL) {
            	printBoxBorder(BOX_WIDTH);
			}

            q = q->next;
        }
    }
}

int main() {
    push("First Memo", "This is the first memo.");
    push("Second Memo", "This is the second memo.");
    system("CLS");
    display();
    return 0;
}
